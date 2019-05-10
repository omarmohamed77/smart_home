/*
 * button interupt.h
 *
 *  Created on: May 8, 2019
 *      Author: omar
 */

#ifndef BUTTON_INTERRUPT_H_
#define BUTTON_INTERRUPT_H_


#include "port.h"
void button_interrupt();
void GPIOF_Handler(void);
void EnableInterrupts(void);



#endif /* BUTTON_INTERRUPT_H_ */
