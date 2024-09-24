#pragma once
#ifndef _FUNCTION_DEFINE_HPP_
#define _FUNCTION_DEFINE_HPP_
#include <v8-function.h>
#include <v8-context.h>
#include <iostream>
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
	
}
#endif // !_FUNCTION_DEFINE_HPP_
