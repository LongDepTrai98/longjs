#include <engine/app.hpp>
#include <v8.h>
#include <v8-platform.h>
#include <v8-initialization.h>
#include <libplatform/libplatform.h>
#include <engine/function.hpp>
#include <helper/v8helper.hpp>
#include <engine/app_timer.hpp>
#include <engine/module.hpp>
#include <engine/environment.hpp>
#include <binder/cppbinder.hpp>
#include <binder/glfwbinder.hpp>
#include <binder/glbinder.hpp>

namespace longjs
{
	app::app()
	{
	}

	v8::Platform* app::initialize()
	{
		v8::V8::InitializeICU();
		v8::V8::InitializeICUDefaultLocation("");
		v8::V8::InitializeExternalStartupData(""); 
		main_platform = v8::platform::NewDefaultPlatform();
		v8::V8::InitializePlatform(main_platform.get());
		if (!v8::V8::Initialize())
		{
			return nullptr; 
		}
		return main_platform.get();
	}
	v8::Platform* app::getPlatform()
	{
		return main_platform.get(); 
	}
	v8::Isolate* app::initializeIsolate()
	{
		create_params.array_buffer_allocator =
			v8::ArrayBuffer::Allocator::NewDefaultAllocator();
		isolate = v8::Isolate::New(create_params);
		return isolate;
	}
	void app::initializeApp(const PATH& path,
		const js_type& type)
	{
		//create loop
		environment::GetInstance()->setIsolate(isolate); 
		v8::TryCatch try_catch(isolate);
		v8::Isolate::Scope isolate_scope(this->isolate);
		// Create a stack-allocated handle scope.
		v8::HandleScope handle_scope(this->isolate); 
		//init global 
		initGlobal(); 
		bindGlobalCPPFunction();
		//bind function
		//create context
		context = createContext();
		v8::Context::Scope context_scope(context);
		//compile global function 
		compileScript("global.js"); 
		//lock scope 
		{
			switch (type)
			{
			case js_type::SCRIPT: 
			{
				compileScript(path);
				break; 
			}
			case js_type::MODULE: 
			{
				compileModule(path); 
				break; 
			}
			default:
				break;
			}
			wait();
		}
		v8Helper::ReportException(isolate, &try_catch);

	}
	void app::initGlobal()
	{
		global = v8::ObjectTemplate::New(isolate);
	}
	void app::shutdown()
	{
		isolate->Dispose();
		v8::V8::Dispose();
		v8::V8::DisposePlatform();
		delete create_params.array_buffer_allocator;
	}
	void app::bindGlobalCPPFunction()
	{
		cppbinder::bindAll(isolate,
			global); 

		//timer 
		app_timer app_timer; 
		global->Set(isolate,
			"lj_timer",
			v8::FunctionTemplate::New(isolate, 
				app_timer.setTimeOut));
		//custom 
		glfwbinder::bindAll(isolate,
			global); 
		glbinder::bindAll(isolate,
			global); 
		global->Set(isolate,
			"plus",
			v8::FunctionTemplate::New(isolate,
				test));
	}

	void app::excute(const PATH& path)
	{
		compileScript(path); 
	}
	void app::wait()
	{
		auto loop = environment::GetInstance()->getLoopUV(); 
		uv_run(loop, UV_RUN_DEFAULT);
	}
	
	void app::compileScript(const PATH& path)
	{
		
		//create context scope 
		v8::TryCatch try_catch(isolate);
		//v8::Context::Scope context_scope(context);
		std::string raw_code;
		if (!fs::readFile(path, raw_code))
		{
			throw std::exception("can't read file");
			return;
		}
		v8::Local<v8::String> source = v8Helper::createV8String(raw_code);

		//create script origin 
		v8::ScriptOrigin origin(isolate, 
			v8Helper::createV8String(path.string()));
		// Compile the source code.
		v8::MaybeLocal<v8::Script> script =
			v8::Script::Compile(context,
				source,
				&origin);
		if (script.IsEmpty())
			return;
		auto result = script.ToLocalChecked()->Run(context);
		v8Helper::ReportException(isolate, &try_catch);
		if (result.IsEmpty())
			return;
	}

	void app::compileModule(const PATH& path)
	{
		const std::string& module_name = path.string(); 
		std::string raw_code; 
		//get raw code 
		if (!fs::readFile(path, raw_code))
		{
			throw std::exception("can't read file");
			return;
		}
		module_wrap module; 
		module.Evaluate(module_name, 
			raw_code,
			isolate);
	}

	v8::Local<v8::Context> app::createContext()
	{
		// Create a new context.
		return v8::Context::New(isolate, NULL, global);
	}
}