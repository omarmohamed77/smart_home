/*
 * button inetrupt.c
 *
 *  Created on: May 8, 2019
 *      Author: omar
 */
#include "button interrupt.h"
 void button_interrupt(){
     Port_Init(5);
     Port_SetPinDirection(5,0x11,PORT_PIN_IN);
     Port_SetPinPullUp(5,0x11,1);
     GPIO_PORTF_IS_R &=~(0x11); // EDGE Sensitive
     GPIO_PORTF_IBE_R &=~(0x11); //disable both edges detection
     GPIO_PORTF_IEV_R&= ~(0x11); //negative edge sensitive
     GPIO_PORTF_ICR_R|=(0x11); // clearing previous interrupts
     GPIO_PORTF_IM_R |=0x11; //interrupt mask send signals to interrupt controller
     NVIC_EN0_R=0x40000000;
     NVIC_PRI7_R&= ~(0x00E00000);
	 EnableInterrupts();




 }


