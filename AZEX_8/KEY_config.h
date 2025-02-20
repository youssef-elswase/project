/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:KEY_config
	
	layer:HAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef _KEY_CONFIG_H_
#define _KEY_CONFIG_H_

#define KEY_ROW_INIT DIO_PIN0
#define KEY_ROW_END DIO_PIN3

#define KEY_COL_INIT DIO_PIN4
#define KEY_COL_END DIO_PIN7

u8 KEY_u8Buttons[4][4]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'?','0','=','+'}
};

#define KEY_Port DIO_PORTC

#define KEY_R1 DIO_PIN0
#define KEY_R2 DIO_PIN1
#define KEY_R3 DIO_PIN2
#define KEY_R4 DIO_PIN3

#define KEY_C1 DIO_PIN4
#define KEY_C2 DIO_PIN5
#define KEY_C3 DIO_PIN6
#define KEY_C4 DIO_PIN7

#endif
