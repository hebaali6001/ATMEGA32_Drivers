/*****************************************************************************/
/*DIO Configuration file                                                     */
/*****************************************************************************/

#ifndef LED_CFG_H
#define LED_CFG_H


#define LED_NumberOfLeds 8

typedef enum
{
	LED_enuPin0 = 0,
	LED_enuPin1,
	LED_enuPin2,
	LED_enuPin3,
	LED_enuPin4,
	LED_enuPin5,
	LED_enuPin6,
	LED_enuPin7,
	LED_enuPin8,
	LED_enuPin9,
	LED_enuPin10,
	LED_enuPin11,
	LED_enuPin12,
	LED_enuPin13,
	LED_enuPin14,
	LED_enuPin15,
	LED_enuPin16,
	LED_enuPin17,
	LED_enuPin18,
	LED_enuPin19,
	LED_enuPin20,
	LED_enuPin21,
	LED_enuPin22,
	LED_enuPin23,
	LED_enuPin24,
	LED_enuPin25,
	LED_enuPin26,
	LED_enuPin27,
	LED_enuPin28,
	LED_enuPin29,
	LED_enuPin30,
	LED_enuPin31,
	LED_enuNumberOfPins,
}LED_tenuPins;



typedef enum{
	LED_enuActiveLow,
	LED_enuActiveHigh
}LED_enuPinMode;


typedef struct
{
	LED_tenuPins LED_PinNumner;
	LED_enuPinMode LED_PinMood;
}LED_strPinCfg_t;


const LED_strPinCfg_t LED_strPinCfg [LED_NumberOfLeds];

#endif /*LED_CGF_H*/