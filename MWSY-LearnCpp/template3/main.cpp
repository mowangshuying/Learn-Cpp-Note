#include <iostream>

#define STATIC_CHECK(expr) { char unnamed[(expr) ? 1 : 0];};

template<class To, class From>
To safeReinterpretCast(From from)
{
	STATIC_CHECK(sizeof(From) <= sizeof(To));
	return reinterpret_cast<To>(from);
}

template <bool>
struct CompileTimeError;

template <>
struct CompileTimeError<true>
{
	// ...
};

#define TEMPLATE_STATIC_CHECK (expr) \
	(CompileTimeError< (expr) != 0 >())


template <bool> 
struct CompileTimeChecker
{
	CompileTimeChecker(...);
};

template <>
struct CompileTimeChecker<false> 
{
};

#define TEMPLATE_STATIC_CHECK_WITH_MSG(expr, msg) \
	{ \
		class ERROR_##msg { }; \
		auto msg = ERROR_##msg(); \
		(void)sizeof(CompileTimeChecker< (expr) >( msg )); \
	}

int main(int argc, char** argv)
{
	//TEMPLATE_STATIC_CHECK_WITH_MSG(false, err);

	class ERROR_msg{ }; 
	//auto check = CompileTimeChecker< true >(ERROR_msg());
	//(void)sizeof(CompileTimeChecker< true >{ERROR_msg()});

	//auto msg = ERROR_msg();
	//sizeof(CompileTimeChecker<false>(msg));

	TEMPLATE_STATIC_CHECK_WITH_MSG(true, msg);

	return 0;
}