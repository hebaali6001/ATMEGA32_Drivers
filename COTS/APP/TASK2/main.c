/*
* Lab1_Task2.c
*
* Created: 1/19/2023 6:41:17 AM
* Author : DELL
*/

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

#include "DIO.h"
#include "LED.h"
#include "Switch.h"



int main(void)
{
	u8 pin_valu1;
	u8 pin_valu2;
	u8 counter=0;
	int i=0;
	DIO_tenuPins LED_arr[8]={DIO_enuPin0,DIO_enuPin1,DIO_enuPin2,DIO_enuPin3,DIO_enuPin4,DIO_enuPin5,DIO_enuPin6,DIO_enuPin7};
	char boun_counter=0;
	
	DIO_enuInit();
	
	while (1) {
		SWITCH_enuGETSwitchValue(DIO_enuPin8,&pin_valu1);
		if(pin_valu1){
			
			LEDenu_LEDON(LED_arr[counter]);
			if(counter<8){
				counter++;	
			}
			
			while(pin_valu1){
				SWITCH_enuGETSwitchValue(DIO_enuPin8,&pin_valu1);
			}
		}
		

		SWITCH_enuGETSwitchValue(DIO_enuPin9,&pin_valu2);
		if(pin_valu2){	
			
			if(counter>0){
				counter--;
			}
			LEDenu_LEDOFF(LED_arr[counter]);
			while(pin_valu2){
				SWITCH_enuGETSwitchValue(DIO_enuPin9,&pin_valu2);
			}
		}
		
	}
}

