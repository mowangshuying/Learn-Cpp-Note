#include <iostream>
#include <functional>

void func()
{
	std::cout << "func()" << std::endl;
}

int main(int argc, char** argv)
{
	std::function<void()> f(func);
	f();
	return 0;
}