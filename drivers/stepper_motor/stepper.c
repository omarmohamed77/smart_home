#include "stepper.h"
uint8 step_no = 0;
void stepper_init()
{
    Port_Init(3);   //initializing port D
    Port_SetPinDirection(3, 0x0F,PORT_PIN_OUT);
}