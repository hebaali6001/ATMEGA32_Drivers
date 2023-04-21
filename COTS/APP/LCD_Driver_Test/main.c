 /*
 * LCD_Driver_test.c
 *
 * Created: 2/10/2023 12:17:53 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"

int main(void)
{
	
	DIO_enuInit();
	LCD_vidInit();


    while (1) 
    {
				
		LCD_enuGotoXY(FIRST_LINE,0);
		LCD_enuWriteNumber(-1615);


		LCD_enuGotoXY(FIRST_LINE,8);
		LCD_enuWriteChar ('H');

		LCD_enuGotoXY(SECOND_LINE,8);
		LCD_enuWriteString  ("HEBA");
		_delay_ms(2000)	;
		LCD_enuSendCommand(CLEAR_DISPLAY);
		
		
    }
}



