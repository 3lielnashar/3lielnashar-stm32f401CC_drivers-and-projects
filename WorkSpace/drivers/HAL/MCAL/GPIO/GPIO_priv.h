/*
 * GPIO_priv.h
 *
 *  Created on: Feb 6, 2023
 *      Author: aliel
 */

#ifndef MCAL_GPIO_GPIO_PRIV_H_
#define MCAL_GPIO_GPIO_PRIV_H_

/*
#define GPIOA_BASE_ADDR		0x40020000
#define GPIOB_BASE_ADDR		0x40020400
#define GPIOC_BASE_ADDR		0x40020800

typedef struct
{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}GPIO_MemMap_t;

// define a pointer to structure
#define GPIOA    ((volatile GPIO_MemMap_t*)(GPIOA_BASE_ADDR))
#define GPIOB    ((volatile GPIO_MemMap_t*)(GPIOB_BASE_ADDR))
#define GPIOC    ((volatile GPIO_MemMap_t*)(GPIOC_BASE_ADDR))

*/
#endif /* MCAL_GPIO_GPIO_PRIV_H_ */
