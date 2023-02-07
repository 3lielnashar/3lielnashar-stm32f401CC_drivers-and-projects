/*
 * GPIO_prog.c
 *
 *  Created on: Feb 6, 2023
 *      Author: aliel
 */


#include "../lib/common_macros.h"
#include "../lib/std_types.h"

#include "GPIO_int.h"
#include "GPIO_priv.h"
#include "GPIO_confg.h"

void MGPIO_vSetPinMode(uint8 PortId, uint8 PinNo, uint8 Mode) {

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */

	if ((PinNo >= NUM_OF_PINS_PER_PORT) || (PortId >= NUM_OF_PORTS)) {
		/* Do Nothing */
	} else {
		switch (PortId) {
		case PORTA_ID:
			GPIOA->MODER &= ~(0b11 << (PinNo * 2));
			GPIOA->MODER |= (Mode << (PinNo * 2));
			break;

		case PORTB_ID:
			GPIOB->MODER &= ~(0b11 << (PinNo * 2));
			GPIOB->MODER |= (Mode << (PinNo * 2));
			break;

		case PORTC_ID:
			GPIOC->MODER &= ~(0b11 << (PinNo * 2));
			GPIOC->MODER |= (Mode << (PinNo * 2));
			break;
		}
	}
}

void MGPIO_vSetPinOutputType(uint8 PortId, uint8 PinNo, uint8 OutType) {
	if ((PinNo >= NUM_OF_PINS_PER_PORT) || (PortId >= NUM_OF_PORTS)) {
		/* Do Nothing */
	} else {
		if (OutType == GPIO_OTYPE_OPENDRAIN) {
			switch (PortId) {
			case PORTA_ID:
				SET_BIT(GPIOA->OTYPER, PinNo);
				break;
			case PORTB_ID:
				SET_BIT(GPIOB->OTYPER, PinNo);
				break;
			case PORTC_ID:
				SET_BIT(GPIOC->OTYPER, PinNo);
				break;
			}
		} else if (OutType == GPIO_OTYPE_PUSHPULL) {
			switch (PortId) {
			case PORTA_ID:
				CLEAR_BIT(GPIOA->OTYPER, PinNo);
				break;
			case PORTB_ID:
				CLEAR_BIT(GPIOB->OTYPER, PinNo);
				break;
			case PORTC_ID:
				CLEAR_BIT(GPIOC->OTYPER, PinNo);
				break;
			}
		}
	}
}

void MGPIO_vSetPinOutputSpeed(uint8 PortId, uint8 PinNo, uint8 OutSpeed) {
	switch (PortId) {
	case PORTA_ID:
		GPIOA->OSPEEDR &= ~(0b11 << (PinNo * 2));
		GPIOA->OSPEEDR |= (OutSpeed << (PinNo * 2));

		break;

	case PORTB_ID:
		GPIOB->OSPEEDR &= ~(0b11 << (PinNo * 2));
		GPIOB->OSPEEDR |= (OutSpeed << (PinNo * 2));

		break;

	case PORTC_ID:
		GPIOC->OSPEEDR &= ~(0b11 << (PinNo * 2));
		GPIOC->OSPEEDR |= (OutSpeed << (PinNo * 2));

		break;

	}

}

void MGPIO_vSetPinInputPull(uint8 PortId, uint8 PinNo, uint8 PullType) {
	switch (PortId) {
	case PORTA_ID:
		GPIOA->PUPDR &= ~(0b11 << (PinNo * 2));
		GPIOA->PUPDR |= (PullType << (PinNo * 2));

		break;

	case PORTB_ID:
		GPIOB->PUPDR &= ~(0b11 << (PinNo * 2));
		GPIOB->PUPDR |= (PullType << (PinNo * 2));

		break;

	case PORTC_ID:
		GPIOC->PUPDR &= ~(0b11 << (PinNo * 2));
		GPIOC->PUPDR |= (PullType << (PinNo * 2));

		break;

	}
}

uint8 MGPIO_uint8GetPinValue(uint8 PortId, uint8 PinNo) {
	uint8 uint8PinValue = 0;
	switch (PortId) {
	case PORTA_ID:
		uint8PinValue = GET_BIT(GPIOA->IDR, PinNo);
		break;
	case PORTB_ID:
		uint8PinValue = GET_BIT(GPIOB->IDR, PinNo);
		break;
	}

	return uint8PinValue;
}

void MGPIO_vSetPORTVal(uint8 PortId, uint16 Val) {
	switch (PortId) {
	case PORTA_ID:
		GPIOA->ODR = 0;
		GPIOA->ODR |= Val;
		break;
	case PORTB_ID:
		GPIOB->ODR = 0;
	    GPIOB->ODR |= Val;
		break;
	case PORTC_ID:
		GPIOA->ODR = 0;
		GPIOA->ODR |= Val;
		break;
	}
}

void MGPIO_vSetPinVal_fast(uint8 PortId, uint8 PinNo, uint8 PinVal) {
	if (PinVal == LOGIC_HIGH) {
		switch (PortId) {
		case PORTA_ID:
			GPIOA->BSRR = (1<<PinNo);
			break;
		case PORTB_ID:
			GPIOB->BSRR = (1<<PinNo);
			break;
		case PORTC_ID:
			GPIOC->BSRR = (1<<PinNo);
			break;
		}
	} else if (PinVal == LOGIC_LOW) {
		switch (PortId) {
		case PORTA_ID:
			GPIOA->BSRR = (1<<(PinNo+16));
			break;
		case PORTB_ID:
			GPIOB->BSRR = (1<<(PinNo+16));
			break;
		case PORTC_ID:
			GPIOC->BSRR = (1<<(PinNo+16));
			break;
		}
	}

}

/*void MGPIO_vSetAlternativeFunction(uint8 PortId, uint8 PinNo, uint8 AltFun) {

}*/

 void MGPIO_vInitOutput(MGPIO_Config_OUTPUT_t* A_xPinConfig){
	MGPIO_vSetPinMode(A_xPinConfig->Port, A_xPinConfig->Pin,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinOutputType(A_xPinConfig->Port, A_xPinConfig->Pin,A_xPinConfig->OutputType);
	MGPIO_vSetPinOutputSpeed(A_xPinConfig->Port, A_xPinConfig->Pin,	A_xPinConfig->OutputSpeed);
}
 void MGPIO_vInitINPUT(MGPIO_Config_INPUT_t* A_xPinConfig) {
	MGPIO_vSetPinMode(A_xPinConfig->Port, A_xPinConfig->Pin,GPIO_MODE_INPUT);
	MGPIO_vSetPinInputPull(A_xPinConfig->Port, A_xPinConfig->Pin,A_xPinConfig->InputPull);
}
/*
 * it is allowed to access only 8 bins no longer
 * as there are forbidden pins
 * PORTA(13,14,15)
 *
 */
/*
void MGPIO_vSetPortMode(uint8 PortId,uint16 value, uint8 Mode){
if(Mode == GPIO_MODE_OUTPUT){
	switch (PortId) {
	case PORTA_ID:
		GPIOA->MODER &= ~(0b11 << (PinNo * 2));
		GPIOA->MODER |= (Mode << (PinNo * 2));
		break;

	case PORTB_ID:
		GPIOB->MODER &= ~(0b11 << (PinNo * 2));
		GPIOB->MODER |= (Mode << (PinNo * 2));
		break;

	case PORTC_ID:
		GPIOC->MODER &= ~(0b11 << (PinNo * 2));
		GPIOC->MODER |= (Mode << (PinNo * 2));
		break;
	}
}
else if(Mode == GPIO_MODE_INPUT){
	switch(PortId){
	case PORTA_ID:
		GPIOA->MODER &= ~(0b11 << (PinNo * 2));
		GPIOA->MODER |= (Mode << (PinNo * 2));
		break;

	case PORTB_ID:
		GPIOB->MODER &= ~(0b11 << (PinNo * 2));
		GPIOB->MODER |= (Mode << (PinNo * 2));
		break;

	case PORTC_ID:
		GPIOC->MODER &= ~(0b11 << (PinNo * 2));
		GPIOC->MODER |= (Mode << (PinNo * 2));
		break;
	}
}

}*/

