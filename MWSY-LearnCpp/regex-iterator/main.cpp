#include <iostream>
#include <regex>

int main(int argc, char** argv)
{
	std::regex reg{ "[\\w]+" };
	while (true)
	{
		std::cout << "Enter a string to split (q=quit):";
		std::string str;
		if (!std::getline(std::cin, str) || str == "q")
		{
			break;
		}

		const std::sregex_iterator end;
		for (std::sregex_iterator iter{ std::cbegin(str),std::cend(str),reg }; iter != end; ++iter)
		{
			//std::cout << "str:" << str << std::endl;
			std::cout << "(*iter)[0].str()=" << (*iter)[0].str() << std::endl;
		}

	}
	return 0;
}