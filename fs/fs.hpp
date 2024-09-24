#pragma once
#ifndef _FS_HPP_
#define _FS_HPP_
#include <filesystem>
namespace longjs
{
	using PATH = std::filesystem::path;
	class fs
	{
	public: 
		static bool readFile(const PATH& path,
			std::string& content); 
	private:
		fs();
	};
}
#endif // !_FS_HPP_

