/*
 * EEPROM_private.h
 *
 *  Created on: Feb 1, 2025
 *      Author: alaa hassan
 */

#ifndef MCAL_EEPROM_PRIVATE_H_
#define MCAL_EEPROM_PRIVATE_H_

/* EEPROM Data Register */
#define EEDR_REG   *((volatile u8 *)0x3D)
/* EEPROM Address Register */
#define EEAR_REG    *((volatile u16 *)0x3E )
#define EEARL_REG   *((volatile u8  *)0x3E )
#define EEARH_REG   *((volatile u8  *)0x3F )

/* EEPROM Control Register */
#define EECR_REG    *((volatile u8  *)0x3C )
#define EECR_EERE   0
#define EECR_EEWE   1
#define EECR_EEMWE  2
#define EECR_EERIE  3



#endif /* MCAL_EEPROM_PRIVATE_H_ */




