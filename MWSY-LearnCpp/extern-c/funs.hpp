#pragma once

#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif 
	

	void func()
	{
		std::cout <<"func:" << __func__ << "() " <<"line:" << __LINE__ << std::endl;
	}


#ifdef __cplusplus
}// matches extern "C
#endif 
