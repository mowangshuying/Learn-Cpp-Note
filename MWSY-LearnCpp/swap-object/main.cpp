#include <iostream>

class SimpleObject
{
public:
	SimpleObject() = default;
	SimpleObject(int mem1, int mem2) : mem1_(mem1), mem2_(mem2)
	{

	}
	void swap(SimpleObject& obj)
	{
		//mem1_ = obj.mem1_;
		//mem2_ = obj.mem2_;
		std::swap(mem1_, obj.mem1_);
		std::swap(mem2_, obj.mem2_);
	}
	void printSelf()
	{
		std::cout << "obj.mem1_:" << mem1_ << " obj.mem2_" << mem2_;
	}
private:
	int mem1_;
	int mem2_;
};

int main(int argc, char** argv)
{
	SimpleObject obj1{ 1,1 };
	SimpleObject obj2{ 2,2 };

	obj1.swap(obj2);
	obj1.printSelf();
	obj2.printSelf();
	return 0;
}