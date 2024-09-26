#ifndef _MODULE_HPP_
#define _MODULE_HPP_
#include <v8-value.h>
#include <v8-isolate.h>
#include <v8-context.h>
#include <v8-primitive.h>
#include <string>
namespace longjs
{
	class module_wrap
	{
	public: 
		static v8::Local<v8::Value> Evaluate(const std::string& module_name,
			const std::string& raw_code, 
			v8::Isolate* isolate);
	protected: 
		static v8::MaybeLocal<v8::Module> loadModule(const std::string& module_name,
			const std::string& raw_code,
			v8::Local<v8::Context> cx);

		static void Instantiate(const std::string& module_name,
			v8::MaybeLocal<v8::Module> maybeModule,
			v8::Local<v8::Context> context);

		static v8::MaybeLocal<v8::Module> callResolve(v8::Local<v8::Context> context,
			v8::Local<v8::String> specifier,
			v8::Local<v8::FixedArray> import_assertions, 
			v8::Local<v8::Module> referrer);

		static v8::Local<v8::Value> execModule(v8::Local<v8::Module> module,
			v8::Local<v8::Context> cx,
			bool nsObject = false);
	};
}
#endif // !_MODULE_HPP_
