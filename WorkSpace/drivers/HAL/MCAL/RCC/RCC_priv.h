/*
 * RCC_priv.h
 *
 *  Created on: Feb 4, 2023
 *      Author: aliel
 */

#ifndef MCAL_RCC_RCC_PRIV_H_
#define MCAL_RCC_RCC_PRIV_H_

#define HSEON   16
#define HSEBYP	18
#define CSSON	19
#define HSION	0
#define PLLON	24

#define SW0     0
#define SW1		1

#define RCC_BASE_ADDR    0x40023800

typedef struct{
	uint32 CR;
	uint32 PLLCFGR;
	uint32 CFGR;
	uint32 CIR;
	uint32 AHB1RSTR;
	uint32 AHB2RSTR;
	uint32 RESERVED1;
	uint32 RESERVED2;
	uint32 APB1RSTR;
	uint32 APB2RSTR;
	uint32 RESERVED3;
	uint32 RESERVED4;
	uint32 AHB1ENR;
	uint32 AHB2ENR;
	uint32 RESERVED5;
	uint32 RESERVED6;
	uint32 APB1ENR;
	uint32 APB2ENR;
	uint32 RESERVED7;
	uint32 RESERVED8;
	uint32 AHB1LPENR;
	uint32 AHB2LPENR;
	uint32 RESERVED9;
	uint32 RESERVED10;
	uint32 APB1LPENR;
	uint32 APB2LPENR;
	uint32 RESERVED11;
	uint32 RESERVED12;
	uint32 BDCR;
	uint32 CSR;
	uint32 RESERVED13;
	uint32 RESERVED14;
	uint32 SSCGR;
	uint32 PLLI1SCFGR;
	uint32 PLLI2SCFGR;
	uint32 RESERVED15;
	uint32 DCKCFGR;

}RCC_MemMap_t;

#define RCC    ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))

#endif /* MCAL_RCC_RCC_PRIV_H_ */
