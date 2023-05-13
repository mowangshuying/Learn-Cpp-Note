#include <iostream>

int main(int argc, char** argv)
{
	int num = 0;
	while (std::cin >> num)
	{
		std::cout << "num=" << num << std::endl;
	}
	return 0;
}