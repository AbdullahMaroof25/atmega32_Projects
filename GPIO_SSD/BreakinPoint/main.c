

#include "StdTypes.h"
#include "GPIO.h"
#include <util/delay.h>



u8 ssd_display_cat[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66,
                          0x6d, 0x7d, 0x07, 0x7f, 0x6f}; // common cathode
						  
#define  ssd_port       PC
#define  control_port   PORTD
#define  E1             PIN0
#define  E2             PIN1
#define  Button_Pin     PIN7
					  

int main(void)
{
	
	GPIO_voidSetPortDirection(ssd_port,0xff);
	GPIO_voidSetPortDirection(PD,0x0f);
	GPIO_voidSetPortValue(PD,0x0f);  
	
	u8 num = 0;
    while (1) 
    {
			 CLEAR_BIT(control_port,E1);
			 SET_BIT(control_port,E2);
			 GPIO_voidSetPortValue(ssd_port,ssd_display_cat[num%10]);
			 _delay_ms(1);
			 CLEAR_BIT(control_port,E2);
			 SET_BIT(control_port,E1);
			 GPIO_voidSetPortValue(ssd_port,ssd_display_cat[num/10]);
			 _delay_ms(1);
	
		if (GPIO_u8GetPortPinValue(PD,Button_Pin) == 0)
		{	
			num ++;
			if (num == 100)
			{
				num = 0;
			}
			while(GPIO_u8GetPortPinValue(PD,Button_Pin) == 0);
			
		}
	
    }
}
