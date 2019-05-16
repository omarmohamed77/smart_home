#include "mcal.h"
#include "Tiva_Home.h"

#define Stepper_Read		0xC0
#define PWM_Data			0x3F

void SystemInit(void){
	UART7_init();
    ADC0_Init();
    Systick_init();
    stepper_init();
    PWM_Init();
}

int main(void)
{
    uint8 Prev_temp = 0, avg, preavg = 0;
    uint8 In_Data, Out_Data, Stepper_Data, Potentiometer_Reading;
    while (1)
    {
        Out_Data = get_temperature();
        SysTick_Wait10ms(10);
        avg = (Out_Data + Prev_temp) / 2;
        if (avg != preavg)
        {
			//send
            if((UART7_FR_R & 0x20)==0){
	            UART7_DR_R = Out_Data;
				Prev_temp = Out_Data;
				preavg = avg;
			}
        }
        //receive
		if((UART7_FR_R & 0x10)==0)
		{
			In_Data  = (UART7_DR_R & 0xFF);
			Potentiometer_Reading = In_Data & PWM_Data;
			PWM_Modulation(Potentiometer_Reading);
            Stepper_Data = In_Data & Stepper_Read;
            Stepper_Data >>= 6;
            if (Stepper_Data == 0x01)
                turn30_CC();
            else if (Stepper_Data == 0x02)
                turn30_CCW();
        }
    }
}
