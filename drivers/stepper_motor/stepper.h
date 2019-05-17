#ifndef STEPPER_H_
#define STEPPER_H_
#include "port.h"
#include "timer.h"
enum direction
{
    CCW, CW
};
void stepper_init();
void OneStep(enum direction dir);
void turn30_CCW(void (*callback)());
void turn30_CC(void (*callback)());
#endif /* STEPPER_H_ */
