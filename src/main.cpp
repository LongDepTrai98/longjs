//#include <stdio.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
//#include <string>
//#include <uv.h>
//
//uv_loop_t* loop;
//uv_timer_t gc_req;
//uv_timer_t fake_job_req;
//
//void callbackFn()
//{
//    printf("callback executed!\n");
//}
//
//typedef void (*functionTemplate)(void);
//
//struct timer
//{
//    uv_timer_t req;
//    std::string text;
//    functionTemplate* callback;
//};
//
//void work(uv_timer_t* handle)
//{
//    timer* timerWrap = (timer*)handle->data;
//
//    ((functionTemplate)timerWrap->callback)();
//
//    printf("%s", timerWrap->text.c_str());
//}
//
//int main()
//{
//    loop = uv_default_loop();
//    for (size_t i = 0; i < 10; i++)
//    {
//        timer* timerWrap = new timer();
//        timerWrap->callback = (functionTemplate*)callbackFn;
//        timerWrap->text = "hello: " + std::to_string(i) + "\n";
//
//        timerWrap->req.data = (void*)timerWrap;
//
//        // could actually be a TCP download or something
//        uv_timer_init(loop, &timerWrap->req);
//        int delay = 1000;
//        int interval = 0;
//        uv_timer_start(&timerWrap->req, work, delay, interval);
//    }
//
//    return uv_run(loop, UV_RUN_DEFAULT);
//}

// Copyright 2015 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#include <v8.h>
//#include <libplatform/libplatform.h>
//
////#include "libplatform/libplatform.h"
////#include "v8-context.h"
////#include "v8-initialization.h"
////#include "v8-isolate.h"
////#include "v8-local-handle.h"
////#include "v8-primitive.h"
////#include "v8-script.h"
////#include "v8.h"
////#include "v8-version.h"
//
//
//#include <uv.h>
//
//uv_loop_t* loop;
//uv_timer_t gc_req;
//uv_timer_t fake_job_req;
//
//void callbackFn()
//{
//    printf("callback executed!\n");
//}
//
//typedef void (*functionTemplate)(void);
//
//struct timer
//{
//    uv_timer_t req;
//    std::string text;
//    functionTemplate* callback;
//    v8::Isolate* isolate; 
//};
//
//void work(uv_timer_t* handle)
//{
//    timer* timerWrap = (timer*)handle->data;
//    v8::Isolate* isolate = timerWrap->isolate; 
//    if (!isolate->InContext())
//    {
//        int a = 3; 
//    }
//    ((functionTemplate)timerWrap->callback)();
//
//    printf("%s", timerWrap->text.c_str());
//}
//
//void Print(const v8::FunctionCallbackInfo<v8::Value>& args)
//{
//    bool first = true;
//    for (int i = 0; i < args.Length(); i++)
//    {
//        v8::HandleScope handle_scope(args.GetIsolate());
//        if (first)
//        {
//            first = false;
//        }
//        else
//        {
//            printf(" ");
//        }
//        v8::String::Utf8Value str(args.GetIsolate(), args[i]);
//
//        printf("%s", *str);
//    }
//
//    timer* timerWrap = new timer();
//    timerWrap->callback = (functionTemplate*)callbackFn;
//    timerWrap->text = "hello: \n";
//    timerWrap->isolate = args.GetIsolate();
//    timerWrap->req.data = (void*)timerWrap;
//
//    // could actually be a TCP download or something
//    uv_timer_init(loop, &timerWrap->req);
//    int delay = 1000;
//    int interval = 0;
//    uv_timer_start(&timerWrap->req, work, delay, interval);
//
//    printf("\n");
//    fflush(stdout);
//}
//
//v8::Local<v8::Context> CreateContext(v8::Isolate* isolate)
//{
//    // Create a template for the global object.
//    v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);
//    // Bind the global 'print' function to the C++ Print callback.
//
//    global->Set(isolate, "print", v8::FunctionTemplate::New(isolate, Print));
//
//    // Create a new context.
//    return v8::Context::New(isolate, NULL, global);
//}
//
//int main(int argc, char* argv[])
//{
//    // Initialize V8.
//    v8::V8::InitializeICU();
//    v8::V8::InitializeExternalStartupData(argv[0]);
//    std::unique_ptr<v8::Platform> platform(v8::platform::NewDefaultPlatform());
//    /*std::unique_ptr<v8::Platform> main_platform = std::move(v8::platform::NewDefaultPlatform());*/
//    v8::V8::InitializePlatform(platform.get());
//    try
//    {
//        bool t = v8::V8::Initialize();
//
//    }
//    catch (const std::exception& e)
//    {
//        int a = 3; 
//    }
//
//    // Create a new Isolate and make it the current one.
//    v8::Isolate::CreateParams create_params;
//    create_params.array_buffer_allocator =
//        v8::ArrayBuffer::Allocator::NewDefaultAllocator();
//    v8::Isolate* isolate = v8::Isolate::New(create_params);
//    {
//        v8::Isolate::Scope isolate_scope(isolate);
//
//        // Create a stack-allocated handle scope.
//        v8::HandleScope handle_scope(isolate);
//
//        // Create a new context.
//        v8::Local<v8::Context> context = CreateContext(isolate);
//
//        // Enter the context for compiling and running the hello world script.
//        v8::Context::Scope context_scope(context);
//
//        {
//            loop = uv_default_loop();
//
//            // Create a string containing the JavaScript source code.
//            v8::Local<v8::String> source =
//                v8::String::NewFromUtf8Literal(isolate, "print('Hello, World!...');");
//
//            // Compile the source code.
//            v8::Local<v8::Script> script =
//                v8::Script::Compile(context, source).ToLocalChecked();
//
//            // Run the script to get the result.
//            v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();
//
//       
//            uv_run(loop, UV_RUN_DEFAULT); 
//            // Convert the result to an UTF8 string and print it.
//            v8::String::Utf8Value utf8(isolate, result);
//            // printf("%s\n", *utf8);
//        }
//    }
//
//    // Dispose the isolate and tear down V8.
//    isolate->Dispose();
//    v8::V8::Dispose();
//    v8::V8::DisposePlatform();
//    delete create_params.array_buffer_allocator;
//    return 0;
//}

#include <iostream>
#include <fs/fs.hpp>
#include <engine/app.hpp>
using namespace longjs; 
int main()
{
	app main_app; 
	std::string path = "test.js"; 
	if (!main_app.initialize())
	{
		std::cout << "Can't init platform\n"; 
		return -1; 
	}
	if (!main_app.initializeIsolate())
	{
		std::cout << "Can't init isolate\n"; 
		return -1; 
	}
	main_app.initializeApp(path, 
		js_type::MODULE); 
	main_app.shutdown(); 
	return 0; 
}
