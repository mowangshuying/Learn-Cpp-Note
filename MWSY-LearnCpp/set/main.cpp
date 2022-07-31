/**
 * c++�м���
 * �ǲ��ظ��Ķ��Ԫ��
*/

#include<iostream>
#include<set>//���򼯺�

int main(int argc, char** argv)
{
	//����һ������
	std::set<std::string> strSet;
	
	// ����3��Ԫ��A,B,C
	strSet.insert("B");
	strSet.insert("A");
	strSet.insert("C");

	// ����һ���ظ���Ԫ��A
	strSet.insert("A");

	//strSet.size() = 3
	std::cout << "strSet.size() = "<< strSet.size() << std::endl;

	

	// set��һ�����򼯺ϣ���Ȼ�ȷ���B,Ȼ��A,Ȼ��C��
	// ��������ĵ�ʱ���ǰ���˳�������A,B,C
	
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