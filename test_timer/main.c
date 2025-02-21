/*
 * main.c
 *
 *  Created on: ١٠‏/٠٢‏/٢٠٢٥
 *      Author: hp
 */


/*
 * main.c
 *
 *  Created on: ١٠‏/٠٢‏/٢٠٢٥
 *      Author: hp
 */

#include "BIT-MATH.h"
#include "STD_Types.h"

#include "TIMER_interface.h"

#include "GIF_interface.h"

#include "LED_interface.h"

LED_Type led1 ={LED_PORTA,LED_PIN0,ACTIVE_HIGH};
LED_Type led2 ={LED_PORTA,LED_PIN1,ACTIVE_HIGH};
LED_Type led3 ={LED_PORTA,LED_PIN2,ACTIVE_HIGH};
volatile u8 count1 =0;
volatile u8 count2 =0;
volatile u8 x =0;
volatile u16 count3 =0;
volatile u16 count4 =0;
void APP (void)
{

	LED_VoidInitialPin(led1);
	LED_VoidInitialPin(led2);
	LED_VoidInitialPin(led3);
	TIMER0_voidInit();
	TIMER2_voidInit();
	GIF_VoidEnable();
}
void DELAY (void)
{
	count1++;
	count2++;
	count3++;
	count4++;
}
int main ()
{
	APP();
	TIMER_u8SetCallBack(&DELAY,TIMER0_CTC_VECTOR_ID);
	while(1)
	{
		if(count1>=100)
		{
			LED_VoidToggle(led1);
			count1=0;
		}
		else if(count2>=200)
		{
			LED_VoidToggle(led2);
			count2=0;
		}
		else if(count3>=300)
		{
			LED_VoidToggle(led3);
			count3=0;
		}
		else if(count4>=500)
		{
			if(x==0)
			{
				TIMER2_voidSetCTC(240);
				x=1;
			}else
			{
				TIMER2_voidSetCTC(30);
				x=0;
			}

			count4=0;
		}


	}
}
