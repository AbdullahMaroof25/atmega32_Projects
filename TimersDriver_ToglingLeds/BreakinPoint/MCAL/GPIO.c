
#include "GPIO.h"
#include "StdTypes.h"
#include "BitMath.h"


void GPIO_voidSetPortDirection (u8 cpy_PORT,u8 Value)
{
	switch(cpy_PORT)
	{
		case PA:
		DDRA=Value;
		break;
		case PB:
		DDRB=Value;
		break;
		case PC:
		DDRC=Value;
		break;
		case PD:
		DDRD=Value;
		break;
		default:
		break;
	}
	
}



void GPIO_voidSetPortPinValue (u8 cpy_PORT , u8 cpy_PIN , u8 cpy_value)
{
	switch(cpy_PORT)
	{
		case PA:
		if (cpy_value == HIGH)
		{
			SET_BIT(PORTA,cpy_PIN);
		}
		else
		{
			CLEAR_BIT(PORTA,cpy_PIN);
		}
		break;
		case PB:
		if (cpy_value == HIGH)
		{
			SET_BIT(PORTB,cpy_PIN);
		}
		else
		{
			CLEAR_BIT(PORTB,cpy_PIN);
		}
		break;
		case PC:
		if (cpy_value == HIGH)
		{
			SET_BIT(PORTC,cpy_PIN);
		}
		else
		{
			CLEAR_BIT(PORTC,cpy_PIN);
		}
		break;
		case PD:
		if (cpy_value == HIGH)
		{
			SET_BIT(PORTD,cpy_PIN);
		}
		else
		{
			CLEAR_BIT(PORTD,cpy_PIN);
		}
		break;
		default:
		break;
	}
}

void GPIO_voidSetPortPindirection (u8 cpy_PORT , u8 cpy_PIN , u8 cpy_direction)
{
	switch(cpy_PORT)
	{
		case PA:
		if ( cpy_direction == OUTPUT  )
		{
			SET_BIT(PORTA,cpy_PIN);
		}
		else
		{
			CLEAR_BIT(PORTA,cpy_PIN);
		}
		break;
		case PB:
		if ( cpy_direction == OUTPUT )
		{
			SET_BIT(PORTB,cpy_PIN);
		}
		else
		{
			CLEAR_BIT(PORTB,cpy_PIN);
		}
		break;
		case PC:
		if ( cpy_direction == OUTPUT )
		{
			SET_BIT(PORTC,cpy_PIN);
		}
		else
		{
			CLEAR_BIT(PORTC,cpy_PIN);
		}
		break;
		case PD:
		if ( cpy_direction == OUTPUT )
		{
			SET_BIT(PORTD,cpy_PIN);
		}
		else
		{
			CLEAR_BIT(PORTD,cpy_PIN);
		}
		break;
		default:
		break;
	}
}


void GPIO_voidSetPortValue(u8 cpy_PORT , u8 cpy_value)
{
	switch(cpy_PORT)
	{
		case PA:
		PORTA = cpy_value;
		break;
		case PB:
		PORTB=cpy_value;
		break;
		case PC:
		PORTC=cpy_value;
		break;
		case PD:
		PORTD=cpy_value;
		break;
		default:
		break;
	}
	
}

u8 GPIO_u8GetPortPinValue(u8 cpy_PORT , u8 cpy_PIN)
{
	u8 read = 0;
	switch(cpy_PORT)
	{
		case PA:
		read = READ_BIT(PINA,cpy_PIN);
		break;
		case PB:
		read = READ_BIT(PINB,cpy_PIN);
		break;
		case PC:
		read = READ_BIT(PINC,cpy_PIN);
		break;
		case PD:
		read = READ_BIT(PIND,cpy_PIN);
		break;
		default:
		break;
	}
	
	return read;
}

u8 GPIO_u8GetPortValue(u8 cpy_PORT)
{
	u8 read = 0;
	read = cpy_PORT;
	return read;
}

void GPIO_TogglePin(u8 cpy_PORT , u8 cpy_PIN )
{
	switch(cpy_PORT)
	{
		case PA:
		TOGGLE_BIT(PORTA,cpy_PIN);
		break;
		case PB:
		TOGGLE_BIT(PORTB,cpy_PIN);
		break;
		case PC:
		TOGGLE_BIT(PORTC,cpy_PIN);
		break;
		case PD:
		TOGGLE_BIT(PORTD,cpy_PIN);
		break;
	}
}