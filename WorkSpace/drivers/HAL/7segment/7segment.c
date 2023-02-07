/*
 * 7segment.c
 *
 *  Created on: Feb 7, 2023
 *      Author: aliel
 */

#include "../MCAL/GPIO/GPIO_int.h"
#include "7segment.h"

void SSEG_vInit(void){
	uint8 i =0; // number of loops
    while (i < NO_OF_PINS) {
		MGPIO_vSetPinMode(SSEG_PORT, FIRST_PIN_ID + i,GPIO_MODE_OUTPUT);
		MGPIO_vSetPinOutputType(SSEG_PORT, FIRST_PIN_ID + i,GPIO_OTYPE_PUSHPULL);
		MGPIO_vSetPinOutputSpeed(SSEG_PORT, FIRST_PIN_ID + i,GPIO_SPEED_LOW);
		i++;
    }
    MGPIO_vSetPORTVal(SSEG_PORT,0X0000);
}
void SSEG_vShow(uint8 val){
	MGPIO_vSetPORTVal(SSEG_PORT,val);
}
