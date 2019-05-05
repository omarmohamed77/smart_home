#include "std_types.h"
#include "tm4c123gh6pm.h"
#include "Common_Macros.h"

/* Functions Prototypes */

void UART0_init(void);
void UART0_Send(uint8 data);
uint8 UART0_Recieve (void);