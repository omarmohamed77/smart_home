#include "TempSensor.h"

uint16 get_temperature() {
    Set_Bit(ADC0_SSCTL3_R, ADC_SSCTL3_TS0);
    uint16 adc_reading;
    ADC0_Reading(&adc_reading);
//    uint16 temp = 147 - ((uint16)(75 * (VREFP - VREFN) * adc_reading) >> 12);
    Clear_Bit(ADC0_SSCTL0_R, ADC_SSCTL0_TS0);
    return adc_reading;
}
