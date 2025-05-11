/*
 * EEPROM_interface.h
 *
 *  Created on: Feb 1, 2025
 *      Author: alaa hassan
 */

#ifndef MCAL_EEPROM_INTERFACE_H_
#define MCAL_EEPROM_INTERFACE_H_

#include"../lib/std_typs.h"
void EEPROM_vWrite         (u16 address, u8 data);

u8   EEPROM_vRead          (u16 address         );
void EEPROM_write(unsigned short address, const u8 *data, u8 size);
void EEPROM_read(unsigned short address, u8 *data, u8 size);

// في ملف EEPROM_interface.h أضف:
void EEPROM_vWriteBlock(u16 address, const u8 *data, u8 size);
void EEPROM_vReadBlock(u16 address, u8 *data, u8 size);

#endif /* MCAL_EEPROM_INTERFACE_H_ */
