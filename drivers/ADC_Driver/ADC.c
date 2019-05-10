
#include "ADC.h"

#define ADC0_SS0_PRI 0x3
#define ADC0_SS1_PRI (0x2 << 4)
#define ADC0_SS2_PRI (0x1 << 8)
#define ADC0_SS3_PRI (0x0 << 12)

volatile int y;

void ADC0_Init(void) {
    SYSCTL_RCGCADC_R |= 0x1; // Enable clock for ADC0
    SYSCTL_RCGCGPIO_R |= 0x10; // Enable portE
    y = 0;
    y = 0;
    y = 0;
    y = 0;
    GPIO_PORTE_DIR_R &= ~(0x04); // E2 as input
    GPIO_PORTE_AFSEL_R |= 0x04;  // enable alternate fun on E2
    GPIO_PORTE_DEN_R &= ~(0x04); // disable digital on E2
    GPIO_PORTE_AMSEL_R |= 0x04;

    ADC0_ACTSS_R &= ~0x8; // Disable  the sequences s3
    ADC0_EMUX_R &= ~0xF000; // Software Trigger
    // ADC0_SSPRI_R = (ADC0_SS3_PRI | ADC0_SS2_PRI | ADC0_SS1_PRI |
    // ADC0_SS0_PRI); // set priority
    ADC0_SSMUX3_R |= 0x1; // mod: set input from AIN1; PE2
    ADC0_SSCTL3_R |= 0x6; // maybe modified for temp sensor
    ADC0_ACTSS_R |= 0x8;  // Enable Sequence 3
}

void ADC0_Reading(uint16 *data) {
    ADC0_PSSI_R |= (0x1 << 3); // begin sampling on SS3
    while ((ADC0_RIS_R & ADC_RIS_INR3) == 0) {
    } // if INT3 is not set"checking if conversion is complete"
    *data = ADC0_SSFIFO3_R;    // Storing the Sampled reading
    ADC0_ISC_R |= ADC_ISC_IN3; // clearing RIS of INT3
    return;
}
