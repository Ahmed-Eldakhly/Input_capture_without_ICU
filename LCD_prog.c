/*
 * LCD_prog.c
 *
 *  Created on: Oct 27, 2018
 *      Author: HOSNY
 */

#include "Stdtypes.h"
#include "LCD_int.h"
#include "DIO_int.h"
#include "LCD_cfg.h"
#define F_CPU 12000000UL
#include "avr/delay.h"

void LCD_vidInit()
{
	_delay_ms(30);

	LCD_vidSendCommand(LCD_FUNC_SET);

	_delay_ms(1);

	LCD_vidSendCommand(LCD_DISPLY_ON);

	_delay_ms(1);

	LCD_vidSendCommand(LCD_CLR);

	_delay_ms(2);

	LCD_vidSendCommand(LCD_ENTRY_MODE);
}

void LCD_vidSendCommand(u8 u8CmdCpy)
{
	DIO_SetPinValue(LCD_CTRL_PORT,RS_PIN,LOW);

	DIO_SetPinValue(LCD_CTRL_PORT,RW_PIN,LOW);

	DIO_SetPinValue(LCD_CTRL_PORT,E_PIN,HIGH);

	DIO_SetPortValue(LCD_DATA_PORT,u8CmdCpy);

	DIO_SetPinValue(LCD_CTRL_PORT,E_PIN,LOW);

	_delay_ms(5);

	DIO_SetPinValue(LCD_CTRL_PORT,E_PIN,HIGH);
}

void LCD_vidWriteChar(u8 u8DataCpy)
{
	DIO_SetPinValue(LCD_CTRL_PORT,RS_PIN,HIGH);

	DIO_SetPinValue(LCD_CTRL_PORT,RW_PIN,LOW);

	DIO_SetPinValue(LCD_CTRL_PORT,E_PIN,HIGH);

	DIO_SetPortValue(LCD_DATA_PORT,u8DataCpy);

	DIO_SetPinValue(LCD_CTRL_PORT,E_PIN,LOW);

	_delay_ms(5);

	DIO_SetPinValue(LCD_CTRL_PORT,E_PIN,HIGH);
}

void LCD_vidWriteString(u8* pu8StringCpy)
{
	u8 u8LoopIndex = 0;
	while(pu8StringCpy[u8LoopIndex] != 0)
	{
		LCD_vidWriteChar(pu8StringCpy[u8LoopIndex]);
		if(u8LoopIndex == 15)
		{
			LCD_vidSendCommand(LCD_LINE2_LOC0);
		}
		else
		{

		}
		u8LoopIndex++;
		_delay_ms(50);
	}
}

void LCD_vidWriteNumber(u16 u16NumVal)
{
	u8 Local_u8Factor;

	if (u16NumVal >= (u16)10000)
	{
		Local_u8Factor = (u8)(u16NumVal / (u16) 10000);
		LCD_vidWriteChar(Local_u8Factor+48);
		u16NumVal = u16NumVal - (u16)(Local_u8Factor * (u16)10000);

		Local_u8Factor = (u8)(u16NumVal / (u16) 1000);
		LCD_vidWriteChar(Local_u8Factor+48);
		u16NumVal = u16NumVal - (u16)(Local_u8Factor * (u16)1000);

		Local_u8Factor = (u8)(u16NumVal / (u16) 100);
		LCD_vidWriteChar(Local_u8Factor+48);
		u16NumVal = u16NumVal - (u16)(Local_u8Factor * (u8)100);

		Local_u8Factor = (u8)(u16NumVal / (u16) 10);
		LCD_vidWriteChar(Local_u8Factor+48);
		Local_u8Factor = u16NumVal - (u16)(Local_u8Factor * (u8)10);
		LCD_vidWriteChar(Local_u8Factor+48);

	}

	else if (u16NumVal >= (u16) 1000 )
	{
		Local_u8Factor = (u8)(u16NumVal / (u16) 1000);
		LCD_vidWriteChar(Local_u8Factor+48);
		u16NumVal = u16NumVal - (u16)(Local_u8Factor * (u16)1000);

		Local_u8Factor = (u8)(u16NumVal / (u16) 100);
		LCD_vidWriteChar(Local_u8Factor+48);
		u16NumVal = u16NumVal - (u16)(Local_u8Factor * (u8)100);

		Local_u8Factor = (u8)(u16NumVal / (u16) 10);
		LCD_vidWriteChar(Local_u8Factor+48);
		Local_u8Factor = u16NumVal - (u16)(Local_u8Factor * (u8)10);
		LCD_vidWriteChar(Local_u8Factor+48);
	}

	else if (u16NumVal >= (u8)100 )
	{
		Local_u8Factor = (u8)(u16NumVal / (u16) 100);
		LCD_vidWriteChar(Local_u8Factor+48);
		u16NumVal = u16NumVal - (u16)(Local_u8Factor * (u8)100);

		Local_u8Factor = (u8)(u16NumVal / (u16) 10);
		LCD_vidWriteChar(Local_u8Factor+48);
		Local_u8Factor = u16NumVal - (u16)(Local_u8Factor * (u8)10);
		LCD_vidWriteChar(Local_u8Factor+48);
	}

	else if (u16NumVal >= (u8) 10 )
	{
		Local_u8Factor = (u8)((u8)u16NumVal / (u8) 10);
		LCD_vidWriteChar(Local_u8Factor+48);
		Local_u8Factor = u16NumVal - (u16)(Local_u8Factor * (u8)10);
		LCD_vidWriteChar(Local_u8Factor+48);
	}

	else
	{
		LCD_vidWriteChar(u16NumVal+48);
	}
}



void xSetVidPosition(u8 x,u8 y)
{
	if((x>=0)&&(x<16))
	{
		switch(y)
		{
			case 1:
				LCD_vidSendCommand(x+128);

				break;
			case 2:
				LCD_vidSendCommand(x+192);

				break;
		}
	}
}










