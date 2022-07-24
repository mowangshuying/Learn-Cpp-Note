#include <iostream>
#include <map>

int main(int argc, char** argv)
{
	std::map<int, std::string> map1 = { {1,"1"},{2,"2"} };

	for (auto& e : map1)
	{
		std::cout << "e.first:" << e.first << " e.second:" << e.second << std::endl;
	}

	map1[3] = "3";
	map1.insert({ 6,"6" });
	
	for (auto& e : map1)
	{
		std::cout << "e.first:" << e.first << " e.second:" << e.second << std::endl;
	}

	auto itf = map1.find(5);
	if (itf == map1.end())
	{
		std::cout << "not find 5"<<std::endl;
	}
	else
	{
		std::cout << "find 5" << std::endl;
	}

}