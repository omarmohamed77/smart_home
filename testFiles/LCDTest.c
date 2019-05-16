/*
 * LCDTest.c
 *
 *  Created on: May 14, 2019
 *      Author: omar
 */
#include "LCD.h"
#include "port.h"
#include "mcal.h"
#include "timer.h"

int main(void)
{
    Systick_init();
    Port_Init(1);
    Port_Init(0);
    Port_SetPinDirection(0, 0xE0, PORT_PIN_OUT);
    Port_SetPinDirection(1, 0xFF, PORT_PIN_OUT);
//    GPIO_PORTA_DATA_BITS_R[0xE0] = 0xE0;
//    GPIO_PORTB_DATA_BITS_R[0xFF] = 0x00;
    LCD_init();
//    LCD_print(15);
    LCD_data('a');
    for (;;)
    {

    }
}

