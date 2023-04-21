 
#include "EXTI.h" 
#include "EXTI_PRV.h" 
#include "EXTI_CFG.h" 





 void (*fptr[3])(void)={NULL,NULL,NULL};



EXTI_ErrorStatus ExtInterrupt_init(void){
	
	EXTI_ErrorStatus status = EXTI_NotOk;
	
	status = EXTI_Ok;
	return status;
}


EXTI_ErrorStatus ExtInterrupt_enbale (EXTI_Interrupt cpy_interruptNum){
	
	EXTI_ErrorStatus status = EXTI_NotOk;
	
	
	if(cpy_interruptNum == EXTI_INT0){
		
		SET_BIT(GICR,INT0);
		MCUCR &= ~(0b00000011);
		MCUCR |= (EXTI_SENSE<<ISC_INT0); 
		
	}else if(cpy_interruptNum == EXTI_INT1){
		
		SET_BIT(GICR,INT1);
		MCUCR &= ~(0b00001100);
		MCUCR |= (EXTI_SENSE<<ISC_INT1);
		
	}else if(cpy_interruptNum == EXTI_INT2){
		
		SET_BIT(GICR,INT2);
		
		if(EXTI_SENSE < FALLING_EDGE){
			status = EXTI_WrongConfig;
		}
		MCUCSR &= ~(0b01000000);
		MCUCSR |= (EXTI_SENSE<<ISC_INT2);
		
	}else{
		status = EXTI_WrongConfig;
	}
	
	status = EXTI_Ok;
	return status;	
}


EXTI_ErrorStatus ExtInterrupt_disable (u8 cpy_interruptNum){
	
	EXTI_ErrorStatus status = EXTI_NotOk;
	
	
	if(cpy_interruptNum == EXTI_INT0){
		
		CLR_BIT(GICR,INT0);		

	}else if(cpy_interruptNum == EXTI_INT1){
		
		CLR_BIT(GICR,INT1);
		
	}else if(cpy_interruptNum == EXTI_INT2){

		CLR_BIT(GICR,INT2);
		
	}else{
		status = EXTI_WrongConfig;
	}
	
	status = EXTI_Ok;
	return status;
}



EXTI_ErrorStatus Set_CallBack(void(*ptr)(void),u8 index){
	
	EXTI_ErrorStatus status = EXTI_NotOk;
	
	fptr[index] = ptr;
	
	status = EXTI_Ok;
	return status;
}


void __vector_1(void)__attribute__((signal));
void __vector_1(void){
	if(fptr[0]!=NULL){
		fptr[0]();
	}
}


void __vector_2(void)__attribute__((signal));
void __vector_2(void){
	if(fptr[1]!=NULL){
		fptr[1]();
	}
}



void __vector_3(void)__attribute__((signal));
void __vector_3(void){
	if(fptr[2]!=NULL){
		fptr[2]();
	}
}