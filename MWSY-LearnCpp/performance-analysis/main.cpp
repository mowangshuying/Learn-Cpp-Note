
// 如何性能分析?
// vs2019 社区版本
// 调试 -> 性能探查器 -> 选择内存使用情况或者cpu使用率

#include <iostream>

int main(int argc, char** argv)
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << i << std::endl;
	}

	for (int i = 0; i < 100*100; i++)
	{
		std::cout << i << std::endl;
	}

	for (int i = 0; i < 100*100*100; i++)
	{
		std::cout << i << std::endl;
	}

	return 0;
}