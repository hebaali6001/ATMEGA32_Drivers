/*
* LCD_Driver_test.c
*
* Created: 2/10/2023 12:17:53 PM
* Author : DELL
*/

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "Switch.h"

int main(void)
{
	
	DIO_enuInit();
	LCD_vidInit();
	
	u8 H_char [] = { 0b00000, 0b01111, 0b01001, 0b00111, 0b00101, 0b11111, 0b00000, 0b00000 };
	u8 B_char [] = { 0b00000, 0b00000, 0b00000, 0b00100, 0b00100, 0b11111, 0b00100, 0b00000 };
	u8 A_char [] = { 0b00000, 0b00000, 0b11100, 0b10100, 0b11100, 0b00111, 0b00000, 0b00000 };
	
	u8 pinx_value1, pinx_value2, piny_value;
	u8 x =0;  /* 0 - 13 */
	u8 y =0;  /* 0 - 1 */
	
	LCD_enuSendCommand(CLEAR_DISPLAY);

	while (1)
	{
		
		
		_delay_ms(50);
		SWITCH_enuGETSwitchValue(Switch_enuPin3,&pinx_value1);
		if(pinx_value1){
			if(x<13){
				x++;
			}
			while(pinx_value1){
				SWITCH_enuGETSwitchValue(Switch_enuPin3,&pinx_value1);
			}
		}
	
	
	SWITCH_enuGETSwitchValue(Switch_enuPin4,&pinx_value2);
	if(pinx_value2){
		if(x>0){
			x--;
		}
		while(pinx_value2){
			SWITCH_enuGETSwitchValue(Switch_enuPin4,&pinx_value2);
		}
	}
	
	SWITCH_enuGETSwitchValue(Switch_enuPin5,&piny_value);
	if(piny_value){
		if(y==0){
			y=1;
			}else if(y==1){
			y=0;
		}
		while(piny_value){
			SWITCH_enuGETSwitchValue(Switch_enuPin5,&piny_value);
		}
	}
	
	LCD_enuSendCommand(CLEAR_DISPLAY);
	LCD_enuWriteSpecialPattern  (H_char, 1, y, x+2);
	LCD_enuWriteSpecialPattern  (B_char, 2, y, x+1);
	LCD_enuWriteSpecialPattern  (A_char, 3, y, x+0);
}
}



