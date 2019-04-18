/*Created on: Mar 17, 2019
 * Martina
 * discription : to connect pin to internal pull down resistor in case enable is 1
 */

# include "Port_SetPinPullDown.h"
 void Port_SetPinPullDown (uint8 port_index, uint8 pins_mask, uint8 enable)
	{
	switch(port_index)
		{
		   case 0:                                                      // port A
			     if(enable)
				    {
	            GPIO_PORTA_PDR_R |= pins_mask;
	          }
           else
					  {
              GPIO_PORTA_PDR_R &= (~(pins_mask));
            }
	     break;
					 
		 case 1:                                                        // portB
			   if(enable)
				  {
	           GPIO_PORTB_PDR_R |= pins_mask;
	        }
        else
					{
             GPIO_PORTB_PDR_R &= (~(pins_mask));
          }
		   break;
					
	   case 2:                                                           // portC
			   if(enable)
					{
	           GPIO_PORTC_PDR_R |= pins_mask;
	        }
         else
					{
             GPIO_PORTC_PDR_R &= (~(pins_mask));
          }
		   break;
	
     	case 3:                                                          // port D
			    if(enable)
				   {
	           GPIO_PORTD_PDR_R |= pins_mask;
	         }
          else
					 {
             GPIO_PORTC_PDR_R &= (~(pins_mask));
           }
		   break;
					 
	    case 4:                                                          // port E
	        if(enable)
		       {
	           GPIO_PORTE_PDR_R |= pins_mask;
	         }
         else
					 {
             GPIO_PORTE_PDR_R &= (~(pins_mask));
           }
		   break;
					 
		   case 5:                                                         // Port F
		     	if(enable)
				  {
	           GPIO_PORTF_PDR_R |= pins_mask;
	        }
         else
					{
             GPIO_PORTF_PDR_R &= (~(pins_mask));
          }
		    break;
	
	 }
}