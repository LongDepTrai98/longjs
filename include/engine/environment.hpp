#ifndef _ENVIRONMENT_HPP_
#define _ENVIRONMENT_HPP_
#include <v8-isolate.h>
#include <uv.h>
#include <pattern/singleton.hpp>
namespace longjs
{
	class workspace; 
	class environment : public Singleton<environment>
	{
	public: 
		environment(); 
		void setIsolate(v8::Isolate* isolate_);
		workspace* createWorkSpace(); 
		uv_loop_t* getLoopUV(); 
		workspace* getWorkSpace(); 
	private: 
		v8::Isolate* isolate; 
		uv_loop_t* loop;
		std::unique_ptr<workspace> main_workspace; 
	};
}
#endif // !_ENVIRONMENT_HPP_
