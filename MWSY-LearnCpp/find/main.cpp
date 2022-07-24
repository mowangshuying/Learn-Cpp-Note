#include <iostream>
#include <vector>
int main(int argc, char** argv)
{
	std::vector<int> vec{ 1,2,3,4,5 };
	auto itf = std::find(std::begin(vec), std::end(vec), 3);
	if (itf == std::end(vec))
	{
		std::cout << "Not find." << std::endl;
		return 0;
	}
	std::cout << "Find." << std::endl;
	return 0;
}