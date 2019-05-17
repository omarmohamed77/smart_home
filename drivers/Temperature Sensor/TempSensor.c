#include "TempSensor.h"

uint16 get_temperature() {
    uint16 adc_reading;
    volatile uint32 temp;
    float32 result;
    ADC0_ACTSS_R &= ~0x8; // disable sequencer 3
    ADC0_SSCTL3_R |= (1 << 3); // read from temp. sensor
    ADC0_ACTSS_R |= 0x8; // Enable Sequencer 3
    ADC0_Reading(&adc_reading);
    result = (adc_reading)*3.3 / 4095;
    temp = ((2.7 - result) * 75) - 55;
    ADC0_ACTSS_R &= ~0x8; // disable sequencer 3
    ADC0_SSCTL3_R &= ~(1 << 3); // read from temp. sensor
    ADC0_ACTSS_R |= 0x8; // Enable Sequencer 3
    return temp;
}
