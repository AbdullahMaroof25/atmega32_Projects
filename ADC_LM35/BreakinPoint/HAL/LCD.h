


#ifndef LCD_H_
#define LCD_H_

#include "StdTypes.h"
#include "GPIO.h"
#include "BitMath.h"
#define F_CPU  8000000
#include <util/delay.h>

#define  _4_bit 0
#define  _8_bit 1

#define LCD_Mode _4_bit

/***************8-bit*********/

#define lcd_port        PC

/****************************/

#define lcd_control     PC
#define RS              PIN4
#define RW              PIN5
#define EN              PIN6

/****************************/

/*************4-bit**********/

#define p1             PIN0
#define p2             PIN1
#define p3             PIN2
#define p4             PIN3

/***************************/

#define first_line   0
#define second_line   1



void LCD_WriteCommand(u8 Command);  
void LCD_Init(void);
void LCD_WriteData(u8 Data);
void LCD_writeChar(u8 Char, u8 line, u8 col);
void LCD_writeString(u8 * str, u8 line, u8 col);
void LCD_goto(u8 line,u8 x);
void Lcd_Clear(void);
void lcd_creatchar(u8* pattern,u8 address);
u8 	 LCD_getCurrAddress(void);  // not complete
void LCD_Writenum(u32 num);
void LCD_Writenum_4D(u16 num);

#endif /* LCD_H_ */