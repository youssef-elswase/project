/*
 * main.c
 *
 *  Created on: ٢٧‏/٠١‏/٢٠٢٥
 *      Author: hp
 */

#include"BIT-MATH.h"
#include"STD_TYPES.h"

#include"DIO_interface.h"

#include"KEY_interface.h"

#include"CLCD_interface.h"

#include"pre/KEY_interface.h"

#include"pre/CLCD_interface.h"
u8 x,y,count=0;
int main ()
{
	CLCD1_voidInial();
	CLCD_voidInial();
	KEY1_voidInit();
	KEY_voidInit();
	while(1)
	{
		do
		{
			x=KEY1_U8GetPressed();
			y=KEY_U8GetPressed();



		}while(x==NOTPRESSED && y==NOTPRESSED);
		if(x!=NOTPRESSED)
		{
			if(count<16)
			{
				CLCD_voidSendData(x);
				count++;
			}else if(count>=16)
			{
				CLCD1_voidSendData(x);
			}


		}else if(y!=NOTPRESSED)
		{
			if(count<16)
			{
				CLCD_voidSendData(y);
				count++;
			}else if(count>=16)
			{
				CLCD1_voidSendData(y);
			}
		}

	}
}
