/*
 * main.c
 *
 *  Created on: ٢٤‏/٠١‏/٢٠٢٥
 *      Author: hp
 */

#include "BIT-MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KEY_interface.h"

#include "CLCD_interface.h"

int main (void)
{
	CLCD_voidInial();
	KEY_voidInit();

	u8 x=NOTPRESSED;
	;

	while(1)
	{
		x=KEY_U8GetPressed();
		if(x!=NOTPRESSED)
		{
			if(x=='?')
			{
				CLCD_ClearScreen();
			}else
			{
				CLCD_voidSendData(x);
			}
		}
	}

}


