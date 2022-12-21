

#include "StdTypes.h"
#include "GPIO.h"
#include "Timers.h"
#include "EXT_INT.h"

void func0(void);



int main(void)
{
	GPIO_voidSetPortDirection(PC,0xff);
	EXT_voidInitGlobalInterrupts();
	Timer0_Interrupt(Overflow,Enable);
	Timer0_SetCallBack_Interrupt(Overflow,func0);
	Timer0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8,OCO_DISCONNECTED);
	Timer0_StartFrom(64);
	

    while (1) 
    {
	}
		
}

void func0(void)
{
	static u8 flag = 0;
	if (flag == 0)
	{
		GPIO_voidSetPortPindirection(PC,PIN0,HIGH);
		Timer0_StartFrom(192);
		flag = 1;
	}
	else
	{
		GPIO_voidSetPortPindirection(PC,PIN0,LOW);
		Timer0_StartFrom(64);
		flag = 0;
	}
}



