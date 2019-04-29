#include "DIO.h"
/**************************************************FUNCTIONS***************************************************************************/

//1.Read data from PORT
uint8 DIO_ReadPort(uint8 port_index , uint8 pins_mask){
	
	uint8 pins_level;
	
	switch(port_index){
		
		case 0:pins_level=  GPIO_PORTA_DATA_R  &(pins_mask);  break;
		case 1:pins_level=  GPIO_PORTB_DATA_R  &(pins_mask);  break;
		case 2:pins_level=  GPIO_PORTC_DATA_R  &(pins_mask);  break;
		case 3:pins_level=  GPIO_PORTD_DATA_R  &(pins_mask);  break;
		case 4:pins_level=  GPIO_PORTE_DATA_R  &(pins_mask);  break;
		default:pins_level= GPIO_PORTF_DATA_R  &(pins_mask); break;
	}

	return pins_level;
}


//2.Write data from PORT
void DIO_WritePort(uint8 port_index , uint8 pins_mask ,Dio_LevelType pins_level){
	
	if(pins_level==STD_LOW){
		
		switch(port_index){
		
		case 0:GPIO_PORTA_DATA_R  &= ~(pins_mask); break;
		case 1:GPIO_PORTB_DATA_R  &= ~(pins_mask); break;
		case 2:GPIO_PORTC_DATA_R  &= ~(pins_mask); break;
		case 3:GPIO_PORTD_DATA_R  &= ~(pins_mask); break;
		case 4:GPIO_PORTE_DATA_R  &= ~(pins_mask); break;
		default:GPIO_PORTF_DATA_R &= ~(pins_mask);break;
	}
		
	}
	
	else{
	switch(port_index){
		
		case 0:GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R &(~pins_mask)) |(pins_mask); break;
		case 1:GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R &(~pins_mask)) |(pins_mask); break;
		case 2:GPIO_PORTC_DATA_R = (GPIO_PORTC_DATA_R &(~pins_mask)) |(pins_mask); break;
		case 3:GPIO_PORTD_DATA_R = (GPIO_PORTD_DATA_R &(~pins_mask)) |(pins_mask); break;
		case 4:GPIO_PORTE_DATA_R = (GPIO_PORTE_DATA_R &(~pins_mask)) |(pins_mask); break;
		default:GPIO_PORTF_DATA_R= (GPIO_PORTF_DATA_R &(~pins_mask)) |(pins_mask); break;
	}
	
}
	
}
	
//3.Toggle data from PORT
void DIO_FlipPort(uint8 port_index , uint8 pins_mask){
	
		switch(port_index){	
			
		case 0:GPIO_PORTA_DATA_R ^=(pins_mask); break;
		case 1:GPIO_PORTB_DATA_R ^=(pins_mask); break;
		case 2:GPIO_PORTC_DATA_R ^=(pins_mask); break;
		case 3:GPIO_PORTD_DATA_R ^=(pins_mask); break;
		case 4:GPIO_PORTE_DATA_R ^=(pins_mask); break;
		default:GPIO_PORTF_DATA_R ^=(pins_mask);break;
	  }
		
}
