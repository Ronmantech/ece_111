/*! Lab1TestAdvanced3
 *  Used for advanced LED blinking with the FRDM-KL46Z.  This adds a .h file to leverage modularity and also provides an example of a proper commenting style.
 * \author  Matthew Shuman
 *
 * \date    August 12th, 2016

 * \bug     No bugs yet

 * @code
 * #include "mbed.h"
 * #include "Blinker.h"
 *
 * PwmOut r(LED_RED);
 *
 * int main()
 * {
 *   Blinker myBlinker;
 *   while(1) {
 *      for(float i = 0; i < 5; i++) {  //Blink the LED 5 times
 *          myBlinker.blink(r or g, frequency in Hertz, % brightness (0 - 1.00) );
 *      }
 *   }//end of while
 * }//end of main
 * @endcode
 */

#include "mbed.h"
#include "Blinker.h"

//This creates Pulse Width Modulated outputs, r and g, and connects them to the red and green LED.
PwmOut r(LED_RED);
PwmOut g(LED_GREEN);

int main()
{
    // constructs member of new Blinker class, myBlinker
    Blinker myBlinker;
    while(1) {
        for(float i = 0; i < 5; i++) {  //Blink the LED 5 times
            // blinks the green LED at 2 Hz, with 75% brightness
            myBlinker.blink(g, 2, .75);
        }
        for(float i = 0; i < 10; i++) {  //Blink the LED 10 times
            // blinks the red LED at 4 Hz, with 15% brightness
            myBlinker.blink(r, 4, .15);
        }
    }//end of while
}//end of main
