/*
 * BUZ_prog.c
 *
 *  Created on: Feb 2, 2025
 *      Author: alaa hassan
 */


#include "../lib/std_typs.h"
#include "../lib/BIT_MATH.h"

#include "../MCAL/DIO_intervace.h"

#include "BUZ_interface.h"
#include "BUZ_private.h"
#include "BUZ_config.h"

/*___________________________________________________________________________________________________________________*/

/*
* Breif : This Function initialize the pin which connected to BUZ as output pin
* Parameters :
            => struct has the BUZ porn , pin , status
* return : void
*/
void BUZ_vInit(BUZ_config BUZ_Configuration)
{

	DIO_enumSetPinDirection(BUZ_Configuration.PortName, BUZ_Configuration.PinNumber, DIO_PIN_OUTPUT);
}

/*___________________________________________________________________________________________________________________*/

/*
* Breif : This Function set high on BUZ pin ( BUZ on )
* Parameters :
            => struct has the BUZ porn , pin , status
* return : void
*/
void BUZ_vOn(BUZ_config BUZ_Configuration)
{

  if (BUZ_Configuration.ActiveState == ACTIVE_HIGH)
  {

	  DIO_enumWritePinValue(BUZ_Configuration.PortName, BUZ_Configuration.PinNumber, DIO_PIN_OUTPUT);
  }
  else if (BUZ_Configuration.ActiveState == ACTIVE_LOW)
  {

	  DIO_enumWritePinValue(BUZ_Configuration.PortName, BUZ_Configuration.PinNumber, DIO_PIN_OUTPUT);
  }
}

/*___________________________________________________________________________________________________________________*/

/*
* Breif : This Function set low on BUZ pin ( BUZ off )
* Parameters :
              => struct has the BUZ porn , pin , status
* return : void
*/
void BUZ_vOff(BUZ_config BUZ_Configuration)
{

  if (BUZ_Configuration.ActiveState == ACTIVE_HIGH)
  {

	  DIO_enumWritePinValue(BUZ_Configuration.PortName, BUZ_Configuration.PinNumber, DIO_PIN_OUTPUT);
  }
  else if (BUZ_Configuration.ActiveState == ACTIVE_LOW)
  {

	  DIO_enumWritePinValue(BUZ_Configuration.PortName, BUZ_Configuration.PinNumber, DIO_PIN_OUTPUT);
  }
}

/*___________________________________________________________________________________________________________________*/

/*
* Breif : This Function toggle BUZ pin
* Parameters :
            => struct has the BUZ porn , pin , status
* return : void
*/
void BUZ_vTog(BUZ_config BUZ_Configuration)
{
	DIO_enumTogglePinValue(BUZ_Configuration.PortName, BUZ_Configuration.PinNumber);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
