#include "tm4c123gh6pm.h"
void SystemInit(void) {}
volatile int temperature, delay;
float Vresult;
void ADC_init(void) {
    SYSCTL_RCGCGPIO_R |= 0x10;
    delay = 0;
    SYSCTL_RCGCADC_R |= 0x1;
    delay = 0;
    delay = 0;
    delay = 0;
    // GPIO config.
    // GPIO_PORTE_AFSEL_R |= 0x8;
    // GPIO_PORTE_DEN_R &= ~0x8;
    // GPIO_PORTE_AMSEL_R |= 0x8;
    // ADC config.
    ADC0_ACTSS_R &= ~0x8;   // disable ss3
    ADC0_EMUX_R &= ~0xF000; // software trigger
    // ADC0_SSMUX3_R = 0x0; //read from channel 0 (PE3)
    ADC0_SSCTL3_R |= 0x6; // single ended, one sample at a time, interrupt
                          // enable
    ADC0_SSCTL3_R |= (1 << 3); // read from temp. sensor
    ADC0_ACTSS_R |= 0x8;       // enable ss3
}
int main(void) {
    ADC_init();
    // reading
    while (1) {
        ADC0_PSSI_R |= 0x8; // take a sample
        while ((ADC0_RIS_R & 0x8) == 0) {
        }
        Vresult = (ADC0_SSFIFO3_R)*3.3 / 4095;
        temperature = ((2.7 - Vresult) * 75) - 55;
        ADC0_ISC_R = 0x8;
    }
}