

#include "StdTypes.h"
#include "GPIO.h"
#include "EXT_INT.h"
#include "ADC.h"
#include "LCD.h"


void func0(void);
void func1(void);

volatile u16 temp = 0;
volatile u16 read = 0;
int main(void)
{
	EXT_voidInitGlobalInterrupts();
	
	GPIO_voidSetPortDirection(lcd_port,0xff);
	GPIO_voidSetPortDirection(PA,0);
	
	LCD_Init();
	LCD_writeString("Temp = ",first_line,0);
	
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	ADC_SetCallBack(func0);
	ADC_Interrupt(Enable);
	
	
    while (1) 
    {
		temp = TEMP_Read(ch_0);
		read = ADC_Read(ch_0);
	}
		
}

void func0(void)
{
	temp = TEMP_Read(ch_0);
	read = ADC_Read(ch_0);
	LCD_goto(second_line,0);
	LCD_Writenum_4D(temp);
	LCD_goto(second_line,5);
	LCD_Writenum_4D(read);
}

void func1(void)
{
	
	
}

