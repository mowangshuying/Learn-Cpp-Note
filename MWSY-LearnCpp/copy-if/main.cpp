#include <iostream>
#include <vector>
#include <algorithm> 
int main(int argc, char** argv)
{
	std::vector<int> vct1{ 0,1,2,3,4,5 };
	std::vector<int> vct2;

	vct2.resize(std::size(vct1));

	std::copy_if(std::begin(vct1), std::end(vct1), std::begin(vct2), [](int i) {
		return i % 2 == 0;
		});

	std::for_each(std::begin(vct2), std::end(vct2), [](int i) {
		std::cout << i << " ";
		});
	std::cout << std::endl;

	return 0;
}