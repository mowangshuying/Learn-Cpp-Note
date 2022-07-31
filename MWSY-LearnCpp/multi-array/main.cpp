#include <iostream>

int main(int argc, char** argv)
{
	//计算机将二维数组用一维数组表示
	//multiArr[0][0]
	//multiArr[0][1]
	//multiArr[0][2]
	//multiArr[0][3]          //multiArr[0]

	//multiArr[1][0]
	//multiArr[1][1]
	//multiArr[1][2]
	//multiArr[1][3]          //multiArr[1]

	//multiArr[2][0]
	//multiArr[2][1]
	//multiArr[2][2]
	//multiArr[2][3]         //multiArr[2]

	int multiArr[3][4] = { {0,1,2,3},{10,11,22,33},{20,21,22,23} };

	int *multiArr0 = multiArr[0];
	int* multiArr1 = multiArr[1];
	int* multiArr2 = multiArr[2];

	std::cout << "multiArr0[0] = " << multiArr0[0] << std::endl;
	std::cout << "multiArr0[1] = " << multiArr0[1] << std::endl;
	std::cout << "multiArr0[2] = " << multiArr0[2] << std::endl;
	std::cout << "multiArr0[3] = " << multiArr0[3] << std::endl;


	return 0;
}