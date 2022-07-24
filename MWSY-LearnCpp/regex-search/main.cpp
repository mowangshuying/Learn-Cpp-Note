#include <iostream>
#include <regex>
#include <string>

int main(int argc, char** argv)
{
	std::regex r{ "//\\s*(.+)$" };
	
	while (true)
	{
		std::cout << " Enter a string with optional code comments (q=quit): ";
		std::string str;
		if (!std::getline(std::cin, str) || str == "q")
		{
			break;
		}

		std::smatch tmpMatch;
		if (!std::regex_search(str, tmpMatch, r))
		{
			std::cout << " No comment found!" << std::endl;
			return 0;
		}

		std::cout << " tmpMatch[0]=" << tmpMatch[0] << std::endl;
		std::cout << " tmpMatch[1]=" << tmpMatch[1] << std::endl;
		std::cout << " tmpMatch.prefix():" << tmpMatch.prefix() << std::endl;
		std::cout << " tmpMatch.suffix():" << tmpMatch.suffix() << std::endl;
	}

	return 0;
}