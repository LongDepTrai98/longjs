#pragma once
#ifndef _APP_HPP_
#define _APP_HPP_
#include <memory>
#include <uv.h>
//v8 include 
#include <v8-platform.h>
#include <v8-isolate.h>
#include <v8-object.h>
#include <v8-context.h>
#include <v8-traced-handle.h>
#include <v8-isolate.h>
#include <v8-exception.h>
//fs
#include <fs/fs.hpp>

namespace longjs
{
	class app
	{
	public: 
		app(); 
		~app() = default; 
	public: 
		v8::Platform* initialize(); 
		v8::Platform* getPlatform();
		v8::Isolate* initializeIsolate(); 
		void initializeApp(const PATH& path);
		void shutdown(); 
		void bindGlobalFunction(v8::Local<v8::ObjectTemplate> global);
		void excute(const PATH& script);
		void wait(); 
		uv_loop_t* getLoopUV();
	private: 
		void compileScript(const PATH& path);
		void compileModule(const std::string& raw_code);
		v8::Local<v8::Context> createContext(v8::Isolate* isolate);
		void ReportException(v8::Isolate* isolate,
			v8::TryCatch* try_catch);
	protected: 
		std::unique_ptr<v8::Platform> main_platform{ nullptr };
		v8::Isolate* isolate{ nullptr };
		v8::Local<v8::Context> context;
		v8::Local<v8::ObjectTemplate> global; 
		v8::Isolate::CreateParams create_params;
		uv_loop_t* main_loop;// main_loop
	};
}
#endif // !_APP_HPP_


