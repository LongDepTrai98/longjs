#pragma once
#ifndef _V8_HELPER_HPP_
#define _V8_HELPER_HPP_
#include <v8.h>
namespace longjs
{
	class v8Helper
	{
	public: 
		static v8::Local<v8::String> createV8String(const std::string& str)
		{
			return v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), str.c_str()).ToLocalChecked();
		}

		static std::string toString(const v8::String::Utf8Value& v8_value)
		{
			return *v8_value; 
		}

		static const char* ToCString(const v8::String::Utf8Value& value) {
			return *value ? *value : "<string conversion failed>";
		}

		static v8::Local<v8::Integer> createV8Integer(const int& num)
		{
			return v8::Integer::New(v8::Isolate::GetCurrent(), num);
		}

		static v8::Local<v8::Boolean> createV8Bool(const bool& b)
		{
			return v8::Boolean::New(v8::Isolate::GetCurrent(), b);
		}

		static void ReportException(v8::Isolate* isolate,
			v8::TryCatch* try_catch) {
			v8::HandleScope handle_scope(isolate);
			v8::String::Utf8Value exception(isolate, try_catch->Exception());
			const char* exception_string = v8Helper::ToCString(exception);
			v8::Local<v8::Message> message = try_catch->Message();
			if (message.IsEmpty()) {
				// V8 didn't provide any extra information about this error; just
				// print the exception.
				//fprintf(stderr, "%s\n", exception_string);
			}
			else {
				// Print (filename):(line number): (message).
				v8::String::Utf8Value filename(isolate,
					message->GetScriptOrigin().ResourceName());
				v8::Local<v8::Context> context(isolate->GetCurrentContext());
				const char* filename_string = v8Helper::ToCString(filename);
				int linenum = message->GetLineNumber(context).FromJust();
				fprintf(stderr, "%s:%i: %s\n", filename_string, linenum, exception_string);
				// Print line of source code.
				v8::String::Utf8Value sourceline(
					isolate, message->GetSourceLine(context).ToLocalChecked());
				const char* sourceline_string = v8Helper::ToCString(sourceline);
				fprintf(stderr, "%s\n", sourceline_string);
				// Print wavy underline (GetUnderline is deprecated).
				int start = message->GetStartColumn(context).FromJust();
				for (int i = 0; i < start; i++) {
					fprintf(stderr, " ");
				}
				int end = message->GetEndColumn(context).FromJust();
				for (int i = start; i < end; i++) {
					fprintf(stderr, "^");
				}
				fprintf(stderr, "\n");
				v8::Local<v8::Value> stack_trace_string;
				if (try_catch->StackTrace(context).ToLocal(&stack_trace_string) &&
					stack_trace_string->IsString() &&
					stack_trace_string.As<v8::String>()->Length() > 0) {
					v8::String::Utf8Value stack_trace(isolate, stack_trace_string);
					const char* err = v8Helper::ToCString(stack_trace);
					fprintf(stderr, "%s\n", err);
				}
			}
		}

	private: 
		v8Helper(); 
	};
}
#endif // !_V8_HELPER_HPP_
