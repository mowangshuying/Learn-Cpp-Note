#include<iostream>
#include<thread>

class Request
{
public:
	explicit Request(int id) : id_(id) {

	}
	void process()
	{
		std::cout << "Processing request id_ = " << id_ << std::endl;
	}
private:
	int id_;
};

int main(int argc, char** argv)
{
	Request req(1);

	std::thread t(&Request::process, &req);
	t.join();

	return 0;
}