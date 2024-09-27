#include <engine/workspace.hpp>
#include <uuid/UuidGenerator.h>
namespace longjs
{
	workspace::workspace()
	{
	}
	jsobject* workspace::getObjectInWorkspace(const std::string& uuid)
	{
		if (map_objects.count(uuid) == 0) return nullptr; 
		return map_objects.at(uuid).get(); 
	}
	jsobject* workspace::add(std::unique_ptr<jsobject> obj)
	{
		std::string uuid = obj->getUUid(); 
		map_objects.insert({ obj->getUUid(),
			std::move(obj)});
		return map_objects.at(uuid).get(); 
	}
}