#include <iostream>
#include <future>//std::future

void doWork(std::promise<int> theProm)
{
	theProm.set_value(1);
}

int main(int argc, char** argv)
{
	std::promise<int> prom;
	auto futu = prom.get_future();

	std::thread th(&doWork, std::move(prom));

	//
	int result = futu.get();
	std::cout << "result = " << result << std::endl;

	th.join();

	return 0;
}