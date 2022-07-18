#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	std::vector<int> vct1{ 1,2,3,4,5 };

	auto beg1 = vct1.begin();
	auto end1 = vct1.end();
	for (; beg1 != end1; beg1++)
	{
		std::cout << *beg1 << " ";
	}
	std::cout<<std::endl;

	auto beg2 = std::begin(vct1);
	auto end2 = std::end(vct1);
	for (; beg2 != end2; beg2++)
	{
		std::cout << *beg2 << " ";
	}
	std::cout << std::endl;
}