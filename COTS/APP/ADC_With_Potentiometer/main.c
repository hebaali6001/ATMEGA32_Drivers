/*
* ADC_7-seg_with_potonchometer.c
*
* Created: 2/9/2023 5:33:11 AM
* Author : DELL
*/

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO.h"
#include "7-SEG.h"
#include "ADC.h"


int main(void)
{
	u16 adcResult, result;
	DIO_enuInit();
	ADC_enuInit();
	while (1)
	{
		ADC_enuGetValue(ADC_enuChannel_0 , &adcResult);

		result = (adcResult*50 /1023 * 99/50);
		
		SSEG_Display(1 , result%10);
		SSEG_Display(2 , result/10);

		//_delay_ms(200);
	}
}

