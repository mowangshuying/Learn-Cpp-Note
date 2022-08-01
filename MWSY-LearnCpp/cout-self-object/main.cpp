#include <iostream>

class SelfObj
{
public:
	int x1 = 1;
	int x2 = 2;
	int x3 = 3;
};

std::ostream& operator<<(std::ostream& o, const SelfObj& obj)
{
	o << "SelfObj.x1=" << obj.x1 << " SelfObj.x2=" << obj.x2 << " SelfObj.x3=" << obj.x3;
	return o;
}


int main(int argc, char** argv)
{
	SelfObj obj;
	std::cout << obj << std::endl;

	return 0;
}