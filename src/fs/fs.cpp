#include <fs/fs.hpp>
#include <fstream>
namespace longjs
{
	bool fs::readFile(const PATH& path, std::string& content)
	{
		std::ifstream file;
		file.open(path, std::ifstream::ate);
		char* contents;
		if (!file) {
			contents = new char[1];
			content = std::string(contents);
			delete[]contents; 
			return false;
		}
		size_t file_size = file.tellg();
		file.seekg(0);
		std::filebuf* file_buf = file.rdbuf();
		contents = new char[file_size + 1]();
		file_buf->sgetn(contents, file_size);
		file.close();
		content = std::string(contents);
		delete []contents; 
		return true;
	}
}
