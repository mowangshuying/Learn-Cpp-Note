#include <iostream>

class FuncObject
{
public:
	void operator()() 
	{
		std::cout << "operator()" << std::endl;
	}
};

int main(int argc, char** argv)
{
	FuncObject func;
	func();
	return 0;
}