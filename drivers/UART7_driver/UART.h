#include "mcal.h"
#define Received_Data_Mask      0x000000FF


/* Functions Prototypes */
void UART7_init(void);
uint8 Data_Available_To_Be_Received(void);
void UART7_Send(uint8 data);
uint8 UART7_Receive(void);
