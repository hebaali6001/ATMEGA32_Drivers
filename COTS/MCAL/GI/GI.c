 
 
 #include "GI.h"
 
 
 
 
 void GIE_Enable(void){
	 
	 SET_BIT(SREG , GIE);
 }
 
 void GIE_Disable(void){
	 
	 CLR_BIT(SREG , GIE);
 }