/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:GIF_project
	
	layer:MCAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "BIT-MATH.h"
#include "STD_TYPES.h"

#include "GIF_register.h"
#include "GIF_interface.h"

void GIF_VoidEnable (void)
{
	SET_BIT(SREG,SREG_I);
}
void GIF_VoidDisable (void)
{
	CLR_BIT(SREG,SREG_I);
}