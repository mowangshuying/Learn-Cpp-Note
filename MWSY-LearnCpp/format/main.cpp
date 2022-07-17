#include <iostream>
#include <string>

// cpp20 �����format
#include <format>

int main(int argc, char** argv)
{
	std::string tmpHelloStr{ "hello" };
	std::string tmpWorldStr{ "world" };

	std::string str = std::format("{},{}",tmpHelloStr,tmpWorldStr);
	std::cout << "str:" << str << std::endl;

	return 0;
}