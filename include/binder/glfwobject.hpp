#ifndef _GLFW_JSOBJECT_HPP_
#define _GLFW_JSOBJECT_HPP_
#include<engine/jsobject.hpp>
class GLFWwindow; 
namespace longjs
{
	class glfwobject : public jsobject
	{
	public: 
		glfwobject(); 
		~glfwobject() = default; 
	public: 
		GLFWwindow* main_window; 
	};
}
#endif // !_GLFW_JSOBJECT_HPP_
