#include <engine/app_timer.hpp>
#include <v8-isolate.h>
#include <v8-context.h>
#include <iostream>
#include <helper/v8helper.hpp>
#include <map>
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
		wrap_timer->isolate = isolate;
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
		wrap_timer->check();
	}

	void app_timer::onTimerCallback(uv_timer_t* handle)
	{
		st_timer* wrap_timer = (st_timer*)handle->data;
		v8::Isolate* isolate = wrap_timer->isolate;
		//create function callback
		v8::Local<v8::Function> callback = v8::Local<v8::Function>::New(
			isolate,
			wrap_timer->callback
		);
		v8::Local<v8::Context> context = isolate->GetCurrentContext(); 
		if (context.IsEmpty())
		{
			std::cout << "Context null" << std::endl; 
			return; 
		}
		if (isolate->IsDead()) {
			std::cout << "Isolate dead\n";
			return;
		}
		callback->Call(
			context,
			v8::Undefined(isolate),
			0,
			NULL); 
	}

	void app_timer::on_timer_close_complete(uv_handle_t* handle)
	{
		free(handle);
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
