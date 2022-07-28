#include <iostream>
#include <thread>

int n1 = 1;
thread_local int n2 = 2;//������ȫ�ֵ��̱߳�����ÿ���̶߳�������������ĸ���

void func1()
{
	n2++;
	std::cout << "func1 n2 = " << n2 << std::endl;
}

void func2()
{
	n2++;
	std::cout << "func2 n2 = " << n2 << std::endl;
}

int main(int argc, char** argv)
{
	std::thread t1(func1);
	std::thread t2(func2);

	t1.join();
	t2.join();

	std::cout << "main() n2 = " << n2 << std::endl;

	return 0;
}