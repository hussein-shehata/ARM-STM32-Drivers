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


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include "TYPES.H"
#define ENABLE 		1
#define DISABLE		0
/* Definition for the clock buses for the peripheral*/
#define RCC_AHB 	0
#define RCC_APB1 	1
#define RCC_APB2	2

void RCC_voidInit(void); /* function to initialize the RCC according to the configuration on .config file*/
void RCC_voidEnableClock(u8 Copy_u8Bus ,u8 Copy_u8PerhID); /* function to enable clock for the selected periphral */
void RCC_voidDisableClock(u8 Copy_u8Bus ,u8 Copy_u8PerhID); /*function to disable clock for the selected periphral */

#endif
