/**
* std::set_intersection：集合的交集
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main()
{
	std::vector<int> v1{ 1,2,3,4,5,6,7,8 };
	std::vector<int> v2{ 5,  7,  9,10 };

	// 使用std::set_intersection需要对v1和v2排序保证容器内元素是按照顺序排列的
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());

	std::vector<int> v_intersection;
	std::set_intersection(v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		std::back_inserter(v_intersection));
	for (int n : v_intersection)
		std::cout << n << ' ';
	std::cout << std::endl;
}