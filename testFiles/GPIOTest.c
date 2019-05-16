#include "port.h"
#include "DIO.h"
#include "timer.h"
#include "PWM.h"

int main(void)
{
    uint8 coun = 0;
    PWM_Init();
    Systick_init();
    Port_Init(5);   //F
    Port_SetPinDirection(5, 0x06, PORT_PIN_OUT);
    GPIO_PORTF_DATA_BITS_R[0x06] = 0x06;
    for (;;)
    {
        coun = (coun + 5) % 64;
        PWM_Modulation(coun);
        SysTick_Wait10ms(100);
        GPIO_PORTF_DATA_BITS_R[0x06] ^= 0x06;
//        GPIO_PORTB_DATA_BITS_R[0x40] ^= 0x40;
    }
}
