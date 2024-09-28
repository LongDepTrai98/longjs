#include <binder/glbinder.hpp>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <v8-isolate.h>
#include <v8-value.h>
#include <v8-json.h>
#include <v8-container.h>
#include <v8.h>
#include <iostream>
namespace longjs
{
	static void CallbackResult(uint32_t index, v8::Local<v8::Value> element, void* data)
	{

	}

	void glbinder::bindAll(v8::Isolate* isolate, v8::Handle<v8::ObjectTemplate> global)
	{
		global->Set(isolate,
			"glewInit",
			v8::FunctionTemplate::New(isolate,
				_glewInit));
		global->Set(isolate,
			"glViewport",
			v8::FunctionTemplate::New(isolate,
				_glViewport));
		global->Set(isolate,
			"glGenVertexArrays",
			v8::FunctionTemplate::New(isolate,
				_glGenVertexArrays));
		global->Set(isolate,
			"glBindVertexArray",
			v8::FunctionTemplate::New(isolate,
				_glBindVertexArray));
		global->Set(isolate,
			"glGenBuffers",
			v8::FunctionTemplate::New(isolate,
				_glGenBuffers));
		global->Set(isolate,
			"glBindBuffer",
			v8::FunctionTemplate::New(isolate,
				_glBindBuffer));
		global->Set(isolate,
			"glBufferData",
			v8::FunctionTemplate::New(isolate,
				_glBufferData));
		global->Set(isolate,
			"glClearColor",
			v8::FunctionTemplate::New(isolate,
				_glClearColor));
		global->Set(isolate,
			"glClear",
			v8::FunctionTemplate::New(isolate,
				_glClear));
	}
	void glbinder::_glewInit(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		glewExperimental = GL_TRUE;
		bool b = glewInit() == GLEW_OK; 
		args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), bool(b)));
	}
	void glbinder::_glViewport(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& x = args[0]->IntegerValue(context).ToChecked();
		const int64_t& y = args[0]->IntegerValue(context).ToChecked();
		const int64_t& width = args[0]->IntegerValue(context).ToChecked();
		const int64_t& height = args[0]->IntegerValue(context).ToChecked();
		glViewport(0, 
			0, 
			800,
			600); 
	}
	void glbinder::_glGenVertexArrays(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& size = args[0]->IntegerValue(context).ToChecked();
		unsigned int VAO;
		glGenVertexArrays(size, &VAO);
		args.GetReturnValue().Set(v8::Number::New(isolate, VAO)); 
	}
	void glbinder::_glBindVertexArray(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& VAO = args[0]->IntegerValue(context).ToChecked();
		glBindVertexArray(VAO);
	}
	void glbinder::_glGenBuffers(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		unsigned int VBO;
		const int64_t& size = args[0]->IntegerValue(context).ToChecked();
		glGenBuffers(1, &VBO);
		args.GetReturnValue().Set(v8::Number::New(isolate, VBO));

	}
	void glbinder::_glBindBuffer(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& df = args[0]->IntegerValue(context).ToChecked();
		const int64_t& VBO = args[1]->IntegerValue(context).ToChecked();
		if (df == GL_ARRAY_BUFFER)
		{
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
		}
	}
	void glbinder::_glBufferData(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& df = args[0]->IntegerValue(context).ToChecked();
		if (args[1]->IsFloat32Array())
		{
			v8::Local<v8::Float32Array> float32Array = v8::Local<v8::Float32Array>::Cast(args[1]);
			auto length = float32Array->Length();
			auto buffer = float32Array->Buffer();
			glBufferData(GL_ARRAY_BUFFER, 
				length * sizeof(float),
				buffer->Data(), 
				GL_STATIC_DRAW);
		}
	}

	void glbinder::_glClear(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void glbinder::_glClearColor(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const float_t& r = static_cast<float>(args[0]->NumberValue(context).ToChecked());
		const float_t& g = static_cast<float>(args[1]->IntegerValue(context).ToChecked());
		const float_t& b = static_cast<float>(args[2]->IntegerValue(context).ToChecked());
		const float_t& a = static_cast<float>(args[3]->IntegerValue(context).ToChecked());
		glClearColor(r,g,b,a);
	}
}