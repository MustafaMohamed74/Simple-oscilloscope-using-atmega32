/*
 * BIT_MATH.h
 *
 *  Created on: Sep 1, 2023
 *      Author: aminz
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define Set_Bit(Var,BitNo) Var=Var|(1<<BitNo)
#define Clr_Bit(Var,BitNo) Var=Var&(~(1<<BitNo))
#define Tog_Bit(Var,BitNo) Var=Var^(1<<BitNo)
#define Get_Bit(Var,BitNo) ((Var>>BitNo)&1) //Sheefted no on lift the operator

#endif /* BIT_MATH_H_ */
