/*Created on: Mar 16, 2019
 * Martina
 */


#include "DIO.h"
void DIO_WritePort(uint8 port_index, uint8 pins_mask, enum Dio_LevelType pins_level)
   {
	
  switch (port_index)
   {
		case 0 :                                                     // Port A
			if(pins_level==1)
			{
			GPIO_PORTA_DATA_R |=pins_mask;                             // bit or 0001000 =0001000
			}                          				
			else
			{
			GPIO_PORTA_DATA_R &=(~(pins_mask));                        //bit and 1110111 = xxx0xxx
			}
			break ;
		
		case 1 :                                                     // Port B
        if(pins_level==1)
			   {
			    GPIO_PORTB_DATA_R |=pins_mask;                          
			   }                          				
			  else
			   {
			    GPIO_PORTA_DATA_R &=(~(pins_mask));                          
	       }			
			break ;
		
		case 2 :                                                      // Port C
        if(pins_level==1)
			   {
			    GPIO_PORTC_DATA_R |=pins_mask;                          
			   }                          				
			  else
			   {
			    GPIO_PORTC_DATA_R &=(~(pins_mask));                          
	       }					
			break ;
		
		case 3 :                                                    // Port D
			   if(pins_level==1)
			   {
			    GPIO_PORTD_DATA_R |=pins_mask;                          
			   }                          				
			  else
			   {
			    GPIO_PORTD_DATA_R &=(~(pins_mask));                          
	       }						                                   
			break ;
		
		case 4 :                                                    // Port E
         if(pins_level==1)
			   {
			    GPIO_PORTE_DATA_R |=pins_mask;                          
			   }                          				
			  else
			   {
			    GPIO_PORTE_DATA_R &=(~(pins_mask));                          
	       }								
			break ;
		
		case 5 :                                                   // Port F
          if(pins_level==1)
			   {
			    GPIO_PORTF_DATA_R |=pins_mask;                          
			   }                          				
			  else
			   {
			    GPIO_PORTF_DATA_R &=(~(pins_mask));                          
	       }								
			break ;
   }
}
