  #ifndef LCD_PRV_H
  #define LCD_PRV_H




#define CLEAR_DISPLAY		0x01
#define RETURN_HOME			0x02
#define ENTERY_MODE			0x06
#define DESPLAY_ON			0x0c		//1100
#define	DESPLAY_OFF			0x08		//1000
#define FUNCTION_SET		0x38		//0011 1100			number of lines=2 ,  font is 5*8
#define SET_CGRAM_ADRS		0x40//
#define SET_DDRAM_ADRS		0x80//
#define WRITE_DATA			0x0200//
#define SHIFT_CURSOR_RIGHT	0x14
#define SHIFT_CURSOR_LEFT	0x10







  #endif /*LCD_PRV_H*/