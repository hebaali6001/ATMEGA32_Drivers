/*
* task4 7-SEGMENT.c
*
* Created: 1/29/2023 11:05:25 AM
* Author : DELL
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "7-SEG.h"
#include "DIO.h"
#include "Switch.h"


int main(void)
{
	u8 counter=0;
	u8 pin1_value,pin2_value;
	
	DIO_enuInit();

	while (1)
	{
		
		SWITCH_enuGETSwitchValue(Switch_enuPin16,&pin1_value);
		if(pin1_value){
			if(counter<99){
				counter++;
			}
			while(pin1_value){
				SWITCH_enuGETSwitchValue(Switch_enuPin16,&pin1_value);
			}
		}
		
		SWITCH_enuGETSwitchValue(Switch_enuPin17,&pin2_value);
		if(pin2_value){
			if(counter>0){
				counter--;
			}
			while(pin2_value){
				SWITCH_enuGETSwitchValue(Switch_enuPin17,&pin2_value);
			}
		}
		
		SSEG_Display(1,counter%10);
		SSEG_Display(2,counter/10);
		
	}
}
