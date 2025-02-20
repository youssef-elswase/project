/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:CLCD1_interface
	
	layer:HAL

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef _CLCD1_INTERFACE_H_
#define _CLCD1_INTERFACE_H_

#include "CLCD1_config.h"

#if CLCD1_MODE==4
#define  FOUR_BITS 0x28
#elif CLCD1_MODE==8
#define EIGHT_BITS 0x38
#endif
#define lcd_DisplayOn_CursorOff       0x0c          
#define lcd_DisplayOn_CursorOn        0x0e          
#define lcd_DisplayOff_CursorOff      0x08          
#define lcd_Clear                     0x01          
#define lcd_EntryMode                 0x06          
#define lcd_Home                      0x02          
#define lcd_CGRAM                     0x40          
#define lcd_SetCursor                 0x80          
#define lcd_FunctionReset             0x30

#define CLCD1_ROW_1 1
#define CLCD1_ROW_2 2
#define CLCD1_ROW_3 3
#define CLCD1_ROW_4 4

#define CLCD1_COL_1 1
#define CLCD1_COL_2 2
#define CLCD1_COL_3 3
#define CLCD1_COL_4 4
#define CLCD1_COL_5 5
#define CLCD1_COL_6 6
#define CLCD1_COL_7 7
#define CLCD1_COL_8 8
#define CLCD1_COL_9 9
#define CLCD1_COL_10 10
#define CLCD1_COL_11 11
#define CLCD1_COL_12 12
#define CLCD1_COL_13 13
#define CLCD1_COL_14 14
#define CLCD1_COL_15 15
#define CLCD1_COL_16 16
#define CLCD1_COL_17 17
#define CLCD1_COL_18 18
#define CLCD1_COL_19 19
#define CLCD1_COL_20 20

void CLCD1_voidInial        ( void                         );
void CLCD1_voidSendData     ( u8 COPY_Data                 );
void CLCD1_voidSendCommand  ( u8 COPY_Command              );
void CLCD1_voidSendString   (const u8 *COPY_u8PtrString    );
void CLCD1_SendNumber       ( u64 COPY_u64Number           );
void CLCD1_SetPosition      ( u8 COPY_u8Row , u8 COPY_u8Col);
void CLCD1_SetExtraChar     ( u8 COPY_u8Row , u8 COPY_u8Col);
void CLCD1_ClearScreen      ( void                         ); 
#endif