

#ifndef EXT_INT_H_
#define EXT_INT_H_


#include "MemMap.h"
#include "StdTypes.h"
#include "BitMath.h"



typedef enum
{
	EXT_INT_0 ,
	EXT_INT_1 ,
	EXT_INT_2 
}t_EXT_INT;

typedef enum
{
	LOW_LEVEL ,
	ON_CHANGE ,
	FALLIN_EDGE ,
	RISIN_EDGE 
}t_TRIGGERING_CONDITION;



void EXT_voidEnableExtInt(t_EXT_INT cpy_ext_int , t_TRIGGERING_CONDITION cpy_condition);
void EXT_voidDisableExtInt(t_EXT_INT cpy_ext_int);
void EXT_voidInitGlobalInterrupts(void);
void SetCallBack_ExtInt(t_EXT_INT cpy_ext_int ,void(*func)(void));



#endif /* EXT_INT_H_ */