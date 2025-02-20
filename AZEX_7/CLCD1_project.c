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

#include "CLCD1_config.h"
#include "CLCD1_interface.h"
#include "CLCD1_private.h"
#include "CLCD1_extrachar.h"



void CLCD1_voidInial        ( void                         )
{
#if CLCD1_MODE == 8
	_delay_ms(50);

	DIO_eunmSetPortDirection (CLCD1_DATA_PORT,DIO_PORT_OUTPUT);
	DIO_eunmSetPinDirection (CLCD1_CONTROL_PORT,CLCD1_RS,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD1_CONTROL_PORT,CLCD1_RM,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD1_CONTROL_PORT,CLCD1_EN,DIO_PIN_OUTPUT);

	CLCD1_voidSendCommand (lcd_Home);
	_delay_ms(1);

	CLCD1_voidSendCommand (EIGHT_BITS);
	_delay_ms(1);

	CLCD1_voidSendCommand (lcd_DisplayOn_CursorOn);
	_delay_ms(1);

	 CLCD1_ClearScreen      ();

	CLCD1_voidSendCommand (lcd_EntryMode);
	_delay_ms(1);

#elif CLCD1_MODE == 4

	_delay_ms(50);
	DIO_eunmSetPinDirection (CLCD1_DATA_PORT,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD1_DATA_PORT,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD1_DATA_PORT,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD1_DATA_PORT,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD1_CONTROL_PORT,CLCD1_RS,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD1_CONTROL_PORT,CLCD1_RM,DIO_PIN_OUTPUT);
	DIO_eunmSetPinDirection (CLCD1_CONTROL_PORT,CLCD1_EN,DIO_PIN_OUTPUT);

	CLCD1_voidSendCommand (lcd_Home);
	_delay_ms(30);

	CLCD1_voidSendCommand (FOUR_BITS);
	_delay_ms(1);

	CLCD1_voidSendCommand (lcd_DisplayOn_CursorOn);
	_delay_ms(1);

	CLCD1_ClearScreen      (                        );

	CLCD1_voidSendCommand (lcd_EntryMode);
	_delay_ms(1);

#endif

}
void CLCD1_voidSendData     ( u8 COPY_Data                 )
{
#if CLCD1_MODE == 8

	DIO_eunmSetPortValue (CLCD1_DATA_PORT,COPY_Data);
	DIO_eunmSetPinValue (CLCD1_CONTROL_PORT,CLCD1_RS,DIO_PIN_HIGH);
	DIO_eunmSetPinValue (CLCD1_CONTROL_PORT,CLCD1_RM,DIO_PIN_LOW);
	CLCD1_voidSendFallingEdge();

#elif CLCD1_MODE == 4

	DIO_eunmSetPinValue (CLCD1_CONTROL_PORT,CLCD1_RS,DIO_PIN_HIGH);
	DIO_eunmSetPinValue (CLCD1_CONTROL_PORT,CLCD1_RM,DIO_PIN_LOW);
	DIO_voidWriteHighNibble (CLCD1_DATA_PORT,(COPY_Data>>4));
	CLCD1_voidSendFallingEdge();
	DIO_voidWriteHighNibble (CLCD1_DATA_PORT,COPY_Data);
	CLCD1_voidSendFallingEdge();


#endif
}
void CLCD1_voidSendCommand  ( u8 COPY_Command              )
{
#if CLCD1_MODE == 8

	DIO_eunmSetPortValue (CLCD1_DATA_PORT,COPY_Command);
	DIO_eunmSetPinValue (CLCD1_CONTROL_PORT,CLCD1_RS,DIO_PIN_LOW);
	DIO_eunmSetPinValue (CLCD1_CONTROL_PORT,CLCD1_RM,DIO_PIN_LOW);
	CLCD1_voidSendFallingEdge();

#elif CLCD1_MODE == 4

	DIO_eunmSetPinValue (CLCD1_CONTROL_PORT,CLCD1_RS,DIO_PIN_LOW);
	DIO_eunmSetPinValue (CLCD1_CONTROL_PORT,CLCD1_RM,DIO_PIN_LOW);
	DIO_voidWriteHighNibble (CLCD1_DATA_PORT,(COPY_Command>>4));
	CLCD1_voidSendFallingEdge();
	DIO_voidWriteHighNibble (CLCD1_DATA_PORT,COPY_Command);
	CLCD1_voidSendFallingEdge();


#endif
}
void CLCD1_voidSendString   ( const u8 *COPY_u8PtrString   )
{
	u8 LOC_u8Iterator = 0;
	while(COPY_u8PtrString[LOC_u8Iterator] != '\0')
	{
		CLCD1_voidSendData(COPY_u8PtrString[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}
void CLCD1_SendNumber       ( u64 COPY_u64Number           )
{
	u64 LOC_u64Reversed = 1;
	if(COPY_u64Number==0)
	{
		CLCD1_voidSendData('0');
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
void CLCD1_SetPosition      ( u8 COPY_u8Row , u8 COPY_u8Col)
{
	u8 LOC_u8Data ;
	if(COPY_u8Row<1||COPY_u8Row>4||COPY_u8Col>20||COPY_u8Col<1)
	{
		LOC_u8Data = lcd_SetCursor;
	}
	else if (COPY_u8Row == CLCD1_ROW_1)
	{
		LOC_u8Data = ((lcd_SetCursor) + (COPY_u8Col - 1));
	}
	else if (COPY_u8Row == CLCD1_ROW_2)
	{
		LOC_u8Data = ((lcd_SetCursor) + (0x40) + (COPY_u8Col - 1));
	}
	else if (COPY_u8Row == CLCD1_ROW_3)
	{
		LOC_u8Data = ((lcd_SetCursor) +  (0x14) + (COPY_u8Col - 1));
	}
	else if (COPY_u8Row == CLCD1_ROW_4)
	{
		LOC_u8Data = ((lcd_SetCursor) + (0x54) + (COPY_u8Col - 1));
	}
	CLCD1_voidSendCommand (LOC_u8Data);
	_delay_ms(1);
}
void CLCD1_SetExtraChar     ( u8 COPY_u8Row , u8 COPY_u8Col)
{
	u8 LOC_u8Iterator = 0;
	CLCD1_voidSendCommand (lcd_CGRAM);

	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < (sizeof(CLCD1_u8Extrachar)/sizeof(CLCD1_u8Extrachar[0])) ; LOC_u8Iterator++ )
	{
		CLCD1_voidSendData ( CLCD1_u8Extrachar[LOC_u8Iterator] );
	}

	CLCD1_SetPosition ( COPY_u8Row , COPY_u8Col );

	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++ )
	{
		CLCD1_voidSendData ( LOC_u8Iterator );
	}
}
void CLCD1_ClearScreen      ( void                         )
{
	CLCD1_voidSendCommand (lcd_Clear);
	_delay_ms(10);
}
static void CLCD1_voidSendFallingEdge()
{
	DIO_eunmSetPinValue(CLCD1_CONTROL_PORT,CLCD1_EN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_eunmSetPinValue(CLCD1_CONTROL_PORT,CLCD1_EN,DIO_PIN_LOW);
	_delay_ms(1);
}



