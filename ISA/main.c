/*
 * main.c
 *
 *  Created on: ١٥‏/١٢‏/٢٠٢٤
 *      Author: hp
 */
#include "BIT-MATH.h"
#include "STD_Types.h"

#include "SSD_interface.h"

#include "SW_interface.h"

#include "DIO_interface.h"
#include "DIO_private.h"


#define NOT_DONE 0
#define DONE 1

#define F_CPU 8000000ul
#include <util/delay.h>
int main (void)
{
	SW_Type sw0 ={DIO_PORTA,DIO_PIN0,SW_INT_PULL_UP};
	SW_Type sw1 ={DIO_PORTA,DIO_PIN1,SW_INT_PULL_UP};
	SW_Type sw2 ={DIO_PORTA,DIO_PIN2,SW_INT_PULL_UP};
	SW_Type sw3 ={DIO_PORTA,DIO_PIN3,SW_INT_PULL_UP};
	SW_Type sw4 ={DIO_PORTA,DIO_PIN4,SW_INT_PULL_UP};
	SW_Type sw5 ={DIO_PORTA,DIO_PIN5,SW_INT_PULL_UP};
	SW_Type sw6 ={DIO_PORTA,DIO_PIN6,SW_INT_PULL_UP};
	SW_Type sw7 ={DIO_PORTA,DIO_PIN7,SW_INT_PULL_UP};

	SSD_Type ssd0 = {SSD_CommonCathod,SSD_PORTD,SSD_PORTC,SSD_PIN0};
	SSD_Type ssd1 = {SSD_CommonCathod,SSD_PORTD,SSD_PORTC,SSD_PIN1};

	SW_VoidInital(sw0);
	SW_VoidInital(sw1);
	SW_VoidInital(sw2);
	SW_VoidInital(sw3);
	SW_VoidInital(sw4);
	SW_VoidInital(sw5);
	SW_VoidInital(sw6);
	SW_VoidInital(sw7);

	SSD_VoidIntialDataPin(ssd0);
	SSD_VoidIntialDataPin(ssd1);

	u8 x,y,value;
	SW_Type arrx[]={sw0,sw1,sw2};
	SW_Type arry[]={sw3,sw4,sw5};

	while (1)
	{
		x=0;
		y=0;
		value=0;
		// value x
		for(int i=0; i<3 ; i++)
		{
			if(SW_u8GetPressed(arrx[i]) == SW_NOT_PRESSED )
			{
				switch((arrx[i].Pin))
				{
				case 0:
					x+=1;
					break;
				case 1:
					x+=2;
					break;
				case 2:
					x+=4;
					break;
				}
			}
		}
		// value y
		for(int i=0; i<3 ; i++)
		{
			if(SW_u8GetPressed(arry[i]) == SW_NOT_PRESSED )
			{
				switch((arry[i].Pin))
				{
				case 3:
					y+=1;
					break;
				case 4:
					y+=2;
					break;
				case 5:
					y+=4;
					break;
				}
			}
		}

		// output

		switch(PINA_R>>6)
				{
				case 0 :
					value = x+y;
					break;
				case 1 :
					value = x-y;
					break;
				case 2 :
					value = x*y;
					break;
				case 3 :
					value = x/y;
					break;

				}

		SSD_VoidEnable (ssd0);
		SSD_VoidDisable (ssd1);
		SSD_VoidSendNumber (ssd0,value/10);
		_delay_ms(5);
		SSD_VoidEnable (ssd1);
		SSD_VoidDisable (ssd0);
		SSD_VoidSendNumber (ssd1,value%10);
		_delay_ms(5);

	}


	/*

	while(1)
	{

		// value x
		switch(PINA_R)
		{
		case 0 :
			x=0;
			break;
		case 1 :
			x=1;
			break;
		case 2 :
			x=2;
			break;
		case 3 :
			x=3;
			break;
		case 4 :
			x=4;
			break;
		case 5 :
			x=5;
			break;
		case 6 :
			x=6;
			break;
		case 7 :
			x=7;
			break;

		}
		// value y
		switch(PINA_R>>3)
		{
		case 0 :
			y=0;
			break;
		case 1 :
			y=1;
			break;
		case 2 :
			y=2;
			break;
		case 3 :
			y=3;
			break;
		case 4 :
			y=4;
			break;
		case 5 :
			y=5;
			break;
		case 6 :
			y=6;
			break;
		case 7 :
			y=7;
			break;

		}
		// output
		switch(PINA_R>>6)
		{
		case 0 :
			value = x+y;
			break;
		case 1 :
			value = x-y;
			break;
		case 2 :
			value = x*y;
			break;
		case 3 :
			value = x/y;
			break;

		}



		SSD_VoidEnable (ssd0);
		SSD_VoidDisable (ssd1);
		SSD_VoidSendNumber (ssd0,value/10);
		_delay_ms(5);
		SSD_VoidEnable (ssd1);
		SSD_VoidDisable (ssd0);
		SSD_VoidSendNumber (ssd1,value%10);
		_delay_ms(5);
	}

	 */

}


