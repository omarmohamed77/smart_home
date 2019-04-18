/*
 * port.h
 *
 *
 *      Author: omar
 */

#ifndef PORT_H_
#define PORT_H_
#include "mcal.h"
void Port_Init(uint8 port_index);
void Port_SetPinDirection(uint8 port_index, uint8 pins_mask,enum Port_PinDirectionType pins_direction);
void Port_SetPinPullDown (uint8 port_index, uint8 pins_mask, uint8 enable);
void Port_SetPinPullUp(uint8 port_index,uint8 pins_mask,uint8 enable);

#endif /* PORT_H_ */
