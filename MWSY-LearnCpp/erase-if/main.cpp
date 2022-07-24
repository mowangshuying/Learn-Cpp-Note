#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm> 
int main(int argc, char** argv)
{
	std::vector<std::string> vct{ "","one","two","three","four" };
	for (auto& str : vct) 
	{
		std::cout << "\"" << str << "\"";
	}
	std::cout << std::endl;


	std::erase_if(vct, [](const std::string str) {
		return str.empty();
		});
	for (auto& str : vct)
	{
		std::cout << "\"" << str << "\"";
	}
	std::cout << std::endl;

	return 0;
}