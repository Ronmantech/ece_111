/*! Lab2
 *  Used to turn the FRDM-KL46Z into a voltmeter.
 */


#include "mbed.h"
#include "SLCD.h"

SLCD slcd;                          //Setup the LCD on the FRDM-KL46Z.
DigitalOut  led1(LED1);             //Setup the green LED.
AnalogIn    ReadVoltage(A0);        //Setup the analog input.


main()
{
    
    //Add a pull up resistor to SW1.
    led1 = 0;                       //Turn on the green LED.
    slcd.DP1(1);                    //Turn on the decimal point
    
    while(1) {
        led1=!led1;                     //Toggle the green LED
        slcd.printf("%4.0f", ReadVoltage.read()*3300.f);  //Use this line to read the analog input.
        wait(2);                  //Wait 2 seconds.
    }
}
