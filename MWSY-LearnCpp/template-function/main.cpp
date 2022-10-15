#include<iostream>

inline const int max(const int& a, const int& b)
{
	std::cout << __FUNCTION__ << __LINE__ << std::endl;
	return a < b ? b : a;
}

/**
 * 模板参数 T称为模板参数
 * 呼叫参数 a和b是呼叫参数
*/
template <typename T>
inline const T max(const T& a, const T& b)
{
	std::cout << __FUNCTION__ << __LINE__ << std::endl;
	return a < b ? b : a;
}

template <typename T1,typename T2>
inline const T1 max(const T1& a, const T2& b)
{
	std::cout << __FUNCTION__ << __LINE__ << std::endl;
	//return a < b ? b : a;

	T1 max = 0;

	if (a < b) 
	{
		max = static_cast<T1>(b);
	}
	else
	{
		max = a;
	}

	return max;
}

int main(int argc, char** argv)
{
	max(1, 2);

	max(1.0, 1.0);

	max(2, 1.0);

	return 0;
}