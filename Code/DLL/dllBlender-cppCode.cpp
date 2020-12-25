#include "stdafx.h"
#include <utility>
#include <limits.h>
#include "Header.h"
#pragma data_seg(".shared")
 
#pragma comment (linker,"/section:.shared,RWS")
__declspec(allocate(".shared")) int x = 0;
 
int getx(int a)
{
   	x = a;
   	return 0;
}
int returnx()
{
   	return x;
}
