#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

typedef enum {
	PWM_1 	=	0b110,
	PWM_2	=	0b111
}PWM_mode;


void MPWM_voidInit(TIM_TypeDef *TIMERx ,u8 Copy_u8ChannelNo, PWM_mode Copy_u32Mod , u16 Copy_u16PreScaler ,u16 Copy_u16TOPValue );
void MPWM_voidSetTopValue(TIM_TypeDef *TIMERx , u16 Copy_u16TopValue);
void MPWM_voidSetDutyCycle(TIM_TypeDef *TIMERx ,u8 Copy_u8ChannelNo, u8 Copy_u8Duty);
void MPWM_voidDeInit(TIM_TypeDef *TIMERx ,u8 Copy_u8ChannelNo);

#endif
