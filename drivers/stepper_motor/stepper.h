#ifndef STEPPER_H_
#define STEPPER_H_
#include "port.h"
enum direction {CCW,CW};
void stepper_init();
void OneStep(enum direction dir);
void rotate30_CCW();
void rotate30_CW();
#endif /* STEPPER_H_ */
