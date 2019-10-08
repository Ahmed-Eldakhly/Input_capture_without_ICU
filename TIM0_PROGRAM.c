/*
 * TIM0_PROGRAM.c
 *
 *  Created on: 28 Jun 2019
 *      Author: mohamed
 */

#include"StdTypes.h"
#include "TIM0_Configure.h"
#include"TIM0_PRIVATE.h"
#include"TIM0_interface.h"
#include"utils.h"
void TIM0_vidInit(void)
{
	if(TIMER_MODE==NORMAL_MODE)
	{
		Clear_Bit(TCCR0,WGM00);
		Clear_Bit(TCCR0,WGM01);
		Set_Bit(TIMSK,TOIE0);
	}
	else if(TIMER_MODE==CTC_MODE)
	{
		Clear_Bit(TCCR0,WGM00);
		Set_Bit(TCCR0,WGM01);
		Set_Bit(TIMSK,TOIE0);
	}
	TCCR0|=PRESCALER_SELECT;
}


void TIM0_vidSetTimerval(u8 u8CNT)
{
	TCNT0=u8CNT;
}
void TIM0_vidSetTimerCompiar(u8 u8CNR)
{
	OCR0=u8CNR;
}
