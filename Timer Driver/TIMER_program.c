/*******************************************
 Author     : Taher Mohamed
 Data       : 13/11/2021
********************************************/

#include "TIMER_interface.h"

/*Static global variables*/
/* Variable to define interval mode of Timer*/
static volatile u8 TIM2_u8IntervalMode;
static volatile u8 TIM3_u8IntervalMode;
static volatile u8 TIM4_u8IntervalMode;
/*Private macros*/
/* Local macros to set and get Interval mode for timer interrupt*/
#define TIM2_SET_INTERVAL_MODE(MODE)                          TIM2_u8IntervalMode = MODE
#define TIM2_GET_INTERVAL_MODE()                               (TIM2_u8IntervalMode & 1)

#define TIM3_SET_INTERVAL_MODE(MODE)                          TIM3_u8IntervalMode = MODE
#define TIM3_GET_INTERVAL_MODE()                               (TIM3_u8IntervalMode & 1)

#define TIM4_SET_INTERVAL_MODE(MODE)                          TIM4_u8IntervalMode = MODE
#define TIM4_GET_INTERVAL_MODE()                               (TIM4_u8IntervalMode & 1)

static void (*Timer_CallBack_2)(void);
static void (*Timer_CallBack_3)(void);
static void (*Timer_CallBack_4)(void);

void TIM_vInit(TIM_TypeDef *TIMERx,TIM_ConfigType *TIM_ConfigPtr)
{
	TIM_vSetPeriodValue(TIMERx,TIM_ConfigPtr->PeriodVal);

	TIM_vSetPrescalerValue(TIMERx,TIM_ConfigPtr->PrescalerVal);

	TIM_vSetARR_Buffer(TIMERx,TIM_ConfigPtr->AutoReloadBuffer);

	TIM_vSetCMS_State(TIMERx,TIM_ConfigPtr->Center_Aligned_Mode);

	TIM_vSetDirection(TIMERx,TIM_ConfigPtr->Direction_State);

	TIM_vSetClkDiv(TIMERx,TIM_ConfigPtr->Clock_Div_Factor);

	TIM_vSet_Interrupt(TIMERx,TIM_ConfigPtr->UDI_State);

	//TIM_vSetCounterState(TIMERx,TIM_ConfigPtr->Counter_State);
}

// new update
void TIM_vClearINTBit(TIM_TypeDef *TIMERx )
{
	 CLR_BIT(TIMERx->SR,0);
}

void TIM_vSetPeriodValue(TIM_TypeDef *TIMERx , u32 Copy_u32PeriodVal)
{
	TIMERx->ARR = (u16)Copy_u32PeriodVal;
}

void TIM_vSetPrescalerValue(TIM_TypeDef *TIMERx , u32 Copy_u32PrescalerVal)
{
	TIMERx->PSC = (u16)Copy_u32PrescalerVal;
}

void TIM_vSetCounterState(TIM_TypeDef *TIMERx,CNT_State Copy_x_State)
{
	switch(Copy_x_State)
	{
	case Disable_CNT:
		CLR_BIT(TIMERx->CR1,0);
		break;
	case Enable_CNT:
		SET_BIT(TIMERx->CR1,0);
		break;	
	}
}


void TIM_vSetARR_Buffer(TIM_TypeDef *TIMERx,ARR_Buffer_State Copy_xAutoReloadBuffer)
{
	switch(Copy_xAutoReloadBuffer)
	{
	case Disable_ARR_Buffer:
		CLR_BIT(TIMERx->CR1,7);
		break;
	case Enable_ARR_Buffer:
		SET_BIT(TIMERx->CR1,7);
		break;
	
	}
}


void TIM_vSetCMS_State(TIM_TypeDef *TIMERx,CMS_State Copy_xCenter_Aligned_Mode)
{
	switch(Copy_xCenter_Aligned_Mode)
	{
	case Edge_Aligned_Mode:
		CLR_BIT(TIMERx->CR1,5);
		CLR_BIT(TIMERx->CR1,6);
		break;

	case Center_Aligned_Mode_1:
		SET_BIT(TIMERx->CR1,5);
		CLR_BIT(TIMERx->CR1,6);
		break;

	case Center_Aligned_Mode_2:
		CLR_BIT(TIMERx->CR1,5);
		SET_BIT(TIMERx->CR1,6);
		break;

	case Center_Aligned_Mode_3:
		SET_BIT(TIMERx->CR1,5);
		SET_BIT(TIMERx->CR1,6);
		break;

	}
}


void TIM_vSetDirection(TIM_TypeDef *TIMERx,DIR_State Copy_xDirection_State)
{
	switch(Copy_xDirection_State)
	{
	case UpCounter:
		CLR_BIT(TIMERx->CR1,4);
		break;
	case DownCounter:
		SET_BIT(TIMERx->CR1,4);
		break;
	
	}
}

void TIM_vSetClkDiv(TIM_TypeDef *TIMERx,Clk_Div Copy_xClock_Div_Factor)
{
	switch(Copy_xClock_Div_Factor)
	{
	case Div_1:
		CLR_BIT(TIMERx->CR1,8);
		CLR_BIT(TIMERx->CR1,9);
		break;

	case Div_2:
		SET_BIT(TIMERx->CR1,8);
		CLR_BIT(TIMERx->CR1,9);
		break;

	case Div_3:
		CLR_BIT(TIMERx->CR1,8);
		SET_BIT(TIMERx->CR1,9);
		break;
	}
}



void TIM_vSet_Interrupt(TIM_TypeDef *TIMERx,TIM_Update_INT_State Copy_xIntState)
{
	switch(Copy_xIntState)
	{
		case Disable_TIM_Update_Interrupt:
			CLR_BIT(TIMERx->DIER,0);
			break;
		case Enable_TIM_Update_Interrupts:
			SET_BIT(TIMERx->DIER,0);
			break;	
	}
}


void TIM_vSetBusyWait(TIM_TypeDef *TIMERx,u32 Copy_u32Ticks, u32 Copy_u32TicksTybe)
{
	/*Assign ticks to load register*/
	TIMERx->ARR = (u16)(Copy_u32Ticks * Copy_u32TicksTybe);
	CLR_BIT(TIMERx->DIER,0);
	/*Start timer*/
	SET_BIT(TIMERx->CR1,0);
	/*Wait until CNT is equal to comapre value */
	while(TIMERx->CNT != TIMERx->ARR);
	/*Stop timer*/
	TIMERx->CNT=0;
	CLR_BIT(TIMERx->CR1,0);
	/*Clear Timer registers*/
	TIMERx->ARR = 0;
}

void TIM_vSetIntervalSingle  (TIM_TypeDef *TIMERx, u32 Copy_u32Ticks, u32 Copy_u32TicksTybe, void (*Copy_vpFuncPtr)(void) )
{
	/*/*Stop timer*/
	CLR_BIT(TIMERx->CR1,0);
	/*Clear Timer registers*/
	TIMERx->ARR = 0;
	/*Assign ticks to load register*/
	TIMERx->ARR = (u16)(Copy_u32Ticks * Copy_u32TicksTybe) ;
	/* Assign callBack function */
	if(TIMERx ==TIMER2){
		Timer_CallBack_2 = Copy_vpFuncPtr;
		TIM2_SET_INTERVAL_MODE(TIM_SINGLE_INTERVAL_MODE);/* Set Mode to Single */
	}
	else if (TIMERx == TIMER3){
		Timer_CallBack_3 = Copy_vpFuncPtr;
		TIM3_SET_INTERVAL_MODE(TIM_SINGLE_INTERVAL_MODE);
	}
	else if (TIMERx ==TIMER4){
		Timer_CallBack_4 = Copy_vpFuncPtr;
		TIM4_SET_INTERVAL_MODE(TIM_SINGLE_INTERVAL_MODE);
	}

	SET_BIT(TIMERx->DIER,0);
	/*Start timer*/
	SET_BIT(TIMERx->CR1,0);
}

void TIM_vSetIntervalPeriodic(TIM_TypeDef *TIMERx,u32 Copy_u32Ticks ,u32 Copy_u32TicksTybe , void (* Copy_vpFuncPtr) (void))
{
	/*Assign ticks to load register*/
	TIMERx->ARR = (u16)(Copy_u32Ticks * Copy_u32TicksTybe) ;
	/*Assign the function to the callback function */
	if(TIMERx ==TIMER2){
		Timer_CallBack_2 = Copy_vpFuncPtr;
		TIM2_SET_INTERVAL_MODE(TIM_PERIODIC_INTERVAL_MODE);/* Set Mode to periodic */
		TIM_vClearINTBit(TIMER2);
	}
	else if (TIMERx == TIMER3){
		Timer_CallBack_3 = Copy_vpFuncPtr;
		TIM3_SET_INTERVAL_MODE(TIM_PERIODIC_INTERVAL_MODE);
		TIM_vClearINTBit(TIMER3);
	}
	else if (TIMERx ==TIMER4){
		Timer_CallBack_4 = Copy_vpFuncPtr;
		TIM4_SET_INTERVAL_MODE(TIM_PERIODIC_INTERVAL_MODE);
		TIM_vClearINTBit(TIMER4);
	}
	/*Enable Timer interrupt*/
	SET_BIT(TIMERx->DIER,0);
	/*Start the counter*/
	SET_BIT(TIMERx->CR1,0);
}




/*-----------------------------------Interrupt Handler*************************************/
void TIM2_IRQHandler(void)
{
	if(TIM2_GET_INTERVAL_MODE()  == TIM_SINGLE_INTERVAL_MODE)
	{
		CLR_BIT(TIMER2->DIER,0);
		CLR_BIT(TIMER2->CR1,0);
		TIMER2->ARR = 0;
	}

	Timer_CallBack_2();
	CLR_BIT(TIMER2->SR,0);	/*Clear interrupt flag*/

}
void TIM3_IRQHandler(void)
{
	if(TIM3_GET_INTERVAL_MODE()  == TIM_SINGLE_INTERVAL_MODE)
	{
		CLR_BIT(TIMER3->DIER,0);
		CLR_BIT(TIMER3->CR1,0);
		TIMER3->ARR = 0;
	}

	Timer_CallBack_3();
	CLR_BIT(TIMER3->SR,0);	/*Clear interrupt flag*/

}
void TIM4_IRQHandler(void)
{
	if(TIM4_GET_INTERVAL_MODE()  == TIM_SINGLE_INTERVAL_MODE)
	{

		CLR_BIT(TIMER4->DIER,0);
		CLR_BIT(TIMER4->CR1,0);
		TIMER4->ARR = 0;
	}

	Timer_CallBack_4();
	CLR_BIT(TIMER4->SR,0);	/*Clear interrupt flag*/
}
