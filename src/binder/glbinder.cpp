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
		global->Set(isolate,
			"glVertexAttribPointer",
			v8::FunctionTemplate::New(isolate,
				_glVertexAttribPointer));
		global->Set(isolate,
			"glEnableVertexAttribArray",
			v8::FunctionTemplate::New(isolate,
				_glEnableVertexAttribArray));
		global->Set(isolate,
			"glCreateShader",
			v8::FunctionTemplate::New(isolate,
				_glCreateShader));
		global->Set(isolate,
			"glShaderSource",
			v8::FunctionTemplate::New(isolate,
				_glShaderSource));
		global->Set(isolate,
			"glCompileShader",
			v8::FunctionTemplate::New(isolate,
				_glCompileShader));
		global->Set(isolate,
			"glCreateProgram",
			v8::FunctionTemplate::New(isolate,
				_glCreateProgram));
		global->Set(isolate,
			"glAttachShader",
			v8::FunctionTemplate::New(isolate,
				_glAttachShader));
		global->Set(isolate,
			"glLinkProgram",
			v8::FunctionTemplate::New(isolate,
				_glLinkProgram));
		global->Set(isolate,
			"glDeleteShader",
			v8::FunctionTemplate::New(isolate,
				_glDeleteShader));
		global->Set(isolate,
			"glUseProgram",
			v8::FunctionTemplate::New(isolate,
				_glUseProgram));
		global->Set(isolate,
			"glDrawArrays",
			v8::FunctionTemplate::New(isolate,
				_glDrawArrays));
		global->Set(isolate,
			"glDeleteVertexArrays",
			v8::FunctionTemplate::New(isolate,
				_glDeleteVertexArrays));
		global->Set(isolate,
			"glDeleteBuffers",
			v8::FunctionTemplate::New(isolate,
				_glDeleteBuffers));
		global->Set(isolate,
			"glDeleteProgram",
			v8::FunctionTemplate::New(isolate,
				_glDeleteProgram));
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

	void glbinder::_glVertexAttribPointer(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& index = args[0]->IntegerValue(context).ToChecked();
		const int64_t& size = args[1]->IntegerValue(context).ToChecked(); 
		const int64_t& type = args[2]->IntegerValue(context).ToChecked();
		const int64_t& normalized = args[3]->IntegerValue(context).ToChecked();
		const int64_t& stride = args[4]->IntegerValue(context).ToChecked(); 
		const int64_t& offset = args[5]->IntegerValue(context).ToChecked(); 
		glVertexAttribPointer(index, 
			size, 
			type, 
			normalized, 
			stride * sizeof(float),
			(void*)(offset));
	}

	void glbinder::_glEnableVertexAttribArray(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& layout_index = args[0]->IntegerValue(context).ToChecked();
		glEnableVertexAttribArray(layout_index);

	}

	void glbinder::_glCreateShader(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& df = args[0]->IntegerValue(context).ToChecked();
		GLuint index = glCreateShader(df);
		args.GetReturnValue().Set(v8::Number::New(isolate, index));
	}

	void glbinder::_glShaderSource(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& shader = args[0]->IntegerValue(context).ToChecked();
		v8::String::Utf8Value source(isolate,args[1]->ToString(context).ToLocalChecked()); 
		const char* str_source = *source;
		glShaderSource(shader, 
			1,
			&str_source,
			nullptr);
	}

	void glbinder::_glCompileShader(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& shader = args[0]->IntegerValue(context).ToChecked();
		glCompileShader(shader);
		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
		    glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		    std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

	void glbinder::_glCreateProgram(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		unsigned int shaderProgram = glCreateProgram();
		args.GetReturnValue().Set(v8::Number::New(isolate, shaderProgram));
	}

	void glbinder::_glAttachShader(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& shaderProgram = args[0]->IntegerValue(context).ToChecked();
		const int64_t& shader = args[1]->IntegerValue(context).ToChecked();
		glAttachShader(shaderProgram, shader); 
	}

	void glbinder::_glLinkProgram(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& shaderProgram = args[0]->IntegerValue(context).ToChecked();
		glLinkProgram(shaderProgram); 
		int success;
		char infoLog[512];
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
			std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
	}

	void glbinder::_glDeleteShader(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& shader = args[0]->IntegerValue(context).ToChecked();
		glDeleteShader(shader); 
	}

	void glbinder::_glUseProgram(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& shaderProgram = args[0]->IntegerValue(context).ToChecked();
		glUseProgram(shaderProgram);
	}

	void glbinder::_glDrawArrays(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const int64_t& def = args[0]->IntegerValue(context).ToChecked();
		const int64_t& first = args[1]->IntegerValue(context).ToChecked();
		const int64_t& count = args[2]->IntegerValue(context).ToChecked();
		glDrawArrays(def, 
			first,
			count);
	}

	void glbinder::_glDeleteVertexArrays(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		GLuint VAO = args[0]->IntegerValue(context).ToChecked();
		glDeleteVertexArrays(1, &VAO);
	}

	void glbinder::_glDeleteBuffers(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		GLuint VBO = args[0]->IntegerValue(context).ToChecked();
		glDeleteBuffers(1, &VBO);
	}

	void glbinder::_glDeleteProgram(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		GLuint program = args[0]->IntegerValue(context).ToChecked();
		glDeleteProgram(program); 
	}

	void glbinder::_glClearColor(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		auto context = isolate->GetCurrentContext();
		const float_t& r = static_cast<float>(args[0]->NumberValue(context).ToChecked());
		const float_t& g = static_cast<float>(args[1]->NumberValue(context).ToChecked());
		const float_t& b = static_cast<float>(args[2]->NumberValue(context).ToChecked());
		const float_t& a = static_cast<float>(args[3]->NumberValue(context).ToChecked());
		glClearColor(r,g,b,a);
	}
}