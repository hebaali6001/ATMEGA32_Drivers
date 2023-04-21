/*
 * Lab1_Task1.c
 *
 * Created: 1/17/2023 10:15:01 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#include "DIO.h"
#include "LED.h"


int main(void)
{
	int i=0;
	DIO_tenuPins LED_arr[8]={DIO_enuPin0,DIO_enuPin1,DIO_enuPin2,DIO_enuPin3,DIO_enuPin4,DIO_enuPin5,DIO_enuPin6,DIO_enuPin7};
    while (1) 
    {
		for(i=0;i<8;i++){
			LEDenu_LEDON(LED_arr[i]);
			_delay_ms(5000);
			LEDenu_LEDOFF(LED_arr[i]);
		}
		for(i=7;i>=0;i--){
			LEDenu_LEDON(LED_arr[i]);
			_delay_ms(5000);
			LEDenu_LEDOFF(LED_arr[i]);
		}
		
    }
}

