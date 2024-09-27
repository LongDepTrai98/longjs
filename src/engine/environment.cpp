#include <engine/environment.hpp>
#include <engine/workspace.hpp>
#include <engine/jsobject.hpp>
#include <engine/workspace.hpp>
namespace longjs
{
	environment::environment()
	{
		loop = uv_default_loop();// main_loop
		main_workspace = std::unique_ptr<workspace>(new workspace()); 
	}
	void environment::setIsolate(v8::Isolate* isolate_)
	{
		isolate = isolate_; 
	}
	workspace* environment::createWorkSpace()
	{
		main_workspace = std::unique_ptr<workspace>(new workspace());
		return main_workspace.get();
	}
	uv_loop_t* environment::getLoopUV()
	{
		return loop;
	}
	workspace* environment::getWorkSpace()
	{
		return main_workspace.get(); 
	}
}