#include "TempSensor.h"

uint16 get_temperature() {
    uint16 adc_reading;
    uint16 temp;
    float32 result;
    ADC0_ACTSS_R &= ~0x8; // disable sequencer 3
    Set_Bit(ADC0_SSCTL3_R, ADC_SSCTL3_TS0);

    ADC0_ACTSS_R |= 0x8; // Enable Sequencer 3
    ADC0_Reading(&adc_reading);
    result = (adc_reading)*3.3 / 4095;
    temp = ((2.7 - result) * 75) - 55;
    // temp = 147 - ((uint16)(75 * (VREFP - VREFN) * adc_reading) >> 12);
    ADC0_ACTSS_R &= ~0x8; // disable sequencer 3
    Clear_Bit(ADC0_SSCTL3_R, ADC_SSCTL3_TS0);
    ADC0_ACTSS_R |= 0x8; // Enable Sequencer 3
    return temp;
}
