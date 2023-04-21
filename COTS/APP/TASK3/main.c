/*
 * task3 7-SEGMENT.c
 *
 * Created: 1/24/2023 9:44:03 PM
 * Author : DELL
 */ 

#define	 F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "7-SEG.h"
#include "DIO.h"
#include "LED.h"
#include "Stdtypes.h"

int main(void)
{
	
	 DIO_enuInit();
    while (1) 
    {
		for(int i=0;i<10;i++){
		SSEG_Display(1 ,i);
		_delay_ms(500);
		}
		/*
		PORTA |= ~0x5b;
		*//*
		DDRA=0xff;
		ASSIGN_REG(PORTA,~0x5b);
*/
    }
}

