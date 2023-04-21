#include "Stdtypes.h"
#include "Bitmath.h"
#include "DIO.h"
#include "DIO_Cfg.h"
#include "DIO_Prv.h"

#include <avr/io.h>





DIO_tenuErrorStatus DIO_enuInit(void)
{
	u8 i;
	
	
	u8 Loc_u8PortNumber;
	u8 Loc_u8PinNumber;
	for (i=0; i<DIO_enuNumberOfPins; i++)
	{
		Loc_u8PortNumber = i/8;
		Loc_u8PinNumber = i%8;
		
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				if (DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRA, Loc_u8PinNumber);
					CLR_BIT(PORTA, Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRA, Loc_u8PinNumber);
					if (DIO_strPinCfg[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PINA, Loc_u8PinNumber); //pull up(input and then write 1 to the port reg.)
					}
				}
				break;
				
			case(DIO_PORTB):
				if (DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRB, Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus == DIO_enuLow)
						CLR_BIT(PORTB, Loc_u8PinNumber);
					else
						SET_BIT(PORTB, Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRB, Loc_u8PinNumber);
					if (DIO_strPinCfg[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PINB, Loc_u8PinNumber);
					}
				}
				break;
			
			case(DIO_PORTC):
				if (DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRC, Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus == DIO_enuLow)
						CLR_BIT(PORTC, Loc_u8PinNumber);
					else
						SET_BIT(PORTC, Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRC, Loc_u8PinNumber);
					if (DIO_strPinCfg[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PINC, Loc_u8PinNumber);

					}
				}
				break;
			
			case(DIO_PORTD):
				if (DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRD, Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus == DIO_enuLow)
						CLR_BIT(PORTD, Loc_u8PinNumber);
					else
						SET_BIT(PORTD, Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRD, Loc_u8PinNumber);
					if (DIO_strPinCfg[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PIND, Loc_u8PinNumber);
					}
				}
				break;
		}
	}
	return DIO_enuOk;
}

DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber)
{
	
	u8 Loc_u8PortNumber;
	u8 Loc_u8PinNumber;

	Loc_u8PortNumber = Cpy_enuPinNumber/8;
	Loc_u8PinNumber = Cpy_enuPinNumber%8;
	DIO_tenuErrorStatus Loc_enuStatus = DIO_enuOk;
	if (Cpy_enuPinNumber > DIO_enuNumberOfPins) {
		Loc_enuStatus = DIO_enuNotOk;
	}
	else{
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				SET_BIT(PORTA, Loc_u8PinNumber);
				break;
				
			case(DIO_PORTB):
				SET_BIT(PORTB, Loc_u8PinNumber);
				break;
			
			case(DIO_PORTC):
				SET_BIT(PORTC, Loc_u8PinNumber);
				break;
			
			case(DIO_PORTD):
				SET_BIT(PORTD, Loc_u8PinNumber);
				break;
		}
	}
	return Loc_enuStatus;
}

DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber)
{
	
	u8 Loc_u8PortNumber;
	u8 Loc_u8PinNumber;

	Loc_u8PortNumber = Cpy_enuPinNumber/8;
	Loc_u8PinNumber = Cpy_enuPinNumber%8;
	DIO_tenuErrorStatus Loc_enuStatus = DIO_enuOk;
	if (Cpy_enuPinNumber > DIO_enuNumberOfPins) {
		Loc_enuStatus = DIO_enuNotOk;
	}
	else{
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				CLR_BIT(PORTA, Loc_u8PinNumber);
				break;
				
			case(DIO_PORTB):
				CLR_BIT(PORTB, Loc_u8PinNumber);
				break;
			
			case(DIO_PORTC):
				CLR_BIT(PORTC, Loc_u8PinNumber);
				break;
			
			case(DIO_PORTD):
				CLR_BIT(PORTD, Loc_u8PinNumber);
				break;
		}
	}
	return Loc_enuStatus;
}

DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber, u8 *Add_pu8PinValue)
{
	
	
	u8 Loc_u8PortNumber;
	u8 Loc_u8PinNumber;

	Loc_u8PortNumber = Cpy_enuPinNumber/8;
	Loc_u8PinNumber = Cpy_enuPinNumber%8;
	DIO_tenuErrorStatus Loc_enuStatus = DIO_enuOk;
	if (Cpy_enuPinNumber > DIO_enuNumberOfPins) {
		Loc_enuStatus = DIO_enuNotOk;
	}
	else{
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				*Add_pu8PinValue = GET_BIT(PINA, Loc_u8PinNumber);
				break;
				
			case(DIO_PORTB):
				*Add_pu8PinValue = GET_BIT(PINB, Loc_u8PinNumber);
				break;
			
			case(DIO_PORTC):
				*Add_pu8PinValue = GET_BIT(PINC, Loc_u8PinNumber);
				break;
			
			case(DIO_PORTD):
				*Add_pu8PinValue = GET_BIT(PIND, Loc_u8PinNumber);
				break;
		}
	}
	return Loc_enuStatus;
}

