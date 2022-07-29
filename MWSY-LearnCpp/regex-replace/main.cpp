#include <iostream>
#include <regex>

/**
 * regex_replace Ҫ������������ʽ���Լ�����һ���滻ƥ���ַ����ĸ�ʽ���ַ���
 * ���ƥ��ĸ�ʽ���ַ�������ʹ������ת�����У�����ƥ�����ַ����Ĳ�������
 * 
 * ת������			ת������
 * $n				ƥ���n����׽����ַ���������$1��ʾ��һ����׽�飬$2��ʾ�ڶ�����׽���
 * $&				ƥ������������ʽ���ַ���
 * $`				�����������У���ƥ��������ʽ�����ַ������Ĳ���
 * $'				�����������У���ƥ��������ʽ�����ַ����Ҳ�Ĳ���
 * $$				ƥ�䵥����Ԫ����
*/

int main(int argc, char** argv)
{
	const std::string rawStr = "<body><h1>Header</h1><p>some text</p></body>";
	
	// ����������ʽ������ƥ���ַ���
	std::regex rex("<h1>(.*)</h1><p>(.*)</p>");
	
	// Ŀ���ַ����ĸ�ʽ
	const std::string dstFormatStr = "H1=$1 and P=$2";

	std::string dstStr = std::regex_replace(rawStr,rex,dstFormatStr);

	std::cout << "rawStr:" << rawStr << std::endl;//rawStr:<body><h1>Header</h1><p>some text</p></body>
	std::cout << "dstStr:" << dstStr << std::endl;//dstStr:<body>H1=Header and P=some text</body>

	return 0;
}