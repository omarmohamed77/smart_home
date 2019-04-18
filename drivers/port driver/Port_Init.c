/*
 * Port_Init.c
 *
 *  Created on: Mar 10, 2019
 *      Author: omar
 */
#include "mcal.h"
void Port_Init(uint8 port_index)
{ volatile uint32 delay;
	SET_BIT(SYSCTL_RCGCGPIO_R,port_index);  /* CLOCK ENABLE */
delay= SYSCTL_RCGCGPIO_R; /* delay */


/* 1. port commit reg unlock
 * 2. allow changes to GPIOAFSEL, GPIOPUR(pull_up), GPIOPDR(pull_down), and GPIODEN(digital_enable) regs
 * 3. Disable analog function
 * 4. GPIO clear bit PCTL
 * 5. No alternate function
 * 6. Enable digital
 */





if(port_index==0) {
	 GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
 	 GPIO_PORTA_CR_R |= 0x000000FF;
	 GPIO_PORTA_AMSEL_R &=(~0x000000FF);
	 GPIO_PORTA_PCTL_R &= (~0xFFFFFFFF);
	 GPIO_PORTA_AFSEL_R &=(~0x000000FF);
	 GPIO_PORTA_DEN_R |=0x000000FF;}


if(port_index==1)    {
 GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
 GPIO_PORTB_CR_R |= 0x000000FF;
 GPIO_PORTB_AMSEL_R &= (~0x000000FF);
 GPIO_PORTB_PCTL_R &=  (~0xFFFFFFFF);
 GPIO_PORTB_AFSEL_R &= (~0x000000FF);
 GPIO_PORTB_DEN_R |=0x000000FF;}

 if(port_index==2){
	 GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;
	 GPIO_PORTC_CR_R |= 0x000000FF;
	 GPIO_PORTC_AMSEL_R &= (~0x000000FF);
	 GPIO_PORTC_PCTL_R &= (~0xFFFFFFFF);
	 GPIO_PORTC_AFSEL_R &= (~0x000000FF);
	 GPIO_PORTC_DEN_R |=0x000000FF;}

 if(port_index==3){
	 GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
	 GPIO_PORTD_CR_R |= 0x000000FF;
	 GPIO_PORTD_AMSEL_R &= (~0x000000FF);
	 GPIO_PORTD_PCTL_R &= (~0xFFFFFFFF);
	 GPIO_PORTD_AFSEL_R &= (~0x000000FF);
	 GPIO_PORTD_DEN_R |=0x000000FF;}


 if(port_index==4){
	 GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;
	 GPIO_PORTE_CR_R |= 0x0000003F;
	 GPIO_PORTE_AMSEL_R &= (~0x0000003F);
	 GPIO_PORTE_PCTL_R &= (~0x00FFFFFF);
	 GPIO_PORTE_AFSEL_R &= (~0x0000003F);
	 GPIO_PORTE_DEN_R |=0x0000003F;}

 if(port_index==5){
	 GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	 GPIO_PORTF_CR_R |= 0x0000001F;
	 GPIO_PORTF_AMSEL_R &=(~0x0000001F);
	 GPIO_PORTF_PCTL_R &= (~0x000FFFFF);
	 GPIO_PORTF_AFSEL_R &=(~0x0000001F);
	 GPIO_PORTF_DEN_R |=    0x0000001F; }
}

