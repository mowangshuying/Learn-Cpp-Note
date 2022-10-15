#include <iostream>
#include <typeinfo>
#include <string>

template <typename T>
class Type 
{
public:
	static std::string name() 
	{
		std::cout << "Type::name()" << std::endl;
		return typeid(T).name(); 
	}
};

template <>
class Type<char>
{
public:
	static std::string name() 
	{
		std::cout << "Type<char>::name()" << std::endl;
		return "char"; 
	};
};

template <typename T>
std::string type(T t)
{
	std::cout << "type(T t)" << std::endl;
	return Type<T>::name();
}

int main(int argc, char** argv)
{
	std::cout << type('x') << std::endl;
	std::cout << type(true) << std::endl;
	
	int** p = NULL;
	std::cout << type(p) << std::endl;
	return 0;
}