 #ifndef ADC_CFG_H
 #define ADC_CFG_H
 
 
 
/*********************************************************************************************/ 
							/*Source Reference*/
							
 #define ADC_REF_SOURCE_SELECTION			ADE_AVCC
 // Select one of these:
 #define ADC_AREF							(0x00) //lma negy nsht3`l behom hn7tag n3mlhom shift 3shan kda hml #define musk ely t7t d // aw kont mn l awl 3mlt kda 0b00 00000 we 0b 01 00000 3shan ana msh hammni l 5-bits ely awlneen we ana kda kda h 3ml OR ll rqm da fa a5ehom zero bs da msh a7sn 7aga fe l debugging 
 #define ADE_AVCC							(0x01)
 #define ADC_INTERNAL_256					(0x03)
  			 
/********************************************************************************************/ 



/********************************************************************************************/ 
							/*Enable ADC Module*/
							
 #define ADC_INTERRUPT_ENABLE				ADC_DISABLE
 // Select one of these:
 #define ADC_ENABLE							1
 #define ADC_DISABLE						0
/********************************************************************************************/



/********************************************************************************************/
							/*Auto Trigger source*/
							
 #define ADC_AUTO_TRIGGER					ADC_AT_DISABLE
  // Select one of these:
 #define ADC_AT_ENABLE						1
 #define ADC_AT_DISABLE						0
 /*******************************************************************************************/
 
 
 
 /*******************************************************************************************/
							/*ADC Prescaller Selection*/
							
 #define ADC_PRESCALLER_SELECTION 			ADC_PRESCALLER_DIV_2  
 // Select one of these:
 #define ADC_PRESCALLER_DIV_2				(0x00)  		
 #define ADC_PRESCALLER_DIV_4				(0x02)
 #define ADC_PRESCALLER_DIV_8       		(0x03)
 #define ADC_PRESCALLER_DIV_16      		(0x04)
 #define ADC_PRESCALLER_DIV_32      		(0x05)
 #define ADC_PRESCALLER_DIV_64      		(0x06)
 #define ADC_PRESCALLER_DIV_128				(0x07)
 /*******************************************************************************************/
 
 
 
/********************************************************************************************/ 
							/*ADC Prescaller Selection*/
							 
 #define ADC_ADJUST_RESULT					ADC_ADJUST_LEFT
  // Select one of these:
 #define ADC_ADJUST_RIGHT					0
 #define ADC_ADJUST_LEFT					1
 /*******************************************************************************************/
 
 
 #endif /* ADC_CFG_H */