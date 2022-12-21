
#include "Timers.h"

/***************** Timer0 ******************/

static void(*Fptr_T0_OV)(void)=NULLPTR;
static void(*Fptr_T0_OC)(void)=NULLPTR;


void Timer0_Init(Timer0_Mode_type mode,Timer0_Scaler_type scaler ,OCMode_type oc_mode)
{
	switch (scaler)
	{
		case TIMER0_STOP:
		CLEAR_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
		break;
		case TIMER0_SCALER_1:
		SET_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
		break;
		case TIMER0_SCALER_8:
		CLEAR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
		break;
		case TIMER0_SCALER_64:
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
		break;
		case TIMER0_SCALER_256:
		CLEAR_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		case TIMER0_SCALER_1024:
		SET_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		case EXTERNALl_FALLING:
		CLEAR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		case EXTERNAL_RISING:
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		default:
		CLEAR_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
		break;
		
	}
	switch (oc_mode)
	{
		case OCO_DISCONNECTED:
		CLEAR_BIT( TCCR0,COM00);
		CLEAR_BIT( TCCR0,COM01);
		break;
		case OCO_TOGGLE:
		SET_BIT( TCCR0,COM00);
		CLEAR_BIT( TCCR0,COM01);
		break;
		case OCO_NON_INVERTING:
		CLEAR_BIT( TCCR0,COM00);
		SET_BIT( TCCR0,COM01);
		break;
		case OCO_INVERTING:
		SET_BIT( TCCR0,COM00);
		SET_BIT( TCCR0,COM01);
		break;
		
	}
	switch (mode)
	{
		case TIMER0_NORMAL_MODE :
		CLEAR_BIT( TCCR0,WGM00);
		CLEAR_BIT( TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT( TCCR0,WGM00);
		CLEAR_BIT( TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLEAR_BIT( TCCR0,WGM00);
		SET_BIT( TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT( TCCR0,WGM00);
		SET_BIT( TCCR0,WGM01);
		break;
		default:
		CLEAR_BIT( TCCR0,WGM00);
		CLEAR_BIT( TCCR0,WGM01);
		break;
	}
}

void Timer0_StartFrom(u8 value)
{
    TCNT0 = value ;	
}

u8 Timer0_Read(void)
{
	return TCNT0 ;
}

void Timer0_End_at(u8 value)
{
	OCR0 = value;
}

void Timer0_PWM_Generate(u16 value)
{
	 OCR0 = ((value * 256) / 100 ) - 1;
	 
}


void Timer0_Interrupt(Timer_Interrtupt_type type,Interrupt_statue statue)
{
	switch(type)
	{
		case Overflow:
		switch(statue)
		{
			case Enable:
			SET_BIT(TIMSK, TOIE0);
			break;
			case Disable:
			CLEAR_BIT(TIMSK, TOIE0);
			break;
		}
		break;
		case CTC:
		switch(statue)
		{
			case Enable:
			SET_BIT(TIMSK,OCIE0);
			break;
			case Disable:
			CLEAR_BIT(TIMSK,OCIE0);
			break;
		}
		break;
	}
	
}
void Timer0_SetCallBack_Interrupt(Timer_Interrtupt_type type,void(*func)(void))
{
	switch(type)
	{
		case Overflow:
		Fptr_T0_OV = func;
		break;
		case CTC:
		Fptr_T0_OC = func;
		break;
	}
	
}
 
 ISR(TIMER0_OV)
 {
	 if (Fptr_T0_OV != NULLPTR)
	 {
		 Fptr_T0_OV();
	 }
 }
  
ISR(TIMER0_OC_vect)
{
	if (Fptr_T0_OC != NULLPTR)
	{
		Fptr_T0_OC();
	}	
}

/******************************************/

/***************** Timer1 ******************/

static void(*Fptr_T1_OV)(void)=NULLPTR;
static void(*Fptr_T1_OCA)(void)=NULLPTR;
static void(*Fptr_T1_OCB)(void)=NULLPTR;
static void(*Fptr_T1_ICU)(void)=NULLPTR;


void Timer1_Init(Timer1Mode_type mode,Timer1Scaler_type scaler)
{
	TCCR1B&=0XF8;       //0b11111000
	scaler=scaler&0x07;
	TCCR1B|=scaler;
	switch(mode)
	{
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case Timer1_FastPWM10_bit_Mode:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
	}
}

void Timer1_OCU_Init(OC1_Unit unit,OC1_Mode_type type)
{
	switch(unit)
	{
		case OC1A:
		switch(type)
		{
			case OCR_DISCONNECTED:
			CLEAR_BIT(TCCR1A,COM1A0);
			CLEAR_BIT(TCCR1A,COM1A1);
			break;
			case OCR_TOGGLE:
			SET_BIT(TCCR1A,COM1A0);
			CLEAR_BIT(TCCR1A,COM1A1);
			break;
			case OCR_NON_INVERTING:
			CLEAR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;
			case OCR_INVERTING:
			SET_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;
			
		}
		break;
		case OC1B:
		switch(type)
		{
			case OCR_DISCONNECTED:
			CLEAR_BIT(TCCR1A,COM1B0);
			CLEAR_BIT(TCCR1A,COM1B1);
			break;
			case OCR_TOGGLE:
			SET_BIT(TCCR1A,COM1B0);
			CLEAR_BIT(TCCR1A,COM1B1);
			break;
			case OCR_NON_INVERTING:
			CLEAR_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
			break;
			case OCR_INVERTING:
			SET_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
			break;
			
		}
		break;
		
	}
}

void Timer1_StartFrom(u16 value)
{
	TCNT1 = value;
}

u16 Timer1_Read(void)
{
	return TCNT1;
}

void Timer1_Interrupt(Timer1_Interrtupt_type type,Interrupt_statue statue)
{
	switch(type)
	{
		case Timer1_OverflowInterrupt:
		switch(statue)
		{
			case Enable:
			SET_BIT(TIMSK,TOIE1);
			break;
			case Disable:
			CLEAR_BIT(TIMSK,TOIE1);
			break;
		}
		break;
		case Timer1_InputCaptureInterrupt:
		switch(statue)
		{
			case Enable:
			SET_BIT(TIMSK,TICIE1);
			break;
			case Disable:
			CLEAR_BIT(TIMSK,TICIE1);
			break;
		}
		break;
		case Timer1_OutputCompareA_MatchInterrupt:
		switch(statue)
		{
			case Enable:
			SET_BIT(TIMSK, OCIE1A);
			break;
			case Disable:
			CLEAR_BIT(TIMSK, OCIE1A);
			break;
		}
		break;
		case Timer1_OutputCompareB_MatchInterrupt:
		switch(statue)
		{
			case Enable:
			SET_BIT(TIMSK, OCIE1B);
			break;
			case Disable:
			CLEAR_BIT(TIMSK, OCIE1B);
			break;
		}
		break;
		
	}
}
void Timer1_End_at(OC1_Unit unit,u16 value)
{
	switch(unit)
	{
		case OC1A:
		OCR1A = value;
		break;
		case OC1B:
		OCR1B = value;
		break;
	}
}

void Timer1_PWM_Generate(OC1_Unit unit,u16 value)
{
	switch(unit)
	{
		case OC1A :
		OCR1A = ((value * 256) / 100) - 1 ;
		break;
		case OC1B:
		OCR1B = ((value * 256) / 100) - 1 ;
		break;
		
	}
}

void Timer1_SetCallBack_Interrupt(Timer1_Interrtupt_type type,void(*func)(void))
{
	switch(type)
	{
		case Timer1_InputCaptureInterrupt:
		Fptr_T1_ICU = func;
		break;
		case Timer1_OutputCompareA_MatchInterrupt:
		Fptr_T1_OCA = func;
		break;
		case Timer1_OutputCompareB_MatchInterrupt:
		Fptr_T1_OCB = func;
		break;
		case Timer1_OverflowInterrupt:
		Fptr_T1_OV = func;
	}
}

ISR(TIMER1_ICU_vect)
{
	if (Fptr_T1_ICU != NULLPTR)
	{
		Fptr_T1_ICU();
	}
}
ISR(TIMER1_OCA_vect)
{
	if (Fptr_T1_OCA != NULLPTR)
	{
		Fptr_T1_OCA();
	}
}
ISR(TIMER1_OCB_vect)
{
	if (Fptr_T1_OCB != NULLPTR)
	{
		Fptr_T1_OCB();
	}
}
ISR(TIMER1_OVF_vect)
{
	if (Fptr_T1_OV != NULLPTR)
	{
		Fptr_T1_OV();
	}
}

/********************************************/

/************* Timer2 **********************/

static void(*Fptr_T2_OV)(void)=NULLPTR;
static void(*Fptr_T2_OC)(void)=NULLPTR;

void Timer2_Init(Timer2_Mode_type mode,Timer2_Scaler_type scaler,OCMode_type oc_mode)
{
	switch (scaler)
	{
		case TIMER2_STOP:
		CLEAR_BIT(TCCR2, CS20);
		CLEAR_BIT(TCCR2, CS21);
		CLEAR_BIT(TCCR2, CS22);
		break;
		case TIMER2_SCALER_1:
		SET_BIT(TCCR2, CS20);
		CLEAR_BIT(TCCR2, CS21);
		CLEAR_BIT(TCCR2, CS22);
		break;
		case TIMER2_SCALER_8:
		CLEAR_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLEAR_BIT(TCCR2, CS22);
		break;
		case TIMER2_SCALER_64:
		SET_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLEAR_BIT(TCCR2, CS22);
		break;
		case TIMER2_SCALER_256:
		CLEAR_BIT(TCCR2, CS20);
		CLEAR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
		break;
		case TIMER2_SCALER_1024:
		SET_BIT(TCCR2, CS20);
		CLEAR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
		break;
	}
		switch (oc_mode)
		{
			case OCO_DISCONNECTED:
			CLEAR_BIT( TCCR2,COM20);
			CLEAR_BIT( TCCR2,COM21);
			break;
			case OCO_TOGGLE:
			SET_BIT( TCCR2,COM20);
			CLEAR_BIT( TCCR2,COM21);
			break;
			case OCO_NON_INVERTING:
			CLEAR_BIT( TCCR2,COM20);
			SET_BIT( TCCR2,COM21);
			break;
			case OCO_INVERTING:
			SET_BIT( TCCR2,COM20);
			SET_BIT( TCCR2,COM21);
			break;	
		}
		switch (mode)
		{
			case TIMER2_NORMAL_MODE :
			CLEAR_BIT( TCCR2,WGM20);
			CLEAR_BIT( TCCR2,WGM21);
			break;
			case TIMER2_PHASECORRECT_MODE:
			SET_BIT( TCCR2,WGM20);
			CLEAR_BIT( TCCR2,WGM21);
			break;
			case TIMER2_CTC_MODE:
			CLEAR_BIT( TCCR2,WGM20);
			SET_BIT( TCCR2,WGM21);
			break;
			case TIMER2_FASTPWM_MODE:
			SET_BIT( TCCR2,WGM20);
			SET_BIT( TCCR2,WGM21);
			break;
			default:
			CLEAR_BIT( TCCR2,WGM20);
			CLEAR_BIT( TCCR2,WGM21);
			break;
		}
}

void Timer2_StartFrom(u8 value)
{
	 TCNT2 = value ;	
}

u8 Timer2_Read(void)
{
	return TCNT2 ;
	
}
void Timer2_End_at(u8 value)
{
	OCR2 = value;
}
void Timer2_PWM_Generate(u16 value)
{
	 OCR2 = ((value * 256) / 100 ) - 1;
}
void Timer2_Interrupt(Timer_Interrtupt_type type,Interrupt_statue statue)
{
	switch(type)
	{
		case Overflow:
		switch(statue)
		{
			case Enable:
			SET_BIT(TIMSK, TOIE2);
			break;
			case Disable:
			CLEAR_BIT(TIMSK, TOIE2);
			break;
		}
		break;
		case CTC:
		switch(statue)
		{
			case Enable:
			SET_BIT(TIMSK,OCIE2);
			break;
			case Disable:
			CLEAR_BIT(TIMSK,OCIE2);
			break;
		}
		break;
	}
}
void Timer2_SetCallBack_Interrupt(Timer_Interrtupt_type type,void(*func)(void))
{
	switch(type)
	{
		case Overflow:
		Fptr_T2_OV = func;
		break;
		case CTC:
		Fptr_T2_OC = func;
		break;
	}
}

ISR(TIMER2_OVF_vect)
{
	if (Fptr_T2_OV != NULLPTR)
	{
		Fptr_T2_OV();
	}
}

ISR(TIMER2_COMP_vect)
{
	if (Fptr_T2_OC != NULLPTR)
	{
		Fptr_T2_OC();
	}
}