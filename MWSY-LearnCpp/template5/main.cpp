//#include <iostream>
//#include <type_traits>
//
//template <class T>
//T foo(T a, T b) {
//	return a + b;
//}
//
//template <class T>
//T bar(T a, std::type_identity_t<T> b) {
//	return a + b;
//}
//
//int main() {
//	//foo(4.2, 1); // error, deduced conflicting types for 'T'
//	std::cout << bar(4.2, 1) << '\n';  // OK, calls bar<double>
//}

#include <iostream>
#include <vector>

//class NullType;
//
//template <typename T>
//class TypeTraits
//{
//private:
//	template <class U> 
//	struct PointerTraits
//	{
//		enum {
//			result = false,
//		};
//		typedef NullType PointeeType;
//	};
//
//	template <class U>
//	struct PointerTraits<U*>
//	{
//		enum {
//			result = true,
//		};
//		typedef U PointeeType;
//	};
//public:
//	enum {
//		isPointer = PointerTraits<T>::result,
//	};
//
//	typedef PointerTraits<T>::PointeeType PointeeType;
//};
//
//int main(int argc, char** argv)
//{
//	//TypeTraits<int>::PointeeType x = 1;
//	//TypeTraits<int*>::PointeeType x = 1;
//
//	std::cout << TypeTraits<int>::isPointer << std::endl;
//	std::cout << TypeTraits<int*>::isPointer << std::endl;
//	//TypeTraits<int>::PointeeType NullType
//	//TypeTraits<int*>::PointeeType pInt = 5;
//	
//	const bool iterIsPtr = TypeTraits<std::vector<int>::iterator>::isPointer;
//	std::cout << "iterIsPtr:" << iterIsPtr << std::endl;
//
//	return 0;
//}

//class NullType;
//template <class T, class U>
//struct TypeList
//{
//	typedef T HEAD;
//	typedef U TAIL;
//};
//
//typedef TypeList<char, TypeList<signed char, TypeList<unsigned char, NullType>>> AllCharTypes;

//template <typename ResultType>
//class Functor {
//
//};
//
//template <typename ResultType, typename Parm>
//class Functor {
//	
//};

//template <typename RusultType, class TList>
//class Functor {
//};


int main(int argc, char** argv)
{
	return 0;
}