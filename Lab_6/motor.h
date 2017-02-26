#include "mbed.h"
#ifndef MOTOR_H
#define MOTOR_H

#define LEFT 1
#define RIGHT 2
 
 
class Motor
{
public:
    /**
     * Motor Will Create a Motor object Connected to the Specified pins.
     * @param Pins to be Connected to the specified L293 http://www.ti.com/lit/ds/symlink/l293.pdf
     * @param Positive
     * @param Negative
     * @param Speed
     */
    Motor (PinName Positive, PinName Negative,PinName Speed);
    /**
     * Control the Direction of the Movement
     * @param move will specefiy the Direction.
     * Input 1 or 2.
     *  1 : Postive VCC Negtaive GND, 2 : Postive GND Negtaive VCC   
     */
    void Direction(int move);
    /** 
     * Stops the Movement of the motor
     * @param None.
     * Input 1 or 2.
     */
    void Stop();
    /**
     * Controls the speed of the motor with a input.
     * @param motor_speed from 0 to 100. 0 is the slowest and 100 is max speed. 
     * 
     */
    void Speed(int motor_speed);
 
protected:
     DigitalOut _positive;
     DigitalOut _negative;
     PwmOut     _speed;
     
    
}; //end of Motor class
#endif