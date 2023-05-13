#include <iostream>
#include <windows.h>

std::string getAppPath()
{
	char szPath[256] = { 0 };
	int nSize = GetModuleFileNameA(NULL, szPath, sizeof(szPath));
	if (nSize <= 0) 
	{
		return "";
	}
	return szPath;
}

int main(int argc, char** argv)
{
	//std::cout << "app path:" << argv[0] << std::endl;
	std::cout << "app path:" << getAppPath() << std::endl;
	return 0;
}