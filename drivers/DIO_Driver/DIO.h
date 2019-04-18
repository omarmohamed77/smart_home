#ifndef DIO_H_
#define DIO_H_

#include "mcal.h"

void DIO_WritePort(uint8 port_index, uint8 pins_mask, enum Dio_LevelType pins_level);
uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask);
void DIO_FlipPort (uint8 port_index, uint8 pins_mask);

#endif /* DIO_H_ */
