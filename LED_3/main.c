/*
 * main.c
 *
 *  Created on: ١٤‏/١٢‏/٢٠٢٤
 *      Author: hp
 */
#include "BIT-MATH.h"
#include "STD_Types.h"

#include "LED_interface.h"

#include <util/delay.h>

int main (void)
{
	LED_Type led0 ={LED_PORTA,LED_PIN0,ACTIVE_HIGH};
	LED_Type led1 ={LED_PORTA,LED_PIN1,ACTIVE_HIGH};
	LED_Type led2 ={LED_PORTA,LED_PIN2,ACTIVE_HIGH};
	LED_Type led3 ={LED_PORTA,LED_PIN3,ACTIVE_HIGH};
	LED_Type led4 ={LED_PORTA,LED_PIN4,ACTIVE_HIGH};
	LED_Type led5 ={LED_PORTA,LED_PIN5,ACTIVE_HIGH};
	LED_Type led6 ={LED_PORTA,LED_PIN6,ACTIVE_HIGH};
	LED_Type led7 ={LED_PORTA,LED_PIN7,ACTIVE_HIGH};

	LED_VoidInitialPin(led0);
	LED_VoidInitialPin(led1);
	LED_VoidInitialPin(led2);
	LED_VoidInitialPin(led3);
	LED_VoidInitialPin(led4);
	LED_VoidInitialPin(led5);
	LED_VoidInitialPin(led6);
	LED_VoidInitialPin(led7);

	LED_Type arr [ ] ={
			led0,
			led1,
			led2,
			led3,
			led4,
			led5,
			led6,
			led7,
	};

	s8 j;
	s8 i;
	while(1)
	{

		for(i=3 , j=4  ; i>=0 , j<=8 ; i-- , j++)
		{

			LED_VoidTurnOn (arr[i]);
			LED_VoidTurnOn (arr[j]);

			_delay_ms(100);

		}
		for(i=3 , j=4  ; i>=0 , j<=8 ; i-- , j++)
		{

			LED_VoidTurnOff (arr[i]);
			LED_VoidTurnOff (arr[j]);

			_delay_ms(100);

		}


	}
}

