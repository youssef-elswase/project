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

#include"CLCD1_interface.h"

int main ()
{
	CLCD1_voidInial();
	while(1)
	{
		CLCD1_voidSendString("body");
		_delay_ms(1000);
		CLCD1_SetPosition(CLCD1_ROW_2,CLCD1_COL_1);
		CLCD1_voidSendString("mano");
		_delay_ms(1000);
		CLCD1_SetPosition(CLCD1_ROW_3,CLCD1_COL_1);
		CLCD1_voidSendString("youssef");
		_delay_ms(1000);
		CLCD1_SetPosition(CLCD1_ROW_4,CLCD1_COL_1);
		CLCD1_voidSendString("Hazem");
		_delay_ms(1000);
		CLCD1_ClearScreen();
		_delay_ms(1000);



	}
}
