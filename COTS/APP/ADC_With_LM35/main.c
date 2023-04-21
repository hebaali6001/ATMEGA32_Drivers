/*
 * ADC_LM35.c
 *
 * Created: 2/18/2023 4:08:11 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "7-SEG.h"
#include "ADC.h"
#include "LM35.h"
#include "DIO.h"




int main(void)
{
   DIO_enuInit();
   ADC_enuInit();
   
   u16 temprture=10;
   
    while (1) 
    {
		LM_ReadTemp_c(ADC_enuChannel_0,&temprture);
		
		SSEG_Display(1 , temprture%10);
		SSEG_Display(2 , temprture/10);
		
    }
}

