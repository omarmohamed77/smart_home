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
#include "timer.h"

int main(void)
{
    Port_Init(5);
    Port_SetPinDirection(5, 0x06, PORT_PIN_OUT);
    Systick_init();
    UART7_init();
    uint8 inD;
    uint8 led = 0;
    for (;;)
    {
        SysTick_Wait10ms(5);
        if (Data_Available_To_Be_Received())
        {
            inD = UART7_DR_R & 0xFF;
            if (inD == 't')
            {
                led ^= 0x02;
                GPIO_PORTF_DATA_BITS_R[0x06] = led;
                SysTick_Wait10ms(50);
                inD = UART7_DR_R & 0xFF;
                if (inD == 'o')
                    led ^= 0x04;
            }
            else if (inD == 'o')
            {
                led ^= 0x04;
                GPIO_PORTF_DATA_BITS_R[0x06] = led;
                SysTick_Wait10ms(50);
                inD = UART7_DR_R & 0xFF;
                if (inD == 't')
                    led ^= 0x02;
            }
        }
        GPIO_PORTF_DATA_BITS_R[0x06] = led;
    }
}

