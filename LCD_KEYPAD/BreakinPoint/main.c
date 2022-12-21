

#include "StdTypes.h"
#include "GPIO.h"
#include "BitMath.h"
#include "LCD.h"
#include "KeyPad.h"
#define F_CPU  8000000
#include <util/delay.h>


#define lcd_port        PA
#define lcd_control     PA
#define keypad_port     PB
#define default_key     '.'
#define Password        15907


int main(void)
{
	u8 key=default_key;
	u8 x = 0;
	u16 num = 0;
	GPIO_voidSetPortDirection(lcd_port,0xff);
	GPIO_voidSetPortDirection(keypad_port,0X0F);
	GPIO_voidSetPortValue(keypad_port,0xff);
	LCD_Init();
    //LCD_writeString("123",0,0);
	//LCD_writeChar('A',0,10);
	//LCD_writeChar('A',1,5);
	//u8 ptr[]={0b00000001,0b00000010,0b000001000,0b00010000};
	//lcd_creatchar(ptr,1);
	//LCD_writeChar(1,1,0);
	LCD_writeString("password",0,0);
	LCD_goto(1,0);
    while (1) 
    {
		
		key = keyPad();
		if(key != default_key)
		{
				if ((key >= '0') && (key <= '9'))
				{
					num = (num*10)+(key - '0');
					LCD_writeChar(key,1,x);
					x++;
				}
				else if(key == '=')
				{
					if (num == Password)
					{
						Lcd_Clear();
						LCD_writeString("Welcome",0,0);
					}
					else
					{
						Lcd_Clear();
						LCD_writeString("Wrong",0,0);
					}
					
				}
				
				
				
				
		}
	}
}