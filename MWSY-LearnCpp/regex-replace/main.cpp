#include <iostream>
#include <regex>

/**
 * regex_replace 要求输入正则表达式，以及用于一个替换匹配字符串的格式化字符串
 * 这个匹配的格式化字符串可以使用如下转义序列，引用匹配子字符串的部分内容
 * 
 * 转义序列			转义序列
 * $n				匹配第n个捕捉组的字符串，例如$1表示第一个捕捉组，$2表示第二个捕捉组合
 * $&				匹配整个正则表达式的字符串
 * $`				在输入序列中，在匹配正则表达式的子字符串左侧的部分
 * $'				在输入序列中，在匹配正则表达式的子字符串右侧的部分
 * $$				匹配单个美元符号
*/

int main(int argc, char** argv)
{
	const std::string rawStr = "<body><h1>Header</h1><p>some text</p></body>";
	
	// 定义正则表达式，用于匹配字符串
	std::regex rex("<h1>(.*)</h1><p>(.*)</p>");
	
	// 目标字符串的格式
	const std::string dstFormatStr = "H1=$1 and P=$2";

	std::string dstStr = std::regex_replace(rawStr,rex,dstFormatStr);

	std::cout << "rawStr:" << rawStr << std::endl;//rawStr:<body><h1>Header</h1><p>some text</p></body>
	std::cout << "dstStr:" << dstStr << std::endl;//dstStr:<body>H1=Header and P=some text</body>

	return 0;
}