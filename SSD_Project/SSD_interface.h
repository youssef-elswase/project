/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:SSD_interface
	
	layer:MCAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_


#define SSD_CommonCathod 0
#define SSD_CommonAnode  1

#define SSD_PORTA 0
#define SSD_PORTB 1
#define SSD_PORTC 2
#define SSD_PORTD 3

#define SSD_PIN0 0
#define SSD_PIN1 1
#define SSD_PIN2 2
#define SSD_PIN3 3
#define SSD_PIN4 4
#define SSD_PIN5 5
#define SSD_PIN6 6
#define SSD_PIN7 7


typedef struct {
	u8 Type;
	u8 DataPort;
	u8 EnablePort;
	u8 EnablePin;
}SSD_Type;

void SSD_VoidIntialDataPin (SSD_Type COPY_StructConfig);
void SSD_VoidEnable        (SSD_Type COPY_StructConfig);
void SSD_VoidDisable       (SSD_Type COPY_StructConfig);
void SSD_VoidSendNumber    (SSD_Type COPY_StructConfig, u8 COPY_u8Number);

#endif
