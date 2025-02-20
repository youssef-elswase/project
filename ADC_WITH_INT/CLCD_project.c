/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:CLCD_project

	layer:HAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

#define F_CPU 8000000ul
#include "util/delay.h"

#include "STD_Types.h"
#include "BIT-MATH.h"

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_extrachar.h"



void CLCD_voidInial        ( void                         )
{
#if CLCD_MODE == 8
	_delay_ms(50);

	DIO_eunmSetPortDirection (CLCD_DATA_PORT,DIO_PORT_OUTPUT);
	DIO_eunmSetPinDirection (CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD_CONTROL_PORT,CLCD_RM,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_OUTPUT);

	CLCD_voidSendCommand (lcd_Home);
	_delay_ms(1);

	CLCD_voidSendCommand (EIGHT_BITS);
	_delay_ms(1);

	CLCD_voidSendCommand (lcd_DisplayOn_CursorOn);
	_delay_ms(1);

	 CLCD_ClearScreen      ();

	CLCD_voidSendCommand (lcd_EntryMode);
	_delay_ms(1);

#elif CLCD_MODE == 4

	_delay_ms(50);
	DIO_eunmSetPinDirection (CLCD_DATA_PORT,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD_DATA_PORT,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD_DATA_PORT,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD_DATA_PORT,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD_CONTROL_PORT,CLCD_RM,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_OUTPUT);

	CLCD_voidSendCommand (lcd_Home);
	_delay_ms(30);

	CLCD_voidSendCommand (FOUR_BITS);
	_delay_ms(1);

	CLCD_voidSendCommand (lcd_DisplayOn_CursorOn);
	_delay_ms(1);

	CLCD_ClearScreen      (                        );

	CLCD_voidSendCommand (lcd_EntryMode);
	_delay_ms(1);

#endif

}
void CLCD_voidSendData     ( u8 COPY_Data                 )
{
#if CLCD_MODE == 8

	DIO_eunmSetPortValue (CLCD_DATA_PORT,COPY_Data);
	DIO_eunmSetPinValue (CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_HIGH);
	DIO_eunmSetPinValue (CLCD_CONTROL_PORT,CLCD_RM,DIO_PIN_LOW);
	CLCD_voidSendFallingEdge();

#elif CLCD_MODE == 4

	DIO_eunmSetPinValue (CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_HIGH);
	DIO_eunmSetPinValue (CLCD_CONTROL_PORT,CLCD_RM,DIO_PIN_LOW);
	DIO_voidWriteHighNibble (CLCD_DATA_PORT,(COPY_Data>>4));
	CLCD_voidSendFallingEdge();
	DIO_voidWriteHighNibble (CLCD_DATA_PORT,COPY_Data);
	CLCD_voidSendFallingEdge();


#endif
}
void CLCD_voidSendCommand  ( u8 COPY_Command              )
{
#if CLCD_MODE == 8

	DIO_eunmSetPortValue (CLCD_DATA_PORT,COPY_Command);
	DIO_eunmSetPinValue (CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_LOW);
	DIO_eunmSetPinValue (CLCD_CONTROL_PORT,CLCD_RM,DIO_PIN_LOW);
	CLCD_voidSendFallingEdge();

#elif CLCD_MODE == 4

	DIO_eunmSetPinValue (CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_LOW);
	DIO_eunmSetPinValue (CLCD_CONTROL_PORT,CLCD_RM,DIO_PIN_LOW);
	DIO_voidWriteHighNibble (CLCD_DATA_PORT,(COPY_Command>>4));
	CLCD_voidSendFallingEdge();
	DIO_voidWriteHighNibble (CLCD_DATA_PORT,COPY_Command);
	CLCD_voidSendFallingEdge();


#endif
}
void CLCD_voidSendString   ( const u8 *COPY_u8PtrString   )
{
	u8 LOC_u8Iterator = 0;
	while(COPY_u8PtrString[LOC_u8Iterator] != '\0')
	{
		CLCD_voidSendData(COPY_u8PtrString[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}
void CLCD_SendNumber       ( u64 COPY_u64Number           )
{
	u64 LOC_u64Reversed = 1;
	if(COPY_u64Number==0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		while(COPY_u64Number != 0)
		{
			LOC_u64Reversed = ( LOC_u64Reversed*10 ) + ( COPY_u64Number%10 );
			COPY_u64Number/=10;
		}
		while(LOC_u64Reversed != 1)
		{
			LOC_u64Reversed = ( LOC_u64Reversed%10 ) + 48;
			LOC_u64Reversed/=10;
		}
	}
}
void CLCD_SetPosition      ( u8 COPY_u8Row , u8 COPY_u8Col)
{
	u8 LOC_u8Data ;
	if(COPY_u8Row<1||COPY_u8Row>2||COPY_u8Col>16||COPY_u8Col<1)
	{
		LOC_u8Data = lcd_SetCursor;
	}
	else if (COPY_u8Row == CLCD_ROW_1)
	{
		LOC_u8Data = ((lcd_SetCursor) + (COPY_u8Col - 1));
	}
	else if (COPY_u8Row == CLCD_ROW_2)
	{
		LOC_u8Data = ((lcd_SetCursor) + (64) + (COPY_u8Col - 1));
	}
	CLCD_voidSendCommand (LOC_u8Data);
	_delay_ms(1);
}
void CLCD_SetExtraChar     ( u8 COPY_u8Row , u8 COPY_u8Col)
{
	u8 LOC_u8Iterator = 0;
	CLCD_voidSendCommand (lcd_CGRAM);

	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < (sizeof(CLCD_u8Extrachar)/sizeof(CLCD_u8Extrachar[0])) ; LOC_u8Iterator++ )
	{
		CLCD_voidSendData ( CLCD_u8Extrachar[LOC_u8Iterator] );
	}

	CLCD_SetPosition ( COPY_u8Row , COPY_u8Col );

	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++ )
	{
		CLCD_voidSendData ( LOC_u8Iterator );
	}
}
void CLCD_ClearScreen      ( void                         )
{
	CLCD_voidSendCommand (lcd_Clear);
	_delay_ms(10);
}
static void CLCD_voidSendFallingEdge()
{
	DIO_eunmSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_eunmSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_LOW);
	_delay_ms(1);
}




