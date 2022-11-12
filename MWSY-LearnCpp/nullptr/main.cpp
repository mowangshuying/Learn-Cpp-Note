#include <iostream>

#include <cstddef> // nullptr_t

void func(int arg)
{
	std::cout << "func:" << __FUNCTION__ << " line:" << __LINE__ << std::endl;
}

void func(void* arg)
{
	std::cout << "func:" << __FUNCTION__ << " line:" << __LINE__ << std::endl;
}

int main(int argc, char** argv)
{
	func(0);
	func(NULL);
	func(nullptr);// nullptr是一个关键字
	return 0;
}