#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char** argv)
{
	std::vector<int> vct{ 1,2,3,4 };
	// begin end 0 ʹ��Ĭ�ϵļӷ�
 	int sum = std::accumulate(std::begin(vct),std::end(vct),0);
	std::cout << "sum=" << sum << std::endl;

	// ����˻�
	int mul = std::accumulate(std::begin(vct), std::end(vct),1,[](int value1, int value2)
		{
			return value1 * value2;
		});
	std::cout << "mul:" << std::endl;


	return 0;
}