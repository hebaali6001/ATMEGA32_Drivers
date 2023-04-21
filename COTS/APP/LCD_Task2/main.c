 /*
* LCD_Driver_test.c
*
* Created: 2/10/2023 12:17:53 PM
* Author : DELL
*/

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "Switch.h"

int main(void)
{
	
	DIO_enuInit();
	LCD_vidInit();
	
	u8 R_char [] = { 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001 };
	u8 L_char [] = { 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000};
	u8 ball_1_char [] = { 0b11100, 0b11100, 0b11100, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000 };
	u8 ball_2_char [] = { 0b00000, 0b00000, 0b01110, 0b01110, 0b01110, 0b00000, 0b00000, 0b00000 };
	u8 ball_3_char [] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00111, 0b00111, 0b00111 };
	u8* balls[4] ={ball_1_char,ball_2_char,ball_3_char,ball_2_char};
	u8 i=0;
	u8 pinx_value1, pinx_value2, piny_value;
	u8 xR =15, xL=0, xball=0;      /* 0 - 13 */
	u8 yR =0, yL=0, yball=0;       /* 0 - 1 */
	
	
	LCD_enuSendCommand(CLEAR_DISPLAY);

	while (1)
	{
		
		for(xball=0;xball<15;xball++)
		{
			_delay_ms(50);
			SWITCH_enuGETSwitchValue(Switch_enuPin3,&pinx_value1);
			if(pinx_value1){
				if(yR==0){
					yR=1;
					}else if(yR==1){
					yR=0;
				}
				while(pinx_value1){
					SWITCH_enuGETSwitchValue(Switch_enuPin3,&pinx_value1);
				}
			}
			
			SWITCH_enuGETSwitchValue(Switch_enuPin4,&pinx_value2);
			if(pinx_value2){
				if(yL==0){
					yL=1;
					}else if(yL==1){
					yL=0;
				}
				while(pinx_value2){
					SWITCH_enuGETSwitchValue(Switch_enuPin4,&pinx_value2);
				}
			}
			
			LCD_enuSendCommand(CLEAR_DISPLAY);

			LCD_enuWriteSpecialPattern  (R_char, 1, yR, xR);
			LCD_enuWriteSpecialPattern  (L_char, 2, yL, xL);
			
			i++;
			if(i>3){
				if(yball==0){
					yball=1;
					}else{
					yball=0;
				}
				i=0;
			}
			LCD_enuWriteSpecialPattern  (balls[i], 3, yball,xball);
		}
		
		for(xball=15;xball>0;xball--)
		{
			_delay_ms(50);
			SWITCH_enuGETSwitchValue(Switch_enuPin3,&pinx_value1);
			if(pinx_value1){
				if(yR==0){
					yR=1;
					}else if(yR==1){
					yR=0;
				}
				while(pinx_value1){
					SWITCH_enuGETSwitchValue(Switch_enuPin3,&pinx_value1);
				}
				
			}
			SWITCH_enuGETSwitchValue(Switch_enuPin4,&pinx_value2);
			if(pinx_value2){
				if(yL==0){
					yL=1;
					}else if(yL==1){
					yL=0;
				}
				while(pinx_value2){
					SWITCH_enuGETSwitchValue(Switch_enuPin4,&pinx_value2);
				}
			}
			
			LCD_enuSendCommand(CLEAR_DISPLAY);

			LCD_enuWriteSpecialPattern  (R_char, 1, yR, xR);
			LCD_enuWriteSpecialPattern  (L_char, 2, yL, xL);
			
			i++;
			if(i>3){
				if(yball==0){
					yball=1;
				}else{
					yball=0;
				}
				i=0;
			}
			LCD_enuWriteSpecialPattern  (balls[i], 3, yball,xball);
			
		}
		
	}
}
