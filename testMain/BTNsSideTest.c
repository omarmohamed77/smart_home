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

void wait_n_check()
{
    uint8 quit = 0, inD;
    uint16 pot_reading, prev_pot = 0;
    while (!quit)
    {
        ADC0_Reading(&pot_reading);
        pot_reading = pot_reading >> 7;
        if (pot_reading != prev_pot)
        {
            UART7_Send(pot_reading);
            prev_pot = pot_reading;
        }
        SysTick_Wait10ms(10);
        if (Data_Available_To_Be_Received())
        {
            inD = (uint8) (UART7_DR_R & Received_Data_Mask);
            if (inD == 'c')
            {
                quit = 1;
            }
            else
            {
                LCD_print(inD);
            }
        }
    }
}

int main(void)
{
    uint8 flag1 = 0, flag2 = 0, led = 0, d1, d2;
    uint8 r, l, p, inD;
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
            LCD_print(inD);
        }
        if (flag1 && DIO_ReadPort(5, 0x01))
        {
            flag1 = 0;
        }
        if (flag2 && DIO_ReadPort(5, 0x10))
        {
            flag2 = 0;
        }
        if (!DIO_ReadPort(5, 0x01) && !flag1)
        {
            SysTick_Wait10ms(3);
            if (!DIO_ReadPort(5, 0x01))
            {
                led &= ~0x04;
                led ^= 0x02;
                r = 1;
                flag1 = 1;
            }
        }
        if (!DIO_ReadPort(5, 0x10) && !flag2)
        {
            SysTick_Wait10ms(3);
            if (!DIO_ReadPort(5, 0x10))
            {
                led &= ~0x02;
                led ^= 0x04;
                l = 1;
                flag2 = 1;
            }
        }
        if (pot_reading != prev_pot)
        {
            prev_pot = pot_reading;
            p = 1;
        }
        if (r)
        {
            r = 0;
            UART7_Send('r');
            wait_n_check();
        }
        if (l)
        {
            l = 0;
            UART7_Send('l');
            wait_n_check();
        }
        if (p)
        {
            p = 0;
            UART7_Send(pot_reading);
        }
        GPIO_PORTF_DATA_BITS_R[0x06] = led;
    }
}
