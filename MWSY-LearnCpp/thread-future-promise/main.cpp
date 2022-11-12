#include <iostream>
#include <future>//std::future

void doWork(std::promise<int> theProm)
{
	theProm.set_value(1);
}

int main(int argc, char** argv)
{
	// 1.主线程中创建promise
	std::promise<int> tmpPromise;
	// 2.获取future以便后续获取到 tmpThread计算的结果值
	std::future<int> tmpFuture = tmpPromise.get_future();

	// 3.将prom移动到其他线程中，无法复制tmpPromise只能移动它
	std::thread tmpThread(&doWork, std::move(tmpPromise));

	// 4.获取到线程计算结果
	int result = tmpFuture.get();
	std::cout << "result = " << result << std::endl;

	tmpThread.join();
	std::cout << "main thread end." << std::endl;


	//std::string str = std::move(str2);
	//c_str

	return 0;
}