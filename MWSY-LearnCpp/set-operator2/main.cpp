/**
* std::set_intersection�����ϵĽ���
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main()
{
	std::vector<int> v1{ 1,2,3,4,5,6,7,8 };
	std::vector<int> v2{ 5,  7,  9,10 };

	// ʹ��std::set_intersection��Ҫ��v1��v2����֤������Ԫ���ǰ���˳�����е�
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