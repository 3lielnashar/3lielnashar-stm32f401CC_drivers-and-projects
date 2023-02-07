/*
 * GPIO_int.h
 *
 *  Created on: Feb 6, 2023
 *      Author: aliel
 */

#include "../lib/std_types.h"


#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_

#define GPIO_MODE_INPUT		0b00
#define GPIO_MODE_OUTPUT	0b01
#define GPIO_MODE_ALTFUN	0b10
#define GPIO_MODE_ANALOG	0b11

#define GPIO_INPUT_NO_PULL		0b00
#define GPIO_INPUT_PULL_UP		0b01
#define GPIO_INPUT_PULL_DOWN	0b10

#define PORTA_ID			0
#define PORTB_ID			1
#define PORTC_ID			2

#define NUM_OF_PORTS        3

#define GPIO_OTYPE_PUSHPULL         0
#define GPIO_OTYPE_OPENDRAIN		1

#define GPIO_SPEED_LOW      0b00
#define GPIO_SPEED_MED		0b01
#define GPIO_SPEED_HIGH		0b10
#define GPIO_SPEED_VHIGH	0b11

#define NUM_OF_PINS_PER_PORT 16

#define PIN0_ID       0
#define PIN1_ID       1
#define PIN2_ID       2
#define PIN3_ID       3
#define PIN4_ID       4
#define PIN5_ID       5
#define PIN6_ID       6
#define PIN7_ID       7
#define PIN8_ID       8
#define PIN9_ID       9
#define PIN10_ID      10
#define PIN11_ID      11
#define PIN12_ID      12
#define PIN13_ID      13
#define PIN14_ID      14
#define PIN15_ID      15

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

// to make configuration easily by passing it by address and keeps its positioning
typedef struct {
	uint8 Port;
	uint8 Pin;
	uint8 OutputType;
	uint8 OutputSpeed;
}MGPIO_Config_OUTPUT_t;

typedef struct {
	uint8 Port;
	uint8 Pin;
	uint8 InputPull;
}MGPIO_Config_INPUT_t;
/*
 * Description :
 * initalize the required GPIO_pin faster by using
 * configuration pointer to structure that stores all required inputs
 */
void MGPIO_vInitOutput(MGPIO_Config_OUTPUT_t* A_xPinConfig);
void MGPIO_vInitINPUT(MGPIO_Config_INPUT_t* A_xPinConfig);
// -------------------------------------------------------------------------
/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * 32-bit register
 * each pins is accessed by 2-bits in the MODERR
 * 00: Input (reset state)
 * 01: General purpose output mode
 * 10: Alternate function mode
 * 11: Analog mode
 */
void MGPIO_vSetPinMode(uint8 PortId, uint8 PinNo, uint8 Mode);
// -------------------------------------------------------------------------

/*
 * Description :
 * Setup the output type of the output pins
 * 32-bit register (Higer level is reserved)
 * each pins is accessed by 1-bits in the OTYPER
 * 0: Output push-pull (reset state)
 * 1: Output open-drain
 */

void MGPIO_vSetPinOutputType(uint8 PortId, uint8 PinNo, uint8 OutType);
// -------------------------------------------------------------------------
/*
 * Description :
 * Setup the speed of the slew rate of the output pins
 * 32-bit register
 * each pins is accessed by 2-bits in the OSPEEDR
 * 00: Low speed
 * 01: Medium speed
 * 10: High speed
 * 11: Very high speed
 */
void MGPIO_vSetPinOutputSpeed(uint8 PortId, uint8 PinNo, uint8 OutSpeed);
// -------------------------------------------------------------------------
/*
 * Description :
 * Setup the speed of the type of the input pins
 * 32-bit register
 * each pins is accessed by 2-bits in the PUPDR
 * 00: No pull-up, pull-down
 * 01: Pull-up
 * 10: Pull-down
 * 11: Reserved
 */
void MGPIO_vSetPinInputPull(uint8 PortId, uint8 PinNo, uint8 PullType);
// -------------------------------------------------------------------------
/*
 * Description :
 * These bits are read-only and can be accessed in word mode only. They contain the input
 * value of the corresponding I/O port.
 * 32-bit register (Higer level is reserved)
 */
uint8 MGPIO_uint8GetPinValue(uint8 PortId, uint8 PinNo);
// -------------------------------------------------------------------------
/*
 * Description :
 * write the value required in ODR
 * 32-bit register (Higer level is reserved)
 * each pins is accessed by 1-bits in the ODR
 * 0: LOGIC LOW
 * 1: LOGIC HIGH
 */

void MGPIO_vSetPORTVal(uint8 PortId, uint16 Val);
// -------------------------------------------------------------------------
/*
 * Description :
 * write the value required in BSRR
 * 32-bit register
 * each pins is accessed by 1-bits in the BSRR
 * UPPER 16-bit :
 * 0: No action on the corresponding ODRx bit
 * 1: Resets the corresponding ODRx bit
 * LOWER 16-bit :
 * 0: No action on the corresponding ODRx bit
 * 1: Sets the corresponding ODRx bit
 */
void MGPIO_vSetPinVal_fast(uint8 PortId, uint8 PinNo, uint8 PinVal);
// -------------------------------------------------------------------------
/*
 * Description :
 * Active the alternative function specified for the pin
 */
void MGPIO_vSetAlternativeFunction(uint8 PortId, uint8 PinNo, uint8 AltFun);
// -------------------------------------------------------------------------
/*
 * Description :
 *
 */
void MGPIO_vSetPortMode(uint8 PortId,uint8 value, uint8 Mode);

#endif /* MCAL_GPIO_GPIO_INT_H_ */
