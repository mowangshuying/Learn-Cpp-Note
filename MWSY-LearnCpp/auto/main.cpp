#include <iostream>
#include <vector>

/*
 * auto i = 42;
 *
 * double f();
 * auto d = f();
 * 
 * std::vector<string> v;
 * auto pos = v.begin();
 * 
 * lamda表达式：匿名函数
 * auto l = [](int x) -> bool {
 *		...
 * }
 * 
*/
int main(int argc, char** argv)
{
	auto i = 42;
	std::cout << i << std::endl;

	std::vector<std::string> vct;
	auto beg = vct.begin();

	return 0;
}