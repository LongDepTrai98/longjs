#ifndef _WORK_SPACE_HPP_
#define _WORK_SPACE_HPP_
#include <memory>
#include <unordered_map>
#include <string>
#include <engine/jsobject.hpp>
namespace longjs
{
	class workspace
	{
	public: 
		workspace(); 
		~workspace() = default; 
	public: 
		jsobject* getObjectInWorkspace(const std::string& uuid); 
		jsobject* add(std::unique_ptr<jsobject> obj);
	protected: 
		std::unordered_map<std::string, std::unique_ptr<jsobject>> map_objects; 
	};
}
#endif // !_WORK_SPACE_HPP_
