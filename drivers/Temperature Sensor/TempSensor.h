#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#include "ADC.h"
#include "std_types.h"

#define VREFP 3.3
#define VREFN 0

uint16 get_temperature(); // return temperature value in celsius

#endif /* TEMPSENSOR_H_ */
