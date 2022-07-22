#include <iostream>
#include <stdexcept>

void throwif(bool b)
{
	if (b)
	{
		throw std::runtime_error{ "Here's my exception" };
	}
}

int main(int argc, char** argv)
{
	try
	{
		throwif(false);
		throwif(true);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception:" << e.what() << std::endl;
	}

	return 0;
}