#ifndef SWITCH_H
#define SWITCH_H
#include "DIO.h"
#include "Switch_cfg.h"
#include "Switch_piv.h"



typedef enum{

	SWITCHenu_OK,
	SWITCHenu_NotOK,
	SWITCHenu_Invalid_PinNum,
	SWITCHenu_Wrong_PinDir,
}SWITCH_ErrorStatus;



SWITCH_ErrorStatus SWITCH_enuGETSwitchValue(Switch_tenuPins Cpy_enuPinNumber,u8* Add_pu8PinValue);

#endif /*SWITCH_H*/