/**
 * main.c
 */
#include "ADC.h"
#include "LCD.h"
#include "TempSensor.h"

void testTemp_ADC(){
    ADC0_Init();
    uint8 temp;
    while(1){
        temp = (uint8)get_temperature();

    }
}

int main(void)
{
    testTemp_ADC();
	return 0;

}
