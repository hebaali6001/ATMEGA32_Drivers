  #ifndef SSEG_H
  #define SSEG_H

#include "7-SEG_GFG.h"
#include "7-SEG_PIV.h"
#include "Stdtypes.h"


typedef enum{

	SSEGenu_OK,
	SSEGenu_NotOK,
	SSEGenu_WrongDiriction,
	SSEGenu_WrongMood
}SSEG_ErrorStatus;


SSEG_ErrorStatus SSEG_Display(u8 SSEG_cpynumber ,u8 SSEG_cpyNumber);








  #endif /*SSEG_H*/  