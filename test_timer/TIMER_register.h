/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------
    name:TIMER_register

	
	layer:MCAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef _TIMER_REGISTER_H_
#define _TIMER_REGISTER_H_


#define SREG *((volatile u8*)0x5F)

        /* ENABLE&FLAGE */

#define TIMSK *((volatile u8*)0x59)
#define TIFR *((volatile u8*)0x58)

        /* Timer0 */
		
#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define OCR0 *((volatile u8*)0x5C)

        /* Timer1 */

#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define TCNT1H *((volatile u8*)0x4D)
#define TCNT1L *((volatile u8*)0x4C)
#define TCNT1 *((volatile u16*)0x4C)
#define OCR1AH *((volatile u8*)0x4B)
#define OCR1AL *((volatile u8*)0x4A)
#define OCR1A *((volatile u16*)0x4A)
#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)
#define OCR1B *((volatile u16*)0x48)
#define ICR1H *((volatile u8*)0x47)
#define ICR1L *((volatile u8*)0x46)
#define ICR1 *((volatile u16*)0x46)

        /* Timer2 */

#define TCCR2 *((volatile u8*)0x45)
#define TCNT2 *((volatile u8*)0x44)
#define OCR2 *((volatile u8*)0x43)

        /* WDT */

#define WDTCR *((volatile u8*)0x41)




#endif