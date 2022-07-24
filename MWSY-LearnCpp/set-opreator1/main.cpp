/**
 * set::set_union���ϵĲ�. 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	{
		std::vector<int> v1 = { 1, 2, 3, 4, 5 };
		std::vector<int> v2 = { 3, 4, 5, 6, 7 };
		std::vector<int> dest1;

		std::set_union(v1.begin(), v1.end(),
			v2.begin(), v2.end(),
			std::back_inserter(dest1));

		for (const auto& i : dest1) {
			std::cout << i << ' ';
		}
		std::cout << '\n'; //������ 1 2 3 4 5 6 7
	}

	//���Ԫ�ض��ᱻǶ��
	{
		std::vector<int> v1 = { 1, 2, 3, 4, 5, 5, 5 };
		std::vector<int> v2 = { 3, 4, 5, 6, 7 };
		std::vector<int> dest1;

		std::set_union(v1.begin(), v1.end(),
			v2.begin(), v2.end(),
			std::back_inserter(dest1));

		for (const auto& i : dest1) {
			std::cout << i << ' ';
		}
		std::cout << '\n'; // ������ 1 2 3 4 5 5 5 6 7
	}

	{
		std::vector<int> v1 = { 1, 2, 4, 3, 5, 5, 5 };
		std::vector<int> v2 = { 3, 4, 5, 6, 7 };
		std::vector<int> dest1;

		//v1��v2������˳��ĵĻ�������ֱ�ӵ���set::union�����򴥷��жϻ���
		std::sort(v1.begin(), v1.end());

		std::set_union(v1.begin(), v1.end(),
			v2.begin(), v2.end(),
			std::back_inserter(dest1));

		for (const auto& i : dest1) {
			std::cout << i << ' ';
		}
		std::cout << '\n'; // ������ 1 2 3 4 5 5 5 6 7
	}
}