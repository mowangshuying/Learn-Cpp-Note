#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> g_count = 0;

void func()
{
	for (int i = 0; i < 10000; i++)
	{
		g_count++;
	}
}

int main(int argc, char** argv)
{
	std::thread t1(func);
	std::thread t2(func);

	t1.join();
	t2.join();

	std::cout << "g_count = " << g_count << std::endl;

	return 0;
}