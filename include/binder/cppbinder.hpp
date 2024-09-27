#ifndef _CPP_BINDER_HPP_
#define _CPP_BINDER_HPP_
#include <v8-value.h>
#include <v8-function.h>
#include <v8-isolate.h>
#include <v8-object.h>
namespace longjs
{
	class cppbinder
	{
	public: 
		static void bindAll(v8::Isolate* isolate,
			v8::Handle<v8::ObjectTemplate> global);
		static void print(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void error(const v8::FunctionCallbackInfo<v8::Value>& args); 
	private: 
		cppbinder(); 
	};
}
#endif // !1
