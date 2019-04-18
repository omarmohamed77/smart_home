#include "Port_SetPinPullUp"
void Port_SetPinPullUp(uint8 port_index,uint8 pins_mask,uint8 enable){
	switch(port_index){
		case 0://case port A
			if(enable){
	GPIO_PORTA_PUR_R |= pins_mask;
	}
        else{
         GPIO_PORTA_PUR_R &= (~(pins_mask));
            }
	     break;
		case 1://case portB
			if(enable){
	GPIO_PORTB_PUR_R |= pins_mask;
	}
        else{
         GPIO_PORTB_PUR_R &= (~(pins_mask));
            }
		   break;
	case 2://case portC
			
			if(enable){
	GPIO_PORTC_PUR_R |= pins_mask;
	}
        else{
         GPIO_PORTC_PUR_R &= (~(pins_mask));
            }
		   break;
	
	case 3://case portD
			
			Port_reg=GPIO_PORTD_PUR_R;
			if(enable){
	GPIO_PORTD_PUR_R |= pins_mask;
	}
        else{
         GPIO_PORTC_PUR_R &= (~(pins_mask));
            }
		   break;
	case 4://case portE
			Port_reg=GPIO_PORTE_PUR_R;
	if(enable){
	GPIO_PORTE_PUR_R |= pins_mask;
	}
        else{
         GPIO_PORTE_PUR_R &= (~(pins_mask));
            }
		   break;
		case 5://case Portf
			if(enable){
	GPIO_PORTF_PUR_R |= pins_mask;
	}
        else{
         GPIO_PORTF_PUR_R &= (~(pins_mask));
            }
		   break;
	
	}
}
