/*
b * EEPROM_prog.c
 *
 *  Created on: Feb 1, 2025
 *      Author: alaa hassan
 */

#include <avr/io.h>
#include "../lib/BIT_MATH.h"
#include "../lib/std_typs.h"
#include <util/delay.h>
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

/*___________________________________________________________________________________________________________________*/

/*
Function Name        : EEPROM_write
Function Returns     : void
Function Arguments   : unsigned short address, unsigned char data
Function Description :  write one byte to the given  address.
*/
void EEPROM_vWrite(u16 address, u8 data)
{
    /*set up address register*/
    EEARL_REG = (u8)address;  // تعيين الجزء المنخفض من العنوان
    EEARH_REG = (u8)(address >> 8);  // تعيين الجزء المرتفع من العنوان
    /*set up data register*/
    EEDR_REG = data;
    /*write logical one to EEMWE*/
    SET_BIT(EECR_REG, EECR_EEMWE);
    /*start EEPROM write by setting EEWE*/
    SET_BIT(EECR_REG, EECR_EEWE);
    /* wait for completion of write operation*/
    while (READ_BIT(EECR_REG, EECR_EEWE) == 1);
}

/*___________________________________________________________________________________________________________________*/

/*
Function Name        : EEPROM_read
Function Returns     : unsigned char
Function Arguments   :  unsigned short address
Function Description :  read one byte from the given  address.
*/
u8 EEPROM_vRead(u16 address)
{
  /*set up address register*/
  EEARL_REG = (char)address;
  EEARH_REG = (char)(address >> 8);
  /*start EEPROM read by setting EERE*/
  SET_BIT(EECR_REG, EECR_EERE);
  /*return data from data register*/
  return EEDR_REG;
}

// دالة الكتابة (تدعم بيانات متعددة البايتات)
void EEPROM_write(unsigned short address, const u8 *data, u8 size) {
    for(u8 i = 0; i < size; i++) {
        EEAR = address + i; // تعيين العنوان الحالي
        EEDR = data[i]; // تعيين البيانات
        SET_BIT(EECR, EEMWE); // تمكين الكتابة
        SET_BIT(EECR, EEWE); // بدء الكتابة
        while (GET_BIT(EECR, EEWE)); // انتظار اكتمال الكتابة
    }
}

// دالة القراءة (تدعم بيانات متعددة البايتات)
void EEPROM_read(unsigned short address, u8 *data, u8 size) {
    for(u8 i = 0; i < size; i++) {
        EEAR = address + i; // تعيين العنوان الحالي
        SET_BIT(EECR, EERE); // بدء القراءة
        data[i] = EEDR; // تخزين البيانات المقروءة
    }
}

// في ملف EEPROM_prog.c أضف التنفيذ:
void EEPROM_vWriteBlock(u16 address, const u8 *data, u8 size) {
    for(u8 i = 0; i < size; i++) {
        EEPROM_vWrite(address + i, data[i]);
        _delay_ms(10); // تأخير لضمان اكتمال الكتابة
    }
}

void EEPROM_vReadBlock(u16 address, u8 *data, u8 size) {
    for(u8 i = 0; i < size; i++) {
        data[i] = EEPROM_vRead(address + i);
    }
}
