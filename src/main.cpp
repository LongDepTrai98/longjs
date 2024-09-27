#include <iostream>
#include <fs/fs.hpp>
#include <engine/app.hpp>
using namespace longjs; 
int main()
{
	app main_app; 
	std::string path = "test.js"; 
	if (!main_app.initialize())
	{
		std::cout << "Can't init platform\n"; 
		return -1; 
	}
	if (!main_app.initializeIsolate())
	{
		std::cout << "Can't init isolate\n"; 
		return -1; 
	}
	main_app.initializeApp(path, 
		js_type::MODULE); 
	main_app.shutdown(); 
	return 0; 
}