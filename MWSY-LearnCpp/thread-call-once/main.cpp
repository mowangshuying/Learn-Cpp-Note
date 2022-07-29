#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
/**
 * std::call_once����ͷ�ļ� <mutex> 
 * std::call_once��std::once_flag��ȷ����������ĳ������������һ�Ρ�
*/

std::once_flag g_onceFlag;

void init()
{
	std::cout << "init()..." << std::endl;
}

void processing()
{
	std::call_once(g_onceFlag,&init);
	std::cout << "Processing..." << std::endl;
}

int main(int arv, char** argv)
{
	std::vector<std::thread> threadVct(3);

	for (auto& t : threadVct)
	{
		t = std::thread(&processing);
	}

	//join all threads
	for (auto& t : threadVct)
	{
		t.join();
	}

	return 0;
}