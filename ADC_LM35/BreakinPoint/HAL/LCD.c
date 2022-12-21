
#include "LCD.h"

#if(LCD_Mode==_8_bit)

void LCD_WriteCommand(u8 Command)
{
	GPIO_voidSetPortPinValue(lcd_control,RS,LOW);
	GPIO_voidSetPortPinValue(lcd_control,RW,LOW);
	GPIO_voidSetPortValue(lcd_port,Command);
	GPIO_voidSetPortPinValue(lcd_control,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPortPinValue(lcd_control,EN,LOW);
	_delay_ms(1);
	
}
void LCD_WriteData(u8 Data)
{
	GPIO_voidSetPortPinValue(lcd_control,RS,HIGH);
	GPIO_voidSetPortPinValue(lcd_control,RW,LOW);
	GPIO_voidSetPortValue(lcd_port,Data);
	GPIO_voidSetPortPinValue(lcd_control,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPortPinValue(lcd_control,EN,LOW);
	_delay_ms(1);
	
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);  
	_delay_ms(1);
	LCD_WriteCommand(0x0c);   
	_delay_ms(1);
	LCD_WriteCommand(0x01);
	_delay_ms(2);
	LCD_WriteCommand(0x06);  
	_delay_ms(1);
}

#elif(LCD_Mode == _4_bit)

void LCD_WriteCommand(u8 Command)
{
	GPIO_voidSetPortPinValue(lcd_control,RS,LOW);
	GPIO_voidSetPortPinValue(lcd_control,RW,LOW);
	GPIO_voidSetPortPinValue(lcd_port,p1,READ_BIT(Command,4));
	GPIO_voidSetPortPinValue(lcd_port,p2,READ_BIT(Command,5));
	GPIO_voidSetPortPinValue(lcd_port,p3,READ_BIT(Command,6));
	GPIO_voidSetPortPinValue(lcd_port,p4,READ_BIT(Command,7));
	GPIO_voidSetPortPinValue(lcd_control,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPortPinValue(lcd_control,EN,LOW);
	_delay_ms(1);
	GPIO_voidSetPortPinValue(lcd_port,p1,READ_BIT(Command,0));
	GPIO_voidSetPortPinValue(lcd_port,p2,READ_BIT(Command,1));
	GPIO_voidSetPortPinValue(lcd_port,p3,READ_BIT(Command,2));
	GPIO_voidSetPortPinValue(lcd_port,p4,READ_BIT(Command,3));
	GPIO_voidSetPortPinValue(lcd_control,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPortPinValue(lcd_control,EN,LOW);
	_delay_ms(1);
	
}
void LCD_WriteData(u8 Data)
{
	GPIO_voidSetPortPinValue(lcd_control,RS,HIGH);
	GPIO_voidSetPortPinValue(lcd_control,RW,LOW);
	GPIO_voidSetPortPinValue(lcd_port,p1,READ_BIT(Data,4));
	GPIO_voidSetPortPinValue(lcd_port,p2,READ_BIT(Data,5));
	GPIO_voidSetPortPinValue(lcd_port,p3,READ_BIT(Data,6));
	GPIO_voidSetPortPinValue(lcd_port,p4,READ_BIT(Data,7));
	GPIO_voidSetPortPinValue(lcd_control,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPortPinValue(lcd_control,EN,LOW);
	_delay_ms(1);
	GPIO_voidSetPortPinValue(lcd_port,p1,READ_BIT(Data,0));
	GPIO_voidSetPortPinValue(lcd_port,p2,READ_BIT(Data,1));
	GPIO_voidSetPortPinValue(lcd_port,p3,READ_BIT(Data,2));
	GPIO_voidSetPortPinValue(lcd_port,p4,READ_BIT(Data,3));
	GPIO_voidSetPortPinValue(lcd_control,EN,HIGH);
	_delay_ms(1);
	GPIO_voidSetPortPinValue(lcd_control,EN,LOW);
	_delay_ms(1);
	
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	_delay_ms(1);
	LCD_WriteCommand(0x28);
	_delay_ms(1);
	LCD_WriteCommand(0x0c);
	_delay_ms(1);
	LCD_WriteCommand(0x06);
	_delay_ms(2);
	LCD_WriteCommand(0x83);
	_delay_ms(1);
}

#endif

void LCD_goto(u8 line,u8 x)
{
	
	if (line == first_line)
	{
		LCD_WriteCommand(0X80+x);
	}
	else if (second_line == 1)
	{
		LCD_WriteCommand(0X80+0x40+x);
	}
}

void LCD_writeChar(u8 Char, u8 line, u8 col)
{
	LCD_goto(line,col);
	LCD_WriteData(Char);
}

void LCD_writeString(u8 * str, u8 line, u8 col)
{
	u8 i=0;
	LCD_goto(line,col);
	while (str[i] != '\0' )
	{
		if (((line * 0x40)+col)+ i == 0x10)
			LCD_goto(1,0);		
		LCD_WriteData(str[i]);
		i++;
	}
}

void Lcd_Clear(void)
{
	LCD_WriteCommand(0x01);
}

void lcd_creatchar(u8* pattern,u8 address)
{
	u8 i;
	LCD_WriteCommand(0x40+(address*8));
	for (i=0;i<8;i++)
	{
		LCD_WriteData(pattern[i]);
	}
}

/*u8 	 LCD_getCurrAddress(void)
{
	u8 address;
	GPIO_voidSetPortPinValue(lcd_control,RS,LOW);
	GPIO_voidSetPortPinValue(lcd_control,RW,HIGH);
	while(GPIO_u8GetPortPinValue(lcd_port,p4) == HIGH);
	
}*/
void LCD_Writenum(u32 num)
{
	u16 rem=1,j,i=0,arr[16]={0};
	if (num==0)
	{
		LCD_WriteData('0');
	}
	else if (num<0)
	{
		num =num*(-1);
		LCD_WriteData('-');
	}
	while (num>0)
	{
		rem=num%10;
		arr[i]=rem+'0';
		num=num/10;
		i++;
	}
	for (j=i;j>0;j--)
	{
		LCD_WriteData(arr[j-1]);
	}

}

void LCD_Writenum_4D(u16 num)
{
	LCD_WriteData((num/1000)+'0');
	LCD_WriteData(((num%1000)/100)+'0');
	LCD_WriteData(((num%100)/10)+'0');
	LCD_WriteData((num%10)+'0');

}