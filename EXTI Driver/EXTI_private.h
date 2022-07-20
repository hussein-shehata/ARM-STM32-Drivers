#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_BASE_ADDRESS			0x40010400

#define NULL_PTR    ((void*)0)


typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RSTR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_t;

#define EXTI ((volatile EXTI_t *) 0x40010400)

/*#define LINE0 		0
#define LINE1 		1
#define LINE2 		2
#define LINE3 		3
#define LINE4 		4
#define LINE5 		5




#define RISING 		0
#define FALLING 	1
#define ON_CHANGE	2*/


#endif
