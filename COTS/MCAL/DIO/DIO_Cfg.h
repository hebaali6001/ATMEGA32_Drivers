/********************************************/
/*		DIO Configuration file				*/
/********************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H
#include "Bitmath.h"
#include "DIO.h"


#define DIO_DIR_INPUT			0
#define DIO_DIR_OUTPUT			1

#define DIO_INPUT_PULL_UP		0
#define DIO_INPUT_PULL_DOWN		1

#define DIO_enuLow              0
#define DIO_enuHigh             1

typedef struct  
{
	u8 DIO_PinDirection;
	u8 DIO_InputStatus;
}DIO_strPinCfg_t;



const DIO_strPinCfg_t DIO_strPinCfg [32];



#endif /*DIO_CFG_H*/