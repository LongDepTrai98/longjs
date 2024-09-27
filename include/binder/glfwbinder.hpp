#ifndef _GLFW_BINDER_HPP_
#define _GLFW_BINDER_HPP_
#include <v8-value.h>
#include <v8-function.h>

class GLFWwindow; 

namespace longjs
{
	class glfwbinder
	{
	public: 
		static void bindAll(v8::Isolate* isolate,
			v8::Handle<v8::ObjectTemplate> global);
		static void _glfwInit(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glfwWindowHint(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void _glfwCreateWindow(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void _glfwMakeContextCurrent(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void _glfwDestroyWindow(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void _glfwTerminate(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void _glfwPollEvents(const v8::FunctionCallbackInfo<v8::Value>& args);
		static void	_glfwSwapBuffers(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void _glfwWindowShouldClose(const v8::FunctionCallbackInfo<v8::Value>& args);
		static GLFWwindow* getMainWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	private: 
		glfwbinder(); 
	};
}
#endif // !_GLFW_BINDER_HPP_
