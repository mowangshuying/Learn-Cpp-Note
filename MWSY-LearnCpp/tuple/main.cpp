#include <tuple>
#include <iostream>
#include <string>
#include <format>

int main(int argc, char** argv)
{
	using SimpleTuple = std::tuple<bool, int, std::string>;
	SimpleTuple t1{ true,1,"test" };
	//获取元组内的元素
	std::cout << std::format("t1 = ({},{},{})", std::get<0>(t1), std::get<1>(t1), std::get<2>(t1)) << std::endl;
	//获取元组的大小
	std::cout << std::format("t1.size={}", std::tuple_size<SimpleTuple>::value) << std::endl;

	////////////////////////////////////////元组的结构化绑定///////////////////////////////////////////////////////
	
	//绑定值
	auto [b, i, str] {t1};
	std::cout << std::format("b={},i={},str={}", b, i, str) << std::endl;

	//绑定引用
	auto& [b1, i1, str1] {t1};
	b1 = false;
	i1 = 2;
	str1 = "test1";
	std::cout << std::format("t1 = ({},{},{})", std::get<0>(t1), std::get<1>(t1), std::get<2>(t1)) << std::endl;

	
	////////////////////////////////////////使用tie()函数进行结构化绑定/////////////////////////////////////////////
	
	std::tuple t3{ true,3,"test3" };
	bool b3 = false;
	int i3 = 0;
	std::string str3 = "";

	std::tie(b3, i3, str3) = t3;
	std::cout << std::format("b3={},i3={},str3={}", b3, i3, str3) << std::endl;

	bool b31 = false;
	int i31 = 0;
	std::tie(b31, i31, std::ignore) = t3;
	std::cout << std::format("b31={},i31={}", b31, i31) << std::endl;


	//////////////////////////////////////连接两个元组/////////////////////////////////////////////////////////////

	std::tuple t41{ false,0,"test1" };
	std::tuple t42{ true,1,"test2" };
	auto t4 = std::tuple_cat(t41, t42);
	//std::tuple_size<auto>(t4); //暂时没有此语法的

	return 0;
}