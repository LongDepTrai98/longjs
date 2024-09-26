#include <engine/environment.hpp>

namespace longjs
{
	environment::environment()
	{
		loop = uv_default_loop();// main_loop
	}
	void environment::setIsolate(v8::Isolate* isolate_)
	{
		isolate = isolate_; 
	}
	uv_loop_t* environment::getLoopUV()
	{
		return loop;
	}
}