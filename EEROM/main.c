/*
 * main.c
 *
 *  Created on: ٢٧‏/٠١‏/٢٠٢٥
 *      Author: hp
 */
#include<util/delay.h>
#include "BIT-MATH.h"
#include "STD_TYPES.h"
#include "EEROM_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KEY_interface.h"
#include "pre/KEY_interface.h"
u8 check_pass (void);
u8 check_user(void);

#define TRY 2
s8 try =TRY;
u8 x=NOTPRESSED,y=NOTPRESSED,flag=0;
u8 pass [4]={
		0,0,0,0
};
u8 user [16]={
		0
};
u8 check0=0;
u8 check1=0;
u8 i=0x0004;
int main ()
{
	CLCD_voidInial();
	KEY_voidInit();
	KEY1_voidInit();
	if(EEROM_VoidReadDataFromAddress(0x0004)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0005)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0006)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0007)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0008)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0009)==0xff&&
			EEROM_VoidReadDataFromAddress(0x000A)==0xff&&
			EEROM_VoidReadDataFromAddress(0x000B)==0xff&&
			EEROM_VoidReadDataFromAddress(0x000C)==0xff&&
			EEROM_VoidReadDataFromAddress(0x000D)==0xff&&
			EEROM_VoidReadDataFromAddress(0x000E)==0xff&&
			EEROM_VoidReadDataFromAddress(0x000F)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0010)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0011)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0012)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0013)==0xff)
	{
		//set name
		CLCD_voidSendString("Enter name:");
		CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
		for(u8 addr=0x0004;addr<0x0014;addr++)
		{

			do{
				y=KEY1_U8GetPressed();
			}while(y==NOTPRESSED);
			if(y=='=')
			{
				for(u8 x=i;x<16;x++)
				{
					user[x]=NOTPRESSED;
				}

				break;
			}
			CLCD_voidSendData(y);
			if(y!=NOTPRESSED)
			{
				EEROM_VoidSendDataToAddress(addr,y);
			}
			//CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
			_delay_ms(250);
		}


		CLCD_ClearScreen();

		CLCD_voidSendString("* * * * * * * *");
		CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
		CLCD_voidSendString("* * * * * * * *");

		_delay_ms(3000);

		CLCD_ClearScreen();
	}
	if(EEROM_VoidReadDataFromAddress(0x0000)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0001)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0002)==0xff&&
			EEROM_VoidReadDataFromAddress(0x0003)==0xff)
	{
		//set pass
		CLCD_voidSendString("select Password:");
		CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
		for(u8 addrpass=0x0000;addrpass<0x0004;addrpass++)
		{
			do{
				y=KEY1_U8GetPressed();
				x=KEY_U8GetPressed();
			}while(x==NOTPRESSED&&y==NOTPRESSED);
			if(y!=NOTPRESSED)
			{
				EEROM_VoidSendDataToAddress(addrpass,y);
				CLCD_voidSendData(y);
			}else
			{
				EEROM_VoidSendDataToAddress(addrpass,x);
				CLCD_voidSendData(x);
			}
			_delay_ms(500);
			CLCD_SetPosition(CLCD_ROW_2,addrpass+1);
			CLCD_voidSendData('*');
		}

		CLCD_ClearScreen();

		CLCD_voidSendString("* * * * * * * *");
		CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
		CLCD_voidSendString("* * * * * * * *");

		_delay_ms(3000);

		CLCD_ClearScreen();
	}

	CLCD_voidSendString("Welcome :");
	CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
	do{
		CLCD_voidSendData(EEROM_VoidReadDataFromAddress(i));
		i++;
	}while(EEROM_VoidReadDataFromAddress(i)!=0xff);
	_delay_ms(2000);
	CLCD_ClearScreen();

	check0=check_user();
	check1=check_pass();
	while(1)
	{
		if( check0==0 || check1==0 )
		{
			CLCD_voidSendString("you have");
			CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
			CLCD_voidSendData(try+48);
			CLCD_voidSendString(" times");
			_delay_ms(2000);
			CLCD_ClearScreen();
		}

		if(try>0)
		{

			if(check0==0 && check1==0)
			{
				CLCD_voidSendString("user error!");
				CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
				CLCD_voidSendString("pass error!");
				_delay_ms(2000);
				try--;
				check0=check_user();
				check1=check_pass();

			}else if(check0==0 && check1==1)
			{
				CLCD_voidSendString("user error!");
				_delay_ms(2000);
				try--;
				check0=check_user();
			}else if(check0==1 && check1==0)
			{
				CLCD_voidSendString("pass error!");
				_delay_ms(2000);
				try--;
				check1=check_pass();
			}else if(check0==1 && check1==1)
			{

				CLCD_voidSendString("** safe open **");
				break;
			}

		}else
		{
			CLCD_voidSendString("** safe close **");
			break;

		}

	}

}


u8 check_pass (void)
{
	CLCD_ClearScreen();
	u8 checkpass=0;
	CLCD_voidSendString("Enter Password:");
	CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
	for(u8 i=0;i<4;i++)
	{
		do{
			y=KEY1_U8GetPressed();
			x=KEY_U8GetPressed();
		}while(x==NOTPRESSED&&y==NOTPRESSED);
		if(y!=NOTPRESSED)
		{
			CLCD_voidSendData(y);
			pass[i]=y;
		}else
		{
			CLCD_voidSendData(x);
			pass[i]=x;
		}

		_delay_ms(500);
		CLCD_SetPosition(CLCD_ROW_2,i+1);
		CLCD_voidSendData('*');
	}


	CLCD_ClearScreen();
	_delay_ms(1000);
	if(pass[0]==EEROM_VoidReadDataFromAddress(0x0000)&&
			pass[1]==EEROM_VoidReadDataFromAddress(0x0001)&&
			pass[2]==EEROM_VoidReadDataFromAddress(0x0002)&&
			pass[3]==EEROM_VoidReadDataFromAddress(0x0003))
	{
		checkpass=1;
	}

	return checkpass;

}
u8 check_user (void)
{
	CLCD_ClearScreen();
	u8 checkuser=0;
	CLCD_voidSendString("Enter user:");
	CLCD_SetPosition(CLCD_ROW_2,CLCD_COL_1);
	for(int i=0;i<16;i++)
	{
		do{
			y=KEY1_U8GetPressed();
		}while(y==NOTPRESSED);
		if(y=='=')
		{
			for(u8 x=i;x<16;x++)
			{
				user[x]=NOTPRESSED;
			}

			break;
		}
		CLCD_voidSendData(y);
		user[i]=y;
		_delay_ms(250);

	}

	_delay_ms(1000);
	CLCD_ClearScreen();
	if(EEROM_VoidReadDataFromAddress(0x0004)==user[0]&&
			EEROM_VoidReadDataFromAddress(0x0005)==user[1]&&
			EEROM_VoidReadDataFromAddress(0x0006)==user[2]&&
			EEROM_VoidReadDataFromAddress(0x0007)==user[3]&&
			EEROM_VoidReadDataFromAddress(0x0008)==user[4]&&
			EEROM_VoidReadDataFromAddress(0x0009)==user[5]&&
			EEROM_VoidReadDataFromAddress(0x000A)==user[6]&&
			EEROM_VoidReadDataFromAddress(0x000B)==user[7]&&
			EEROM_VoidReadDataFromAddress(0x000C)==user[8]&&
			EEROM_VoidReadDataFromAddress(0x000D)==user[9]&&
			EEROM_VoidReadDataFromAddress(0x000E)==user[10]&&
			EEROM_VoidReadDataFromAddress(0x000F)==user[11]&&
			EEROM_VoidReadDataFromAddress(0x0010)==user[12]&&
			EEROM_VoidReadDataFromAddress(0x0011)==user[13]&&
			EEROM_VoidReadDataFromAddress(0x0012)==user[14]&&
			EEROM_VoidReadDataFromAddress(0x0013)==user[15])
	{
		checkuser=1;
	}
	return checkuser;

}
