#include "std_types.h"
#include "tm4c123gh6pm.h"
#include "Common_Macros.h"

#define Received_Data_Mask      0x000000FF


/* Functions Prototypes */
void UART1_init(void);
bool Data_Available_To_Be_Received(void);
void UART1_Send(uint8 data);
uint8 UART1_Receive(void);
