/*******************************************
 Author     : Taher Mohamed
 Data       : 13/11/2021
********************************************/




#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#include "TYPES.h"
#include "BIT_MATH.h"



#define TIMER1_BASE_ADDRESS                        0x40012C00
#define TIMER2_BASE_ADDRESS                        0x40000000
#define TIMER3_BASE_ADDRESS                        0x40000400
#define TIMER4_BASE_ADDRESS                        0x40000800
#define TIMER5_BASE_ADDRESS                        0x40000C00
#define TIMER6_BASE_ADDRESS                        0x40001000
#define TIMER7_BASE_ADDRESS                        0x40001400
#define TIMER8_BASE_ADDRESS                        0x40013400
#define TIMER9_BASE_ADDRESS                        0x40014C00
#define TIMER10_BASE_ADDRESS                       0x40015000
#define TIMER11_BASE_ADDRESS                       0x40015400
#define TIMER12_BASE_ADDRESS                       0x40001800
#define TIMER13_BASE_ADDRESS                       0x40001C00
#define TIMER14_BASE_ADDRESS                       0x40002000


typedef struct
{
  volatile u16 CR1;
  u16  RESERVED0;
  volatile u16 CR2;
  u16  RESERVED1;
  volatile u16 SMCR;
  u16  RESERVED2;
  volatile u16 DIER;
  u16  RESERVED3;
  volatile u16 SR;
  u16  RESERVED4;
  volatile u16 EGR;
  u16  RESERVED5;
  volatile u16 CCMR1;
  u16  RESERVED6;
  volatile u16 CCMR2;
  u16  RESERVED7;
  volatile u16 CCER;
  u16  RESERVED8;
  volatile u16 CNT;
  u16  RESERVED9;
  volatile u16 PSC;
  u16  RESERVED10;
  volatile u16 ARR;
  u16  RESERVED11;
  volatile u16 RCR;
  u16  RESERVED12;
  volatile u16 CCR1;
  u16  RESERVED13;
  volatile u16 CCR2;
  u16  RESERVED14;
  volatile u16 CCR3;
  u16  RESERVED15;
  volatile u16 CCR4;
  u16  RESERVED16;
  volatile u16 BDTR;
  u16  RESERVED17;
  volatile u16 DCR;
  u16  RESERVED18;
  volatile u16 DMAR;
  u16  RESERVED19;
} TIM_TypeDef;


#define TIMER1                   ((TIM_TypeDef*)TIMER1_BASE_ADDRESS)
#define TIMER2                   ((TIM_TypeDef*)TIMER2_BASE_ADDRESS)
#define TIMER3                   ((TIM_TypeDef*)TIMER3_BASE_ADDRESS)
#define TIMER4                   ((TIM_TypeDef*)TIMER4_BASE_ADDRESS)
#define TIMER5                   ((TIM_TypeDef*)TIMER5_BASE_ADDRESS)
#define TIMER6                   ((TIM_TypeDef*)TIMER6_BASE_ADDRESS)
#define TIMER7                   ((TIM_TypeDef*)TIMER7_BASE_ADDRESS)
#define TIMER8                   ((TIM_TypeDef*)TIMER8_BASE_ADDRESS)
#define TIMER9                   ((TIM_TypeDef*)TIMER9_BASE_ADDRESS)
#define TIMER10                  ((TIM_TypeDef*)TIMER10_BASE_ADDRESS)
#define TIMER11                  ((TIM_TypeDef*)TIMER11_BASE_ADDRESS)
#define TIMER12                  ((TIM_TypeDef*)TIMER12_BASE_ADDRESS)
#define TIMER13                  ((TIM_TypeDef*)TIMER13_BASE_ADDRESS)
#define TIMER14                  ((TIM_TypeDef*)TIMER14_BASE_ADDRESS)


#endif
