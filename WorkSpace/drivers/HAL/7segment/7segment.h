/*
 * 7segment.h
 *
 *  Created on: Feb 7, 2023
 *      Author: aliel
 */

#ifndef HAL_7SEGMENT_7SEGMENT_H_
#define HAL_7SEGMENT_7SEGMENT_H_


#define SSEG_PORT    PORTA_ID


#define FIRST_PIN_ID         PIN0_ID
#define NO_OF_PINS         4

void SSEG_vInit(void);
void SSEG_vShow(uint8 val);

#endif /* HAL_7SEGMENT_7SEGMENT_H_ */
