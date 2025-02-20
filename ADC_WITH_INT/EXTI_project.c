/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:EXTI_project

	layer:MCAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
 */
#include "BIT-MATH.h"
#include "STD_Types.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


void (*EXTI_CallBack[3]) (void) = { NULL } ; 

void EXTI_VoidInit(void)
{
	#ifdef EXTI_LINE
		#if EXTI_LINE == EXTI_LINE1
			#if EXTI_SENSE_MODE == EXTI_LOW_LEVEL
				CLR_BIT(MCUCR,2) ; CLR_BIT(MCUCR,3) ;
			#elif EXTI_SENSE_MODE == EXTI_ON_CHARGE
				CLR_BIT(MCUCR,2) ; SET_BIT(MCUCR,3) ;
			#elif EXTI_SENSE_MODE == EXTI_FALLING_EDGE
				SET_BIT(MCUCR,2) ; CLR_BIT(MCUCR,3) ;
			#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
				SET_BIT(MCUCR,2) ; SET_BIT(MCUCR,3) ;
			#endif
		#elif EXTI_LINE == EXTI_LINE0
			#if EXTI_SENSE_MODE == EXTI_LOW_LEVEL
				CLR_BIT(MCUCR,0) ; CLR_BIT(MCUCR,1) ;
			#elif EXTI_SENSE_MODE == EXTI_ON_CHARGE
				CLR_BIT(MCUCR,0) ; SET_BIT(MCUCR,1) ;
			#elif EXTI_SENSE_MODE == EXTI_FALLING_EDGE
				SET_BIT(MCUCR,0) ; CLR_BIT(MCUCR,1) ;
			#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
				SET_BIT(MCUCR,0) ; SET_BIT(MCUCR,1) ;
			#endif
		#elif EXTI_LINE == EXTI_LINE2
			#if EXTI_SENSE_MODE == EXTI_FALLING_EDGE
				 CLR_BIT(MCUCSR,6) ;
			#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
				 SET_BIT(MCUCSR,6) ;
			#else
				#error "Wrong INT0_SENSE configuration option"
		
		#endif

	#endif
#endif

}
void EXTI_VoidSetSignalLatch(u8 COPY_SenseMode, u8 COPY_u8Line)
{
	COPY_u8Line = (6 - COPY_u8Line) *-2;
	if(COPY_u8Line>=EXTI_LINE0 && COPY_u8Line<=EXTI_LINE1)
	{
		switch(COPY_SenseMode)
		{
		case EXTI_LOW_LEVEL:CLR_BIT(MCUCR,COPY_u8Line) ; CLR_BIT(MCUCR,COPY_u8Line+1) ;break;
		case EXTI_ON_CHANGE:SET_BIT(MCUCR,COPY_u8Line) ; CLR_BIT(MCUCR,COPY_u8Line+1) ;break;
		case EXTI_FALLING_EDGE:CLR_BIT(MCUCR,COPY_u8Line) ; SET_BIT(MCUCR,COPY_u8Line+1) ;break;
		case EXTI_RISING_EDGE:SET_BIT(MCUCR,COPY_u8Line) ; SET_BIT(MCUCR,COPY_u8Line+1) ;break;
		}
		
	}
	else
	{
		switch(COPY_SenseMode)
		{
		case EXTI_FALLING_EDGE: CLR_BIT(MCUCSR,6) ;break;
		case EXTI_RISING_EDGE : SET_BIT(MCUCSR,6) ;break;
		}
		
	}
}
u8 EXTI_VoidEnable(u8 COPY_u8Line)
{
	u8 local_u8ErrorStutas = OK;
	if((COPY_u8Line<EXTI_LINE1)&&(COPY_u8Line>EXTI_LINE2))
	{
		SET_BIT(GICR,COPY_u8Line);
	}
	else
	{
		local_u8ErrorStutas = NOK;
	}
	return local_u8ErrorStutas;
}
u8 EXTI_VoidDisable(u8 COPY_u8Line)
{
	u8 local_u8ErrorStutas = OK;
	if((COPY_u8Line<EXTI_LINE1)&&(COPY_u8Line>EXTI_LINE2))
	{ 
		CLR_BIT( GICR , COPY_u8Line );
	}
	else
	{
		local_u8ErrorStutas = NOK;
	}
	return local_u8ErrorStutas;
}
void EXTI_VoidClearFlag(u8 COPY_u8Line)
{
	SET_BIT( GIFR , COPY_u8Line );
}
u8 EXTI_u8GetFlag( u8 COPY_u8Line ){

	return RED_BIT( GIFR , COPY_u8Line );

}
void EXTI_VoidSetCallBack(void (*COPY_pvoidCallBack)(void) , u8 COPY_u8EXTILine )
{
	if(COPY_pvoidCallBack != NULL)
	{
		EXTI_CallBack[COPY_u8EXTILine] = COPY_pvoidCallBack;
	}
}

	void __vector_1(void) __attribute__((signal));
	void __vector_1(void)
	{
		if(EXTI_CallBack[0] != NULL)
		{
			EXTI_CallBack[0]();
			EXTI_VoidClearFlag( EXTI_LINE0 );
		}
	}
	
	void __vector_2(void) __attribute__((signal));
	void __vector_2(void)
	{
		if(EXTI_CallBack[1] != NULL)
		{
			EXTI_CallBack[1]();
			EXTI_VoidClearFlag( EXTI_LINE1 );
		}
	}
	
	void __vector_3(void) __attribute__((signal));
	void __vector_3(void)
	{

		if( EXTI_CallBack[2] != NULL ){

			EXTI_CallBack[2]();
			EXTI_VoidClearFlag( EXTI_LINE2 );

		}

	}
