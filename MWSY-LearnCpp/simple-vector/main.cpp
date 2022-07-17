#include <iostream>
#include <vector>

template<typename Iter>
void myPrint(Iter begin, Iter end)
{
	for (auto iter{ begin }; iter != end; iter++)
	{
		std::cout << *iter << " ";
	}
}

template<typename InputIter, typename OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter targer)
{
	for (auto iter{ begin }; iter != end; ++iter, ++targer)
	{
		(*targer) = (*iter);
	}
}

template<typename InputIter>
auto mySum(InputIter begin, InputIter end)
{
	auto sum{ *begin };
	for (auto iter{ ++begin }; iter != end; ++iter)
	{
		sum += (*iter);
	}
	return sum;
}

int main(int argc, char** argv)
{
	std::vector<int> values1{ 1,2,3,4,5 };
	for (auto iter{ std::cbegin(values1) }; iter != std::cend(values1); ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	myPrint(values1.cbegin(), values1.cend());
	std::cout << std::endl;


	std::vector<int> values2(values1.size());
	myCopy(std::cbegin(values2), std::cend(values2), std::begin(values2));

	// 输出流迭代器
	// ostream_iterator属于I/O流STL适配器，用于获取一个元素，同时保存在缓冲器中，
	// 可以供Cout输出。如果把cout看做成一个对 象，那么在Cout对象当中存在一片用于
	// 数据存储的区域。ostream_iterator在STL中一般配合copy函数一起使用，如下代码
	myCopy(std::cbegin(values1), std::cend(values1), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	// 输入流迭代器
	// 使用istream_iterator从控制台中读取整数，直到流的末尾。
	// 在windows上，按下Ctrl+Z然后在按ener键，就会发生这种情况；
	// 在linux上，按下enter键再按下Ctrl+D组合键也会出现这样情况。
	std::cout << " Enter numbers separated by whitespace." << std::endl;
	std::cout << "please Ctrl+Z followed by enter to stop." << std::endl;

	std::istream_iterator<int> numBegIter{ std::cin };
	std::istream_iterator<int> numEndIter;
	int result{ mySum(numBegIter,numEndIter) };
	std::cout << "result:" << result << std::endl;

	return 0;
}