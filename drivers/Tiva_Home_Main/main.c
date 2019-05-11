#include "mcal.h"
#include "Tiva_Home.h"

#define Stepper_Read		0xC0

void SystemInit(void){
	ADC0_init();
	UART0_init();
	stepper_init();
	//PWM_Init(potentiometer_reading);
}

int main(void){
	uint8 Prev_temp=0;
	uint8 In_Data, Stepper_Data;
	while(1) {
		if(get_temperature()!=Prev_temp)
		{
			//send
			if((UART0_FR_R & 0x20)==0)
			{
				UART0_DR_R = get_temperature();
				Prev_temp = get_temperature();
			}
		}
		else
		{
			//receive
			if((UART0_FR_R & 0x10)==0)
			{
					In_Data  = (UART0_DR_R & 0xff);
					Stepper_Data = In_Data & Stepper_Read;
					Stepper_Data >>= 6;
					if(Stepper_Data == 0b01)
						rotate30_CW();
					else if(Stepper_Data == 0b10)
						rotate30_CCW();
			}
		}
	}
}