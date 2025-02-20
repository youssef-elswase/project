/*
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:DIO_private
	
	layer:MCAL

	by:Youssef Elswase


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/* Group A Registers */
#define PORTA_R  *((volatile u8*)0x3B)
#define DDRA_R   *((volatile u8*)0x3A)
#define PINA_R   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB_R  *((volatile u8*)0x38)
#define DDRB_R   *((volatile u8*)0x37)
#define PINB_R   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC_R  *((volatile u8*)0x35)
#define DDRC_R   *((volatile u8*)0x34)
#define PINC_R   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD_R  *((volatile u8*)0x32)
#define DDRD_R   *((volatile u8*)0x31)
#define PIND_R   *((volatile u8*)0x30)

/*PULL UP */
#define  SFIOR   *((volatile u8*)0x50)


#endif
