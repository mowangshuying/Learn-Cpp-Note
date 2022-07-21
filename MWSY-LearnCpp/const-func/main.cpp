#include <iostream>

class SimpleObject
{
public:
	SimpleObject() = default;
	SimpleObject(const int& mem1, const int& mem2) : mem1_(mem1), mem2_(mem2)
	{

	}

	int getMem1()
	{
		return mem1_;
	}

	int getMem1() const
	{
		return mem1_;
	}
private:
	int mem1_;
	int mem2_;
};

int main(int argc, char** argv)
{
	const SimpleObject obj1{ 1,1 };
	std::cout << "obj1.mem1_:" << obj1.getMem1() << std::endl;

	SimpleObject obj2{ 2,2 };
	std::cout << "obj2.mem1_:" << obj2.getMem1() << std::endl;

	return 0;
}