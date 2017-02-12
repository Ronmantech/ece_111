/*! Lab1TestAdvanced3
 *  Used for advanced LED blinking with the FRDM-KL46Z.  This adds a .h file to leverage modularity and also provides an example of a proper commenting style.
 * @code
 * #include "mbed.h"
 *
 * outputLED may be r or g, frequency is in Hertz, and brightness can range between 0 and 1.
 * void blink(output LED, frequency, brightness)
 * {
 * }
 * @endcode
 */

#include "mbed.h"
// this class file is a template on using .h files.
class Blinker
{
public:
    Blinker(void) {
    };
// class method to blink and LED based on the PwmOut class
    void blink(PwmOut outputLED, float frequency, float brightness) {
        outputLED.period(.001f);
        outputLED = 1- brightness;
        float duration = (1.0/frequency)/2;  //dividing by 2 lets the microcontroller wait for half of the period before changing the LED.
        wait(duration);
        outputLED = 1.0;  //LED is active low, so setting this to 1 turns off the LED.
        wait(duration);
    };

private:

};
