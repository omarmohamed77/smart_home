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
		case 0:		GPIO_PORTD_DATA_R = 0x08;
							break;
		case 1:		GPIO_PORTD_DATA_R = 0x04;
							break;
		case 2:		GPIO_PORTD_DATA_R = 0x02;
							break;
		case 3:		GPIO_PORTD_DATA_R = 0x01;
							break;
		//case 4:		GPIO_PORTD_DATA_R = 0x0B;
			//				break;
		//case 5:		GPIO_PORTD_DATA_R = 0x03;
			//				break;
		//case 6:		GPIO_PORTD_DATA_R = 0x07;
			//				break;
		//case 7:		GPIO_PORTD_DATA_R = 0x06;
			//				break;
		//default:	GPIO_PORTD_DATA_R = 0x0F;
				//			break;
	}
	if(dir)
	{
		step_no = (step_no + 1)%4; 
	}
	else
	{
		if(step_no == 0)
			step_no = 3;
		else
			step_no = step_no - 1;
	}
}
void turn30_CC(void)
{
	int i = 0;
	while(i<300)
	{
		OneStep(CW);
		delaymilli(100);
		i++;
	}
}
void turn30_CCW(void)
{
	int i = 0;
	while(i<300)
	{
		OneStep(CCW);
		delaymilli(100);
		i++;
	}
}
