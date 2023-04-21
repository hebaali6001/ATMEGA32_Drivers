

#include "7-SEG.h"
#include "Bitmath.h"
//#define F_CPU 8000000UL
#include <avr/io.h>



extern const int SSEG_Display_Number_Array[];
extern const int SSEG_Display_Alpha_Array[];

SSEG_ErrorStatus SSEG_Display(u8 SSEG_cpynumber ,u8 cpyNumber){
	
	if(SSEG_Array[SSEG_cpynumber-1].Active_State==SSEG_enuCommonCathode){
		
		if(SSEG_Array[SSEG_cpynumber-1].Port_Number==SSEG_enuPortA){
			
			PORTA &=0x00;
			ASSIGN_REG(PORTA, SSEG_Display_Number_Array[cpyNumber]);
			
			}else if(SSEG_Array[SSEG_cpynumber-1].Port_Number==SSEG_enuPortB){
			
			PORTB &=0x00;
			ASSIGN_REG(PORTB, SSEG_Display_Number_Array[cpyNumber]);
			
			}else if(SSEG_Array[SSEG_cpynumber-1].Port_Number==SSEG_enuPortC){

			PORTC &=0x00;
			ASSIGN_REG(PORTC, SSEG_Display_Number_Array[cpyNumber]);
			
			}else if(SSEG_Array[SSEG_cpynumber-1].Port_Number==SSEG_enuPortD){

			PORTD &=0x00;
			ASSIGN_REG(PORTD, SSEG_Display_Number_Array[cpyNumber]);
			
		}
	}else{
		
		if(SSEG_Array[SSEG_cpynumber-1].Port_Number==SSEG_enuPortA){

			PORTA &=0x00;
			ASSIGN_REG(PORTA, ~SSEG_Display_Number_Array[cpyNumber]);
			
			}else if(SSEG_Array[SSEG_cpynumber-1].Port_Number==SSEG_enuPortB){
			
			PORTB &=0x00;
			ASSIGN_REG(PORTB, ~SSEG_Display_Number_Array[cpyNumber]);
			
			}else if(SSEG_Array[SSEG_cpynumber-1].Port_Number==SSEG_enuPortC){
			
			PORTC &=0x00;
			ASSIGN_REG(PORTC, ~SSEG_Display_Number_Array[cpyNumber]);
			
			}else if(SSEG_Array[SSEG_cpynumber-1].Port_Number==SSEG_enuPortD){

			PORTD &=0x00;
			ASSIGN_REG(PORTD, ~SSEG_Display_Number_Array[cpyNumber]);
			
		}
		
	}
	
	
	return SSEGenu_OK;
}