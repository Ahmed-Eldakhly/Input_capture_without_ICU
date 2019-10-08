/*
 * utils.h
 *
 *  Created on: 19 Jun 2019
 *      Author: mohamed
 */

#ifndef UTILS_H_
#define UTILS_H_

#define Set_Bit(Reg,Bit) (Reg|=(1<<Bit))
#define Clear_Bit(Reg,Bit) (Reg&=(~(1<<Bit)))
#define Get_Bit(Reg,Bit) ((Reg>>Bit)&1)
#define Toggel_Bit(Reg,Bit) (Reg^=(1<<Bit))


#define Set_Reg(Reg) (Reg|=0xff)
#define Clear_Reg(Reg) (Reg&=0x00)
//#define Get_Reg(Reg) (Reg&0xff) we can use reg directly so it is meaningless
#define Toggel_Reg(Reg) (Reg^=0xff)


#define Set_Hnepples(reg) (reg|=0xf0)
#define Set_Lnepples(reg) (reg|=0x0f)
#define Clear_Hnepples(reg) (reg&=0x0f)
#define Clear_Lnepples(reg) (reg&=0xf0)


#define Input 0
#define Output 1


#define Low 0
#define High 1


#endif /* UTILS_H_ */
