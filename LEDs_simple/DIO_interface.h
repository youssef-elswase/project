/*
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:DIO_interface
	
	layer:MCAL

	by:Youssef Elswase


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1

#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1

#define DIO_PORT_INPUT  0
#define DIO_PORT_OUTPUT 0XFF

#define DIO_PORT_LOW  0
#define DIO_PORT_HIGH 0XFF

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

typedef enum{
	DIO_NOK,
	DIO_OK
}DIO_ErrorStatus;


DIO_ErrorStatus DIO_eunmSetPinDirection     (u8 COPY_u8PORT ,u8 COPY_u8PIN ,u8 COPY_u8Direction );
DIO_ErrorStatus DIO_eunmSetPinValue         (u8 COPY_u8PORT ,u8 COPY_u8PIN ,u8 COPY_u8Value     );
DIO_ErrorStatus DIO_eunmGetPin              (u8 COPY_u8PORT ,u8 COPY_u8PIN  ,u8 *COPY_PtrData   );
DIO_ErrorStatus DIO_eunmTogglePin		    (u8 COPY_u8PORT ,u8 COPY_u8PIN  			        );
DIO_ErrorStatus DIO_eunmSetPortDirection    (u8 COPY_u8PORT ,u8 COPY_u8Direction                );
DIO_ErrorStatus DIO_eunmSetPortValue        (u8 COPY_u8PORT ,u8 COPY_u8Value                    );
DIO_ErrorStatus DIO_eunmGetPort         	(u8 COPY_u8PORT ,u8 *COPYs_PtrData			        );
DIO_ErrorStatus DIO_eunmToggelPort          (u8 COPY_u8PORT 				  			        );







#endif
