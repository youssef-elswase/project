/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:LED_project
	
	layer:HAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include "STD_Types.h"
#include "BIT-MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void LED_VoidInitialPin ( LED_Type LED_Configuration )
{
	DIO_eunmSetPinDirection ( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_OUTPUT );
}
void LED_VoidTurnOn     ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{
		DIO_eunmSetPinValue   ( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH );
	}
	else if ( LED_Configuration.Active_State == ACTIVE_LOW )
	{
		DIO_eunmSetPinValue   ( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW );
	}
}
void LED_VoidTurnOff    ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{
		DIO_eunmSetPinValue   ( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW );
	}
	else if ( LED_Configuration.Active_State == ACTIVE_LOW )
	{
		DIO_eunmSetPinValue   ( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH );
	}
}
void LED_VoidToggle     ( LED_Type LED_Configuration )
{
	DIO_eunmTogglePin  (LED_Configuration.Port , LED_Configuration.Pin);
}
