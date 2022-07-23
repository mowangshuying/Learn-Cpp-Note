#include <tuple>
#include <iostream>
#include <string>
#include <format>

int main(int argc, char** argv)
{
	using SimpleTuple = std::tuple<bool, int, std::string>;
	SimpleTuple t1{ true,1,"test" };
	//��ȡԪ���ڵ�Ԫ��
	std::cout << std::format("t1 = ({},{},{})", std::get<0>(t1), std::get<1>(t1), std::get<2>(t1)) << std::endl;
	//��ȡԪ��Ĵ�С
	std::cout << std::format("t1.size={}", std::tuple_size<SimpleTuple>::value) << std::endl;

	////////////////////////////////////////Ԫ��Ľṹ����///////////////////////////////////////////////////////
	
	//��ֵ
	auto [b, i, str] {t1};
	std::cout << std::format("b={},i={},str={}", b, i, str) << std::endl;

	//������
	auto& [b1, i1, str1] {t1};
	b1 = false;
	i1 = 2;
	str1 = "test1";
	std::cout << std::format("t1 = ({},{},{})", std::get<0>(t1), std::get<1>(t1), std::get<2>(t1)) << std::endl;

	
	////////////////////////////////////////ʹ��tie()�������нṹ����/////////////////////////////////////////////
	
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


	//////////////////////////////////////��������Ԫ��/////////////////////////////////////////////////////////////

	std::tuple t41{ false,0,"test1" };
	std::tuple t42{ true,1,"test2" };
	auto t4 = std::tuple_cat(t41, t42);
	//std::tuple_size<auto>(t4); //��ʱû�д��﷨��

	return 0;
}