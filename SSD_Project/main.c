/*
 * main.c
 *
 *  Created on: ٠١‏/١٢‏/٢٠٢٤
 *      Author: hp
 */
#include "BIT-MATH.h"
#include "STD_Types.h"

#include "SSD_interface.h"
#define F_CPU 8000000ul
#include <util/delay.h>
int main (void)
{
	SSD_Type SSD ={SSD_CommonCathod
			,SSD_PORTC
			,SSD_PORTD
			,SSD_PIN0  };
	SSD_VoidIntialDataPin(SSD);
	SSD_VoidEnable(SSD);
	u8 arr[10]={0,1,2,3,4,5,6,7,8,9};
	while(1)
	{
		for(int i=0; i<=9;i++)
		{
			SSD_VoidSendNumber(SSD,arr[i]);
			_delay_ms(1000);

		}
	}
}
