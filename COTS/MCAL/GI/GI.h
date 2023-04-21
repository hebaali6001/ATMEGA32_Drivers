 
#ifndef GI_H_
#define GI_H_

#include "GI_CFG.h"
#include "GI_PRV.h"

#include "Bitmath.h"
#include "Stdtypes.h"

#define SREG      *(( volatile u8 * const)0x5F)
#define GIE       7



void GIE_Enable(void);

void GIE_Disable(void);




#endif /* GI_H_ */