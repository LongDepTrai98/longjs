#pragma once
#ifndef _UUID_HPP_
#define _UUID_HPP_
#include <uuid/uuid_4.h>
#include <string>
class UuidGenerator
{
public:
	UuidGenerator()
	{
	}
	~UuidGenerator() {}
public:
	static std::string CreateUUID();
private:

};
#endif // !_UUID_HPP_


