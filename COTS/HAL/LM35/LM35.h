 
 #ifndef LM35_H
 #define LM35_H
 
 #include "LM35_CFG.h"
 #include "LM35_PRV.h"
 #include "ADC.h"
 
 
 typedef enum{
	 
	 LM_enuOk = 0,
	 LM_enuNotOk,
	 
	 }LM_enuErrorStatus;
 
 
 
 LM_enuErrorStatus LM_ReadTemp_F(ADC_tenuChannelNumber ChannelNum,u16* AddTempResult);
 LM_enuErrorStatus LM_ReadTemp_c(ADC_tenuChannelNumber ChannelNum,u16* AddTempResult);
 
 
 

 
 #endif /*LM35_H*/