#include <iostream>

template<typename T>
class SimpleWrapper
{
public:
	SimpleWrapper(const T& t) :object_(t)
	{

	}

	T getObject()
	{
		return object_;
	}
private:
	T object_;
};

int main(int argc, char** argv)
{
	SimpleWrapper<int> iw{ 1 };
	std::cout << "iw::getObject():" << iw.getObject() << std::endl;

	SimpleWrapper<std::string> strw{ "hello,world!" };
	std::cout << "iw::getObject():" << strw.getObject() << std::endl;
	return 0;
}