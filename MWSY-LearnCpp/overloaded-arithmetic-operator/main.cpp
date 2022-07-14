#include <iostream>

/**
 * 重载算数运算符，诸如+,-,*,/
 * 
 * 建议使用全局函数
 * 
 * 函数原型: 
 * T operator(const T&,const T&);
 * T operator(const T&,const E&);
 * 
*/

class CommonData
{
public:
	CommonData() = default;
	CommonData(int x, int y) : m_x(x), m_y(y)
	{

	}
public:
	int m_x;
	int m_y;
};

class OtherData
{
public:
	OtherData() = default;
	OtherData(int x, int y,int z = 0) : m_x(x), m_y(y),m_z(z)
	{

	}
public:
	int m_x;
	int m_y;
	int m_z;
};

// 同类相加
CommonData operator+(const CommonData& data1, const CommonData& data2)
{
	CommonData data;
	data.m_x = data1.m_x + data2.m_x;
	data.m_y = data1.m_y + data2.m_y;
	return data;
}

// 不同类相加
CommonData operator+(const CommonData& data1, const OtherData& data2)
{
	CommonData data;
	data.m_x = data1.m_x + data2.m_x;
	data.m_y = data1.m_y + data2.m_y;
	return data;
}

CommonData operator+(const OtherData& data1, const OtherData& data2)
{
	CommonData data;
	data.m_x = data1.m_x + data2.m_x;
	data.m_y = data1.m_y + data2.m_y;
	return data;
}

// operator+(const CommonData& data1, const OtherData& data2) 
// 无法被重载两次，只是传入类型区分重载
//OtherData operator+(const CommonData& data1, const OtherData& data2)
//{
//	OtherData data;
//	data.m_x = data1.m_x + data2.m_x;
//	data.m_y = data1.m_y + data2.m_y;
//	return data;
//}


int main(int argc, char** argv)
{
	CommonData cData1{ 1,1 };
	CommonData cData2{ 2,2 };

	CommonData cData3 = cData1 + cData2;
	std::cout << "cData3.m_x:" << cData3.m_x << " cData3.m_y:" << cData3.m_y << std::endl;

	OtherData cData4{ 4,4 };
	CommonData cData5 = cData1 + cData4;
	std::cout << "cData5.m_x:" << cData5.m_x << " cData5.m_y:" << cData5.m_y << std::endl;

	return 0;
}