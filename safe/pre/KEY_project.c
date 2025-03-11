/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:KEY_project

	layer:HAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
 */
#define F_CPU 8000000ul
#include <util/delay.h>

#include "../BIT-MATH.h"
#include "../STD_TYPES.h"

#include "../DIO_interface.h"

#include "KEY_interface.h"
#include "KEY_private.h"
#include "KEY_config.h"


void KEY1_voidInit (void)
{
	DIO_eunmSetPinInterPullUp     (KEY1_Port ,KEY1_R1 ,DIO_PIN_HIGH );
	DIO_eunmSetPinInterPullUp     (KEY1_Port ,KEY1_R2 ,DIO_PIN_HIGH );
	DIO_eunmSetPinInterPullUp     (KEY1_Port ,KEY1_R3 ,DIO_PIN_HIGH );
	DIO_eunmSetPinInterPullUp     (KEY1_Port ,KEY1_R4 ,DIO_PIN_HIGH );

	DIO_eunmSetPinDirection       (KEY1_Port ,KEY1_C1 ,DIO_PIN_OUTPUT );
	DIO_eunmSetPinDirection       (KEY1_Port ,KEY1_C2 ,DIO_PIN_OUTPUT );
	DIO_eunmSetPinDirection       (KEY1_Port ,KEY1_C3 ,DIO_PIN_OUTPUT );
	DIO_eunmSetPinDirection       (KEY1_Port ,KEY1_C4 ,DIO_PIN_OUTPUT );

	DIO_eunmSetPinValue           (KEY1_Port ,KEY1_C1 ,DIO_PIN_HIGH );
	DIO_eunmSetPinValue           (KEY1_Port ,KEY1_C2 ,DIO_PIN_HIGH );
	DIO_eunmSetPinValue           (KEY1_Port ,KEY1_C3 ,DIO_PIN_HIGH );
	DIO_eunmSetPinValue           (KEY1_Port ,KEY1_C4 ,DIO_PIN_HIGH );

}

u8 KEY1_U8GetPressed (void)
{
	u8 LOC_u8Return = NOTPRESSED;
	u8 LOC_u8GetPressed;

	u8 LOC_u8Row ;
	u8 LOC_u8Col ;

	for(LOC_u8Col = 0 + KEY1_COL_INIT ; LOC_u8Col < KEY1_COL_END + 1 ; LOC_u8Col++ )
	{
		DIO_eunmSetPinValue (KEY1_Port ,LOC_u8Col ,DIO_PIN_LOW);

		for(LOC_u8Row = 0 + KEY1_ROW_INIT ; LOC_u8Row < KEY1_ROW_END + 1 ; LOC_u8Row++ )
		{
			DIO_eunmGetPin   (KEY1_Port ,LOC_u8Row  ,&LOC_u8GetPressed);

			if(LOC_u8GetPressed == 0)
			{
				_delay_ms(50);
				DIO_eunmGetPin   (KEY1_Port ,LOC_u8Row  ,&LOC_u8GetPressed);
				if(LOC_u8GetPressed == 0)
				{
					LOC_u8Return = KEY1_u8Buttons[LOC_u8Row - KEY1_ROW_INIT][LOC_u8Col - KEY1_COL_INIT];
				}
				DIO_eunmGetPin   (KEY1_Port ,LOC_u8Row  ,&LOC_u8GetPressed);
				while (DIO_PIN_LOW == LOC_u8GetPressed)
				{
					DIO_eunmGetPin   (KEY1_Port ,LOC_u8Row  ,&LOC_u8GetPressed);
				}

				break;


			}


		}
		DIO_eunmSetPinValue           (KEY1_Port ,LOC_u8Col ,DIO_PIN_HIGH );
	}


	return LOC_u8Return;

}
