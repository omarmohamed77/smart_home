#include "PWM.h"

void PWM_Init(void) {
    int volatile delay;

    SYSCTL_RCGCPWM_R |= (1 << 1); // activate PWM module 1 clock
    SYSCTL_RCGC2_R |= (1 << 5);   // activate port F clock
    delay = SYSCTL_RCGC2_R;       // allow time for clock to stabalize
    delay = SYSCTL_RCGC2_R;       // allow time for clock to stabalize
    GPIO_PORTF_DR4R_R |= (1 << 2);
    GPIO_PORTF_DEN_R |= (1 << 2);      // enable digital output on PF2
    GPIO_PORTF_AFSEL_R |= (1 << 2);    // activate  Alternate function on PF2
    GPIO_PORTF_PCTL_R |= (0x00000500); // set alternate peripheral to PWM
    PWM1_3_CTL_R &= ~(1 << 0);         // disable pwm block until ready to use
    PWM1_3_CTL_R &= ~(1 << 1);         // set count-down mode
    PWM1_3_GENA_R |= (0xC2); // drive pwm low on CmpA and high on zero(low
                             // logic)
    PWM1_3_LOAD_R = (5000 - 1); // 5000 (16khz pwm)
    PWM1_3_CMPA_R =
        (2500 - 1); // set couter value at which CmpA triggers (any value now)
    PWM1_3_CTL_R |= (0x01);               // enable pwm block
    PWM1_ENABLE_R |= (PWM_ENABLE_PWM6EN); // Enable pwm output to M1PWM6
}
void PWM_Modulation(int potiometer_reading) {
    int duty_c = ((2500 * potiometer_reading) / 64);
    PWM1_3_CTL_R &= ~(1 << 0); // disable pwm block until ready to use
    PWM1_3_CTL_R &= ~(1 << 1); // set count-down mode
    PWM1_3_GENA_R |= (0xC2);   // drive pwm low on CmpA and high on zero(low
                             // logic)
    PWM1_3_LOAD_R = (5000 - 1); // 5000 (16khz pwm)
    PWM1_3_CMPA_R =
        (duty_c); // set couter value at which CmpA triggers (any value now)
    PWM1_3_CTL_R |= (0x01);               // enable pwm block
    PWM1_ENABLE_R |= (PWM_ENABLE_PWM6EN); // Enable pwm output to M1PWM6
}
