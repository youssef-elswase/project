/*
 * main.c
 *
 *  Created on: ١٣‏/١٢‏/٢٠٢٤
 *      Author: hp
 */
#include "BIT-MATH.h"
#include "STD_Types.h"

#include "DIO_interface.h"

#include <util/delay.h>


int main (void)
{
	DIO_eunmSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);

	while(1)
	{
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		_delay_ms(1000);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		_delay_ms(1000);


	}
}
