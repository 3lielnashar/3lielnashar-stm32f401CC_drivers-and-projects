/*
 * RCC_int.h
 *
 *  Created on: Feb 4, 2023
 *      Author: aliel
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_
/*
 * M means MCAL
 * v means void
 */
#define RCC_AHB1    0
#define RCC_AHB2	1
#define RCC_APB1	2


#define RCC_EN_GPIOA  0
#define RCC_EN_GPIOB  1
/*
 * and so on ...
 * */


void MRCC_vInit(void) ;
void MRCC_vEnableClock(/*???*/);
void MRCC_vDisableClock(/*???*/);



#endif /* MCAL_RCC_RCC_INT_H_ */
