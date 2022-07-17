#include <filesystem> // c++17 ��ʼ����
#include <string>
#include <iostream>

void printDirStructure(const std::filesystem::path& path,int level)
{
	if (!std::filesystem::exists(path))
	{
		std::cout << "path error!" << std::endl;
		return;
	}

	const std::string spacer(level * 2, ' ');
	// ͨ������is_regular_file�ж��Ƿ����ļ�
	if (std::filesystem::is_regular_file(path))
	{
		std::cout << std::format("{}File: {} ({} bytes)", spacer, path.string(), std::filesystem::file_size(path))<<std::endl;
		return;
	}

	// ͨ������is_directory�ж��Ƿ�ΪĿ¼
	if (std::filesystem::is_directory(path))
	{
		std::cout << std::format("{}Dir: {}", spacer, path.string()) << std::endl;
		
		// ������Ŀ¼�µ������ļ�
		for (auto& entry : std::filesystem::directory_iterator(path))
		{
			printDirStructure(entry, level + 1);
		}
		return;
	}
}

int main(int argc, char** argv)
{
	const std::filesystem::path path{"E:\\CodeLibraries\\MWSY-LearnCpp"};
	printDirStructure(path, 0);
	return 0;
}
