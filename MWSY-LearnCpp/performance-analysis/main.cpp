
// ������ܷ���?
// vs2019 �����汾
// ���� -> ����̽���� -> ѡ���ڴ�ʹ���������cpuʹ����

#include <iostream>

int main(int argc, char** argv)
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << i << std::endl;
	}

	for (int i = 0; i < 100*100; i++)
	{
		std::cout << i << std::endl;
	}

	for (int i = 0; i < 100*100*100; i++)
	{
		std::cout << i << std::endl;
	}

	return 0;
}