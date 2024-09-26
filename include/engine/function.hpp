#pragma once
#ifndef _FUNCTION_DEFINE_HPP_
#define _FUNCTION_DEFINE_HPP_
#include <v8-function.h>
#include <v8-context.h>
#include <iostream>
#include <helper/v8helper.hpp>
namespace longjs
{
	static void print(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate(); 
		for (int i = 0; i < args.Length(); ++i)
		{
			v8::String::Utf8Value str(isolate,
				args[i]);
			std::cout << *str << std::endl; 
		}
	}

	static void test(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		//return ar 
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& a = args[0]->IntegerValue(context).ToChecked();
		const int64_t& b = args[1]->IntegerValue(context).ToChecked();
		args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), a + b));
	}
	
}
#endif // !_FUNCTION_DEFINE_HPP_
