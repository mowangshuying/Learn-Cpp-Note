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
	std::weak_ptr<SimpleObj> obj2 = obj1;

	obj1.reset();
	if (obj2.lock())
	{
		std::cout << "obj1 still alive." << std::endl;
	}
	else
	{
		std::cout << "obj1 has been freed." << std::endl;
	}

	return 0;
}