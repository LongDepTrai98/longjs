#include <engine/jsobject.hpp>
#include <uuid/UuidGenerator.h>
namespace longjs
{
	jsobject::jsobject()
	{
		uuid = UuidGenerator::CreateUUID(); 
	}
	const std::string jsobject::getUUid()
	{
		return uuid; 
	}
}
