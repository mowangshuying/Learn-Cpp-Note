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

	// �����������
	// ostream_iterator����I/O��STL�����������ڻ�ȡһ��Ԫ�أ�ͬʱ�����ڻ������У�
	// ���Թ�Cout����������cout������һ���� ����ô��Cout�����д���һƬ����
	// ���ݴ洢������ostream_iterator��STL��һ�����copy����һ��ʹ�ã����´���
	myCopy(std::cbegin(values1), std::cend(values1), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	// ������������
	// ʹ��istream_iterator�ӿ���̨�ж�ȡ������ֱ������ĩβ��
	// ��windows�ϣ�����Ctrl+ZȻ���ڰ�ener�����ͻᷢ�����������
	// ��linux�ϣ�����enter���ٰ���Ctrl+D��ϼ�Ҳ��������������
	std::cout << " Enter numbers separated by whitespace." << std::endl;
	std::cout << "please Ctrl+Z followed by enter to stop." << std::endl;

	std::istream_iterator<int> numBegIter{ std::cin };
	std::istream_iterator<int> numEndIter;
	int result{ mySum(numBegIter,numEndIter) };
	std::cout << "result:" << result << std::endl;

	return 0;
}