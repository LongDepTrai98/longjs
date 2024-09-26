#include <iostream>
#include <engine/module.hpp>
#include <helper/v8helper.hpp>
#include <v8-script.h>
#include <fs/fs.hpp>

namespace longjs
{
    v8::Local<v8::Value> module_wrap::Evaluate(const std::string& module_name,
        const std::string& raw_code, 
        v8::Isolate* isolate)
    {
        v8::TryCatch try_catch(isolate);
        v8::Local<v8::Context> context = isolate->GetCurrentContext(); 
        if (context.IsEmpty())
        {
            std::cout << "context null\n"; 
        }
        auto maybeModule = loadModule(module_name,
            raw_code,
            context
        );
        v8::Local<v8::Value> result = execModule(maybeModule.ToLocalChecked(),
            context);
        v8Helper::ReportException(isolate, &try_catch);
        return result; 
    }

    v8::MaybeLocal<v8::Module> module_wrap::loadModule(const std::string& module_name, 
        const std::string& raw_code,
        v8::Local<v8::Context> context)
    {
        //lock context 
        v8::Context::Scope context_scope(context);
        v8::Isolate* isolate = context->GetIsolate(); 
        v8::TryCatch try_catch(isolate);
        //compile module 
        v8::ScriptOrigin origin_module(isolate,
            v8Helper::createV8String(module_name),
            0, // line file offset
            0, // line coloum offser
            false,
            -1,
            v8::Local<v8::Value>(),
            false,
            false,
            true);
        v8::Local<v8::String> code = v8Helper::createV8String(raw_code);
        v8::ScriptCompiler::Source source(code, origin_module);
        v8::MaybeLocal<v8::Module> maybeModule = v8::ScriptCompiler::CompileModule(isolate,
            &source);
        v8::Local<v8::Module> mod;
        v8Helper::ReportException(isolate, &try_catch); 
        if (!maybeModule.ToLocal(&mod))
        {
            std::cout << "Can't compile module\n"; 
            return v8::MaybeLocal<v8::Module>(); 
        }
        Instantiate(module_name,
            maybeModule, 
            context); 
        return maybeModule;
    }

    void module_wrap::Instantiate(const std::string& module_name, 
        v8::MaybeLocal<v8::Module> maybeModule,
        v8::Local<v8::Context> context)
    {
        v8::Maybe<bool> result = maybeModule.ToLocalChecked()->InstantiateModule(context,
            callResolve);
        if (result.IsNothing()) {
            v8::TryCatch try_catch(context->GetIsolate());
            auto state = maybeModule.ToLocalChecked()->GetStatus();
            v8::String::Utf8Value v8_error_string(context->GetIsolate(), try_catch.Exception());
            throw std::exception("Can't instantiate module.");
        }
    }
    v8::MaybeLocal<v8::Module> module_wrap::callResolve(v8::Local<v8::Context> context, 
        v8::Local<v8::String> specifier,
        v8::Local<v8::FixedArray> import_assertions,
        v8::Local<v8::Module> referrer)
    {
        v8::Isolate* isolate = context->GetIsolate(); 
        v8::String::Utf8Value str_v8_specifier(isolate,
            specifier);

        const std::string str_module_path = v8Helper::toString(str_v8_specifier);
        //std::cout << "Load module: " << str_module_path << std::endl;
        //static WF::JS::PATH path;
        std::string raw_code;
        if (!fs::readFile(str_module_path, raw_code))
        {
            throw std::exception("can't read file");
            return  v8::MaybeLocal<v8::Module>();
        }
        //static WF::JS::PATH parent_path;
        /*WF::JS::PackageHelper::getRawCode(str_module_name,
            raw_code,
            parent_path);*/
        //load raw_code

        return loadModule(str_module_path,
            raw_code,
            context);
    }
    v8::Local<v8::Value> module_wrap::execModule(v8::Local<v8::Module> module, v8::Local<v8::Context> cx, bool nsObject)
    {
        v8::Local<v8::Value> retValue;
        if (!module->Evaluate(cx).ToLocal(&retValue)) {
            printf("Error evaluating module!\n");
            exit(EXIT_FAILURE);
        }
        return nsObject ? module->GetModuleNamespace() : retValue;
    }
}
