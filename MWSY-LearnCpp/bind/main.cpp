#include <iostream>
#include <functional>

void printfStr(std::string str1, std::string str2)
{
	std::cout << "str1=" << str1 << ",str2=" << str2 << std::endl;
}

int main(int argc, char** argv)
{
	printfStr("hello", "world");

	// 第一个参数被绑定为hello,第二个参数为占位符号
	std::function<void(std::string)> bindfunc1 = std::bind(printfStr, "hello", std::placeholders::_1);
	bindfunc1("world");

	//第一个参数为占位符号，第二个参数为world
	std::function<void(std::string)> bindfunc2 = std::bind(printfStr, std::placeholders::_1, "world");
	bindfunc2("hello");

	return 0;
}