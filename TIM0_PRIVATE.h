/*
 * TIM0_PRIVATE.h
 *
 *  Created on: 28 Jun 2019
 *      Author: mohamed
 */

#ifndef TIM0_PRIVATE_H_
#define TIM0_PRIVATE_H_
#include"StdTypes.h"

#define NORMAL_MODE 0
#define CTC_MODE 1

#define PRESCALER_1 0x01
#define PRESCALER_8 0x02
#define PRESCALER_64 0x03
#define PRESCALER_256 0x04
#define PRESCALER_1024 0x05

//Register
#define TCNT0 (*(volatile u8*)0x52)
#define OCR0 (*(volatile u8*)0x5C)
#define TCCR0 (*(volatile u8*)0x53)
#define TIMSK (*(volatile u8*)0x59)
#define SREG (*(volatile u8*)0x5F)

#define WGM00 6
#define WGM01 3
#define TOIE0 0
#define OCIE0 1

#endif /* TIM0_PRIVATE_H_ */
