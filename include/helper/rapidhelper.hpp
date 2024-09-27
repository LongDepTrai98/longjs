#ifndef _RAPID_HELPER_HPP_
#define _RAPID_HELPER_HPP_
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <rapidjson/istreamwrapper.h>
#include <string>
namespace longjs
{
	class rapidhelper
	{
	public: 
		static std::string rapid_dump(const rapidjson::Value& value)
		{
			rapidjson::StringBuffer buffer;
			rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
			value.Accept(writer);
			return buffer.GetString();
		}
		static rapidjson::Value rapid_create_string(const std::string& str,
			rapidjson::Document::AllocatorType& allocator)
		{
			return rapidjson::Value(str.c_str(), allocator);
		}
	private: 
		rapidhelper(); 
	};
}
#endif // !_RAPID_HELPER_HPP_
