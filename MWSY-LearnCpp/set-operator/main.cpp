/**
 * mowangshuying
 * 2022/7/24
 * @brief: ���ϲ���:�жϼ��ϵİ�����ϵ(cpp17/cpp20)
 * @detail:ʹ��std::includes�ж���������֮��Ĺ�ϵ����Ҫ����ͷ�ļ�
 * algorithm(�㷨��)
*/

#include < algorithm >
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	std::vector<int> vct1{ 1,2,3,4,5 };
	std::vector<int> vct2{ 10,20,3,4,5 };
	std::vector<int> vct3{ 1,2,3 };


	//δ����ֱ��ʹ��std::includes�ᵼ���ж�
	///*if (std::includes(std::cbegin(vct1), std::cend(vct1), std::cbegin(vct2), std::cend(vct2)))
	//{
	//	std::cout << "the vct2 is sub of vct1";
	//}*/

	//if (std::includes(std::cbegin(vct2), std::cend(vct2), std::cbegin(vct1), std::cend(vct1)))
	//{
	//	std::cout << "the vct1 is sub of vct2";
	//}

	// std::includes��Ҫvector��Ҫ�������
	std::sort(vct1.begin(), vct1.end());
	std::sort(vct2.begin(), vct2.end());
	std::sort(vct3.begin(), vct3.end());

	///////////////////////////vct1��vct2�İ�����ϵ/////////////////////////////////////////////
	std::cout << "************************�ָ���*******************************" << std::endl;
	// vct1������vct2
	if (std::includes(std::cbegin(vct1), std::cend(vct1), std::cbegin(vct2), std::cend(vct2)))
	{
		std::cout << "the vct2 is sub of vct1\n";
	}
	// vct2������vct1
	if (std::includes(std::cbegin(vct2), std::cend(vct2), std::cbegin(vct1), std::cend(vct1)))
	{
		std::cout << "the vct1 is sub of vct2\n";
	}


	/////////////////////////vct1��vct3�İ�����ϵ//////////////////////////////////////////////////
	std::cout << "************************�ָ���*******************************" << std::endl;
	// vct1����vct3
	if (std::includes(std::cbegin(vct1), std::cend(vct1), std::cbegin(vct3), std::cend(vct3)))
	{
		std::cout << "the vct3 is sub of vct1\n";
	}
	// vct3������vct1
	if (std::includes(std::cbegin(vct3), std::cend(vct3), std::cbegin(vct1), std::cend(vct1)))
	{
		std::cout << "the vct1 is sub of vct3\n";
	}

	///////////////////////�۲��������//////////////////////////////////////////////////////////
	//vct1 = { 1,2,3,4,5 }
	//vct3 = { 1,2,3}
	//��vct3����4,3,����֮�����ڲ���˳��������Ҫ��vct3����������ٵ���std::includes

	std::cout << "************************�ָ���*******************************" << std::endl;
	vct3.push_back(4);
	vct3.push_back(3);

	std::sort(vct3.begin(), vct3.end());
	// vct1����vct3
	if (std::includes(std::cbegin(vct1), std::cend(vct1), std::cbegin(vct3), std::cend(vct3)))
	{
		std::cout << "the vct3 is sub of vct1";
	}
	// vct3������vct1
	if (std::includes(std::cbegin(vct3), std::cend(vct3), std::cbegin(vct1), std::cend(vct1)))
	{
		std::cout << "the vct1 is sub of vct3";
	}


	

	return 0;
}