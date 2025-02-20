/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:KEY_config
	
	layer:HAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef _KEY1_CONFIG_H_
#define _KEY1_CONFIG_H_

#define KEY1_ROW_INIT DIO_PIN0
#define KEY1_ROW_END DIO_PIN3

#define KEY1_COL_INIT DIO_PIN4
#define KEY1_COL_END DIO_PIN7

u8 KEY1_u8Buttons[4][4]={
	{'E','L','S','W'},
	{'A','S','E','*'},
	{'a','q','f','a'},
	{'d','r','q','='}
};

#define KEY1_Port DIO_PORTC

#define KEY1_R1 DIO_PIN0
#define KEY1_R2 DIO_PIN1
#define KEY1_R3 DIO_PIN2
#define KEY1_R4 DIO_PIN3

#define KEY1_C1 DIO_PIN4
#define KEY1_C2 DIO_PIN5
#define KEY1_C3 DIO_PIN6
#define KEY1_C4 DIO_PIN7

#endif
