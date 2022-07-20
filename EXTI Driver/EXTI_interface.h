#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define LINE0 		0
#define LINE1 		1
#define LINE2 		2
#define LINE3 		3
#define LINE4 		4
#define LINE5 		5




#define RISING 		0
#define FALLING 	1
#define ON_CHANGE	2

void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger (u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);
void EXTI0_VidSetCallBack( void (*ptr) (void) );
void EXTI1_VidSetCallBack( void (*ptr) (void) );

#endif
