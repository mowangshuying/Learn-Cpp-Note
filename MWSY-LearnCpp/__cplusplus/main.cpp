#include <iostream>

#if __cplusplus < 201103L
#error should use C++ 11 implementation
#endif


/*
 * ��Visual Studio�����ô˱�����ѡ��
 * ����Ŀ�ġ� ����ҳ���Ի��� �й���ϸ��Ϣ���������Visual Studio������C ++�������͹������ԡ�
 * ѡ�� �������ԡ� >�� C / C ++�� >�� �����С�����ҳ��
 * ��/Zc:__cplusplus��/Zc:__cplusplus-��ӵ�����ѡ�����
*/

int main(int argc, char** argv)
{
	std::cout << __cplusplus << std::endl;
	return 0;
}