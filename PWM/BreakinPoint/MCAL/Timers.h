

#ifndef TIMERS_H_
#define TIMERS_H_

#include "BitMath.h"
#include "StdTypes.h"
#include "MemMap.h"

typedef enum
{
	Enable=0,
	Disable
}Interrupt_statue;


/****************** Timer0 *************/
typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer0_Scaler_type;

typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0_Mode_type;
typedef enum
{
	OCO_DISCONNECTED=0,
	OCO_TOGGLE,
	OCO_NON_INVERTING,
	OCO_INVERTING

}OCMode_type;

typedef enum
{
	Overflow,
	CTC
}Timer_Interrtupt_type;

 void Timer0_Init(Timer0_Mode_type mode,Timer0_Scaler_type scaler,OCMode_type oc_mode); //done
 void Timer0_StartFrom(u8 value);//done
 u8 Timer0_Read(void);//done
 void Timer0_End_at(u8 value); //done
 void Timer0_PWM_Generate(u16 value);
 void Timer0_Interrupt(Timer_Interrtupt_type type,Interrupt_statue statue);//done
 void Timer0_SetCallBack_Interrupt(Timer_Interrtupt_type type,void(*func)(void));//done

/****************** Timer1 *************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL1_FALLING,
	EXTERNAL1_RISING
}Timer1Scaler_type;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE,
	Timer1_FastPWM10_bit_Mode

}Timer1Mode_type;

typedef enum
{
	OC1A,
	OC1B
	
}OC1_Unit;

typedef enum
{
	OCR_DISCONNECTED=0,
	OCR_TOGGLE,
	OCR_NON_INVERTING,
	OCR_INVERTING

}OC1_Mode_type;

typedef enum
{
	Timer1_InputCaptureInterrupt,
	Timer1_OutputCompareA_MatchInterrupt,
	Timer1_OutputCompareB_MatchInterrupt, 
	Timer1_OverflowInterrupt
	
}Timer1_Interrtupt_type;

void Timer1_Init(Timer1Mode_type mode,Timer1Scaler_type scaler); //done
void Timer1_OCU_Init(OC1_Unit unit,OC1_Mode_type type); //done
void Timer1_StartFrom(u16 value); //done
u16 Timer1_Read(void);  //done
void Timer1_End_at(OC1_Unit unit,u16 value); //done
void Timer1_PWM_Generate(OC1_Unit unit,u16 value);
void Timer1_Interrupt(Timer1_Interrtupt_type type,Interrupt_statue statue); //done
void Timer1_SetCallBack_Interrupt(Timer1_Interrtupt_type type,void(*func)(void)); //done

/****************** Timer2 *************/

typedef enum{
	TIMER2_STOP=0,
	TIMER2_SCALER_1,
	TIMER2_SCALER_8,
	TIMER2_SCALER_64,
	TIMER2_SCALER_256,
	TIMER2_SCALER_1024
}Timer2_Scaler_type;

typedef enum
{
	TIMER2_NORMAL_MODE=0,
	TIMER2_PHASECORRECT_MODE,
	TIMER2_CTC_MODE,
	TIMER2_FASTPWM_MODE

}Timer2_Mode_type;


void Timer2_Init(Timer2_Mode_type mode,Timer2_Scaler_type scaler,OCMode_type oc_mode); //done
void Timer2_StartFrom(u8 value);//done
u8 Timer2_Read(void);//done
void Timer2_End_at(u8 value); //done
void Timer2_PWM_Generate(u16 value);
void Timer2_Interrupt(Timer_Interrtupt_type type,Interrupt_statue statue);//done
void Timer2_SetCallBack_Interrupt(Timer_Interrtupt_type type,void(*func)(void));//done

/************************************************/





#endif /* TIMERS_H_ */