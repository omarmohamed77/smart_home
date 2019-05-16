#include "mcal.h"
#include "Tiva_Home.h"

#define Stepper_Read		0xC0

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
    uint8 In_Data, Stepper_Data, Out_Data;
    while (1)
    {
        Out_Data = get_temperature();
        SysTick_Wait10ms(10);
        avg = (Out_Data + Prev_temp) / 2;
        if (avg != preavg)
        {
			//send
            UART7_Send(Out_Data);
            Prev_temp = Out_Data;
            preavg = avg;

        }
        //receive
        if (!(UART7_FR_R & UART_FR_RXFE))
        {

            In_Data = (uint8) (UART7_DR_R & Received_Data_Mask);
            Stepper_Data = In_Data & Stepper_Read;
            Stepper_Data >>= 6;
            if (Stepper_Data == 0x01)
                turn30_CC();
            else if (Stepper_Data == 0x02)
                turn30_CCW();
        }
    }
}
