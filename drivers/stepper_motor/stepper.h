#ifndef STEPPER_H_
#define STEPPER_H_
#include "port.h"
enum direction {CCW,CW};
void stepper_init();
void OneStep(enum direction dir);
#endif /* STEPPER_H_ */
