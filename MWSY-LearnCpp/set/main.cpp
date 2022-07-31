/**
 * c++中集合
 * 是不重复的多个元素
*/

#include<iostream>
#include<set>//有序集合

int main(int argc, char** argv)
{
	//创建一个集合
	std::set<std::string> strSet;
	
	// 插入3个元素A,B,C
	strSet.insert("B");
	strSet.insert("A");
	strSet.insert("C");

	// 插入一个重复的元素A
	strSet.insert("A");

	//strSet.size() = 3
	std::cout << "strSet.size() = "<< strSet.size() << std::endl;

	

	// set是一个有序集合，虽然先放入B,然后A,然后C，
	// 但是输出的的时候还是按照顺序输出的A,B,C
	
	// strSet:
	// setSet.Elem = A
	// setSet.Elem = B
	// setSet.Elem = C
	std::cout << "strSet:" << std::endl;
	for (auto& str : strSet)
	{
		std::cout << "setSet.Elem = " << str << std::endl;
	}

	return 0;
}