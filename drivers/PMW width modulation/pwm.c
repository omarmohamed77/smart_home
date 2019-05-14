#include "PWM.h"

void PWM_Init(void) {
    int volatile delay;

    SYSCTL_RCGCPWM_R |= (1 << 0); // activate PWM module 0 clock
    SYSCTL_RCGC2_R |= (1 << 4);   // activate port E clock
    delay = SYSCTL_RCGC2_R;       // allow time for clock to stabalize
    GPIO_PORTE_DR4R_R |= (1 << 4);
    GPIO_PORTE_DEN_R |= (1 << 4);      // enable digital output on PE4
    GPIO_PORTE_AFSEL_R |= (1 << 4);    // activate  Alternate function on PE4
    GPIO_PORTE_PCTL_R |= (0x00040000); // set alternate peripheral to PWM
    PWM0_2_CTL_R &= ~(1 << 0);         // disable pwm block until ready to use
    PWM0_2_CTL_R &= ~(1 << 1);         // set count-down mode
    PWM0_2_GENA_R |= (0xC2); // drive pwm low on CmpA and high on zero(low
                             // logic)
    PWM0_2_LOAD_R = (5000 - 1); // 5000 (16khz pwm)
    PWM0_2_CMPA_R =
        (2500 - 1); // set couter value at which CmpA triggers (any value now)
    PWM0_2_CTL_R |= (0x01);               // enable pwm block
    PWM0_ENABLE_R |= (PWM_ENABLE_PWM4EN); // Enable pwm output to M1PWM2
}
void PWM_Modulation(int potiometer_reading) {
    int duty_c = ((2500 * potiometer_reading) / 64);
    PWM0_2_CTL_R &= ~(1 << 0); // disable pwm block until ready to use
    PWM0_2_CTL_R &= ~(1 << 1); // set count-down mode
    PWM0_2_GENA_R |= (0xC2);   // drive pwm low on CmpA and high on zero(low
                             // logic)
    PWM0_2_LOAD_R = (5000 - 1); // 5000 (16khz pwm)
    PWM0_2_CMPA_R =
        (duty_c); // set couter value at which CmpA triggers (any value now)
    PWM0_2_CTL_R |= (0x01);               // enable pwm block
    PWM0_ENABLE_R |= (PWM_ENABLE_PWM4EN); // Enable pwm output to M1PWM2
}
