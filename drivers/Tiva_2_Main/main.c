#include "button interrupt.h"
#include "LCD.H"
#include "UART.h"
#include "port.h"
#include "timer.h"
#include "ADC.h"
#include "stdbool.h"


bool left=0;
bool right=0 ;

void SystemInit(){
		ADC0_Init();
		Systick_init();
		button_interrupt();
	UART7_init();	
		



}
	

	
	int main(){
				uint8 motor=0;
		uint8 temp=0;

		Port_Init(0);
		Port_SetPinDirection(0,0xE0,PORT_PIN_OUT); //lcd port d
		Port_Init(1);
		Port_SetPinDirection(1,0xFF,PORT_PIN_OUT); //lcd port b
	LCD_init();
		//LCD_data('H');
		
		
		//uint16 adc;
		//uint8  led;
		
		
		while(1){
			motor=0;
	//		left=0;
		//	right=0 ;
	//	ADC0_Reading(&adc);
		//	led=adc<<6; //maping to 6 bit
if (! (UART7_FR_R & UART_FR_RXFE) )
	  temp=  (UART7_DR_R & 0xFF)	;
			//temp= UART7_Receive();
			LCD_data((uint8)((temp / 100) + 48));
	LCD_data((uint8)(((temp%100) / 10) + 48));
	LCD_data((uint8)((temp%10) + 48));
	
if(left){
			left=0;
	right=0 ;
		motor &=(1<<7);
			UART7_Send(motor);
		
			
			
	
}
			
			
			
		else if(right){
		right=0;
		left=0;	
			motor &=(1<<6);
			UART7_Send(motor);
		}
		
		

			
		
		
	}}
