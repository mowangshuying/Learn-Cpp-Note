#include<iostream>

int main(int argc, char** argv)
{
	int* pInt = new int;
	if (pInt == nullptr)
	{
		std::cout << "pInt == nullptr" << std::endl;
		return 0;
	}
	delete pInt;
	pInt = nullptr;
	
	int* pIntArray = { new int[5] };
	if (pIntArray == nullptr)
	{
		std::cout << "pIntArray == nullptr" << std::endl;
		return 0;
	}

	delete[] pIntArray;
	pIntArray = nullptr;

	return 0;
}