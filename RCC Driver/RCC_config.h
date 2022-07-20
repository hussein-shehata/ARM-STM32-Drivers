/*************************************************************************************************
 * FILE_NAME:  RCC_interface.h
 *
 * DATE CREATED: Oct 20, 2021
 *
 *  Author:       Hussein Shehata
 *
 *  Version : V1
 *
 * DESCRIPTION:  Header file for the RCC driver
 ************************************************************************************************/
#ifndef RCC_config_H_
#define RCC_config_H_
#include "RCC_private.h"
/*option for Clock Type:
	1-RCC_HSE_CRYSTAL
	2-RCC_HSE_RC
	3-RCC_HSI	
	4-RCC_PLL
*/
#define RCC_CLOCK_TYPE	 	RCC_HSI				/* Choose the required mode for the Clock Type */
#define RCC_HSE_CLOCK_FREQUENCY_IN_MHZ 			16 				/* the frequency of the external clock frequency to be used in knowing the result of the pll circuit if used it is >72MHZ */
/* options for Clock security system:
	1-ENABLE
	2-DISABLE
	*/
	
#define CLOCK_SECURITY_SYSTEM 	DISABLE
/*only change the following if the clock type is PLL
	options for the input clock to the PLL circuit : 
		1-RCC_PLL_INPUT_HSE_DIV_2
		2-RCC_PLL_INPUT_HSI_DIV_2
		3-RCC_PLL_INPUT_HSE
	*/
#if RCC_CLOCK_TYPE == RCC_PLL
	#define  RCC_PLL_INPUT 	RCC_PLL_INPUT_HSE_DIV_2 		/* choose the required input to the PLL circuit */
	/* options to increase the multiply factor are 2 to 16 */
	#define RCC_PLL_MULTIPLY_FACTOR  4  					/* choose the number */ 
		
#endif

/* configuring the scale of Clock Buses*/

/* Configuring AHB BUS
 * 		1-SYSCLK_NOT_DIVIDED
 *  	2-SYSCLK_DIVIDED_BY_2
 *  	3-SYSCLK_DIVIDED_BY_4
 *  	4-SYSCLK_DIVIDED_BY_8
 *  	5-SYSCLK_DIVIDED_BY_16
 *  	6-SYSCLK_DIVIDED_BY_64
 *  	7-SYSCLK_DIVIDED_BY_128
 *  	8-SYSCLK_DIVIDED_BY_256
 *  	9-SYSCLK_DIVIDED_BY_512
 * */

/* Defining the options for configuring*/

typedef enum {
	SYSCLK_NOT_DIVIDED,SYSCLK_DIVIDED_BY_2=8,SYSCLK_DIVIDED_BY_4,SYSCLK_DIVIDED_BY_8,\
	SYSCLK_DIVIDED_BY_16,SYSCLK_DIVIDED_BY_64,\
	SYSCLK_DIVIDED_BY_128,SYSCLK_DIVIDED_BY_256,SYSCLK_DIVIDED_BY_512};


#define RCC_AHB_BUS	SYSCLK_DIVIDED_BY_4

/* Configuring APB1 & APB2 BUS
 * 		1-HCLK_NOT_DIVIDED
 * 		2-HCLK_DIVIDED_BY_2
 * 		3-HCLK_DIVIDED_BY_4
 * 		4-HCLK_DIVIDED_BY_8
 * 		5-HCLK_DIVIDED_BY_16
 */

/* Defining the options for configuring*/
typedef enum{
	HCLK_NOT_DIVIDED,HCLK_DIVIDED_BY_2=4,HCLK_DIVIDED_BY_8,HCLK_DIVIDED_BY_16};

#define RCC_APB1_BUS	HCLK_DIVIDED_BY_2
#define RCC_APB2_BUS	HCLK_DIVIDED_BY_8
#endif
