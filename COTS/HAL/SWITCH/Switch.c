
#include "Switch.h"
#include "Switch_CFG.h"
#include "Switch_PIV.h"
#include "Bitmath.h"
#include "Stdtypes.h"
#include <util/delay.h>






SWITCH_ErrorStatus SWITCH_enuGETSwitchValue(Switch_tenuPins Cpy_enuPinNumber,u8* Add_pu8PinValue){
	int i,j,count=0;
	
	if(Cpy_enuPinNumber>Switch_enuNumberOfPins){
		return SWITCHenu_Invalid_PinNum;
		
		}else if((DIO_strPinCfg [Cpy_enuPinNumber].DIO_PinDirection)!=DIO_DIR_INPUT){
		return SWITCHenu_Wrong_PinDir;
	}
	
	for(j=0;j<Number_Of_Switshs;j++){
		if(Switch_Pins[j].SwitchPin_Num==Cpy_enuPinNumber){
			if(Switch_Pins[j].SwitchPin_State==Switch_enuPullup){
				for(i=0 ; i<5 ; i++){
					DIO_enuGetPin(Cpy_enuPinNumber,Add_pu8PinValue);
					if(*Add_pu8PinValue==0){
						count++;
						_delay_ms(50);
					}
				}
				if(count>=3){
					*Add_pu8PinValue=1;
					}else{
					*Add_pu8PinValue=0;
				}
				}else{
				for(i=0 ; i<5 ; i++){
					DIO_enuGetPin(Cpy_enuPinNumber,Add_pu8PinValue);
					if(*Add_pu8PinValue==1){
						count++;
						_delay_ms(50);
					}
				}
				if(count>=3){
					*Add_pu8PinValue=1;
					}else{
					*Add_pu8PinValue=0;
				}
			}
	    }
	}
	return SWITCHenu_OK;
}