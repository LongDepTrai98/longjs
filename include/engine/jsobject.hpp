#ifndef _JS_OBJECT_HPP_
#define _JS_OBJECT_HPP_
#include <string>
namespace longjs
{
	//interface of jsobject
	class jsobject
	{
	public: 
		jsobject(); 
		const std::string getUUid();
		template<class T> 
		T* as(); 
	protected: 
		std::string uuid; 
	};
	template<class T>
	inline T* jsobject::as()
	{
		return static_cast<T*>(this);
	}
}
#endif // !_JS_OBJECT_HPP_
