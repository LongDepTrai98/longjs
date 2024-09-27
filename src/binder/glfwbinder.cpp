#include <binder/glfwbinder.hpp>
#include <GLFW/glfw3.h>
#include <v8-isolate.h>
#include <helper/v8helper.hpp>
#include <helper/rapidhelper.hpp>
#include <binder/glfwobject.hpp>
#include <engine/environment.hpp>
#include <engine/workspace.hpp>

namespace longjs
{
	void glfwbinder::bindAll(v8::Isolate* isolate, v8::Handle<v8::ObjectTemplate> global)
	{
		global->Set(isolate,
			"glfwInit",
			v8::FunctionTemplate::New(isolate,
				_glfwInit));
		global->Set(isolate,
			"glfwWindowHint",
			v8::FunctionTemplate::New(isolate,
				_glfwWindowHint));
		global->Set(isolate,
			"glfwCreateWindow",
			v8::FunctionTemplate::New(isolate,
				_glfwCreateWindow));
		global->Set(isolate,
			"glfwMakeContextCurrent",
			v8::FunctionTemplate::New(isolate,
				_glfwMakeContextCurrent));
		global->Set(isolate,
			"glfwDestroyWindow",
			v8::FunctionTemplate::New(isolate,
				_glfwDestroyWindow));
		global->Set(isolate,
			"glfwTerminate",
			v8::FunctionTemplate::New(isolate,
				_glfwTerminate));
		global->Set(isolate,
			"glfwPollEvents",
			v8::FunctionTemplate::New(isolate,
				_glfwPollEvents));
		global->Set(isolate,
			"glfwSwapBuffers",
			v8::FunctionTemplate::New(isolate,
				_glfwSwapBuffers));
		global->Set(isolate,
			"glfwWindowShouldClose",
			v8::FunctionTemplate::New(isolate,
				_glfwWindowShouldClose));
	}
	void glfwbinder::_glfwInit(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate(); 
		auto isCreate = glfwInit(); 
		args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(),bool(isCreate)));
	}
	void glfwbinder::_glfwWindowHint(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	void glfwbinder::_glfwCreateWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		//width , height, name
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& width = args[0]->IntegerValue(context).ToChecked();
		const int64_t& height = args[1]->IntegerValue(context).ToChecked();
		v8::String::Utf8Value name_str(isolate, args[2]->ToString(context).ToLocalChecked()); 
		const std::string& w_name = *name_str;
		std::unique_ptr<glfwobject> glfw_object = std::unique_ptr<glfwobject>(new glfwobject());
		glfw_object->main_window = glfwCreateWindow(width,
			height,
			w_name.c_str(),
			NULL,
			NULL);
		rapidjson::Document isCreate; 
		isCreate.SetObject(); 
		auto& allocator = isCreate.GetAllocator(); 
		isCreate.AddMember("uuid",
			rapidhelper::rapid_create_string(glfw_object->getUUid(),allocator),
			allocator); 
		!glfw_object->main_window ? isCreate.AddMember("create", false, allocator) : isCreate.AddMember("create", true, allocator);
		args.GetReturnValue().Set(v8::JSON::Parse(context,
			v8Helper::createV8String(rapidhelper::rapid_dump(isCreate))).ToLocalChecked());
		environment::GetInstance()->getWorkSpace()->add(std::move(glfw_object)); 
	}
	void glfwbinder::_glfwMakeContextCurrent(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		auto main_window = getMainWindow(args);
		if (main_window)
		{
			glfwMakeContextCurrent(main_window);
		}
	}
	void glfwbinder::_glfwDestroyWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		auto main_window = getMainWindow(args); 
		if (main_window)
		{
			glfwDestroyWindow(main_window);
		}
	}
	void glfwbinder::_glfwTerminate(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		glfwTerminate(); 
	}
	void glfwbinder::_glfwPollEvents(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		glfwPollEvents(); 
	}
	void glfwbinder::_glfwSwapBuffers(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		auto main_window = getMainWindow(args);
		if (main_window)
		{
			glfwSwapBuffers(main_window);
		}
	}
	void glfwbinder::_glfwWindowShouldClose(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		bool t = true; 
		auto main_window = getMainWindow(args);
		if (main_window)
		{
			t = glfwWindowShouldClose(main_window);
		}
		args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), bool(t)));
	}
	GLFWwindow* glfwbinder::getMainWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		if (!args[0]->IsObject())
		{
			return nullptr;
		}
		v8::Local<v8::Object> window_obj = args[0]->ToObject(context).ToLocalChecked();
		v8::Local<v8::String> str = v8::JSON::Stringify(context,
			window_obj).ToLocalChecked();
		v8::String::Utf8Value json_str(isolate,
			str);
		rapidjson::Document doc;
		if (doc.Parse(*json_str).HasParseError())
		{
			return nullptr;
		}
		std::string uuid = doc["uuid"].GetString();
		glfwobject* glfw_obj = environment::GetInstance()->getWorkSpace()->getObjectInWorkspace(uuid)->as<glfwobject>();
		return glfw_obj->main_window; 
	}
}
