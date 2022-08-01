#include <iostream>
#include <memory>

class SimpleObj : public std::enable_shared_from_this<SimpleObj>
{
public:
	std::shared_ptr<SimpleObj> getSharedPtr()
	{
		return shared_from_this();
	}

	std::weak_ptr<SimpleObj> getWeakPtr()
	{
		return weak_from_this();
	}
};

int main(int argc, char** argv)
{
	auto ptr1 = std::make_shared<SimpleObj>();
	auto ptr2 = ptr1->getSharedPtr();
	auto ptr3 = ptr1->getWeakPtr();
	return 0;
}