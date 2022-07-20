/*
 * stk_program.c
 *
 *  Created on: Nov 13, 2021
 *      Author: Hussein
 */

#include	"stk_interface.h"
#include 	"stk_config.h"
#include 	"stk_private.h"
#include 	"BIT_MATH.h"

static void (*callback)(void) = NULL_PTR;

/************************************************************************************************************* */
/*Static global variables*/
/************************************************************************************************************* */
/* Variable to define interval mode of Systick*/
static volatile u8 STK_u8IntervalMode;

/************************************************************************************************************* */
/*Private macros*/
/************************************************************************************************************* */
/* Local macros to set and get Interval mode for Systick exception*/
#define STK_SET_INTERVAL_MODE(MODE)                          STK_u8IntervalMode = MODE
#define STK_GET_INTERVAL_MODE()                             (STK_u8IntervalMode & 1)


void SysTick_Handler(void)
{
	u8 Local_u8Temporary = 0;
	if(STK_GET_INTERVAL_MODE() == STK_SINGLE_INTERVAL_MODE)
	{
		/*Disable systick exception*/
		SYSTICK->CTRL  &= ~(1 << 1);
		/*Stop the counter*/
		SYSTICK->CTRL  &= ~(1 << 0);
		/*Clear Systick registers*/
		SYSTICK->LOAD = 0;
		SYSTICK->VAL  = 0;
	}
	else
	{
		/*No Action*/
	}

	/*Execute callback function*/
	callback();

	/*Clear exception flag*/
	Local_u8Temporary = GET_BIT(SYSTICK->CTRL,16);
}

void MSTK_voidInit(u8 Copy_xClockSource){
	switch(Copy_xClockSource)
	{
	case STK_CLK_SRC_AHB_DIVIDED_BY_8:
		CLR_BIT(SYSTICK->CTRL,2);
		break;
	case STK_CLK_SRC_AHB:
		SET_BIT(SYSTICK->CTRL,2);
		break;
	default:
		/*No Action*/
		break;
	}
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks, u32 Copy_u32TicksTybe){
	SYSTICK->LOAD =Copy_u32Ticks * Copy_u32TicksTybe;
	SYSTICK->CTRL  |=  (1 << 0);
	//SYSTICK->CTRL |= (1<<0); /* enable counter "mdrtsh a3mlha fe el init 3shan momken mtsht8lsh*/
	while((GET_BIT(SYSTICK->CTRL,16))== 0){} /* wait for the flag to be 1 */
	SYSTICK->CTRL  &= ~(1 << 0);
	SYSTICK->LOAD =0;
	SYSTICK->VAL  = 0;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , u32 Copy_u32TicksTybe, void (*Copy_ptr) (void)){
	SYSTICK->CTRL  &= ~(1 << 0);
	SYSTICK->LOAD =0;
	SYSTICK->VAL  = 0;
	SYSTICK->LOAD =Copy_u32Ticks * Copy_u32TicksTybe;
	STK_SET_INTERVAL_MODE(STK_SINGLE_INTERVAL_MODE);
	callback=Copy_ptr; /* make a callback function */
	SYSTICK->CTRL  |=  (1 << 1); /* enable interrupt */
	SYSTICK->CTRL |= (1<<0); /* enable counter "mdrtsh a3mlha fe el init 3shan momken mtsht8lsh*/
}
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks ,u32 Copy_u32TicksTybe , void (* Copy_vpFuncPtr) (void)){

	SYSTICK->LOAD =Copy_u32Ticks * Copy_u32TicksTybe;
	STK_SET_INTERVAL_MODE(STK_PERIODIC_INTERVAL_MODE);
	callback=Copy_vpFuncPtr; /* make a callback function */
	SYSTICK->CTRL  |=  (1 << 1); /* enable interrupt */
	SYSTICK->CTRL |= (1<<0); /* enable counter "mdrtsh a3mlha fe el init 3shan momken mtsht8lsh*/
}
void MSTK_voidStopInterval(void){
	SYSTICK->LOAD=0;
	SYSTICK->VAL=0;
	SYSTICK->CTRL &= ~(1<<0) & ~(1<<1); /* disable counter */
}

u32 MSTK_u32GetElapsedTime(u32 Copy_u32TicksTybe){
	u32 time;
	time =SYSTICK->LOAD - SYSTICK->VAL;
	time=time* Copy_u32TicksTybe;
	return time ;
}

u32 MSTK_u32GetRemainingTime(u32 Copy_u32TicksTybe){
	return ((SYSTICK->VAL) * Copy_u32TicksTybe);
}
