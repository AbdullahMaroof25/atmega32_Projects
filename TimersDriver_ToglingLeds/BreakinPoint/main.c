

#include "StdTypes.h"
#include "GPIO.h"
#include "EXT_INT.h"
#include "BitMath.h"
#include "LCD.h"
#include "KeyPad.h"
#include "Timers.h"

#define F_CPU  8000000
#include <util/delay.h>


#define lcd_port        PA
#define lcd_control     PA
#define keypad_port     PB
#define default_key     '.'

void func0(void);
void func1(void);

volatile u16 flag = 0;

int main(void)
{
	u8 c2=0,c3=0,c4=0;
	EXT_voidInitGlobalInterrupts();
	GPIO_voidSetPortDirection(PC,0xff);
	GPIO_voidSetPortDirection(PA,0xff);
	
	Timer0_SetCallBack_Interrupt(Overflow,func0);
	Timer0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8,OCO_DISCONNECTED);
	Timer0_Interrupt(Overflow,Enable);
	Timer0_StartFrom(6);
	

	

    while (1) 
    {
		if (flag == 4000)
		{
			Timer0_StartFrom(6);
			GPIO_TogglePin(PC,PIN0);
			flag = 0;
			c2++;
			c3++;
			c4++;
			
			
		}
		if (c2 == 2)
		{
			GPIO_TogglePin(PC,PIN1);
			c2 = 0;
		}
		if (c3 == 3)
		{
			GPIO_TogglePin(PC,PIN2);
			c3 = 0;
		}
		if (c4 == 4)
		{
			GPIO_TogglePin(PC,PIN3);
			c4 = 0;
		}
	
	}
}

void func0(void)
{
	flag++;
}

void func1(void)
{
	
	
}

