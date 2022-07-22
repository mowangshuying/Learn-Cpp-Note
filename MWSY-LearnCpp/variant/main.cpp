#include <iostream>
#include <variant>//��Ҫcpp17��֧��

int main(int argc, char** argv)
{
	std::variant<int, float, std::string> var;
	
	var = 0;
	var = 1.1f;
	var = "An std::string";

	std::cout << "Type index:" << var.index() << std::endl;
	
	// ͨ��holds_alternative�ж��Ƿ����������͵�ֵ
	std::cout << "Contains an int:" << std::holds_alternative<int>(var) << std::endl;
	std::cout << "Contains an float:" << std::holds_alternative<float>(var) << std::endl;
	std::cout << "Contains an str:" << std::holds_alternative<std::string>(var) << std::endl;

	std::cout << std::get<std::string>(var) << std::endl;
	std::cout << std::get<2>(var) << std::endl;

	return 0;
}