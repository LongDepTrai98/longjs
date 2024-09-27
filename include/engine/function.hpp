#pragma once
#ifndef _FUNCTION_DEFINE_HPP_
#define _FUNCTION_DEFINE_HPP_
#include <v8-function.h>
#include <v8-context.h>
#include <iostream>
#include <helper/v8helper.hpp>
#include <helper/rapidhelper.hpp>
#include <engine/environment.hpp>
#include <GLFW/glfw3.h>
namespace longjs
{
	//static void print(const v8::FunctionCallbackInfo<v8::Value>& args)
	//{
	//	v8::Isolate* isolate = args.GetIsolate(); 
	//	for (int i = 0; i < args.Length(); ++i)
	//	{
	//		v8::String::Utf8Value str(isolate,
	//			args[i]);
	//		std::cout << *str << std::endl; 
	//	}
	//}

	//static void error(const v8::FunctionCallbackInfo<v8::Value>& args)
	//{
	//	v8::Isolate* isolate = args.GetIsolate();
	//	for (int i = 0; i < args.Length(); ++i)
	//	{
	//		v8::String::Utf8Value str(isolate,
	//			args[i]);
	//		std::cerr << *str << std::endl;
	//	}
	//}

	static void test(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		//return ar
		
		if (!glfwInit()) {
			std::cerr << "Failed to initialize GLFW!" << std::endl;
			//return false;
		}


		environment::GetInstance(); 
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& a = args[0]->IntegerValue(context).ToChecked();
		const int64_t& b = args[1]->IntegerValue(context).ToChecked();
		rapidjson::Document root; 
		root.SetObject(); 
		auto& allocator = root.GetAllocator(); 
		root.AddMember("test", 3, allocator); 
		root.AddMember("test2", 4, allocator);
		std::string rapid_dump_test = rapidhelper::rapid_dump(root); 
		args.GetReturnValue().Set(v8::JSON::Parse(context,v8Helper::createV8String(rapid_dump_test)).ToLocalChecked());
	}
	
}
#endif // !_FUNCTION_DEFINE_HPP_
