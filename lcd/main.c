/*
 * main.c
 *
 *  Created on: ٢٦‏/٠١‏/٢٠٢٥
 *      Author: hp
 */


#include<util/delay.h>

#include"BIT-MATH.h"
#include"STD_TYPES.h"

#include"DIO_interface.h"

#include"CLCD_interface.h"

int main ()
{
	CLCD_voidInial();
	while(1)
	{
		CLCD_voidSendData('A');
		_delay_ms(1000);
		CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_2);
		CLCD_voidSendData('A');
		_delay_ms(1000);
		CLCD_ClearScreen();
		_delay_ms(1000);
	}
}
