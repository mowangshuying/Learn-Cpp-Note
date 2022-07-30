#include <mutex>
#include <iostream>
#include <thread>

std::mutex g_mutex;
int g_count = 0;
void Func()
{
	for (int i = 0; i < 10000; i++)
	{
		g_mutex.lock();
		g_count++;
		g_mutex.unlock();
	}
}

int main(int argc, char** argv)
{
	std::thread t1(Func);
	std::thread t2(Func);

	t1.join();
	t2.join();

	if (g_count == 20000)
	{
		std::cout << "g_count == 20000" << std::endl;
	}
	else
	{
		std::cout << "g_count != 20000" << std::endl;
	}

	return 0;
}