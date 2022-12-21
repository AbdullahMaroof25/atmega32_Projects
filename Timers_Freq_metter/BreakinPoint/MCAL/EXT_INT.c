
#include "EXT_INT.h"

static void(*Fptr_INT0)(void) = NULLPTR;
static void(*Fptr_INT1)(void) = NULLPTR;
static void(*Fptr_INT2)(void) = NULLPTR;

void EXT_voidEnableExtInt(t_EXT_INT cpy_ext_int , t_TRIGGERING_CONDITION cpy_condition)
{
	switch(cpy_ext_int)
	{
		case EXT_INT_0:
		switch(cpy_condition)
		{
			case LOW_LEVEL:
			CLEAR_BIT(MCUCSR,ISC00);
			CLEAR_BIT(MCUCSR,ISC01);
			break;
			case ON_CHANGE:
			SET_BIT(MCUCSR,ISC00);
			CLEAR_BIT(MCUCSR,ISC01);
			break;
			case FALLIN_EDGE:
			CLEAR_BIT(MCUCSR,ISC00);
			SET_BIT(MCUCSR,ISC01);
			break;
			case RISIN_EDGE:
			SET_BIT(MCUCSR,ISC00);
			SET_BIT(MCUCSR,ISC00);
			break;
			default:
			break;
		}
		SET_BIT(GICR,INT0);
		break;
		case EXT_INT_1:
		switch(cpy_condition)
		{
			case LOW_LEVEL:
			CLEAR_BIT(MCUCSR,ISC10);
			CLEAR_BIT(MCUCSR,ISC11);
			break;
			case ON_CHANGE:
			SET_BIT(MCUCSR,ISC10);
			CLEAR_BIT(MCUCSR,ISC11);
			break;
			case FALLIN_EDGE:
			CLEAR_BIT(MCUCSR,ISC10);
			SET_BIT(MCUCSR,ISC11);
			break;
			case RISIN_EDGE:
			SET_BIT(MCUCSR,ISC10);
			SET_BIT(MCUCSR,ISC11);
			break;
			default:
			break;
		}
		SET_BIT(GICR,INT1);
		break;
		case EXT_INT_2:
		switch(cpy_condition)
		{
			case FALLIN_EDGE:
			CLEAR_BIT(MCUCSR,ISC2);
			break;
			case RISIN_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
			default:
			SET_BIT(MCUCSR,ISC2);
			break;
		}
		SET_BIT(GICR,INT2);
		break;
	}
	
	
}

void EXT_voidDisableExtInt(t_EXT_INT cpy_ext_int)
{
	switch(cpy_ext_int)
	{
		case EXT_INT_0:
		CLEAR_BIT(GICR,INT0);
		break;
		case EXT_INT_1:
		CLEAR_BIT(GICR,INT1);
		break;
		case EXT_INT_2:
		CLEAR_BIT(GICR,INT2);
		break;
		default:
		break;
	}
}

void EXT_voidInitGlobalInterrupts(void)
{
	sei();
	
}

void SetCallBack_ExtInt(t_EXT_INT cpy_ext_int ,void(*func)(void))
{
	switch(cpy_ext_int)
	{
		case EXT_INT_0:
		Fptr_INT0 = func ;
		break;
		case EXT_INT_1:
		Fptr_INT1 = func ;
		break;
		case EXT_INT_2:
		//Fptr_INT2 = func ;  //to reset the the system
		break;
	}
}

ISR(INT0_vect)
{
	if (Fptr_INT0!=NULLPTR)
	{
		Fptr_INT0();
	}
	
}
ISR(INT1_vect)
{
	if (Fptr_INT1!=NULLPTR)
	{
		Fptr_INT1();
	}
}
ISR(INT2_vect)
{
	//if (Fptr_INT2!=NULLPTR)   to make the program adress points to adress 0 which is reset
	//{
		Fptr_INT2();
	//}
}