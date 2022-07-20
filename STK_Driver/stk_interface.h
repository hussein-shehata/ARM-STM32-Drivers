/*
 * stk_interface.h
 *
 *  Created on: Nov 13, 2021
 *      Author: Hussein
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

#include "TYPES.h"

#define SYSTICK_TIMER_TICK_MS               100

/************************************************************************************************************* */
/*Systick ticks types*/
#define SYSTICK_TICKS_US                    1
#define SYSTICK_TICKS_MS					1000
#define SYSTICK_TICKS_S						1000000

/************************************************************************************************************* */
/* Systick clock source options*/
#define	STK_CLK_SRC_AHB_DIVIDED_BY_8        0
#define	STK_CLK_SRC_AHB						1

/************************************************************************************************************* */
/* Systick Interval modes*/
#define STK_SINGLE_INTERVAL_MODE		    0
#define STK_PERIODIC_INTERVAL_MODE	     	1

/************************************************************************************************************* */
/*Functions prototype*/

void MSTK_voidInit(u8 Copy_xClockSource);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks, u32 Copy_u32TicksTybe);
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , u32 Copy_u32TicksTybe, void (*Copy_ptr) (void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks ,u32 Copy_u32TicksTybe , void (* Copy_vpFuncPtr) (void));
void MSTK_voidStopInterval(void);
u32 MSTK_u32GetElapsedTime(u32 Copy_u32TicksTybe);
u32 MSTK_u32GetRemainingTime(u32 Copy_u32TicksTybe);


#endif /* STK_INTERFACE_H_ */
