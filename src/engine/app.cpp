#include <engine/app.hpp>
#include <v8.h>
#include <v8-platform.h>
#include "v8-initialization.h"
#include "libplatform/libplatform.h"
#include <engine/function.hpp>
#include <helper/v8helper.hpp>
#include <engine/app_timer.hpp>
namespace longjs
{
	app::app()
	{
	}
	v8::Platform* app::initialize()
	{
		v8::V8::InitializeICU();
		v8::V8::InitializeICUDefaultLocation("");
		v8::V8::InitializeExternalStartupData(""); 
		main_platform = v8::platform::NewDefaultPlatform();
		v8::V8::InitializePlatform(main_platform.get());
		if (!v8::V8::Initialize())
		{
			return nullptr; 
		}
		return main_platform.get();
	}
	v8::Platform* app::getPlatform()
	{
		return main_platform.get(); 
	}
	v8::Isolate* app::initializeIsolate()
	{
		create_params.array_buffer_allocator =
			v8::ArrayBuffer::Allocator::NewDefaultAllocator();
		isolate = v8::Isolate::New(create_params);
		return isolate;
	}
	void app::initializeApp(const PATH& path)
	{
		//create loop
		main_loop = uv_default_loop();
		v8::Isolate::Scope isolate_scope(this->isolate);
		// Create a stack-allocated handle scope.
		v8::HandleScope handle_scope(this->isolate);
		//create context
		context = createContext(isolate);
		//v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);
		//global->Set(isolate, "print", v8::FunctionTemplate::New(isolate, print));
		//app_timer app_timer;
		//app_timer.initialize(main_loop); 
		//global->Set(isolate, "setTimeout", v8::FunctionTemplate::New(isolate, app_timer.setTimeOut));
		//context = v8::Context::New(this->isolate, NULL, global);
		//try catch 
		compileScript(path);
		wait();
		uv_loop_close(main_loop);
	}
	void app::shutdown()
	{
		isolate->Dispose();
		v8::V8::Dispose();
		v8::V8::DisposePlatform();
		delete create_params.array_buffer_allocator;
	}
	void app::bindGlobalFunction(v8::Local<v8::ObjectTemplate> global)
	{
		global->Set(isolate, 
			"print",
			v8::FunctionTemplate::New(isolate,
				print));
		//create function timer
		app_timer app_timer; 
		app_timer.initialize(main_loop); 
		global->Set(isolate,
			"setTimeout",
			v8::FunctionTemplate::New(isolate, 
				app_timer.setTimeOut)); 
	}
	void app::excute(const PATH& path)
	{
		compileScript(path); 
	}
	void app::wait()
	{
		uv_run(main_loop, UV_RUN_DEFAULT);
	}
	uv_loop_t* app::getLoopUV()
	{
		return main_loop;
	}
	void app::compileScript(const PATH& path)
	{
		//create context scope 
		v8::TryCatch try_catch(isolate);
		v8::Context::Scope context_scope(this->context); 
		std::string raw_code;
		if (!fs::readFile(path, raw_code))
		{
			throw std::exception("can't read file"); 
			return;
		}
		v8::Local<v8::String> source = v8Helper::createV8String(raw_code);

		//create script origin 
		v8::ScriptOrigin origin(isolate, v8Helper::createV8String(path.string()));
		// Compile the source code.
		v8::MaybeLocal<v8::Script> script =
			v8::Script::Compile(context,
				source, 
				&origin);
		if (script.IsEmpty())
			return; 
		auto result = script.ToLocalChecked()->Run(this->context);
		ReportException(isolate, &try_catch);
		if (result.IsEmpty())
			return; 
		v8::String::Utf8Value utf8(this->isolate, result.ToLocalChecked());
	}

	void app::compileModule(const std::string& raw_code)
	{
	}

	v8::Local<v8::Context> app::createContext(v8::Isolate* isolate)
	{
		v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);
		// Bind the global 'print' function to the C++ Print callback.
		bindGlobalFunction(global); 
		// Create a new context.
		return v8::Context::New(isolate, NULL, global);
	}


	void app::ReportException(v8::Isolate* isolate,
		v8::TryCatch* try_catch) {
		v8::HandleScope handle_scope(isolate);
		v8::String::Utf8Value exception(isolate, try_catch->Exception());
		const char* exception_string = v8Helper::ToCString(exception);
		v8::Local<v8::Message> message = try_catch->Message();
		if (message.IsEmpty()) {
			// V8 didn't provide any extra information about this error; just
			// print the exception.
			fprintf(stderr, "%s\n", exception_string);
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
}