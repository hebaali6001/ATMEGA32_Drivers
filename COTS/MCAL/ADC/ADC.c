

#include "ADC.h" 

//#include "AVR_ISR.h"

  
   ADC_tenuErrorStatus ADC_enuInit(void){
	   
	   /*ADC Reference configuration*/
	   ADMUX &= ADC_REF_MUSK;
	   ADMUX |= (ADC_REF_SOURCE_SELECTION<<6);
	   
	   
	   /* ADC Enable/Disable Auto Trigger */
	   ADCSRA &= ADC_AUTO_TRIGGER_MUSK;
	   ADCSRA |= (ADC_AUTO_TRIGGER<<5);
	   
	   /* ADC Enable/Disable Interrupt */
	   ADCSRA &= ADC_INTERRUPT_EN_MUSK;
	   ADCSRA |= (ADC_INTERRUPT_ENABLE<<3);
	   
	   /* ADC Prescaller Selection */
	   ADCSRA &= ADC_PRESCALLER_MUSK;
	   ADCSRA |= ADC_PRESCALLER_SELECTION;
	   
	   /* ADC Enable/Disable Right Adjust */
		ADMUX &= ADC_ADJUST_RES_MUSK;
		ADMUX |= ADC_ADJUST_RESULT<<5;
		
	   /* ADC_module Enable */
		ADCSRA |= 0x80;
		
		return ADC_enuOK;
   }
   
   
   
    ADC_tenuErrorStatus ADC_enuGetValue(ADC_tenuChannelNumber cpy_ChannelNumber , u16* Add_pu16value){
		
		/* Set the needed Channel */
		u8 admux_var = ADMUX;
		admux_var &= ADC_CHANNEL_MUSK;
		admux_var |= cpy_ChannelNumber;
		ADMUX = admux_var;
		
		/* Start Conversion */
		ADCSRA |= (1<<6);
		
		/* Wait until conversion is done */
		while(!(ADCSRA>>4));
		
		/* Dead Data */
		
#if (ADC_ADJUST_RESULT == ADC_ADJUST_RIGHT)
		//*Add_pu16value = ( (ADCH<<8) + ADCL );
		*Add_pu16value = ADC;
#else (ADC_ADJUST_RESULT == ADC_ADJUST_LEFT)
		//*Add_pu16value =  ( (ADCH<<2) + (ADCL>>6) );
		*Add_pu16value = ADC>>6;
#endif

	/*clear the ADC flag to be ready to start another conversion*/
		ADCSRA &= ~(1<<4);
	
		return ADC_enuOK;
	}
	
///note :: ay 7aga fe l MCAL leha init .. bs l interrubt mmkn la afkr brdo law a3mlha init keda .. l hal mlhash init	
	
	 ADC_tenuErrorStatus ADC_tenuStartAutoTrigger(ADC_tenuChannelNumber cpy_ChannelNumber,ADC_tenuAutoTriggerSource cpy_Source){
		 
		 /* Set the needed Channel */
		u8 admux_var = ADMUX;
		admux_var &= ADC_CHANNEL_MUSK;
		admux_var |= cpy_ChannelNumber;
		ADMUX = admux_var;
		 
		 /* set the trigger source */
		 u8 sfior_var = SFIOR;
		 sfior_var &= 0x1f;
		 sfior_var |= cpy_Source;
		 SFIOR = sfior_var;
		 
		/* Start Conversion */
		ADCSRA |= (1<<6); 
	 }
	 
	 
	 /*
	ISR_ITI(ADC){			 // ADC = 16    //ad5loo rqm l ADC mn l table ey fe page 44 bs l a7sn eni a3ml #defines ll table da 3shan  
		
		
		
	}
	*/