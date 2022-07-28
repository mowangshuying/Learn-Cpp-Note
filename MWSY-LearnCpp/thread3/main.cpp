#include <iostream>
#include <thread>


int main(int argc, char** argv)
{
	int id = 1;
	int numIters = 5;

	std::thread t1([id, numIters]() 
		{
			for (int i = 0; i < numIters; i++)
			{
				std::cout << " Counter " << id << " has value " << i << std::endl;
			}
		});

	t1.join();

	return 0;
}