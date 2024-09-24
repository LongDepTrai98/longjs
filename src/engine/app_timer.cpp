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
		uv_thread_t this_thread = uv_thread_self();
		//static st_timer* wrap_timer; 
		//if (wrap_timer != nullptr)
		//{
		//	/*wrap_timer->isolate = NULL; 
		//	delete[]wrap_timer; 
		//	wrap_timer = nullptr; */
		//	wrap_timer = nullptr; 
		//}
		st_timer* wrap_timer = new st_timer();
		//wrap_timer = std::unique_ptr<st_timer>(new st_timer()); 
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
	}

	void app_timer::onTimerCallback(uv_timer_t* handle)
	{
		st_timer* wrap_timer = (st_timer*)handle->data;
		v8::Isolate* isolate = wrap_timer->isolate;
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
		//check isolate not have context 
		v8::Local<v8::Context> context; 
		bool isIncontext = isolate->InContext();
		if (!isIncontext)
		{
			v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);
			v8::Local<v8::Context> context = v8::Context::New(isolate, NULL, global);
			v8::Context::Scope context_scope(context);
			v8::Local<v8::Value> result;
			callback->Call(
				context,
				v8::Undefined(isolate),
				0,
				NULL);
		}
		else
		{
			context = isolate->GetCurrentContext();
			callback->Call(
				context,
				v8::Undefined(isolate),
				0,
				NULL);
		}
		uv_timer_stop(handle);
		uv_close((uv_handle_t*)handle, on_timer_close_complete);
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
