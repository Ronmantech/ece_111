#include "mbed.h"
 
#ifndef MBED_MOTOR_H
#define MBED_MOTOR_H
#define LEFT 1
#define RIGHT 2
/** Motor class, create motor object to control speed and direction.
 *
 * Example:
 * @code
 * #include "mbed.h"
 * #include "Motor.h"
 * Motor my_motor(P12,P13P,p11);
 * 
 * int main() {
 * my_motor.Direction(LEFT);
 * wait(0.1);
 * }
 * @endcode
 */
class Motor {
 
public:
    /** Create a motor object.
     *
     * @param  Postive input of A1 on L293DNE 
     * @param  Negative input of A2 on L293DNE
     * @param  Speed  PWM output -> EN1,2 on L293DNE
     *
     */
    Motor (PinName Positive, PinName Negative);
    
    /** control the direction of the movement  
     *
     * @param move is LEFT or RIGHT defined as 1 and 2 in Motor.h
     *
     */
    void Direction(int move);
    
    /**  Stop the motor 
     *  
     * 
     */
    void Stop();
    /** control the speed of the motor object 
     * 
     * @param motor_speed from 0 to 100. 0 is the slowest and 100 is max speed. 
     * 
     */
    void Speed(int motor_speed);
    
protected:
     PwmOut  _positive;
     PwmOut  _negative;
};
 
#endif