#include <iostream>
#include <regex>

int main(int argc, char** argv)
{
	std::regex r{"\\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[0-9]|[1-2][0-9]|3[0-1])"};
	while (true)
	{
		std::cout << "Enter a date (year/month/day) (q=quit):";
		std::string str;
		if (!std::getline(std::cin, str) || str == "q")
		{
			break;
		}

		if (!std::regex_match(str, r))
		{
			std::cout << "invalid date." << std::endl;
		}

		std::cout << "valid date." << std::endl;
	}
	return 0;
}