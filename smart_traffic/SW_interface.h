/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:SW_interface
	
	layer:HAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef _SW_INTERFACE_H_
#define _SW_INTERFACE_H_

#define SW_PORTA 0
#define SW_PORTB 1
#define SW_PORTC 2
#define SW_PORTD 3

#define SW_PIN0 0
#define SW_PIN1 1
#define SW_PIN2 2
#define SW_PIN3 3
#define SW_PIN4 4
#define SW_PIN5 5
#define SW_PIN6 6
#define SW_PIN7 7

#define SW_NOT_PRESSED 0
#define SW_PRESSED     1

#define SW_INT_PULL_UP   0
#define SW_EXT_PULL_UP   1
#define SW_EXT_PULL_DOWN 2
#define SW_FLOTING       3

typedef struct {
	u8 Port;
	u8 Pin;
	u8 Pull_State;
} SW_Type;

void SW_VoidInital (SW_Type SW_Config);
u8 SW_u8GetPressed (SW_Type SW_Config);

#endif
