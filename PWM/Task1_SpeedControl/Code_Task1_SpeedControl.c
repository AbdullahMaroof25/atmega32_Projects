

#include "StdTypes.h"
#include "GPIO.h"
#include "Timers.h"
#include "EXT_INT.h"




int main(void)
{
	GPIO_voidSetPortDirection(PB,0xff);
	EXT_voidInitGlobalInterrupts();
	Timer0_PWM_Generate(25);
	Timer0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8,OCO_NON_INVERTING);
	
	

    while (1) 
    {
	}
		
}



