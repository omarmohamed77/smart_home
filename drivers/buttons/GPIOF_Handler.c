#include "button interrupt.h"
void GPIOF_Handler(void){
if (GPIO_PORTF_RIS_R&0x01)  //F0
	{
  
		GPIO_PORTF_ICR_R|=0x01;
  //push button f0 event to be executed
 
}


 
else if(GPIO_PORTF_RIS_R&0x10) //F4
{ GPIO_PORTF_ICR_R|=0x10;
	//push button f4 event to be executed
			
	
	
  

}




  }