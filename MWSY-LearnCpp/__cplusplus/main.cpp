#include <iostream>

#if __cplusplus < 201103L
#error should use C++ 11 implementation
#endif


/*
 * 在Visual Studio中设置此编译器选项
 * 打开项目的“ 属性页”对话框。 有关详细信息，请参阅在Visual Studio中设置C ++编译器和构建属性。
 * 选择“ 配置属性” >“ C / C ++” >“ 命令行”属性页。
 * 将/Zc:__cplusplus或/Zc:__cplusplus-添加到其他选项：窗格。
*/

int main(int argc, char** argv)
{
	std::cout << __cplusplus << std::endl;
	return 0;
}