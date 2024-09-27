#include <binder/cppbinder.hpp>
#include <iostream>
namespace longjs
{
	void cppbinder::bindAll(v8::Isolate* isolate, v8::Handle<v8::ObjectTemplate> global)
	{
		global->Set(isolate,
			"print",
			v8::FunctionTemplate::New(isolate,
				print));
		global->Set(isolate,
			"print_error",
			v8::FunctionTemplate::New(isolate,
				error));
	}
	void cppbinder::print(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		for (int i = 0; i < args.Length(); ++i)
		{
			v8::String::Utf8Value str(isolate,
				args[i]);
			std::cout << *str << std::endl;
		}
	}
	void cppbinder::error(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		for (int i = 0; i < args.Length(); ++i)
		{
			v8::String::Utf8Value str(isolate,
				args[i]);
			std::cerr << *str << std::endl;
		}
	}
}