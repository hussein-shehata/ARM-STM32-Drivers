/*************************************************************************************************
 * FILE_NAME:  RCC_interface.h
 *
 * DATE CREATED: Oct 20, 2021
 *
 *  Author:       Hussein Shehata
 *
 *  Version : V1
 *
 * DESCRIPTION:  Source file for the RCC driver
 ************************************************************************************************/	
 
 #include "RCC_interface.h"
 #include "RCC_config.h"
 #include "RCC_private.h"
 #include "BIT_MATH.h"
 
 void RCC_voidInit(void){
	 /* Reseting the 2 registers responsible for configuring the System Clock */
	RCC_CR=0x00000000;
	RCC_CFGR=0x00000000;
	RCC_CR |= (CLOCK_SECURITY_SYSTEM << 19); /* configuring the Clock security system option */
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR |=(1<< 16);	/* to enable HSE clock with no Bypass */
		RCC_CFGR |=(1<<0);  /* to select HSE as system clock*/
		//while(BIT_IS_CLEAR(RCC_CR,17));   /* wait till PLL is ready */

	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR |=(1<< 16) |(1<<18); /* to enable HSE clock with Bypass */
		RCC_CFGR |=(1<<0);  /* to select HSE as system clock*/
		//while(BIT_IS_CLEAR(RCC_CR,17));   /* wait till PLL is ready */

	#elif RCC_CLOCK_TYPE ==RCC_HSI
		RCC_CR |= (1<<0) | (1<<7); /* to enable HSI clock with Trimming =0 */ 
		//while(BIT_IS_CLEAR(RCC_CR,1));   /* wait till HSI is ready */
		
	#elif RCC_CLOCK_TYPE ==RCC_PLL
		RCC_CFGR |=(1<<1);  /* to select PLL as system clock*/
		#if RCC_PLL_INPUT == RCC_PLL_INPUT_HSI_DIV_2
		/* I used RCC_PLL_MULTIPLY_FACTOR-2 to be easily configured */
			#if (RCC_PLL_MULTIPLY_FACTOR > 16) || ((RCC_PLL_MULTIPLY_FACTOR * 8 ) >72)   /* it will give an error if the user chose factor > 16 or the clock after scale will be > 72MHZ*/
				#error "you entered wrong factor"
			#endif
			RCC_CFGR= (RCC_PLL_MULTIPLY_FACTOR-2) | (RCC_CFGR &0XFFC3FFFF) /*to configure the multiplying factor */
			RCC_CFGR &= ~(1<<16);		/* to configure HSI/2 as Input to the PLL circuit */
		#endif 
		
		#if RCC_PLL_INPUT == RCC_PLL_INPUT_HSE
		/* I used RCC_PLL_MULTIPLY_FACTOR-2 to be easily configured */
			#if (RCC_PLL_MULTIPLY_FACTOR > 16) || ((RCC_PLL_MULTIPLY_FACTOR * RCC_HSE_CLOCK_FREQUENCY_IN_MHZ ) >72)   /* it will give an error if the user chose factor > 16 or the clock after scale will be > 72MHZ*/
				#error "you entered wrong factor"
			#endif
			RCC_CFGR= (RCC_PLL_MULTIPLY_FACTOR-2) | (RCC_CFGR &0XFFC3FFFF); /*to configure the multiplying factor */
			RCC_CFGR &= ~(1<<17);			/* to make HSE clock not divided */
			RCC_CFGR |= (1<<16)	;			/* to configure HSE as Input to the PLL circuit */ 
		#endif
		
		#if RCC_PLL_INPUT == RCC_PLL_INPUT_HSE_DIV_2
		/* I used RCC_PLL_MULTIPLY_FACTOR-2 to be easily configured */
			#if (RCC_PLL_MULTIPLY_FACTOR > 16) || ((RCC_PLL_MULTIPLY_FACTOR * RCC_HSE_CLOCK_FREQUENCY_IN_MHZ ) >72)   /* it will give an error if the user chose factor > 16 or the clock after scale will be > 72MHZ*/
				#error "you entered wrong factor"
			#endif
			RCC_CFGR= (RCC_PLL_MULTIPLY_FACTOR-2) | (RCC_CFGR &0XFFC3FFFF); /*to configure the multiplying factor */
			RCC_CFGR |= (1<<17);			/* to make HSE clock  divided by 2 */
			RCC_CFGR |= (1<<16)	;			/* to configure HSE as Input to the PLL circuit */ 
		#endif
		RCC_CR |= (1<<24);   		/* to enable PLL */
		//while(BIT_IS_CLEAR(RCC_CR,24));   /* wait till PLL is ready */
		

	#endif
	/* now we will configure the scales of APB2 BUS */
		RCC_CFGR |=(RCC_APB2_BUS <<11);
	/* now we will configure the scales of APB1 BUS */
		RCC_CFGR |=(RCC_APB1_BUS <<8);
	/* now we will configure the scales of AHB BUS */
		RCC_CFGR |=(RCC_APB2_BUS <<4);

 }
 
 
 
 void RCC_voidEnableClock(u8 Copy_u8Bus ,u8 Copy_u8PerhID){
	 switch(Copy_u8Bus){
		case RCC_AHB:
				SET_BIT(RCC_AHBENR,Copy_u8PerhID);
					break;
		case RCC_APB1:
				SET_BIT(RCC_APB1ENR,Copy_u8PerhID);
					break;
		case RCC_APB2:
				SET_BIT(RCC_APB2ENR,Copy_u8PerhID);
					break;
	 }
 }
 
 void RCC_voidDisableClock(u8 Copy_u8Bus ,u8 Copy_u8PerhID){
	 switch(Copy_u8Bus){
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR,Copy_u8PerhID);
					break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR,Copy_u8PerhID);
					break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR,Copy_u8PerhID);
					break;
	 }
 }
