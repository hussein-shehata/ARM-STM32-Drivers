#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#include "TYPES.h"

#define NVIC_BASE_ADDRESS			0xE000E100

#define NVIC_ISER0 					*((u32*)NVIC_BASE_ADDRESS)
#define NVIC_ISER1 					*((u32*)NVIC_BASE_ADDRESS +0X04)


#define NVIC_ICER0 					*((u32*)NVIC_BASE_ADDRESS + 0X80)
#define NVIC_ICER1 					*((u32*)NVIC_BASE_ADDRESS + 0X84)

#define NVIC_ISPR0					*((u32*)NVIC_BASE_ADDRESS +0x100)
#define NVIC_ISPR1					*((u32*)NVIC_BASE_ADDRESS +0x104)

#define NVIC_ICPR0					*((u32*)NVIC_BASE_ADDRESS +0x180)
#define NVIC_ICPR1					*((u32*)NVIC_BASE_ADDRESS +0x184)


#define NVIC_IABR0 					*((volatile u32*)NVIC_BASE_ADDRESS +0x200)
#define NVIC_IABR1 					*((volatile u32*)NVIC_BASE_ADDRESS +0x204)   /* there is volatile cause it is a read only register will be explained in lec.9 I think*/

#define NVIC_IPR					((volatile u8*)NVIC_BASE_ADDRESS + 0x300)
#define SCB_AIRCR					*((volatile u32*) 0xE000ED00+0x0C)
#endif
