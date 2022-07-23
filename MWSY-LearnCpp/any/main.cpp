#include <any>//cpp17
#include <iostream>

int main(int argc, char** argv)
{
	std::any any1;
	std::any any2{ 3 };
	std::any any3{ "An std::string." };

	std::cout << "any1.has_value():" << any1.has_value() << std::endl;
	std::cout << "any2.has_value():" << any2.has_value() << std::endl;

	std::cout << "any1.type:" << any1.type().name() << std::endl;
	std::cout << "any2.type:" << any2.type().name() << std::endl;

	try 
	{
		int test = std::any_cast<int>(any3);
		std::cout << test << std::endl;
	}
	catch (const std::bad_any_cast& ex)
	{
		std::cout << "Exception:" << ex.what() << std::endl;
	}

	return 0;
}