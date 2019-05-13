#include "mcal.h"
#include "Tiva_Home.h"

#define Stepper_Read		0xC0

int main(void)
{
    UART7_init();
    ADC0_Init();
    Systick_init();
    stepper_init();
    UART0_init();
    uint8 Prev_temp = 0, avg, preavg = 0;
    uint8 In_Data, Stepper_Data, Out_Data;
    while (1)
    {
//        Out_Data = get_temperature();
//        SysTick_Wait10ms(10);
//        avg = (Out_Data + Prev_temp) / 2;
////        UART0_Send(avg - 25 + 48);
////        UART0_Send(' ');
////        UART0_Send(preavg - 25 + 48);
////        UART0_Send('\n');
//        if (avg != preavg)
//        {
//            if ((UART0_FR_R & 0x20) == 0)
//            {
//                UART0_DR_R = 'i';
//            }
//            if ((UART0_FR_R & 0x20) == 0)
//            {
//                UART0_DR_R = '\n';
//            }
//            UART7_Send(Out_Data);
//
//            if ((UART0_FR_R & 0x20) == 0)
//            {
//                UART0_DR_R = 's';
//            }
//            if ((UART0_FR_R & 0x20) == 0)
//            {
//                UART0_DR_R = '\n';
//            }
//            Prev_temp = Out_Data;
//            preavg = avg;
//
//        }
        //else
        //{
        //receive
        if (!(UART7_FR_R & UART_FR_RXFE))
        {

            In_Data = (uint8) (UART7_DR_R & Received_Data_Mask);
            if ((UART0_FR_R & UART_FR_TXFF) == 0)
            {
                UART0_DR_R = 'r';
            }
            UART0_Send(' ');
            UART0_Send((In_Data >> 6) + 48);
            if ((UART0_FR_R & 0x20) == 0)
            {
                UART0_DR_R = '\n';
            }
            Stepper_Data = In_Data & Stepper_Read;
            Stepper_Data >>= 6;
            if (Stepper_Data == 0x01)
            {
                turn30_CC();
                if ((UART0_FR_R & 0x20) == 0)
                {
                    UART0_DR_R = 'c';
                }
                if ((UART0_FR_R & 0x20) == 0)
                {
                    UART0_DR_R = '\n';
                }
            }

            else if (Stepper_Data == 0x02)
            {
                turn30_CCW();
                if ((UART0_FR_R & 0x20) == 0)
                {
                    UART0_DR_R = 'w';
                }
                if ((UART0_FR_R & 0x20) == 0)
                {
                    UART0_DR_R = '\n';
                }
            }
        }
        //}
    }
}
