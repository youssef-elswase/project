/*
 * main.c
 *
 *  Created on: ٠٥‏/٠٢‏/٢٠٢٥
 *      Author: hp
 */

#include "util/delay.h"

#include "BIT-MATH.h"
#include "STD_Types.h"

#include "ADC_interface.h"
#include "ADC_private.h"

#include "CLCD_interface.h"

#include "EXTI_interface.h"

#include "SW_interface.h"

#include "DIO_interface.h"

#include "GIF_interface.h"

u8 result =0;
u8 temp =0;

SW_Type sw ={DIO_PORTD,DIO_PIN2,SW_INT_PULL_UP};

void ADC (void)
{
	CLCD_voidSendString("TEMP :");
	CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
	result =(ADCL|(ADCH<<8));
	temp = result*0.25;
	if(temp<10)
	{

		CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
		CLCD_voidSendData((temp%10)+48);
		CLCD_voidSendData(0x00);


	}else if (temp<100)
	{
		CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
		CLCD_voidSendData((temp/10)+48);
		CLCD_voidSendData((temp%10)+48);

	}
	else
	{

	}

	_delay_ms(3000);
	CLCD_ClearScreen();

}






void APP_INIT(void)
{
	ADC_VoidInit();
	EXTI_VoidInit();
	CLCD_voidInial();
	EXTI_VoidEnable(EXTI_LINE0);
	SW_VoidInital(sw);
	GIF_VoidEnable();

}

int main (void )
{
	APP_INIT();
	//ADC_u8StartConversionAsynch(ADC_CHANNEL0,&result,&TEMP);
	//SET_BIT(ADCSAR,ADSC);


	while(1)
	{
		//ADC_u8StartConversionAsynch(ADC_CHANNEL0,&result,&ADC);
		EXTI_VoidSetCallBack(&ADC,0);

	}
}
