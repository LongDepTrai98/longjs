#ifndef _ENVIRONMENT_HPP_
#define _ENVIRONMENT_HPP_
#include <v8-isolate.h>
#include <uv.h>
#include <pattern/singleton.hpp>
namespace longjs
{
	class environment : public Singleton<environment>
	{
	public: 
		environment(); 
		void setIsolate(v8::Isolate* isolate_); 
		uv_loop_t* getLoopUV(); 
	private: 
		v8::Isolate* isolate; 
		uv_loop_t* loop; 
	};
}
#endif // !_ENVIRONMENT_HPP_
