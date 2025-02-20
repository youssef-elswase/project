/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:EXTI_private

	layer:MCAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
 */
#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#define MCUCR *((volatile u8*) 0x55)
#define MCUCSR *((volatile u8*) 0x54)
#define GICR *((volatile u8*) 0x5B)
#define GIFR *((volatile u8*) 0x5A)

#define NULL 0

#endif