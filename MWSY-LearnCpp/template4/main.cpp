#include <iostream>
#include <vector>

using namespace std;

class A {
protected:
	virtual void self() {
	}
};

class B : public A
{
protected:
	virtual void self() {
	}
public:
	int x_;
};

template <class T, class U>
class Conversion
{
public:
	typedef char Small;
	class Big { char dummy[2]; };

	static Small Test(U) // T -> U
	{
		std::cout << __FUNCSIG__ << std::endl;
		return Small();
	}

	static Big Test(...) // 
	{
		std::cout << __FUNCSIG__ << std::endl;
		return Big();
	}

	static T MakeT();
public:
	enum
	{
		exists = sizeof(Test(MakeT())) == sizeof(Small),
	};

	enum
	{
		exists2Way = exists && Conversion<U, T>::exists,
	};

	enum
	{
		sameType = false,
	};

	//constexpr int t1_ = 1;
};

template <class T>
class Conversion<T,T>
{
public:
	enum {
		exists = 1, exists2Way = 1, sameType = 1
	};
};

#define SUPPERSUBCLASS(T,U) \
	(Conversion<const U*,const T*>::exists) && \
	(Conversion<const T*,const void*>::sameType)

int main(int argc, char** argv)
{
	std::cout << Conversion<double, int>::exists << std::endl; // double ->int 
	std::cout << Conversion<char, char*>::exists << std::endl; // char -> char* 
	std::cout << Conversion<size_t, vector<int>>::exists << std::endl; // size_t -> vecotr<int>

	//double  d = 5.0;
	//Conversion<double,int>::Test(d);
	A a;
	B b;

	A* pA = &b;

	auto a1 = static_cast<A>(b);
	//auto b1 = static_cast<B>(a);
	auto b2 = dynamic_cast<B*>(pA);

	Conversion<A, B>::Test(a); // a -> b
	//Conversion<A, B>::Test(b);
	//Conversion<B, A>::Test(a);
	Conversion<B, A>::Test(b); // b -> a

	//sint t1 = Conversion<A, B>::t1_;


	A* ax = new (std::nothrow) A() ;
	if (ax == nullptr) {
		//return;
	}
}
