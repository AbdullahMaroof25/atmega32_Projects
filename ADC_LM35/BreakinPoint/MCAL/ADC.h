

#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "BitMath.h"
#include "StdTypes.h"

typedef enum{
	
	VREF_AVCC,
	VREF_AREF,
	VREF_256
	
}ADC_Vref_Type;

typedef enum{
	
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	
}ADC_Scaler_Type;

typedef enum {
	ch_0=0,
	ch_1,
	ch_2,
	ch_3,
	ch_4,
	ch_5,
	ch_6,
	ch_7
	
}ADC_Channel_Type;

void ADC_Init(ADC_Vref_Type vref,ADC_Scaler_Type scaler);
u16 ADC_Read(ADC_Channel_Type ch);
void ADC_Interrupt(Interrupt_statue statue);
void ADC_SetCallBack(void(*func)(void));

u16 TEMP_Read(ADC_Channel_Type ch);

#endif /* ADC_H_ */