/*
 * EEPROM_interface.h
 *
 *  Created on: Feb 1, 2025
 *      Author: alaa hassan
 */

#ifndef HAL_EEPROM_INTERFACE_H_
#define HAL_EEPROM_INTERFACE_H_
#include"../lib/std_typs.h"

void EEPROM_vSendDataByte   (u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);

void EEPROM_u8ReadDataByte  (u16 Copy_u16LocationAddress, u8 *Local_u8Data  );



#endif /* HAL_EEPROM_INTERFACE_H_ */
