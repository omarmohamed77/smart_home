
#include"mcal.h"
void Port_SetPinDirection(uint8 port_index, uint8 pins_mask,enum Port_PinDirectionType pins_direction){
	uint32 Port_reg;
	switch(port_index){
		case 0://case port A
			
			if (pins_direction) {//when the mask want to set bit
			GPIO_PORTA_DIR_R |= pins_mask;
		}
		else {// when want to clear bit
			GPIO_PORTA_DIR_R &= (~(pins_mask));
		}
	     break;
		case 1://case portB
			if (pins_direction) {
			GPIO_PORTB_DIR_R |= pins_mask;
		}
		else {
			GPIO_PORTB_DIR_R &= (~(pins_mask));
		}
		   break;
	case 2://case portC
			if (pins_direction) {
			GPIO_PORTC_DIR_R |= pins_mask;
		}
		else {
			GPIO_PORTC_DIR_R &= (~(pins_mask));
		}
		   break;
	
	case 3://case portD
			Port_reg=GPIO_PORTD_DIR_R;
			if (pins_direction) {
			GPIO_PORTD_DIR_R |= pins_mask;
		}
		else {
			GPIO_PORTD_DIR_R &= (~(pins_mask));
		}
		   break;
	case 4://case portE
			Port_reg=GPIO_PORTE_DIR_R;
			if (pins_direction) {
			GPIO_PORTE_DIR_R |= pins_mask;
		}
		else {
			GPIO_PORTE_DIR_R &= (~(pins_mask));
		}
		   break;
		case 5://case portf
			Port_reg=GPIO_PORTF_DIR_R;
			if (pins_direction) {
			GPIO_PORTF_DIR_R |= pins_mask;
		}
		else {
			GPIO_PORTF_DIR_R &= (~(pins_mask));
		}
		   break;
	
	}

}
