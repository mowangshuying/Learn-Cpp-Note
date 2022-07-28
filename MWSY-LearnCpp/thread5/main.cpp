#include <iostream>
#include <thread>

class SimpleObject
{
public:
	SimpleObject() = default;
	
	void loop()
	{
		std::cout << "this is loop" << std::endl;
	}

	void run()
	{
		// t_ = std::thread(&SimpleObject::loop ); 缺少this指针，无法进行调用
		t_ = std::thread(&SimpleObject::loop,this);
	}

	void join()
	{
		t_.join();
	}

private:
	std::thread t_;
	int id_ = 1;
};

int main(int argc, char** argv)
{
	SimpleObject so;
	so.run();
	so.join();
	return 0;
}