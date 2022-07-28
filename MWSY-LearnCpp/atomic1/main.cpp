#include <iostream>
#include <atomic>

int main(int argc, char** argv)
{
	std::atomic<int> tmp;
	// ÅĞ¶ÏÊÇ·ñÊÇÎŞËø
	std::cout <<"tmp.is_lock_free() =" << tmp.is_lock_free() << std::endl;
	return 0;
}