  #ifndef SSEG_CFG_H
  #define SSEG_CFG_H



#define Number_Of_SSEG		2 
/*
#define 0		0x3F
#define 1		0x06
#define 2		0x5B
#define 3		0x4F
#define 4		0x66
#define 5		0x6D
#define 6		0x7D
#define 7		0x07
#define 8		0x7F
#define 9		0x6F
#define A		0x77
#define B		0x7f
#define C		0x39	
#define D		0x3f
#define E		0x79
#define F		0x71
#define H		0x76

*/

  typedef enum
  {
	  SSEG_enuPin0 = 0,
	  SSEG_enuPin1,
	  SSEG_enuPin2,
	  SSEG_enuPin3,
	  SSEG_enuPin4,
	  SSEG_enuPin5,
	  SSEG_enuPin6,
	  SSEG_enuPin7,
	  SSEG_enuPin8,
	  SSEG_enuPin9,
	  SSEG_enuPin10,
	  SSEG_enuPin11,
	  SSEG_enuPin12,
	  SSEG_enuPin13,
	  SSEG_enuPin14,
	  SSEG_enuPin15,
	  SSEG_enuPin16,
	  SSEG_enuPin17,
	  SSEG_enuPin18,
	  SSEG_enuPin19,
	  SSEG_enuPin20,
	  SSEG_enuPin21,
	  SSEG_enuPin22,
	  SSEG_enuPin23,
	  SSEG_enuPin24,
	  SSEG_enuPin25,
	  SSEG_enuPin26,
	  SSEG_enuPin27,
	  SSEG_enuPin28,
	  SSEG_enuPin29,
	  SSEG_enuPin30,
	  SSEG_enuPin31,
	  SSEG_enuNumberOfPins,
  }SSEG_tenuPins;

  typedef enum{
	  
	  SSEG_enuPortA = 0,
	  SSEG_enuPortB,
	  SSEG_enuPortC,
	  SSEG_enuPortD,
	  SSEG_enuNumberOfPorts,
  }SSEG_tenuPortNumber;


typedef enum {

	SSEG_enuCommonCathode = 0,
	SSEG_enuCommonAnode,

	}SSEG_tenu_ActiveState;

typedef struct{
	SSEG_tenuPortNumber Port_Number;
	SSEG_tenu_ActiveState Active_State;
	}SSEG_strSSEGcgf_t;
	
	SSEG_strSSEGcgf_t SSEG_Array[Number_Of_SSEG];

  #endif /*SSEG_CGF_H*/