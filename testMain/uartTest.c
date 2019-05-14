#include "ADC.h"
#include "UART7.h"
#include "stepper.h"
#include "timer.h"
#include "PWM.h"
#include "stepper.h"

int main()
{
    ADC0_Init();
    UART7_init();
    Systick_init();
    Port_Init(1);
    Port_SetPinDirection(1, 0x40, PORT_PIN_IN);
//    PWM_Init();
    stepper_init();
    uint8 indata, pwm = 0;
//    Port_Init(5);
//    Port_SetPinDirection(5, 0x6, PORT_PIN_OUT);

    while (1)
    {
        SysTick_Wait10ms(10);
        if (Data_Available_To_Be_Received())
        {
            indata = UART7_DR_R & 0xFF;
            if (indata == 'l')
            {
                turn30_CCW();
            }

            else if (indata == 'r')
            {
                turn30_CC();
            }
            else if (indata != 'r' && indata != 'l')
            {
//                pwm = indata * 2;
//                PWM_Modulation(pwm);
            }

        }
    }
}
