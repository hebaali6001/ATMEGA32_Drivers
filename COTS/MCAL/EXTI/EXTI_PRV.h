#ifndef EXTI_PRV_H
#define EXTI_PRV_H



#define NULL	( (void*) 0)


#define	MCUCR			*(( volatile u8* const) 0x55 )
#define ISC_INT0		0
#define ISC_INT1		2


#define	MCUCSR          *(( volatile u8* const) 0x54 )
#define ISC_INT2		6


#define	GICR            *(( volatile u8* const) 0x5B )
#define INT0			6
#define INT1			7
#define INT2			5


#define	GIFR            *(( volatile u8* const) 0x5A )
#define INTF0			6
#define INTF1			7
#define INTF2			5












#endif /* EXTI_PRV_H */