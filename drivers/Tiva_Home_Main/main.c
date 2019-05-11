#include "mcal.h"
#include "Tiva_Home.h"

#define Stepper_Read		0xC0

void SystemInit(void){
	UART7_init();
	ADC0_init();
	Systick_init();
	stepper_init();
	//PWM_Init(potentiometer_reading);
}

int main(void){
	uint8 Prev_temp=0, avg, preavg=0;
	uint8 In_Data, Stepper_Data, Out_Data;
	while(1) {
	    Out_Data = get_temperature();
        SysTick_Wait10ms(10);
	    avg = (Out_Data+Prev_temp)/2;
	    if(avg!=preavg)
	    {
	        if((UART7_FR_R & 0x20)==0){
	                UART7_DR_R = Out_Data;
					Prev_temp = Out_Data;
	                preavg = avg;
	        }
	    }
		else
		{
			//receive
			if((UART7_FR_R & 0x10)==0)
			{
					In_Data  = (UART7_DR_R & 0xFF);
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
