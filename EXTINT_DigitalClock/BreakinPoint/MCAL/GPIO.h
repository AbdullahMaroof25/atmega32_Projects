


#ifndef GPIO_H_
#define GPIO_H_
#include "StdTypes.h"
#include "MemMap.h"





#define PA    0    
#define PB    1    
#define PC    2    
#define PD    3   

typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
	
}gpio_pins;


#define INPUT    0    
#define OUTPUT   1    

#define HIGH  1
#define LOW   0



void GPIO_voidSetPortDirection (u8 cpy_PORT,u8 Value);                 //done
void GPIO_voidSetPortPinValue (u8 cpy_PORT , u8 cpy_PIN , u8 cpy_value);  //done
void GPIO_voidSetPortPindirection (u8 cpy_PORT , u8 cpy_PIN , u8 cpy_direction);   
void GPIO_voidSetPortValue(u8 cpy_PORT , u8 cpy_value);                   //done
u8 GPIO_u8GetPortPinValue(u8 cpy_PORT , u8 cpy_PIN);                     //done
u8 GPIO_u8GetPortValue(u8 cpy_PORT);                                    //done




#endif /* GPIO_H_ */