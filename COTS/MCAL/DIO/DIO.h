/********************************************/
/*				DIO file					*/
/********************************************/
#ifndef DIO_H
#define DIO_H
#include "Stdtypes.h"
#include "Bitmath.h"
#include "DIO_Cfg.h"


/*
#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3
*/

typedef enum
{
	DIO_enuOk = 0,  //DIO_enuOk,
	DIO_enuNotOk,
	DIO_enuNullPtr
}DIO_tenuErrorStatus;


typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DIO_tenuPorts;

/*
typedef enum
{
	DIO_enuLow = 0,
	DIO_enuHigh
}DIO_tenuPinValue;
*/

typedef enum
{
	DIO_enuPin0 = 0,
	DIO_enuPin1,
	DIO_enuPin2,
	DIO_enuPin3,
	DIO_enuPin4,
	DIO_enuPin5,
	DIO_enuPin6,
	DIO_enuPin7,
	DIO_enuPin8,
	DIO_enuPin9,
	DIO_enuPin10,
	DIO_enuPin11,
	DIO_enuPin12,
	DIO_enuPin13,
	DIO_enuPin14,
	DIO_enuPin15,
	DIO_enuPin16,
	DIO_enuPin17,
	DIO_enuPin18,
	DIO_enuPin19,
	DIO_enuPin20,
	DIO_enuPin21,
	DIO_enuPin22,
	DIO_enuPin23,
	DIO_enuPin24,
	DIO_enuPin25,
	DIO_enuPin26,
	DIO_enuPin27,
	DIO_enuPin28,
	DIO_enuPin29,
	DIO_enuPin30,
	DIO_enuPin31,
	DIO_enuNumberOfPins,
}DIO_tenuPins;






/********************************************/
/*DIO Init function				
  Input Void
  Output: DIO_tenuErrorStatus to report error*/
/********************************************/
DIO_tenuErrorStatus DIO_enuInit(void);

/********************************************/
/*DIO Set Pin function				
  Input pin number (Range from 0 - 31)
  Output: DIO_tenuErrorStatus to report error*/
/********************************************/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber);

/********************************************/
/*DIO Clear Pin function				
  Input pin number (Range from 0 - 31)
  Output: DIO_tenuErrorStatus to report error*/
/********************************************/
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber);

/********************************************/
/*DIO Get Pin function				
  Input pin number (Range from 0 - 31)
  Output: DIO_tenuErrorStatus to report error*/
/********************************************/
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber,u8* Add_pu8PinValue);


#endif /*DIO_H*/