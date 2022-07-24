/**
 * mowangshuying
 * 2022/7/24
 * @brief: 集合操作:判断集合的包含关系(cpp17/cpp20)
 * @detail:使用std::includes判断两个集合之间的关系，需要引入头文件
 * algorithm(算法库)
*/

#include < algorithm >
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	std::vector<int> vct1{ 1,2,3,4,5 };
	std::vector<int> vct2{ 10,20,3,4,5 };
	std::vector<int> vct3{ 1,2,3 };


	//未排序直接使用std::includes会导致中断
	///*if (std::includes(std::cbegin(vct1), std::cend(vct1), std::cbegin(vct2), std::cend(vct2)))
	//{
	//	std::cout << "the vct2 is sub of vct1";
	//}*/

	//if (std::includes(std::cbegin(vct2), std::cend(vct2), std::cbegin(vct1), std::cend(vct1)))
	//{
	//	std::cout << "the vct1 is sub of vct2";
	//}

	// std::includes需要vector需要是有序的
	std::sort(vct1.begin(), vct1.end());
	std::sort(vct2.begin(), vct2.end());
	std::sort(vct3.begin(), vct3.end());

	///////////////////////////vct1和vct2的包含关系/////////////////////////////////////////////
	std::cout << "************************分割线*******************************" << std::endl;
	// vct1不包含vct2
	if (std::includes(std::cbegin(vct1), std::cend(vct1), std::cbegin(vct2), std::cend(vct2)))
	{
		std::cout << "the vct2 is sub of vct1\n";
	}
	// vct2不包含vct1
	if (std::includes(std::cbegin(vct2), std::cend(vct2), std::cbegin(vct1), std::cend(vct1)))
	{
		std::cout << "the vct1 is sub of vct2\n";
	}


	/////////////////////////vct1和vct3的包含关系//////////////////////////////////////////////////
	std::cout << "************************分割线*******************************" << std::endl;
	// vct1包含vct3
	if (std::includes(std::cbegin(vct1), std::cend(vct1), std::cbegin(vct3), std::cend(vct3)))
	{
		std::cout << "the vct3 is sub of vct1\n";
	}
	// vct3不包含vct1
	if (std::includes(std::cbegin(vct3), std::cend(vct3), std::cbegin(vct1), std::cend(vct1)))
	{
		std::cout << "the vct1 is sub of vct3\n";
	}

	///////////////////////观察如下情况//////////////////////////////////////////////////////////
	//vct1 = { 1,2,3,4,5 }
	//vct3 = { 1,2,3}
	//向vct3放入4,3,放入之后由于不是顺序排列需要对vct3进行排序后再调用std::includes

	std::cout << "************************分割线*******************************" << std::endl;
	vct3.push_back(4);
	vct3.push_back(3);

	std::sort(vct3.begin(), vct3.end());
	// vct1包含vct3
	if (std::includes(std::cbegin(vct1), std::cend(vct1), std::cbegin(vct3), std::cend(vct3)))
	{
		std::cout << "the vct3 is sub of vct1";
	}
	// vct3不包含vct1
	if (std::includes(std::cbegin(vct3), std::cend(vct3), std::cbegin(vct1), std::cend(vct1)))
	{
		std::cout << "the vct1 is sub of vct3";
	}


	

	return 0;
}