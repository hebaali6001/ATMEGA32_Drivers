#ifndef LCD_H
#define LCD_H

#include <util/delay.h>
#include "LCD_CFG.h"
#include "LCD_PRV.h"

typedef enum{
	
	LCD_enuOk=0,
	LCD_enu_NotOk,
	
	}LCD_enuErrorStatus;


void LCD_vidInit  ();

LCD_enuErrorStatus LCD_enuWriteChar  (u8 Copy_u8Data);

LCD_enuErrorStatus LCD_enuSendCommand  (u8 Copy_u8Command);

LCD_enuErrorStatus LCD_enuGotoXY  (u8 Copy_u8XPos, u8 Copy_u8YPos);

LCD_enuErrorStatus LCD_enuWriteSpecialPattern  (u8* Add_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos);

LCD_enuErrorStatus LCD_enuWriteString  (char* Add_pchString);

LCD_enuErrorStatus LCD_enuWriteNumber  (s16 Copy_u16Number);



#endif /*LCD_H*/