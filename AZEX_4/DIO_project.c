/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:DIO_project

	layer:MCAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
 */
#include "BIT-MATH.h"
#include "STD_Types.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

DIO_ErrorStatus DIO_eunmSetPinDirection     (u8 COPY_u8PORT ,u8 COPY_u8PIN ,u8 COPY_u8Direction )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if((COPY_u8PORT <= DIO_PORTD)&&(COPY_u8PIN <= DIO_PIN7))
	{
		if (COPY_u8Direction == DIO_PIN_OUTPUT)
		{
			switch(COPY_u8PORT)
			{
			case DIO_PORTA: SET_BIT(DDRA_R,COPY_u8PIN); break;
			case DIO_PORTB: SET_BIT(DDRB_R,COPY_u8PIN); break;
			case DIO_PORTC: SET_BIT(DDRC_R,COPY_u8PIN); break;
			case DIO_PORTD: SET_BIT(DDRD_R,COPY_u8PIN); break;
			}
		}
		else if (COPY_u8Direction == DIO_PIN_INPUT)
		{
			switch(COPY_u8PORT)
			{
			case DIO_PORTA: CLR_BIT(DDRA_R,COPY_u8PIN); break;
			case DIO_PORTB: CLR_BIT(DDRB_R,COPY_u8PIN); break;
			case DIO_PORTC: CLR_BIT(DDRC_R,COPY_u8PIN); break;
			case DIO_PORTD: CLR_BIT(DDRD_R,COPY_u8PIN); break;
			}
		}
		else
		{
			LOC_enumStatus = DIO_NOK;
		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;
}
DIO_ErrorStatus DIO_eunmSetPinValue         (u8 COPY_u8PORT ,u8 COPY_u8PIN ,u8 COPY_u8Value     )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if((COPY_u8PORT <= DIO_PORTD)&&(COPY_u8PIN <= DIO_PIN7))
	{
		if (COPY_u8Value == DIO_PIN_HIGH)
		{
			switch(COPY_u8PORT)
			{
			case DIO_PORTA: SET_BIT(PORTA_R,COPY_u8PIN);break;
			case DIO_PORTB: SET_BIT(PORTB_R,COPY_u8PIN);break;
			case DIO_PORTC: SET_BIT(PORTC_R,COPY_u8PIN);break;
			case DIO_PORTD: SET_BIT(PORTD_R,COPY_u8PIN);break;
			}
		}
		else if (COPY_u8Value == DIO_PIN_LOW)
		{
			switch(COPY_u8PORT)
			{
			case DIO_PORTA: CLR_BIT(PORTA_R,COPY_u8PIN);break;
			case DIO_PORTB: CLR_BIT(PORTB_R,COPY_u8PIN);break;
			case DIO_PORTC: CLR_BIT(PORTC_R,COPY_u8PIN);break;
			case DIO_PORTD: CLR_BIT(PORTD_R,COPY_u8PIN);break;
			}
		}
		else
		{
			LOC_enumStatus = DIO_NOK ;
		}
	}

	else
	{
		LOC_enumStatus = DIO_NOK ;
	}

	return LOC_enumStatus ;
}
DIO_ErrorStatus DIO_eunmGetPin              (u8 COPY_u8PORT ,u8 COPY_u8PIN  ,u8 *COPY_PtrData   )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if((COPY_u8PORT <= DIO_PORTD)&&(COPY_u8PIN <= DIO_PIN7))
	{
		switch (COPY_u8PORT)
		{
		case DIO_PORTA: *COPY_PtrData = RED_BIT(PINA_R,COPY_u8PIN);break;
		case DIO_PORTB: *COPY_PtrData = RED_BIT(PINB_R,COPY_u8PIN);break;
		case DIO_PORTC: *COPY_PtrData = RED_BIT(PINC_R,COPY_u8PIN);break;
		case DIO_PORTD: *COPY_PtrData = RED_BIT(PIND_R,COPY_u8PIN);break;
		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;
}
DIO_ErrorStatus DIO_eunmTogglePin           (u8 COPY_u8PORT ,u8 COPY_u8PIN                      )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if((COPY_u8PORT <= DIO_PORTD)&&(COPY_u8PIN <= DIO_PIN7))
	{
		switch (COPY_u8PORT)
		{
		case DIO_PORTA: TOG_BIT(PORTA_R,COPY_u8PIN);break;
		case DIO_PORTB: TOG_BIT(PORTB_R,COPY_u8PIN);break;
		case DIO_PORTC: TOG_BIT(PORTC_R,COPY_u8PIN);break;
		case DIO_PORTD: TOG_BIT(PORTD_R,COPY_u8PIN);break;
		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;
}
DIO_ErrorStatus DIO_eunmSetPortDirection    (u8 COPY_u8PORT ,u8 COPY_u8Direction                )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if(COPY_u8PORT <= DIO_PORTD)
	{
		switch (COPY_u8PORT)
		{
		case DIO_PORTA: DDRA_R = COPY_u8Direction;break;
		case DIO_PORTB: DDRB_R = COPY_u8Direction;break;
		case DIO_PORTC: DDRC_R = COPY_u8Direction;break;
		case DIO_PORTD: DDRD_R = COPY_u8Direction;break;
		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;
}
DIO_ErrorStatus DIO_eunmSetPortValue        (u8 COPY_u8PORT ,u8 COPY_u8Value                    )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if((COPY_u8PORT <= DIO_PORTD) && ( (COPY_u8Value<=255) || (COPY_u8Value==DIO_PORT_LOW) || (COPY_u8Value==DIO_PORT_HIGH) ))
	{
		switch (COPY_u8PORT)
		{
		case DIO_PORTA: PORTA_R = COPY_u8Value;break;
		case DIO_PORTB: PORTB_R = COPY_u8Value;break;
		case DIO_PORTC: PORTC_R = COPY_u8Value;break;
		case DIO_PORTD: PORTD_R = COPY_u8Value;break;
		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;
}
DIO_ErrorStatus DIO_eunmGetPort             (u8 COPY_u8PORT ,u8 *COPY_PtrData			        )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if(COPY_u8PORT <= DIO_PORTD)
	{
		switch (COPY_u8PORT)
		{
		case DIO_PORTA: *COPY_PtrData = PINA_R;break;
		case DIO_PORTB: *COPY_PtrData = PINB_R;break;
		case DIO_PORTC: *COPY_PtrData = PINC_R;break;
		case DIO_PORTD: *COPY_PtrData = PIND_R;break;
		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;
}
DIO_ErrorStatus DIO_eunmToggelPort          (u8 COPY_u8PORT 				  			        )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if(COPY_u8PORT <= DIO_PORTD)
	{
		switch (COPY_u8PORT)
		{
		case DIO_PORTA: PORTA_R = ~PORTA_R;break;
		case DIO_PORTB: PORTB_R = ~PORTB_R;break;
		case DIO_PORTC: PORTC_R = ~PORTC_R;break;
		case DIO_PORTD: PORTD_R = ~PORTD_R;break;
		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus ;
}
DIO_ErrorStatus DIO_eunmSetPinInterPullUp     (u8 COPY_u8PORT ,u8 COPY_u8PIN ,u8 COPY_u8ConnectPullUp )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if((COPY_u8PORT <= DIO_PORTD) && (COPY_u8PIN <= DIO_PIN7))
	{
		switch(COPY_u8PORT)
		{
		case DIO_PORTA:
			if(COPY_u8ConnectPullUp == DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRA_R,COPY_u8PIN);
				SET_BIT(PORTA_R,COPY_u8PIN);
			}
			else
			{
				CLR_BIT(PORTA_R,COPY_u8PIN);
			}break;
		case DIO_PORTB:
			if(COPY_u8ConnectPullUp == DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRB_R,COPY_u8PIN);
				SET_BIT(PORTB_R,COPY_u8PIN);
			}
			else
			{
				CLR_BIT(PORTB_R,COPY_u8PIN);
			}break;
		case DIO_PORTC:
			if(COPY_u8ConnectPullUp == DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRC_R,COPY_u8PIN);
				SET_BIT(PORTC_R,COPY_u8PIN);
			}
			else
			{
				CLR_BIT(PORTC_R,COPY_u8PIN);
			}break;
		case DIO_PORTD:
			if(COPY_u8ConnectPullUp == DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRD_R,COPY_u8PIN);
				SET_BIT(PORTD_R,COPY_u8PIN);
			}
			else
			{
				CLR_BIT(PORTD_R,COPY_u8PIN);
			}break;

		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}


	return LOC_enumStatus ;
}
DIO_ErrorStatus DIO_eunmSetHighNibble         (u8 COPY_u8PORT ,u8 COPY_u8Value                        )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if(COPY_u8PORT <= DIO_PORTD)
	{
		COPY_u8Value = (COPY_u8Value<<4);
		switch(COPY_u8PORT)
		{
		case DIO_PORTA :
			PORTA_R&=0x0f;
			PORTA_R|=COPY_u8Value;
			break;
		case DIO_PORTB :
			PORTB_R&=0x0f;
			PORTB_R|=COPY_u8Value;
			break;
		case DIO_PORTC :
			PORTC_R&=0x0f;
			PORTC_R|=COPY_u8Value;
			break;
		case DIO_PORTD :
			PORTD_R&=0x0f;
			PORTD_R|=COPY_u8Value;
			break;
		default:break;

		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus ;
}

DIO_ErrorStatus DIO_voidWriteLowNibble          (u8 COPY_u8PORT ,u8 COPY_u8Value                        )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK;
	if(COPY_u8PORT <= DIO_PORTD)
	{
		COPY_u8Value &=0x0f;
		switch(COPY_u8PORT)
		{
		case DIO_PORTA :
			PORTA_R&=0xf0;
			PORTA_R|=COPY_u8Value;
			break;
		case DIO_PORTB :
			PORTB_R&=0xf0;
			PORTB_R|=COPY_u8Value;
			break;
		case DIO_PORTC :
			PORTC_R&=0xf0;
			PORTC_R|=COPY_u8Value;
			break;
		case DIO_PORTD :
			PORTD_R&=0xf0;
			PORTD_R|=COPY_u8Value;
			break;
		default:break;

		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus ;

}






