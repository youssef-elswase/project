/*
 * Servo_Motor_prog.c
 *
 *  Created on: Feb 19, 2025
 *      Author: alaa hassan
 */



#include "../lib/BIT_MATH.h"
#include "../lib/std_typs.h"

#include "Servo_Motor_interface.h"
#include "Servo_Motor_config.h"
#include "Servo_Motor_private.h"
#include "../MCAL/DIO_intervace.h"

#include "../MCAL/TIMER_interface.h"
#include "../MCAL/TIMER_private.h"

void SM_vInit(void)
{
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
}

void SM_vTimer1Degree(s8 degree)
{
  TCNT1 = 0;
  double value = degree * .005555555556;

  if (0 < value <= 90)
  {
    value += 1.5;
  }
  else if (-90 <= value < 0)
  {
    value -= 1.5;
  }
  OCR1A = value * 1000;
}
