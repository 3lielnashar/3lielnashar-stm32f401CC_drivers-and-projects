/*
 * RCC_prog.c
 *
 *  Created on: Feb 4, 2023
 *      Author: aliel
 */

#include "../lib/common_macros.h"
#include "../lib/std_types.h"

#include "RCC_int.h"
#include "RCC_priv.h"
#include "RCC_confg.h"


void MRCC_vInit(void)
{
	/*1- CSS (ON/OFF) */
	/*2- HSE_BYP */
	CLEAR_BIT(RCC->CR, HSEBYP);
	/*3- select clock switch (HSI/HSE/PLL) */
	SET_BIT(RCC->CFGR, SW0);
	/*4- Bus prescalers   */
	/*5- PLL configuration */
	/*6- Enable the selected clock (HSI ON / HSE ON / PLL ON)*/
#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSEON);
#endif

}

void MRCC_vEnableClock(uint32 A_uint32BusId, uint32 A_uint32PeripheralId)
{
	switch(A_uint32BusId)
	{
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,A_uint32PeripheralId ) ;
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,A_uint32PeripheralId ) ;
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,A_uint32PeripheralId ) ;
		break;
	default:
		/* Error: Bus ID out of range */
		break;
	}
}

void MRCC_vDisableClock(uint32 A_uint32BusId, uint32 A_uint32PeripheralId)
{
	switch(A_uint32BusId)
	{
	case RCC_AHB1:
		CLEAR_BIT(RCC->AHB1ENR,A_uint32PeripheralId ) ;
		break;
	case RCC_AHB2:
		CLEAR_BIT(RCC->AHB2ENR,A_uint32PeripheralId ) ;
		break;
	case RCC_APB1:
		CLEAR_BIT(RCC->APB1ENR,A_uint32PeripheralId ) ;
		break;
	}
}
/*
void MRCC_vEnableClock(uint32 BusId, uint32 PeripheralId) {

}

void MRCC_vDisableClock(/*???) {

}
*/
