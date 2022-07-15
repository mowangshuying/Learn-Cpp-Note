#include <iostream>


class CommonData
{
public:
	CommonData() = default;
	CommonData(int x, int y) : m_x(x), m_y(y)
	{

	}

	CommonData operator+(const CommonData& data)
	{
		CommonData retData{ m_x + data.m_x,m_y + data.m_y };
		return retData;
	}
public:
	int m_x;
	int m_y;
};

int main(int argc, char** argv)
{
	CommonData data1{ 1,1 };
	CommonData data2{ 2,2 };

	CommonData data3 = data1 + data2;
	std::cout << "data3.m_x:" << data3.m_x << " data.m_y:" << data3.m_x << std::endl;
	return 0;
}