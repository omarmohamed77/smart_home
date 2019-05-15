/*
 * uartTest.c
 *
 *  Created on: May 13, 2019
 *      Author: omar
 */
#include "mcal.h"
#include "UART7.h"
#include "port.h"
#include "DIO.h"
#include "ADC.h"
#include "timer.h"
#include "LCD.h"

int main(void)
{
    uint8 flag1 = 0, flag2 = 0, led = 0, d1, d2;
    uint8 r, l, p, inD, lock = 0;
    uint16 pot_reading, prev_pot = 0;
    ADC0_Init();
    Port_Init(5);
    Port_SetPinDirection(5, 0x06, PORT_PIN_OUT);
    Port_SetPinDirection(5, 0x11, PORT_PIN_IN);
    Port_SetPinPullUp(5, 0x11, 1);
    Systick_init();
    UART7_init();
    Port_Init(0);
    Port_Init(1);
    Port_SetPinDirection(0, 0xE0, PORT_PIN_OUT);
    Port_SetPinDirection(1, 0xFF, PORT_PIN_OUT);
    LCD_init();
    for (;;)
    {
        SysTick_Wait10ms(10);
        ADC0_Reading(&pot_reading);
        pot_reading = pot_reading >> 7;
        if (Data_Available_To_Be_Received())
        {
            inD = (uint8) (UART7_DR_R & Received_Data_Mask);
            if (inD == 'c')
            {
                lock = 0;
            }
            else
            {
                LCD_print(inD);
            }
        }
        if (flag1 && DIO_ReadPort(5, 0x01))
        {
            flag1 = 0;
        }
        if (flag2 && DIO_ReadPort(5, 0x10))
        {
            flag2 = 0;
        }
        if (!DIO_ReadPort(5, 0x01) && !flag1 && !lock)
        {
            SysTick_Wait10ms(3);
            if (!DIO_ReadPort(5, 0x01))
            {
                led &= ~0x04;
                led ^= 0x02;
                UART7_Send('r');
                flag1 = 1;
                lock = 1;
            }
        }
        if (!DIO_ReadPort(5, 0x10) && !flag2 && !lock)
        {
            SysTick_Wait10ms(3);
            if (!DIO_ReadPort(5, 0x10))
            {
                led &= ~0x02;
                led ^= 0x04;
                UART7_Send('l');
                flag2 = 1;
                lock = 1;
            }
        }
        if (pot_reading != prev_pot)
        {
            prev_pot = pot_reading;
            UART7_Send(pot_reading);
        }
        if (!lock)
        {
            GPIO_PORTF_DATA_BITS_R[0x06] = led;
        }
    }
}

