#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	std::ifstream inputFile("FileWrite.out");
	if (inputFile.fail())
	{
		std::cout << "Unable to open file for reading." << std::endl;
		return 1;
	}

	std::string nextToken;
	while (inputFile >> nextToken) 
	{
		std::cout << "Token:" << nextToken << std::endl;
	}
	return 0;
}