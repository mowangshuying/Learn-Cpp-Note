#include <iostream>
#include <thread>

class Counter
{
public:
	Counter(int id, int numIters) : id_(id),numIters_(numIters)
	{

	}

	void operator()() const
	{
		for (int i = 0; i < numIters_; i++)
		{
			std::cout << " Counter " << id_ << " has value " << i << std::endl;
		}
	}
private:
	int id_;
	int numIters_;
};

int main(int argc, char** argv)
{
	std::thread t1(Counter(1,6));
	std::thread t2(Counter(2, 4));

	t1.join();
	t2.join();

	return 0;
}