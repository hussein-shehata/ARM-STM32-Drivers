/*
 * stk_private.h
 *
 *  Created on: Nov 13, 2021
 *      Author: Hussein
 */

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#define NULL_PTR    ((void*)0)

#define SYSTICK_BASE_ADDRESS			  (0xE000E010)
/************************************************************************************************************* */

/*Systick registers*/
typedef struct
{
  volatile u32 CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile u32 LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  volatile u32 VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  volatile u32 CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_TypeDef;

/************************************************************************************************************* */

#define SYSTICK    				         ((SysTick_TypeDef *)	SYSTICK_BASE_ADDRESS	)


#endif /* STK_PRIVATE_H_ */
