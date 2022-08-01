#include <memory>
#include <iostream>

int* myAlloc(int value)
{
	return new int(value);
}

void myFree(int* value)
{
	delete value;
}

int main(int argc, char** argv)
{
	std::unique_ptr<int> intPtr1 = std::make_unique<int>(1);
	std::cout << "(*intPtr1) = " << *intPtr1 << std::endl;

	intPtr1.reset();//释放资源并设置为空指针
	intPtr1.reset(new int(2));//释放资源并设置为新的指针
	std::cout << "(*intPtr1) = " << *intPtr1 << std::endl;


	std::unique_ptr<int[]> intArrPtr1 = std::make_unique<int[]>(10);
	intArrPtr1[0] = 0;
	intArrPtr1[1] = 1;
	std::cout << "intArrPtr1[1] = " << intArrPtr1[1] << std::endl;

	//自定义deleter和newer
	std::unique_ptr<int, decltype(&myFree)> intPtr2 (myAlloc(42),myFree);

	return  0;
}