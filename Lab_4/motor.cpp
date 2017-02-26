#include "mbed.h"
#include "Motor.h"
 
Motor::Motor(PinName Positive, PinName Negative): _positive(Positive), _negative(Negative){
     _positive.period(0.03f);      // 4 second period
     _positive.write(0.25f); 
     _negative.period(0.03f);      // 4 second period
    _negative.write(0.25f); 
     
}   
     /* Input 1 or 2 or LEFT and RIGHT
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
    
void Motor::Speed(int motor_speed) {
   float percantage = motor_speed/100;
 
    }//End of Speed