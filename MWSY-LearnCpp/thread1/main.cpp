#include<iostream>
#include<thread>

void counter(int id, int numIters)
{
	for (int i = 0; i < numIters; i++)
	{
		std::cout << " Counter " << id << " has value " << i << std::endl;
	}
}

int main(int argc, char** argv)
{
	std::thread t1(counter, 1, 6);
	std::thread t2(counter, 1, 4);

	t1.join();
	t2.join();

	return 0;
}