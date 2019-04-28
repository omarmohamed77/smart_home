

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "tm4c123gh6pm.h"
#include "Common_Macros.h"


void ADC0_Init();

uint16 ADC0_Reading(uint16 data);


#endif /* ADC_H_ */
