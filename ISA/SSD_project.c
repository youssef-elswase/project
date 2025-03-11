/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:SSD_project
	
	layer:HAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "STD_TYPES.h"
#include "BIT-MATH.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR ;

void SSD_VoidIntialDataPin (SSD_Type COPY_StructConfig)
{
	DIO_eunmSetPortDirection(COPY_StructConfig.DataPort,DIO_PORT_OUTPUT);
}
void SSD_VoidEnable        (SSD_Type COPY_StructConfig)
{
	if(COPY_StructConfig.Type == SSD_CommonCathod)
	{
		 DIO_eunmSetPinDirection  (COPY_StructConfig.EnablePort , COPY_StructConfig.EnablePin , DIO_PIN_HIGH);
		 DIO_eunmSetPinValue (COPY_StructConfig.EnablePort,COPY_StructConfig.EnablePin,DIO_PIN_LOW);
	}
	else if (COPY_StructConfig.Type == SSD_CommonAnode)
	{
		DIO_eunmSetPinDirection  (COPY_StructConfig.EnablePort , COPY_StructConfig.EnablePin , DIO_PIN_HIGH);
		 DIO_eunmSetPinValue (COPY_StructConfig.EnablePort,COPY_StructConfig.EnablePin,DIO_PIN_HIGH);
	}
}
void SSD_VoidDisable       (SSD_Type COPY_StructConfig)
{
	if(COPY_StructConfig.Type == SSD_CommonCathod)
	{
		 DIO_eunmSetPinDirection  (COPY_StructConfig.EnablePort , COPY_StructConfig.EnablePin , DIO_PIN_HIGH);
		 DIO_eunmSetPinValue (COPY_StructConfig.EnablePort,COPY_StructConfig.EnablePin,DIO_PIN_HIGH);
	}
	else if (COPY_StructConfig.Type == SSD_CommonAnode)
	{
		DIO_eunmSetPinDirection  (COPY_StructConfig.EnablePort , COPY_StructConfig.EnablePin , DIO_PIN_HIGH);
		 DIO_eunmSetPinValue (COPY_StructConfig.EnablePort,COPY_StructConfig.EnablePin,DIO_PIN_LOW);
	}
}
void SSD_VoidSendNumber    (SSD_Type COPY_StructConfig, u8 COPY_u8Number)
{
	if(COPY_StructConfig.Type == SSD_CommonCathod)
	{
		DIO_eunmSetPortValue        (COPY_StructConfig.DataPort , Local_u8SSDNumbers[ COPY_u8Number ]);
	}
	else if (COPY_StructConfig.Type == SSD_CommonAnode)
	{
		 DIO_eunmSetPortValue        (COPY_StructConfig.DataPort , ~(Local_u8SSDNumbers[ COPY_u8Number ]));
	}
	
}
