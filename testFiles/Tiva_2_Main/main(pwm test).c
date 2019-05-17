#include "ADC.h"
#include "UART7.h"
#include "stepper.h"
#include "timer.h"
#include "PWM.h"

void SystemInit(){
ADC0_Init();
UART7_init();
Systick_init();
PWM_Init();




}int main(){uint8 indata;
	Port_Init(5);
	Port_SetPinDirection(5,0x6,PORT_PIN_OUT);
	
while(1){
	SysTick_Wait10ms(10);
if (Data_Available_To_Be_Received()){
	indata = UART7_DR_R & 0xFF;
	if (indata=='l'){
	GPIO_PORTF_DATA_R |=0X02;
	GPIO_PORTF_DATA_R &=~0X04;
	}
		
else if (indata=='r'){
	GPIO_PORTF_DATA_R |=0X04;
	GPIO_PORTF_DATA_R &=~0X02;
	}	
else {
	
PWM_Modulation(indata*2);


}



}}}