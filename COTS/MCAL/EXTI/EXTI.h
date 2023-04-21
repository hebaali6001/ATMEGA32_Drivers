#ifndef EXTI_H
#define EXTI_H


#include "Bitmath.h"
#include "Stdtypes.h"
#include "ISR.h"



typedef enum {
	
	EXTI_Ok=0,
	EXTI_NotOk,
	EXTI_WrongConfig,
	
}EXTI_ErrorStatus;

typedef enum{
	
	EXTI_INT0 = 0,
	EXTI_INT1,
	EXTI_INT2,
	
}EXTI_Interrupt;


typedef enum{
	
	LOW_LEVEL=0b00000000,
	ANY_CHANGE,	
	FALLING_EDGE,
	RISING_EDGE,	
	
}EXTI_Sence;


EXTI_ErrorStatus ExtInterrupt_init(void);


EXTI_ErrorStatus ExtInterrupt_enbale (EXTI_Interrupt cpy_interruptNum );


EXTI_ErrorStatus ExtInterrupt_disable (EXTI_Interrupt cpy_interruptNum );


EXTI_ErrorStatus Set_CallBack(void(*ptr)(void),u8 index);











#endif /* EXTI_H */