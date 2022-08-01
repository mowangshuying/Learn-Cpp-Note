#include <iostream>
#include <memory>

class SimpleObj
{
public:
	SimpleObj()
	{
		std::cout << "SimpleObj()" << std::endl;
	}

	SimpleObj(const SimpleObj& simpleObj)
	{
		std::cout << "SimpleObj(const SimpleObj& simpleObj)" << std::endl;
	}

	SimpleObj(SimpleObj&& simpleObj) noexcept
	{
		std::cout << "SimpleObj(SimpleObj&& simpleObj)" << std::endl;
		//str_ = std::move(simpleObj.str_);
	}

	~SimpleObj()
	{
		std::cout << "~SimpleObj()" << std::endl;
	}

public:
	std::string str_;
};

int main(int argc, char** argv)
{
	std::shared_ptr<SimpleObj> obj1 = std::make_shared<SimpleObj>();
	auto obj2 = obj1;

	std::cout << "obj1.use_count() = " << obj1.use_count() << " obj2.use_count() = " << obj2.use_count()<<std::endl;
	
	obj1.reset();
	obj2.reset();
	
	std::cout << "obj1.use_count() = " << obj1.use_count() << " obj2.use_count() = " << obj2.use_count() << std::endl;

	return 0;
}