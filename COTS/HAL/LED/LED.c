/***************************************
DIO INTEREFACE FILE

****************************************/

#include "LED.h"
#include "LED_CFG.h"
#include "LED_PIV.h"
#include "Bitmath.h"
#include "Stdtypes.h"


LED_ErrorStatus LED_Init(void)
{
	DIO_enuInit();	
	return LEDenu_OK;
}

LED_ErrorStatus LEDenu_LEDON(LED_tenuPins Cpy_enuPinNumber)
{
	if(LED_strPinCfg [Cpy_enuPinNumber].LED_PinMood == LED_enuActiveHigh)
	{
		DIO_enuSetPin(Cpy_enuPinNumber);
	}else{
		DIO_enuClearPin(Cpy_enuPinNumber);
	}
	return LEDenu_OK;
}


LED_ErrorStatus LEDenu_LEDOFF(LED_tenuPins Cpy_enuPinNumber)
{
	if(LED_strPinCfg [Cpy_enuPinNumber].LED_PinMood == LED_enuActiveHigh)
	{
		DIO_enuClearPin(Cpy_enuPinNumber);
	}else{
		DIO_enuSetPin(Cpy_enuPinNumber);
	}
	return LEDenu_OK;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     