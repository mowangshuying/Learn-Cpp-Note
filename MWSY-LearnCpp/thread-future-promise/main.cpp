#include <iostream>
#include <future>//std::future

void doWork(std::promise<int> theProm)
{
	theProm.set_value(1);
}

int main(int argc, char** argv)
{
	// 1.���߳��д���promise
	std::promise<int> tmpPromise;
	// 2.��ȡfuture�Ա������ȡ�� tmpThread����Ľ��ֵ
	std::future<int> tmpFuture = tmpPromise.get_future();

	// 3.��prom�ƶ��������߳��У��޷�����tmpPromiseֻ���ƶ���
	std::thread tmpThread(&doWork, std::move(tmpPromise));

	// 4.��ȡ���̼߳�����
	int result = tmpFuture.get();
	std::cout << "result = " << result << std::endl;

	tmpThread.join();
	std::cout << "main thread end." << std::endl;


	//std::string str = std::move(str2);
	//c_str

	return 0;
}