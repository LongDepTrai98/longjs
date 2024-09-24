#include <engine/app_timer.hpp>
#include <v8-isolate.h>
#include <v8-context.h>
#include <iostream>
#include <helper/v8helper.hpp>

namespace longjs
{
	uv_loop_t* tm_loop; 
	void app_timer::initialize(uv_loop_t* loop)
	{
		tm_loop = loop; 
	}

	void app_timer::initTimer(const int64_t& delay,
		const int64_t& interval,
		v8::Isolate* isolate,
		v8::Local<v8::Function> callback)
	{
		st_timer* wrap_timer = new st_timer();
		wrap_timer->isolate = v8::Isolate::GetCurrent(); 
		wrap_timer->callback.Reset(isolate,
			callback); 
		//bind data
		wrap_timer->uv_timer.data = (void*)(wrap_timer); 
		auto isCreateTimer = uv_timer_init(tm_loop,
			&wrap_timer->uv_timer);
		uv_timer_start(&wrap_timer->uv_timer,
			onTimerCallback,
			delay, 
			interval);
	}

	void app_timer::onTimerCallback(uv_timer_t* handle)
	{
		std::cout << "On timer callback" << std::endl;
		st_timer* wrap_timer = (st_timer*)handle->data;
		v8::Isolate* isolate = wrap_timer->isolate;
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		//v8::Context::Scope context_scope(context);
		if (context.IsEmpty())
		{
			int a = 3; 
		}
		//check isolate 
		if (isolate->IsDead()) {
			std::cout << "Isolate dead\n"; 
			return;
		}
		//create function callback
		v8::Local<v8::Function> callback = v8::Local<v8::Function>::New(
			isolate,
			wrap_timer->callback
		);
		////run callback
		v8::Local<v8::Value> result;
		callback->Call(
			context,
			v8::Undefined(isolate),
			0, 
			NULL);
	}

	void app_timer::setTimeOut(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate(); 
		auto context = isolate->GetCurrentContext(); 
		const int64_t& sleep = args[0]->IntegerValue(context).ToChecked();
		const int64_t& interval = args[1]->IntegerValue(context).ToChecked();
		v8::Local<v8::Value> v8Callback = args[2]; 
		if (!v8Callback->IsFunction())
		{
			return; 
		}
		initTimer(sleep,
			interval,
			isolate,
			v8Callback.As<v8::Function>()); 
	}
}
