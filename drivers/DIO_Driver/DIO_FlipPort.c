/*Created on: Mar 18, 2019
 * Martina
 * discription : To Toggle the values of the pins selected by pins_masks in the port selected by port_index
 */
 
 
# include "DIO.h"
void DIO_FlipPort (uint8 port_index, uint8 pins_mask) 
 {				
   switch(port_index)
		{
		   case 0:                                                                   // port A
	            GPIO_PORTA_DATA_R ^= pins_mask;
	     break;
					 
			 case 1:                                                                   // port B
	            GPIO_PORTB_DATA_R ^= pins_mask;
	     break;
						 
		   case 2:                                                                   // port C
	            GPIO_PORTC_DATA_R ^= pins_mask;
	     break;
									 
			 case 3:                                                                   // port D
	            GPIO_PORTD_DATA_R ^= pins_mask;
	     break;
												 
			 case 4:                                                                   // port E
	            GPIO_PORTE_DATA_R ^= pins_mask;
	     break;
			 
			 case 5:                                                                   // port F
	            GPIO_PORTF_DATA_R ^= pins_mask;
	     break;
		 }
	 }
