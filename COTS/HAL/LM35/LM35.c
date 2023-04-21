
#include "LM35.h"



LM_enuErrorStatus LM_ReadTemp_F(ADC_tenuChannelNumber ChannelNum,u16* AddTempResult){

	u16 loc_adcresult;
	
	ADC_enuGetValue(ChannelNum , &loc_adcresult);
	//*AddTempResult = loc_adcresult *5/1023/10;
	
	return LM_enuOk;
}

LM_enuErrorStatus LM_ReadTemp_c(ADC_tenuChannelNumber ChannelNum,u16* AddTempResult){

	u16 loc_adcresult;
	
	ADC_enuGetValue(ChannelNum , &loc_adcresult);
	*AddTempResult = (loc_adcresult *155 /1023);
	
	return LM_enuOk;
} 