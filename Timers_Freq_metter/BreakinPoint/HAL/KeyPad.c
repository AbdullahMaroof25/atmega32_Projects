
#include "KeyPad.h"
static u8 keys_array[4][4]={{'7','8','9','/'},
                            {'4','5','6','*'},
                            {'1','2','3','-'},
                            {'c','0','=','+'}};
	
	
u8 keyPad(void)	
{
	u8 row,col,key=default_key;
	
	GPIO_voidSetPortPinValue(keypad_port,first_out,HIGH);
	GPIO_voidSetPortPinValue(keypad_port,first_out+1,HIGH);
	GPIO_voidSetPortPinValue(keypad_port,first_out+2,HIGH);
	GPIO_voidSetPortPinValue(keypad_port,first_out+3,HIGH);
	
	for(row=0;row<4;row++)
	{
		GPIO_voidSetPortPinValue(keypad_port,first_out+row,LOW);
		for(col=0;col<4;col++)
		{
			if (GPIO_u8GetPortPinValue(keypad_port,first_in+col) == LOW)
			{
				key = keys_array[row][col];
				while(GPIO_u8GetPortPinValue(keypad_port,first_in+col) == LOW);
			}
			
			
		}
		GPIO_voidSetPortPinValue(keypad_port,first_out+row,HIGH);
		
	}
	return key;
}