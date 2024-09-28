#ifndef _GL_BINDER_HPP_
#define _GL_BINDER_HPP_
#include <v8-value.h>
#include <v8-function.h>
namespace longjs
{
	class glbinder
	{
	public: 
		static void bindAll(v8::Isolate* isolate,
			v8::Handle<v8::ObjectTemplate> global);
		static void _glewInit(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void _glViewport(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glGenVertexArrays(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void _glBindVertexArray(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glGenBuffers(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glBindBuffer(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glBufferData(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glClearColor(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glClear(const v8::FunctionCallbackInfo<v8::Value>& args);
	private: 
		glbinder(); 
	};
}
#endif // !1
