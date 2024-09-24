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

	private: 
		v8Helper(); 
	};
}
#endif // !_V8_HELPER_HPP_
