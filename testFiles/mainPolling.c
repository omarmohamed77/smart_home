#include "DIO.h"
#include "UART0.h"
#include "mcal.h"
#include "port.h"
#include "timer.h"

int main(void)
{
    uint8 flag1 = 0, flag2 = 0;
    Systick_init();
    Port_Init(5);
    Port_SetPinDirection(5, 0x11, PORT_PIN_IN);
    Port_SetPinPullUp(5, 0x11, 1);
    UART0_init();
    for (;;)
    {
        SysTick_Wait10ms(1);
        if (!DIO_ReadPort(5, 0x01) && !flag1)
        {
            SysTick_Wait10ms(2);
            if (!DIO_ReadPort(5, 0x01))
            {
                UART0_Send('l');
                flag1 = 1;
            }
        }
        else if (!DIO_ReadPort(5, 0x10) && !flag2)
        {
            SysTick_Wait10ms(2);
            if (!DIO_ReadPort(5, 0x10))
            {
                UART0_Send('r');
                flag2 = 1;
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
    }
    return 0;
}
