#include "tm4c123gh6pm.h"
#include "ADC.h"
#include "UART7.h"
#include "stepper.h"
#include "timer.h"
#include "PWM.h"
#include "stepper.h"
#include "TempSensor.h"

void check_n_setPWM()
{
    uint8 dat;
    if (Data_Available_To_Be_Received())
    {
        dat = UART7_DR_R & 0xFF;
        if (dat != 'l' && dat != 'r')
        {
            PWM_Modulation(dat * 2);
        }
    }
}

int main()
{
    uint16 temp, indata, pwm = 0, dat;
    Systick_init();
    ADC0_Init();
    UART7_init();
    PWM_Init();
    stepper_init();
    void (*fn_ptr)() = check_n_setPWM;
    while (1)
    {
        SysTick_Wait10ms(10);
        temp = get_temperature();
        UART7_Send(temp);
        if (Data_Available_To_Be_Received())
        {
            indata = UART7_DR_R & 0xFFF;
            dat = indata & 0xFF;
            if (dat == 'l')
            {
                turn30_CCW(fn_ptr);
                UART7_Send('c');
            }

            else if (dat == 'r')
            {
                turn30_CC(fn_ptr);
                UART7_Send('c');
            }
            else
            {
                pwm = (dat) * 2;
                PWM_Modulation(pwm);
            }
        }
    }
}
