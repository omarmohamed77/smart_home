#include "mcal.h"
#include "Tiva_Home.h"

void SystemInit(void){
	ADC0_init();
	stepper_init();
	//PWM_Init(potentiometer_reading);
}

int main(void){
	//while receiving
	//interupt sending
}