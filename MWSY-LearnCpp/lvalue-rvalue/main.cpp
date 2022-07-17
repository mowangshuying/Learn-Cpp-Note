#include <iostream>
/**
* 左值：永久对象，可以被取地址，可以出现在等号的左侧
* 典型的左值：有名称的变量，函数形参，栈中对象等
* 
* 右值：临时对象，即将销毁，只能出现在等号的右侧（标准库中有例外，如string,complex等）
* 典型的右值：字面常量，匿名对象（临时对象)以及函数的返回值等。另外也可以通过std::move显式将一个左值转化为右值
* 
* 一个表达式的值要么是左值要么是右值
*/
int main(int argc, char** argv)
{
	//int& a1 = 2;

	int a1 = 0;
	const int&& a2 = std::move(a1);


	return 0;
}