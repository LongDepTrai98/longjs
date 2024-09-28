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
		static void _glVertexAttribPointer(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void _glEnableVertexAttribArray(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glCreateShader(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glShaderSource(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glCompileShader(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glCreateProgram(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glAttachShader(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glLinkProgram(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glDeleteShader(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glUseProgram(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glDrawArrays(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glDeleteVertexArrays(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glDeleteBuffers(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glDeleteProgram(const v8::FunctionCallbackInfo<v8::Value>& args);
	private: 
		glbinder(); 
	};
}
#endif // !1
