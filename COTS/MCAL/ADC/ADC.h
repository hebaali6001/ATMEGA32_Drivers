 #ifndef ADC_H
 #define ADC_H
 
 #include <avr/io.h>
 #include "ADC_CFG.h"
 #include "Stdtypes.h"
 
 
 
 #define ADC_REF_MUSK			(0x3f)
 #define ADC_AUTO_TRIGGER_MUSK	(0xdf)
 #define ADC_INTERRUPT_EN_MUSK	(0xf7)
 #define ADC_ADJUST_RES_MUSK	(0xdf)
 #define ADC_CHANNEL_MUSK 		(0xe0)
 #define ADC_PRESCALLER_MUSK	(0xf8)
 
 
 typedef enum {
	 
	ADC_enuOK=0,
	ADC_enuNotOk,
	ADC_NullPtr,
	
 }ADC_tenuErrorStatus;
 
 
 typedef enum {
	 
	 ADC_enuChannel_0=0x00,
	 ADC_enuChannel_1=0x01,
	 ADC_enuChannel_2=0x02,
	 ADC_enuChannel_3=0x03,
	 ADC_enuChannel_4=0x04,
	 ADC_enuChannel_5=0x05,
	 ADC_enuChannel_6=0x06,
	 ADC_enuChannel_7=0x07,
	 
 }ADC_tenuChannelNumber;
 
 typedef enum {
	 ADC_enuFreeRunning 				= 0x00,
	 ADC_enuAnalogComparator 			= 0x20,
	 ADC_enuExternalInterrupt 			= 0x40,
	 ADC_enuTimer_Counter0_CompareMatch = 0x60,
	 ADC_enuTimer_Counter0_Overflow 	= 0x80,
	 ADC_enuTimer_Counter1_CompareMatch = 0xa0,
	 ADC_enuTimer_Counter1_Overflow 	= 0xc0,
	 ADC_enuTimer_Counter0_CuptureEvent = 0xe0,

 }ADC_tenuAutoTriggerSource;
 
 
 ADC_tenuErrorStatus ADC_enuInit(void);
 
 ADC_tenuErrorStatus ADC_enuGetValue(ADC_tenuChannelNumber cpy_ChannelNumber , u16* Add_pu16value); 		//Sync conversion start and wait for result
 
 ADC_tenuErrorStatus ADC_tenuStartAutoTrigger(ADC_tenuChannelNumber cpy_ChannelNumber , ADC_tenuAutoTriggerSource cpy_Source);		//if used ADC_interrupt should be enabled in itit Function
 
 
 
 
 
 
 
 #endif