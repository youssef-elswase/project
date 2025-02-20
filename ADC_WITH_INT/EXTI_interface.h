/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:EXTI_interface

	layer:MCAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
 */
#ifndef _EXIT_INTERFACE_H_
#define _EXTI_INTERFACE_H_


#define EXTI_LINE0 6
#define EXTI_LINE1 7
#define EXTI_LINE2 5

#define EXTI_FALLING_EDGE 0
#define EXTI_RISING_EDGE  1
#define EXTI_LOW_LEVEL    2
#define EXTI_ON_CHANGE    3

#define NULL 0

void EXTI_VoidInit(void);
void EXTI_VoidSetSignalLatch(u8 COPY_SenseMode, u8 COPY_u8Line);
u8 EXTI_VoidEnable(u8 COPY_u8Line);
u8 EXTI_VoidDisable(u8 COPY_u8Line);
void EXTI_VoidClearFlag(u8 COPY_u8Line);
u8 EXTI_u8GetFlag( u8 Copy_u8Line );
void EXTI_VoidSetCallBack(void (*COPY_pvoidCallBack)(void) , u8 COPY_u8EXTILine );




#endif
