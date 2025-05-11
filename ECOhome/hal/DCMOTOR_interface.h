/*
 * DCMOTOR_interface.h
 *
 *  Created on: Feb 19, 2025
 *      Author: alaa hassan
 */

#ifndef HAL_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_INTERFACE_H_

#define DCMOTOR_CW		0
	#define DCMOTOR_CCW		1
	#define DCMOTOR_STOP	2

	typedef struct
	{
		u8 Copy_uint8DcMotorPort ;
		u8 Copy_uint8DcMotorPinA ;
		u8 Copy_uint8DcMotorPinB ;
	} DCMOTOR_CONFIG ;

	u8 DCMOTOR_uint8Control (DCMOTOR_CONFIG * DcMotor , u8 Copy_uint8State) ;


#endif /* HAL_DCMOTOR_INTERFACE_H_ */
