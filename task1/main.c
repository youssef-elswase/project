/*
 * main.c
 *
 *  Created on: ٢٩‏/١١‏/٢٠٢٤
 *      Author: hp
 */
#include "std/BIT-MATH.h"
#include "std/STD_Types.h"

#include "DIO_interface.h"

#define F_CPU 8000000ul
#include <util/delay.h>

int main (void)
{
	DIO_eunmSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT); //1
	DIO_eunmSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT); //1
	DIO_eunmSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT); //1


	while(1)
	{
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);

		_delay_ms(1000);

		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		DIO_eunmSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
		_delay_ms(1000);
	}









}
