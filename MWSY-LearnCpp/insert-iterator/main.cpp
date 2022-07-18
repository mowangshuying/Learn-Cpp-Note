#include <iostream>
#include <vector>
#include <set>
int main(int argc, char** argv)
{
	std::vector<int> values1{ 1,2,3,4,5 };
	
	std::vector<int> values2;
	std::back_insert_iterator<std::vector<int>> iter1{ values2 };
	std::copy(std::cbegin(values1),std::cend(values1),iter1);
	std::copy(std::cbegin(values2), std::cend(values2), std::ostream_iterator<int>{std::cout, " "});
	std::cout<<std::endl;

	std::set<int> values3;
	std::insert_iterator<std::set<int>> iter2{ values3,std::begin(values3) };
	std::copy(std::cbegin(values1), std::cend(values1), iter2);
	std::copy(std::cbegin(values3), std::cend(values3), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	return 0;
}