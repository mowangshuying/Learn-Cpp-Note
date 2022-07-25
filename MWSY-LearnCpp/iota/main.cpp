#include <iostream>
#include <numeric> //
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	std::vector<int> vct(10);
	std::iota(vct.begin(), vct.end(), 0);//cpp11 numeric
	for (auto i : vct)
	{
		std::cout << i <<",";
	}
	std::cout << std::endl;

	return 0;
}