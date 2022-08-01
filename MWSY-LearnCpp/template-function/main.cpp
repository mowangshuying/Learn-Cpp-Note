#include<iostream>

inline const int& max(const int& a, const int& b)
{
	return a < b ? b : a;
}

/**
 * ģ����� T��Ϊģ�����
 * ���в��� a��b�Ǻ��в���
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