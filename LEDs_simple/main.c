/*
 * main.c
 *
 *  Created on: ٢٦‏/١١‏/٢٠٢٤
 *      Author: hp
 */

#include "BIT-MATH.h"
#include "STD_Types.h"

#include "LED_interface.h"

#include "util\delay.h"

int main(void)
{
	u8 counter=0;
	LED_Type LED1 = {LED_PORTA,LED_PIN0,ACTIVE_HIGH};
	LED_Type LED2 = {LED_PORTA,LED_PIN1,ACTIVE_HIGH};
	LED_Type LED3 = {LED_PORTA,LED_PIN2,ACTIVE_HIGH};

	LED_VoidInitialPin(LED1);
	LED_VoidInitialPin(LED2);
	LED_VoidInitialPin(LED3);

	while(1)
	{
		if(counter % 1 == 0)
		{
			LED_VoidToggle(LED1);
		}
		else if(counter % 2 == 0)
		{
			LED_VoidToggle(LED2);
		}
		else if(counter % 3 == 0)
		{
			LED_VoidToggle(LED3);
		}
		counter++;
		_delay_ms(1000);

	}
	return 0;

}
