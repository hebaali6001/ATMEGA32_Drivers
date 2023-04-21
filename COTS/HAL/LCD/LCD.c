

#include "LCD.h"





LCD_enuErrorStatus LCD_enuWriteChar  (u8 Copy_u8Data){
	
	DIO_enuSetPin(RS);
	DIO_enuClearPin(RW);
	
	DATA &= 0;
	DATA |= Copy_u8Data;
	
	DIO_enuSetPin(EN);
	_delay_ms(2);
	DIO_enuClearPin(EN);
	_delay_ms(2);

	return LCD_enuOk;
}

LCD_enuErrorStatus LCD_enuSendCommand  (u8 Copy_u8Command){
	
	DIO_enuClearPin(RS);
	DIO_enuClearPin(RW);
	
	DATA &= 0;
	DATA |= Copy_u8Command;
	
	DIO_enuSetPin(EN);
	_delay_ms(2);
	DIO_enuClearPin(EN);
	_delay_ms(2);

	return LCD_enuOk;
}


void LCD_vidInit  (){
	_delay_ms(40);
	LCD_enuSendCommand(FUNCTION_SET);
	LCD_enuSendCommand(DESPLAY_ON);
	LCD_enuSendCommand(CLEAR_DISPLAY);
	LCD_enuSendCommand(ENTERY_MODE);

}


LCD_enuErrorStatus LCD_enuGotoXY  (u8 Copy_u8XPos, u8 Copy_u8YPos){
	
	u8 loc_location=0;
	
	if(Copy_u8XPos == FIRST_LINE){
		loc_location = Copy_u8YPos;
		
	}else if(Copy_u8XPos == SECOND_LINE){
		loc_location = 0x40 + Copy_u8YPos ;
	}
	
	LCD_enuSendCommand  (128 + loc_location);
	_delay_ms(2);
	
	return LCD_enuOk;
}
	
LCD_enuErrorStatus LCD_enuWriteSpecialPattern  (u8* Add_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos){
	
	u8 loc_iter=0;
	
	/*get the address of the block in the CGRAM*/
	u8 loc_address = Copy_u8BlockNum*8;
	
	/* Command to Write in CGRAM*/
	LCD_enuSendCommand  (loc_address+64);
	
	/*Write the data in the CGRAM in it's Block*/
	for(loc_iter=0 ; loc_iter<7 ; loc_iter++){
		
		LCD_enuWriteChar  (Add_pu8Pattern[loc_iter]);
	}
	
	/*move courser in the DDRAM*/
	LCD_enuGotoXY  (Copy_u8XPos , Copy_u8YPos);
	
	/*display the char from it's address in the CGRAM to DDRAM*/
	LCD_enuWriteChar  (Copy_u8BlockNum);	
	
	
	return LCD_enuOk;
}

LCD_enuErrorStatus LCD_enuWriteString  (char* Add_pchString){
	 
	 u8 loc_iter=0;
	 while(Add_pchString[loc_iter]!='\0'){
		 
		 LCD_enuWriteChar  (Add_pchString[loc_iter++]);
	 }
	 
	return LCD_enuOk;
}

LCD_enuErrorStatus LCD_enuWriteNumber  (s16 Copy_u16Number){
	
	u8 loc_number , loc_count=0 ;

	if (Copy_u16Number < 0){
		LCD_enuSendCommand(SHIFT_CURSOR_RIGHT);
		LCD_enuWriteChar  ('-');
		Copy_u16Number*=-1;
		
	}
	
	u16 loc_u16Number=Copy_u16Number;
	while(loc_u16Number){
		
		loc_number = loc_u16Number % 10;
		loc_u16Number/= 10;
		loc_count ++;
	}
	
	for(u8 loc_iter = 0 ;loc_iter<loc_count ; loc_iter++){
		
		LCD_enuSendCommand(SHIFT_CURSOR_RIGHT);
	}
	LCD_enuSendCommand(SHIFT_CURSOR_LEFT);
	while(Copy_u16Number){
		
		loc_number = Copy_u16Number % 10;
		LCD_enuWriteChar  (loc_number+48);
		LCD_enuSendCommand(SHIFT_CURSOR_LEFT);
		LCD_enuSendCommand(SHIFT_CURSOR_LEFT);

		Copy_u16Number/= 10;
	}
	
	return LCD_enuOk;
} 