/***************************************
DIO Header FILE

****************************************/
#ifndef LED_H
#define LED_H
#include "DIO.h"
#include "LED_CFG.h"



typedef enum{
	LED_enuForword,
	LED_enuBackword	
}LEDenu_ConectionDIR;

typedef enum{

	LEDenu_OK,
	LEDenu_NotOK,
	LEDenu_WrongDiriction,
	LEDenu_WrongMood
}LED_ErrorStatus;


LED_ErrorStatus LEDenu_LEDON(LED_tenuPins Cpy_enuPinNumber);


LED_ErrorStatus LEDenu_LEDOFF(LED_tenuPins Cpy_enuPinNumber);


#endif /*LED_H*/

/*
,LED_enuPinMode cpy_enuPinMode
*/