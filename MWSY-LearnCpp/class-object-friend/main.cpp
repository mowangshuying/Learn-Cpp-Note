#include <iostream>

class  Class1;
void friend_class1Func(Class1& c1);

class Class1
{
	friend void friend_class1Func(Class1& c1);
private:
	void class1_MemFunc1()
	{
		std::cout << "Class1::class1_MemFunc1()" << std::endl;
	}
private:
	int m_mem1 = 0;
};

void friend_class1Func(Class1 &c1)
{
	std::cout << "friend_class1Func c1.m_mem1:" << c1.m_mem1<<std::endl;
}


int main(int argc, char** argv)
{
	Class1 c1;

	friend_class1Func(c1);
	return 0;
}