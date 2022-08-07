#include <iostream>

//using namespace std;

template <bool _Test, typename _Ty = void>
struct enable_if
{
	//enable_if() 
	//{
	//	std::cout << "template0" << std::endl;
	//}
};

template <typename _Ty>
struct enable_if<true,_Ty>
{
	using type = _Ty;
};

//template <typename _Ty>
//struct enable_if<false,_Ty>
//{
//	using type = void;
//};

template <typename _Ty>
typename enable_if<std::is_default_constructible<_Ty>::value,void>::type ExamleFunc()
{
	//int a = enable_if < std::is_default_constructible<_Ty>::value;
	std::cout << "has default constructible func" << std::endl;
}

template <typename _Ty>
typename enable_if<!std::is_default_constructible<_Ty>::value, void>::type ExamleFunc()
{
	//int a = enable_if < std::is_default_constructible<_Ty>::value;
	std::cout << "not has default constructible func" << std::endl;
}

class ClassObj1
{
public:
	ClassObj1() = default;
};

class ClassObj2
{
public:
	ClassObj2() = delete;
};

int main(int argc, char** argv)
{
	enable_if<true, int>::type x1 = 1;
	std::cout << "x1:" << x1 << std::endl;

	typename enable_if<true, int>::type x2 = 2;
	std::cout << "x2:" << x2 << std::endl;

	ExamleFunc<ClassObj1>();
	ExamleFunc<ClassObj2>();

	// is_default_constructible 
	// 判断是否含有默认的构造函数,
	std::is_default_constructible<ClassObj1>::value;//true
	std::is_default_constructible<ClassObj2>::value;//false

	return 0;
}