#include<iostream>

inline const int& max(const int& a, const int& b)
{
	return a < b ? b : a;
}

/**
 * 模板参数 T称为模板参数
 * 呼叫参数 a和b是呼叫参数
*/
template <typename T>
inline const T& max(const T& a, const T& b)
{
	return a < b ? b : a;
}

template <typename T1,typename T2>
inline const T1& max(const T1& a, const T2& b)
{
	return a < b ? b : a;
}

int main(int argc, char** argv)
{
	return 0;
}