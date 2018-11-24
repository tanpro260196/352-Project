#include <stdint.h>
#include "tm4c123gh6pm.h"
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

//Function Prototypes
void delay();

//Variables
volatile uint32_t ui32Loop;

//*****************************************************************************
//
// GPIO Write - HIGH= GPIO_PIN_X , LOW= 0x00
//
//*****************************************************************************
int main(void)
{
    //Not sure what these do, but without them the code doesn't work :)
    //The first one is to enable port D. Another command to do this is SYSCTL_RCGCGPIO_R |= 0x08
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOD;
    //This one is to start the MCU CPU and set it to 40Mhz
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    //Well, technically, you don't meed to enable port D again. You already do that above. Haven't try it though.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);

    while(1)
    {
        GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0,GPIO_PIN_0); //write HIGH
        GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,0x00);       //write LOW
        GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2,0x00);
        GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_3,GPIO_PIN_3);

        GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2,GPIO_PIN_2);

    }

}
