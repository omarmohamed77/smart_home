#include "stepper.h"
uint8 step_no = 0;
void stepper_init()
{
    Port_Init(3);   //initializing port D
    Port_SetPinDirection(3, 0x0F,PORT_PIN_OUT);
}
void OneStep(enum direction dir)
{
	switch(step_no)
	{
		case 0:		GPIO_PORTD_DATA_R = 0x0E;
							break;
		case 1:		GPIO_PORTD_DATA_R = 0x0C;
							break;
		case 2:		GPIO_PORTD_DATA_R = 0x0D;
							break;
		case 3:		GPIO_PORTD_DATA_R = 0x09;
							break;
		case 4:		GPIO_PORTD_DATA_R = 0x0B;
							break;
		case 5:		GPIO_PORTD_DATA_R = 0x03;
							break;
		case 6:		GPIO_PORTD_DATA_R = 0x07;
							break;
		case 7:		GPIO_PORTD_DATA_R = 0x06;
							break;
		default:	GPIO_PORTD_DATA_R = 0x0F;
							break;
	}
	if(dir)
	{
		step_no = (step_no + 1)%8; 
	}
	else
	{
		step_no = step_no - 1;
		if(step_no < 0)
			step_no = 7;
	}
}
