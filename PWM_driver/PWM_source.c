#include "TIMER_interface.h"
#include "PWM_interface.h"

void MPWM_voidInit(TIM_TypeDef *TIMERx ,u8 Copy_u8ChannelNo, PWM_mode Copy_u32Mod , u16 Copy_u16PreScaler ,u16 Copy_u16TOPValue )
{
	//SET_BIT(TIMERx->CR1 , 7);			//auto reload preload enable
	

	switch(Copy_u8ChannelNo){
	case 1:
		TIMERx->CCMR1 = TIMERx->CCMR1 & ~(0b1111<<4) ; /* clearing the previous  PWM mode*/
		TIMERx->CCMR1 = TIMERx->CCMR1 | (Copy_u32Mod <<4); /* setting the PWM mode*/
		SET_BIT(TIMERx->CCMR1,3);	 //preload enable
		SET_BIT(TIMERx->CCER , 0);		//capture compare output enable for channel 1
		break;
	case 2:
		TIMERx->CCMR1 = TIMERx->CCMR1 & ~(0b1111<<12) ; /* clearing the previous  PWM mode*/
		TIMERx->CCMR1 = TIMERx->CCMR1 | (Copy_u32Mod <<12); /* setting the PWM mode*/
		SET_BIT(TIMERx->CCMR1,11);	 //preload enable
		SET_BIT(TIMERx->CCER , 4);		//capture compare output enable for channel 2
		break;
	case 3:
		TIMERx->CCMR2 = TIMERx->CCMR2 & ~(0b1111<<4) ; /* clearing the previous  PWM mode*/
		TIMERx->CCMR2 = TIMERx->CCMR2 | (Copy_u32Mod <<4); /* setting the PWM mode*/
		SET_BIT(TIMERx->CCMR2,3);	 //preload enable
		SET_BIT(TIMERx->CCER , 8);		 //capture compare output enable for channel 3
		break;
	case 4:
		TIMERx->CCMR2 = TIMERx->CCMR2 & ~(0b1111<<12) ; /* clearing the previous  PWM mode*/
		TIMERx->CCMR2 = TIMERx->CCMR2 | (Copy_u32Mod <<12); /* setting the PWM mode*/
		SET_BIT(TIMERx->CCMR2,11);	 //preload enable
		SET_BIT(TIMERx->CCER , 12);		 //capture compare output enable for channel 4
		break;

	}

	TIMERx->PSC=Copy_u16PreScaler ;
	TIMERx->ARR= Copy_u16TOPValue;
	//TIMERx->CR1 &=0xFC00 ;			/* clear all bits in that register */
	SET_BIT(TIMERx->CR1 , 7);	 //auto reload preload enable

	SET_BIT(TIMERx->CR1,0); /*COUNTER ENABLE */
	SET_BIT(TIMERx->EGR , 0);  //update generation
	

}
void MPWM_voidSetTopValue(TIM_TypeDef *TIMERx , u16 Copy_u16TopValue)
{
	TIMERx->ARR = (u16)Copy_u16TopValue;

}
void MPWM_voidSetDutyCycle(TIM_TypeDef *TIMERx ,u8 Copy_u8ChannelNo, u8 Copy_u8Duty)
{
	u16 Local_u16TempValue= (TIMERx->ARR) * Copy_u8Duty/100.0;
	switch(Copy_u8ChannelNo){
	case 1:
		TIMERx->CCR1=Local_u16TempValue;
		break;
	case 2:
		TIMERx->CCR2=Local_u16TempValue;
		break;
	case 3:
		TIMERx->CCR3=Local_u16TempValue;
		break;
	case 4:
		TIMERx->CCR4=Local_u16TempValue;
		break;

		}
}

void MPWM_voidDeInit(TIM_TypeDef *TIMERx ,u8 Copy_u8ChannelNo){
	switch(Copy_u8ChannelNo){
	case 1:
		TIMERx->CCMR1 = TIMERx->CCMR1 & ~(0b1111<<4) ; /* clearing the previous  PWM mode*/
		CLR_BIT(TIMERx->CCMR1,3);	 //preload enable
		CLR_BIT(TIMERx->CCER , 0);		//capture compare output enable for channel 1
		break;
	case 2:
		TIMERx->CCMR1 = TIMERx->CCMR1 & ~(0b1111<<12) ; /* clearing the previous  PWM mode*/

		CLR_BIT(TIMERx->CCMR1,11);	 //preload enable
		CLR_BIT(TIMERx->CCER , 4);		//capture compare output enable for channel 2
		break;
	case 3:
		TIMERx->CCMR2 = TIMERx->CCMR2 & ~(0b1111<<4) ; /* clearing the previous  PWM mode*/

		CLR_BIT(TIMERx->CCMR2,3);	 //preload enable
		CLR_BIT(TIMERx->CCER , 8);		 //capture compare output enable for channel 3
		break;
	case 4:
		TIMERx->CCMR2 = TIMERx->CCMR2 & ~(0b1111<<12) ; /* clearing the previous  PWM mode*/

		CLR_BIT(TIMERx->CCMR2,11);	 //preload enable
		CLR_BIT(TIMERx->CCER , 12);		 //capture compare output enable for channel 4
		break;

	}
}
