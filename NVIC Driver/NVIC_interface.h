#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(s8 Copy_s8IntID,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority,u32 Copy_u32GROUP);

#define 		GROUP4				0x05FA0300 	/* 4 bits for gp priority */
#define 		GROUP3_1SUB 		0x05FA0400 	/* 3 bits for gp priority  and 1 bit for sub*/
#define 		GROUP2_2SUB			0x05FA0500 	/* 2 bits for gp priority  and 2 bit for sub*/
#define 		GROUP1_3SUB 		0x05FA0600 	/* 1 bits for gp priority  and 3 bit for sub*/
#define 		GROUP0_4SUB 		0x05FA0700 	/* 0 bits for gp priority  and 4 bit for sub*/


#endif
