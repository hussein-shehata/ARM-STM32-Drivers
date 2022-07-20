/*************************************************************************************************
 * [MODULE_NAME]:  RCC_interface.h
 *
 * [DATE CREATED]: Oct 20, 2021
 *
 * [Author]:       Hussein Shehata
 *
 *  Version : V1
 *
 * [DESCRIPTION]:  Header file for the RCC driver
 ************************************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* Register Definitions */
#define RCC_CR			*((u32*)0x40021000) //controls the clk from the 3
#define RCC_CFGR		*((u32*)0x40021004)	//controls the clk from the 3
#define RCC_CIR			*((u32*)0x40021008)
#define RCC_APB2RSTR	*((u32*)0x4002100c)
#define RCC_APB1RSTR	*((u32*)0x40021010)
#define RCC_AHBENR		*((u32*)0x40021014)	// enables and disable clks for all peripherals
#define RCC_APB2ENR		*((u32*)0x40021018)	// enables and disable clks for all peripherals
#define RCC_APB1ENR		*((u32*)0x4002101c)	// enables and disable clks for all peripherals
#define RCC_BDCR		*((u32*)0x40021020)
#define RCC_CSR			*((u32*)0x40021024)



/*Clock Types*/
#define RCC_HSE_CRYSTAL 	0
#define RCC_HSE_RC			1
#define RCC_HSI				2
#define RCC_PLL				3

/* Inputs for PLL */
#define RCC_PLL_INPUT_HSE_DIV_2		0
#define RCC_PLL_INPUT_HSE			1	
#define RCC_PLL_INPUT_HSI_DIV_2		2
#endif
