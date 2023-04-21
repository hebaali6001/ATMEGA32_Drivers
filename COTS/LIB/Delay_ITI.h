#ifndef DELAY_H
#define DELAY_H


 #define F_CPU 1000000UL



void delay_iti(long int millisec){
	long int i=0;
	millisec*=1000;
	while(i<=millisec){
		i++;
	}
}



#endif /* DELAY_H */