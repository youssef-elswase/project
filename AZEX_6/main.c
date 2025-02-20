/*
 * main.c
 *
 *  Created on: ٢٥‏/٠١‏/٢٠٢٥
 *      Author: hp
 */
#include<util/delay.h>

#include"BIT-MATH.h"
#include"STD_TYPES.h"

#include"DIO_interface.h"

#include"CLCD_interface.h"

#include"KEY_interface.h"

#include"SSD_interface.h"

SSD_Type ssd1 ={SSD_CommonCathod,SSD_PORTB,SSD_PORTA,SSD_PIN0};
SSD_Type ssd2 ={SSD_CommonCathod,SSD_PORTB,SSD_PORTA,SSD_PIN1};

u8 z,a0=0,a1=0;
int main()
{
	u8 y=0;
	u8 x=NOTPRESSED;
	CLCD_voidInial();
	KEY_voidInit();
	SSD_VoidIntialDataPin(ssd1);
	SSD_VoidIntialDataPin(ssd2);
	while(1)
	{


		do{
			x=KEY_U8GetPressed();
			y=x;
			if(x!=NOTPRESSED)
			{
				CLCD_voidSendData(x);
				break;
			}
			SSD_VoidDisable(ssd2);
			SSD_VoidEnable(ssd1);
			SSD_VoidSendNumber(ssd1,a0-48);
			_delay_ms(5);
			SSD_VoidDisable(ssd1);
			SSD_VoidEnable(ssd2);
			SSD_VoidSendNumber(ssd2,a1-48);
			_delay_ms(5);
		}while(1);
		a1=a0;
		a0=y;



	}

}

