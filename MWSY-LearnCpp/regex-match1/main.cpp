#include <iostream>
#include <regex>

int main(int argc, char** argv)
{
	std::regex r{ "(\\d{4})/(0?[1-9]|1[0-2])/(0?[0-9]|[1-2][0-9]|3[0-1])" };
	while (true)
	{
		std::cout << "Enter a date (year/month/day) (q=quit):";
		std::string str;
		if (!std::getline(std::cin, str) || str == "q")
		{
			break;
		}

		std::smatch tmpMatch;
		if (!std::regex_match(str,tmpMatch, r))
		{
			std::cout << "invalid date." << std::endl;
		}
		std::cout << "tmpMach[0]=" << tmpMatch[0] << std::endl; // 2022/07/23
		std::cout << "tmpMach[1]=" << tmpMatch[1] << std::endl; // 2022
		std::cout << "tmpMach[2]=" << tmpMatch[2] << std::endl; // 07
		std::cout << "tmpMach[3]=" << tmpMatch[3] << std::endl; // 23
	}
	return 0;
}