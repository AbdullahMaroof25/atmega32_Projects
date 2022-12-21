

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "GPIO.h"
#include "StdTypes.h"

#define keypad_port     PB
#define first_out       PIN0
#define first_in        PIN4
#define default_key     '.'


u8 keyPad(void);



#endif /* KEYPAD_H_ */