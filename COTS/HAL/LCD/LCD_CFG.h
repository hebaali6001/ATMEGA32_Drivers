 #ifndef LCD_CFG_H
 #define LCD_CFG_H


#include <avr/io.h>
#include "DIO.h"



#define DATA	PORTD

#define RS		DIO_enuPin0
#define RW		DIO_enuPin1
#define EN		DIO_enuPin2


#define FIRST_LINE			0
#define SECOND_LINE			1





 #endif /*LCD_CFG_H*/