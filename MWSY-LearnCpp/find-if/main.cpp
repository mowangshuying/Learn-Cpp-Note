#include <iostream>
#include <vector>

bool isBigNum(const int& num)
{
	return num > 100;
}

int main(int argc, char** argv)
{
	std::vector<int> vec{ 1,2,3,4,5,100,200,300,400,500 };

	/////////////////////////// 使用函数作为参数 ////////////////////////////
	auto itf1 = std::find_if(std::begin(vec),std::end(vec),isBigNum);
	if (itf1 == std::end(vec))
	{
		std::cout << "Not find itf1." << std::endl;
		return 0;
	}
	std::cout << "Find itf1 (*itf1) = "<< (*itf1) << std::endl;
	
	/////////////////////////// 使用lamda表达式 ////////////////////////////
	auto itf2 = std::find_if(std::begin(vec), std::end(vec), [](int num) {
		return num < 100;
		});

	if (itf2 == std::end(vec))
	{
		std::cout << "Not find itf2." << std::endl;
		return 0;
	}
	std::cout << "Find itf2 (*itf2) = " << (*itf2) << std::endl;
	
	return 0;
}