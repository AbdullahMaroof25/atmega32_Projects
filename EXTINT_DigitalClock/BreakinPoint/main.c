

#include "StdTypes.h"
#include "GPIO.h"
#include "EXT_INT.h"
#include "BitMath.h"
#include "LCD.h"
#include "KeyPad.h"

#define F_CPU  8000000
#include <util/delay.h>


#define lcd_port        PA
#define lcd_control     PA
#define keypad_port     PB
#define default_key     '.'

void func0(void);
void func1(void);
void func2(void);

volatile u8 hrs = 0;
volatile u8 mints = 0;
int main(void)
{
	u8 dai = 1;
	u8 month = 1;
	u16 yeai = 2021;
	 
	EXT_voidInitGlobalInterrupts();
	GPIO_voidSetPortDirection(PB,0);
	GPIO_voidSetPortDirection(PD,0);
	
	GPIO_voidSetPortDirection(lcd_port,0xff);
	GPIO_voidSetPortDirection(lcd_control,0xff);
	
	GPIO_voidSetPortValue(PB,0xff);
	GPIO_voidSetPortValue(PD,0xff);
	
	EXT_voidEnableExtInt(EXT_INT_0,FALLIN_EDGE);
	EXT_voidEnableExtInt(EXT_INT_1,FALLIN_EDGE);
	EXT_voidEnableExtInt(EXT_INT_2,FALLIN_EDGE);
	
	LCD_Init();
	LCD_writeString("dd/mm/year hh:mm",first_line,0);
	
	SetCallBack_ExtInt(EXT_INT_0,func0);
	SetCallBack_ExtInt(EXT_INT_1,func1);
	SetCallBack_ExtInt(EXT_INT_2,func2);
	
	LCD_writeString("/",second_line,2);
	LCD_writeString("/",second_line,5);
	LCD_writeString(":",second_line,13);
	
	
    while (1) 
    {
		
		if (mints<10)
		{
			LCD_writeString("0",second_line,14);
			LCD_Writenum(mints);
		}
		else
		{
			LCD_goto(second_line,14);
			LCD_Writenum(mints);
		}
		
		if (hrs<10)
		{
			LCD_writeString("0",second_line,11);
			LCD_Writenum(hrs);
		}
		else
		{
			LCD_goto(second_line,11);
			LCD_Writenum(hrs);
		}
		
		if (dai<10)
		{
			LCD_writeString("0",second_line,0);
			LCD_Writenum(dai);
		}
		else
		{
			LCD_goto(second_line,0);
			LCD_Writenum(dai);
		}
		if (month<10)
		{
			LCD_writeString("0",second_line,3);
			LCD_Writenum(month);
		}
		else
		{
			LCD_goto(second_line,3);
			LCD_Writenum(month);
		}
		LCD_goto(second_line,6);
		LCD_Writenum(yeai);
		
		if (mints == 60)
		{
			
			mints = 0;
			hrs++;
		}
		
		if (hrs == 24)
		{
			
			hrs = 0;
		}
		
		
		if(dai == 31)
		{
			month ++;
			dai = 1;
		}
		if (month == 13)
		{
			month  = 1;
			yeai ++;
		}
		if (mints == 59 && hrs == 23)
		{
			_delay_ms(1000);   // any delay to be like a minute 
			mints = 0;
			hrs = 0;
			dai++;
			
		}
		/******************/
		// change the delay to any value   
		_delay_ms(1000);
		mints++;
		/******************/
	}
}

void func0(void)
{
	mints++;
}

void func1(void)
{
	hrs++;
}

void func2(void)
{
	
}
