#include <iostream>

template<unsigned long N>
struct binary
{
	static const unsigned value = binary<N / 10>::value * 2 + N % 10;
};

template <>
struct binary<0>
{
	static const unsigned value = 0;
};


int main(int argc, char** argv)
{
	unsigned const one  = binary<1>::value;
	unsigned const tree = binary<11>::value;
	unsigned const five = binary<101>::value;

	std::cout << "one :" << one  << std::endl;
	std::cout << "tree:" << tree << std::endl;
	std::cout << "five:" << five << std::endl;

	return 0;
}