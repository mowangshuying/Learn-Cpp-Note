#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	std::ofstream outputFile{ "FileWrite.out" };
	if (outputFile.fail())
	{
		std::cout << "Unable to open file for writing." << std::endl;
		return 1;
	}

	outputFile << "hello!" << std::endl;
	outputFile.close();

	std::ofstream apendFile{ "FileWrite.out",std::ios_base::app };
	if (apendFile.fail())
	{
		std::cout << "Unable to open file for appending." << std::endl;
		return 2;
	}

	apendFile << "world!" << std::endl;
	apendFile.close();
	return 0;
}