/*
 * main.c
 *
 *  Created on: ٣١‏/٠١‏/٢٠٢٥
 *      Author: hp
 */

#include<util/delay.h>

#include"BIT-MATH.h"
#include"STD_TYPES.h"

#include"LED_interface.h"

#include"SW_interface.h"

#include"SSD_interface.h"

#include"EXTI_interface.h"

#include"GIF_interface.h"
s8 s=9;
LED_Type red ={LED_PORTA,LED_PIN0,ACTIVE_HIGH};
LED_Type yellow ={LED_PORTA,LED_PIN1,ACTIVE_HIGH};
LED_Type green ={LED_PORTA,LED_PIN2,ACTIVE_HIGH};
SW_Type b1 ={SW_PORTD,SW_PIN2,SW_EXT_PULL_DOWN};
SSD_Type ssd1={SSD_CommonCathod,SSD_PORTC,SSD_PORTD,SSD_PIN0};


void APP_INIT(void)
{

	LED_VoidInitialPin(red);
	LED_VoidInitialPin(yellow);
	LED_VoidInitialPin(green);
	SW_VoidInital(b1);
	SSD_VoidIntialDataPin(ssd1);
	EXTI_VoidInit();
	EXTI_VoidEnable(EXTI_LINE0);
	GIF_VoidEnable();
	SSD_VoidEnable(ssd1);


}
void Stop (void)
{
	LED_VoidTurnOff(red);
	LED_VoidTurnOn(yellow);
	for(s8 i=5;i>=0;i--)
	{
		SSD_VoidSendNumber(ssd1,i);
		_delay_ms(1000);
	}
	LED_VoidTurnOff(yellow);
	LED_VoidTurnOn(green);
	for(s8 i=9;i>=0;i--)
	{
		SSD_VoidSendNumber(ssd1,i);
		_delay_ms(1000);
	}
}

int main (void)
{
	APP_INIT();
	EXTI_VoidSetCallBack(Stop,0);

	while(1)
	{
		s=9;
		LED_VoidTurnOff(green);
		LED_VoidTurnOn(red);
		for( ;s>=0;s--)
		{
			SSD_VoidSendNumber(ssd1,s);
			_delay_ms(1000);
		}


	}
}

