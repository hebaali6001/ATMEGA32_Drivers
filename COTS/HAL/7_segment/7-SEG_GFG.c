

#include "7-SEG.h"




const int SSEG_Display_Number_Array[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};				//to display 0  ,1  ,2  ,3  4  ,5  ,6  ,7  ,8  ,9
const int SSEG_Display_Alpha_Array[]={0x77,0x7f,0x39,0x3f,0x79,0x71,0x76};								//to display A  ,B  ,C  ,D  ,E  ,F  ,H



SSEG_strSSEGcgf_t SSEG_Array[]=
{
	{SSEG_enuPortB,SSEG_enuCommonAnode},
	{SSEG_enuPortC,SSEG_enuCommonAnode}
};