/*
 * main.c
 *
 *  Created on: 29 Jun 2019
 *      Author: mohamed
 */
#include<avr/io.h>
#include"avr/interrupt.h"

#include"StdTypes.h"
#include"ADC_int.h"
#include"DIO_int.h"
#include"TIM0_interface.h"
#include"utils.h"
#include"Util.h"
#include"LCD_int.h"
#include"LCD_cfg.h"

u8 flag=0;
u16 Ton=0;
u16 Toff=0;
u16 freq,duty;
void main ()
{
	DIO_SetPinDirection(PORTB,PIN5,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN6,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN7,OUTPUT);
	DIO_SetPortDirection(PORTA,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN3,OUTPUT);
	DIO_SetPinDirection(PORTD,PIN2,INPUT);
	LCD_vidInit();

	TCCR0=0b01101010;
	OCR0=127;
	TCCR1A=0;
	TCCR1B=2;
	MCUCR=3;
	Set_Bit(SREG,7);
	Set_Bit(GICR,6);
	while(1)
	{
		if(flag==3)
		{
			freq=1000000/(Ton+Toff);
			duty=(u16)(((u32)Ton*100)/(Ton+Toff));
			xSetVidPosition(0,1);
				LCD_vidWriteString("frequency: ");
			xSetVidPosition(10,1);
			LCD_vidWriteNumber(freq);
			xSetVidPosition(0,2);
			LCD_vidWriteString("Duty Cycle: ");
			xSetVidPosition(11,2);
			LCD_vidWriteNumber(duty);
			MCUCR=3;
			flag=0;
		}
	}
}
ISR(INT0_vect)
{
	if(flag==0)
	{
		TCNT1=0;
		MCUCR=2;
		flag++;

	}
	else if(flag==1)
	{
		Ton=TCNT1;
		TCNT1=0;
		MCUCR=3;
		flag++;
	}
	else if(flag==2)
	{
		Toff=TCNT1;
		flag++;
	}
}
