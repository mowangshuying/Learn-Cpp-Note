#include <iostream>

// 数量不定的模板参数
void print()
{
	std::cout<<std::endl;
	std::cout<<"func:" << __FUNCTION__ << " line:" << __LINE__ << std::endl;
}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
	// std::cout << "args count:" << sizeof...(args) << std::endl;
	std::cout << "func:" << __FUNCTION__ << " line:" << __LINE__ << std::endl;
	std::cout << firstArg;
	print(args...);
}

template <typename... Types>
void print(const Types&... args)
{
	std::cout << "func:" << __FUNCTION__ << " line:" << __LINE__ << std::endl;
}

int main(int argc, char** argv)
{
	print("hello", " ", "world", "!");
	return 0;
}