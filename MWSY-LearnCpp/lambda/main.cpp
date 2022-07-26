#include <iostream>

int main(int argc, char** argv)
{
	auto lambdaFunc1 = [](){
		std::cout << "this is lambdaFunc1." << std::endl;
	};
	lambdaFunc1();

	auto lambdaFunc2 = []() -> std::string {
		return "this is lambdaFunc2.";
	};
	std::cout << lambdaFunc2() << std::endl;

	auto lambdaFunc3 = [](const std::string& str) {
		std::cout << str << std::endl;
	};
	lambdaFunc3("this is lambdaFunc3.");

	std::string str4 = "this is lambda4 string.";
	auto lambdaFunc4 = [str4]() {
		std::cout << str4 << std::endl;
	};
	lambdaFunc4();

	std::string str5 = "this is lambda5 string";
	auto lambdaFunc5 = [&str5]() {
		str5 = "this is lambda5 reset string";
	};
	lambdaFunc5();
	std::cout << "str5 = "<< str5 << std::endl;

	return 0;
}