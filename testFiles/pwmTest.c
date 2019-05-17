#include "mcal.h"
#include "timer.h"
#include "PWM.h"

int main(void)
{
    uint8 c = 0;
    Systick_init();
    PWM_Init();
    for (;;)
    {
        PWM_Modulation(c);
        c = (c+15)%64;
        SysTick_Wait10ms(100);
    }
}
