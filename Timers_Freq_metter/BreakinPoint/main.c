

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

volatile u16 T0_flag = 0;
volatile u16 T1_flag = 0;
u32 Freq_Read = 0;
int main(void)
{
	
	EXT_voidInitGlobalInterrupts();
	GPIO_voidSetPortDirection(PA,0xff);
	GPIO_voidSetPortDirection(PC,0xff);
	GPIO_voidSetPortDirection(PB,0);
	GPIO_voidSetPortValue(PB,0xff);
	LCD_Init();
	LCD_writeString("Freq = ",first_line,0);
	
	Timer0_SetCallBack_Interrupt(CTC,func0);
	Timer0_Interrupt(CTC,Enable);
	Timer0_End_at(249);
	Timer0_Init(TIMER0_CTC_MODE,TIMER0_SCALER_8,OCO_DISCONNECTED);
	
	
	Timer1_SetCallBack_Interrupt(Timer1_OverflowInterrupt,func1);
	Timer1_Interrupt(Timer1_OverflowInterrupt,Enable);
	Timer1_Init(TIMER1_NORMAL_MODE,EXTERNAL1_RISING);

    while (1) 
    {
		
	}
}

void func0(void)
{
	Freq_Read = Timer1_Read();
	u16 read = 0;
	T0_flag++;
	if (T0_flag == 4000)
	{
		Freq_Read = (T1_flag * 65536) + Freq_Read ;
		if (Freq_Read >= 1000)
		{
			read =  Freq_Read%1000;
			Freq_Read = Freq_Read/1000;
			LCD_writeString("KHz",second_line,13);
			LCD_goto(second_line,0);
			LCD_Writenum(Freq_Read);
			LCD_writeChar('.',second_line,3);
			LCD_Writenum(read);
		}
		else
		{
			LCD_writeString("Hz",second_line,13);
			LCD_goto(second_line,0);
			LCD_Writenum(Freq_Read);
		}	
	}
}

void func1(void)
{
	T1_flag++;
	
}

