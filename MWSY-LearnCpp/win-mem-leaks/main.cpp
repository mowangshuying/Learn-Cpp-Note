
///////////////////////////////////////////
// ����win���õ��ڴ��⹦��
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif

#endif // 
///////////////////////////////////////////

#include <iostream>

/**
 * windows���õ��Կ��ʹ��
*/

int main(int argc, char** argv)
{
	//////////////////////////////////////
	//����win���õ��ڴ��⹦�� 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//////////////////////////////////////

	int* pInt{ new int };

	//delete(pInt)
	//pInt = nullptr;
	return 0;
}