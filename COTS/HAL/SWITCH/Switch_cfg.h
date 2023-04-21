#ifndef SWITCH_CGF_H
#define SWITCH_CGF_H


#define Number_Of_Switshs  2
  
  typedef enum
  {
	  Switch_enuPin0 = 0,
	  Switch_enuPin1,
	  Switch_enuPin2,
	  Switch_enuPin3,
	  Switch_enuPin4,
	  Switch_enuPin5,
	  Switch_enuPin6,
	  Switch_enuPin7,
	  Switch_enuPin8,
	  Switch_enuPin9,
	  Switch_enuPin10,
	  Switch_enuPin11,
	  Switch_enuPin12,
	  Switch_enuPin13,
	  Switch_enuPin14,
	  Switch_enuPin15,
	  Switch_enuPin16,
	  Switch_enuPin17,
	  Switch_enuPin18,
	  Switch_enuPin19,
	  Switch_enuPin20,
	  Switch_enuPin21,
	  Switch_enuPin22,
	  Switch_enuPin23,
	  Switch_enuPin24,
	  Switch_enuPin25,
	  Switch_enuPin26,
	  Switch_enuPin27,
	  Switch_enuPin28,
	  Switch_enuPin29,
	  Switch_enuPin30,
	  Switch_enuPin31,
	  Switch_enuNumberOfPins,
  }Switch_tenuPins;
  
  
  
typedef enum{
	
	Switch_enuPullup,
	Switch_enuPulldown

}Switch_enuActiveState;  

  
  
typedef struct{
	Switch_tenuPins SwitchPin_Num;
	Switch_enuActiveState SwitchPin_State;
		
}str_SwitchCfg;  
  
str_SwitchCfg Switch_Pins[Number_Of_Switshs];

#endif /*SWITCH_CGF_H*/