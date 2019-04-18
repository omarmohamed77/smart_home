#include "DIO.h"

uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask)
{
    volatile uint32 *PORT = GPIO_PORTA_DATA_BITS_R + ((port_index & 0x03) << 10) + ((port_index >> 2) << 15);
    return PORT[pins_mask];

    // switch (port_index)
    // {
    // case 0:
    //     return (GPIO_PORTA_DATA_R & pins_mask);
    //     break;
    // case 1:
    //     return (GPIO_PORTB_DATA_R & pins_mask);
    //     break;
    // case 2:
    //     return (GPIO_PORTC_DATA_R & pins_mask);
    //     break;
    // case 3:
    //     return (GPIO_PORTD_DATA_R & pins_mask);
    //     break;
    // case 4:
    //     return (GPIO_PORTE_DATA_R & pins_mask);
    //     break;
    // case 5:
    //     return (GPIO_PORTF_DATA_R & pins_mask);
    //     break;

    // default:
    //     break;
    // }
}
