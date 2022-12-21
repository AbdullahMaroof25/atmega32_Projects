
#include "ADC.h"

static void(*fptr_ADC)(void) = NULLPTR;



void ADC_Init(ADC_Vref_Type vref,ADC_Scaler_Type scaler)
{
		switch (vref)
		{
			case VREF_AVCC:
			SET_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
			case VREF_AREF:
			CLEAR_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
			case VREF_256:
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;
		}
			
		ADCSRA=ADCSRA&0xf8;
		scaler=scaler&0x07;
		ADCSRA=ADCSRA|scaler;

		CLEAR_BIT(ADMUX,ADLAR);
		SET_BIT(ADCSRA,ADEN);
}

u16 ADC_Read(ADC_Channel_Type ch)
{
	ADMUX=ADMUX&0xE0;
	ADMUX=ADMUX|ch;

	SET_BIT(ADCSRA,ADSC);

	while(READ_BIT(ADCSRA,ADSC));   
	
	
	return ADC_result;
}


void ADC_Interrupt(Interrupt_statue statue)
{
	switch(statue)
	{
		case Enable:
		SET_BIT( ADCSRA,ADIE);
		break;
		case Disable:
		CLEAR_BIT( ADCSRA,ADIE);
		break;
	}
}

void ADC_SetCallBack(void(*func)(void))
{
	fptr_ADC = func ;
	
}


ISR(ADC_vect)
{
	if (fptr_ADC != NULLPTR)
	{
		fptr_ADC();
	}
}


u16 TEMP_Read(ADC_Channel_Type ch)
{
	u16 adc=ADC_Read(ch);
	u16 volt=((u32)5000*adc)/1024;
	u16 temp=volt/10;
	return temp;
}