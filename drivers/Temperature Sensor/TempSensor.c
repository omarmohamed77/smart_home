#include "TempSensor.h"

uint16 get_temperature() {
    Set_Bit(ADC0_SSCTL0_R, ADC_SSCTL0_TS0);
    uint16 adc_reading = ADC0_Reading();
    uint16 temp = 147.5 - ((75 * (VREFP - VREFN) * adc_reading) / 4096);
}