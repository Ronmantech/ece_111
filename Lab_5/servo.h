#include "Motor.h"
#include "mbed.h"
#include "SLCD.h"
#ifndef MBED_SERVO_H
#define MBED_SERVO_H
 
/** Servo control class, based on a Motor Class object
 *
 * Example:
 * @code
 * #include "mbed.h"
 * #include "Motor.h"
 * #include "Servo.h"
 * Motor my_motor(P12,P13P,p11);
 * Servo my_servo(p21,my_motor);
 * 
 * int main() {
 *     
 * }
 * @endcode
 */
class Servo {
 
public:
    /** Create a servo object.
     *
     * @param pin AnalogIn pin to be feedback, motor is a Motor object from Motor.h  
     */
    Servo(PinName analog_input,PinName Positive, PinName Negative,PinName Speed);
    
    /** Set the servo position
     *
     * @param angle intger in degrees 0-180 to represent the full range.
     */
    void set(int degree);
    
    /**  Read the servo current position in degrees from 0-180
     *
     * @return returns the current anlge of the servo   
     */   
    
     void move(void);
     
     void check();
protected:
    AnalogIn _feedback;
    Motor    _motor;
};
 
#endif
 