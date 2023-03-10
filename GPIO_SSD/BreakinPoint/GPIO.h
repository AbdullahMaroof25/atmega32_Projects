


#ifndef GPIO_H_
#define GPIO_H_
#include "StdTypes.h"

#define DDRA (*(volatile u8*)0x3A)
#define DDRB (*(volatile u8*)0x37)
#define DDRC (*(volatile u8*)0x34)
#define DDRD (*(volatile u8*)0x31)

#define PINA (*(volatile u8*)0x39)
#define PINB (*(volatile u8*)0x36)
#define PINC (*(volatile u8*)0x33)
#define PIND (*(volatile u8*)0x30)

#define PORTA (*(volatile u8*)0x3B)
#define PORTB (*(volatile u8*)0x38)
#define PORTC (*(volatile u8*)0x35)
#define PORTD (*(volatile u8*)0x32)

#define SET_BIT(reg,bit)      reg=(reg|(1<<bit))
#define CLEAR_BIT(reg,bit)      reg=(reg&(~(1<<bit)))
#define TOGGLE_BIT(reg,bit)      reg=(reg^(1<<bit))
#define READ_BIT(reg,bit)      ((reg>>bit)&1)

#define PA    0    
#define PB    1    
#define PC    2    
#define PD    3   
 
#define PIN0     0    
#define PIN1     1    
#define PIN2     2    
#define PIN3     3    
#define PIN4     4    
#define PIN5     5    
#define PIN6     6    
#define PIN7     7    

#define INPUT    0    
#define OUTPUT   1    
#define INPUT_PULLUP    2

#define HIGH  1
#define LOW   0



void GPIO_voidSetPortDirection (u8 cpy_PORT,u8 Value);                 //done
void GPIO_voidSetPortPinDirection (u8 cpy_PORT , u8 cpy_PIN);
void GPIO_voidSetPortPinValue (u8 cpy_PORT , u8 cpy_PIN , u8 cpy_value);   //done
void GPIO_voidSetPortValue(u8 cpy_PORT , u8 cpy_value);                   //done
u8 GPIO_u8GetPortPinValue(u8 cpy_PORT , u8 cpy_PIN);                     //done
u8 GPIO_u8GetPortValue(u8 cpy_PORT);                                    //done




#endif /* GPIO_H_ */