#pragma once
#ifndef _APP_TIMER_HPP_
#define _APP_TIMER_HPP_
#include <uv.h>
#include <v8-function.h>
#include <v8-isolate.h>
namespace longjs
{
	struct st_timer
	{
	public: 
		//handler of timer 
		uv_timer_t uv_timer; 
		v8::Isolate* isolate; 
		v8::Global<v8::Function> callback;
	};
	class app_timer
	{
	public: 
		static void setTimeOut(const v8::FunctionCallbackInfo<v8::Value>& args); 
		static void initTimer(const int64_t& delay,
			const int64_t& interval, 
			v8::Isolate* isolate,
			v8::Local<v8::Function> callback);
		static void onTimerCallback(uv_timer_t* handle);
		static void on_timer_close_complete(uv_handle_t* handle); 
	};
}
#endif // !_APP_TIMER_HPP_


