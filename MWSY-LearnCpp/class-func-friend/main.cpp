#include <iostream>

class  Class1;
class  Class2;

// 注意是有位置关系的
//class Class1
//{
//public:
//	friend void Class2::printClass1Mem1(Class1& c1);
//private:
//	void class1_memFunc1()
//	{
//		std::cout << "Class2::class2_MemFunc1()" << std::endl;
//	}
//private:
//	int m_mem1 = 0;
//};

class Class2
{
private:
	void class2_memFunc1()
	{
		std::cout << "Class3::class2_MemFunc1()" << std::endl;
	}
public:
	void printClass1Mem1(Class1& c1);
private:
	int m_mem1 = 0;
};


// 注意是有位置关系的
class Class1
{
public:
	friend void Class2::printClass1Mem1(Class1& c1);
private:
	void class1_memFunc1()
	{
		std::cout << "Class2::class2_MemFunc1()" << std::endl;
	}
private:
	int m_mem1 = 0;
};

void Class2::printClass1Mem1(Class1& c1)
{
	std::cout << "Class3::printClass2Mem1()::m_mem1:" << c1.m_mem1 << std::endl;
}

int main(int argc, char** argv)
{
	Class1 c1;
	Class2 c2;

	c2.printClass1Mem1(c1);
	return 0;
}