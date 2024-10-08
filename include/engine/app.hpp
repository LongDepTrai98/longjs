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
	enum class js_type
	{
		SCRIPT,
		MODULE
	};
	class app
	{
	public: 
		app(); 
		~app() = default; 
	public: 
		v8::Platform* initialize(); 
		v8::Platform* getPlatform();
		v8::Isolate* initializeIsolate(); 
		void initializeApp(const PATH& path, 
			const js_type& type);
		void initGlobal(); 
		void shutdown(); 
		void bindGlobalCPPFunction();
		void excute(const PATH& script);
		void wait(); 
	private: 
		void compileScript(const PATH& path);
		void compileModule(const PATH& path);
		v8::Local<v8::Context> createContext();
		//void ReportException(v8::Isolate* isolate,
		//	v8::TryCatch* try_catch);
	protected: 
		std::unique_ptr<v8::Platform> main_platform{ nullptr };
		v8::Isolate* isolate{ nullptr };
		v8::Local<v8::Context> context;
		v8::Isolate::CreateParams create_params;
		v8::Handle<v8::ObjectTemplate> global; 
	};
}
#endif // !_APP_HPP_


