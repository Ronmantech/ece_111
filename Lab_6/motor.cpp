#include "mbed.h"
#include "Motor.h"
 
 
 
Motor::Motor(PinName Positive, PinName Negative,PinName Speed):
        _positive(Positive), _negative(Negative), _speed(Speed) {
     _speed.period(0.03f);      // 
     _speed.write(0.45f); 
}   
     /* Input 1 or 2.
     *  1 : Postive VCC Negtaive GND, 2 : Postive GND Negtaive VCC.
     */
void Motor::Direction(int move) {
     if(move == 1){
     _positive = 1;
     _negative = 0;
    }
    else if(move == 2){   
     _positive = 0;
     _negative = 1;
        }
    }//End of Direction
   
     /* No input.
     *  1 : Postive GND Negtaive GND  
     */
void Motor::Stop() {
     _positive = 0;
     _negative = 0;
    }//End of Stop
    /* input is the .
     *  1 : Postive GND Negtaive GND  
     */
void Motor::Speed(int motor_speed) {
   float percantage = motor_speed/100;
   _speed.write(percantage); 
    }//End of Stop