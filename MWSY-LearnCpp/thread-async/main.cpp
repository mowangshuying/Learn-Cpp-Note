#include <iostream>
#include <thread>
#include <future> // async

using namespace std;

int calculate()
{
	return 123;
}

int main(int argc, char** argv)
{
	// 启动一个线程运行并后去结果
	std::future<int> tmpFuture(async(calculate));
	std::cout << tmpFuture.get() << std::endl;
	return 0;
}