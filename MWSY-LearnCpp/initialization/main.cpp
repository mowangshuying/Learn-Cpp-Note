#include <iostream>
#include <vector>

#include <initializer_list>

void print(std::initializer_list<int> vals)
{
	for (auto p = vals.begin(); p != vals.end(); ++p)
	{
		std::cout << *p << std::endl;
	}
}

class Simple
{
public:
	Simple(int a, int b)
	{
		std::cout << "Simple(int a, int b),a=" << a << " b=" << b << std::endl;
	}

	//Simple(std::initializer_list<int> initlist) 
	//{
	//	std::cout << "Simple(std::initializer_list<int> initlist), values=";
	//	for (auto i : initlist) {
	//		std::cout << i << " ";
	//	}
	//	std::cout<<std::endl;
	//}
};

int main(int argc, char** argv)
{
	int values[]{ 1,2,3 };
	std::vector<int> vct{ 1,2,3 };
	std::vector<std::string> cities{"shanghai", "beijing", "shengzhen"};

	int i;
	int j{};  // j 被初始化为0
	int* p;
	int* q{}; // q 被初始化为nullptr


	int x1(5.3);
	int x2 = 5.3;

	//int x3{ 5.0 }; //error
	//int x4 = { 5.3 };//error

	char c1{ 7 };
	//char c2{ 9999 };//error

	std::vector<int> v1{ 1,2,3,4,5 };
	//std::vector<int> v2{ 1,2.3,4,5.6 };

	//参数个数不定 ，类型需要一样
	print({ 1, 2, 3, 4, 5 });

	Simple s1(77, 5);		// Simple(int a, int b),a=77 b=5
	Simple s2{ 77, 5 };		// Simple(std::initializer_list<int> initlist), values=77 5
	//Simple s3{ 77, 5, 42 }; // Simple(std::initializer_list<int> initlist), values=77 5 42
	Simple s4 = { 77, 5 };	// Simple(std::initializer_list<int> initlist), values=77 5

	return 0;
}