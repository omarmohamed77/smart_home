
#include "ADC.h"

#define ADC0_SS0_PRI 0x3
#define ADC0_SS1_PRI (0x2 << 4)
#define ADC0_SS2_PRI (0x1 << 8)
#define ADC0_SS3_PRI (0x0 << 12)

void ADC0_Init(void) {
    int y;
    SYSCTL_RCGC0_R |= 0x00010000; // Enable clock for ADC0
    y = 0;
    y = 0;
    SYSCTL_RCGCGPIO_R |= 0x10;   // Enable portE
    y = 0;
    y = 0;    
    ADC0_ACTSS_R &= ~0x8;         // Disable all the sequences
    // ADC0_RIS_R|= 0x00000000;//No Interrupt used
    ADC0_EMUX_R = (ADC0_EMUX_R & 0x0FFF); // Software Trigger
    ADC0_SSPRI_R = (ADC0_SS3_PRI | ADC0_SS2_PRI | ADC0_SS1_PRI | ADC0_SS0_PRI);
    ADC0_SSMUX3_R = 0x0;                     // 1 Sample
    ADC0_SSCTL3_R |= (0x1 << 2) | (0x1 << 1); // maybe modified for temp sensor
    ADC0_ACTSS_R |= 0x8;                     // Enable Sequence 3
    GPIO_PORTE_DIR_R &= ~(0x04);             // E2 as input
    GPIO_PORTE_AFSEL_R |= 0x04;              // enable alternate fun on E2
    GPIO_PORTE_DEN_R &= ~(0x04);             // disable digital on E2
    GPIO_PORTE_AMSEL_R |= 0x04;
}

void ADC0_Reading(uint16* data) {
    ADC0_PSSI_R = (0x1 << 3); // begin sampling on SS3
    while ((ADC0_RIS_R & ADC_RIS_INR3) != ADC_RIS_INR3){} // if INT3 is not set"checking if conversion is complete"
    *data = ADC0_SSFIFO3_R; // Storing the Sampled reading
    ADC0_ISC_R |= ADC_ISC_IN3;              // clearing RIS of INT3
    return;
}
