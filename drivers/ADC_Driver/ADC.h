

#ifndef ADC_H_
#define ADC_H_

#include "Common_Macros.h"
#include "std_types.h"
#include "tm4c123gh6pm.h"

void ADC0_Init();

void ADC0_Reading(uint16* data);

#endif /* ADC_H_ */
