/*
 * main.c
 *
 *  Created on: ٠٢‏/٠٢‏/٢٠٢٥
 *      Author: hp
 */

#include <util/delay.h>
#include"BIT-MATH.h"
#include"STD_Types.h"

#include"CLCD_interface.h"

#include"ADC_interface.h"

#include"LED_interface.h"

LED_Type led ={LED_PORTD,LED_PIN0,ACTIVE_HIGH};
void APP (void)
{
	CLCD_voidInial();
	LED_VoidInitialPin(led);
	ADC_voidInit();
	ADC_u8SetPrescaler(ADC_PRE_64);
	ADC_voidEnable();

}
u8 result=0;
u8 temp=0;
int main ()
{
	APP();
	CLCD_voidSendString("TEMP:");

	while(1)
	{

		 ADC_u8GetResultSync(ADC_CHANNEL0,&result);
		temp =result*0.25 ;

		if(temp<10)
		{
			CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
			CLCD_voidSendData((temp%10)+48);

		}else if (temp<100)
		{
			CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
			CLCD_voidSendData((temp/10)+48);
			CLCD_voidSendData((temp%10)+48);
		}
		else
		{

		}



		if(temp>=30)
		{
			LED_VoidTurnOn(led);
		}
		else
		{
			LED_VoidTurnOff(led);
		}




	}

}













