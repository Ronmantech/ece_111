#include "mbed.h"
#include "Motor.h"
AnalogIn pot(PTB2);   // variable resistor middile pin
Motor my_motor(PTB1,PTB0); // create a motor object
 
 
int main() {
 
while (1) {  
 
//Stop if in the middle 
if((pot > 0.49) && (pot < 0.61)){
 my_motor.Stop();
      } 
      //Negative Direction 
      else if (pot < 0.48){
          my_motor.Direction(LEFT);
          wait(0.1);
          }
          //Postive Direction
      else if (pot > 0.62 ) {     
          my_motor.Direction(RIGHT);
          wait(0.1);
          }
    }
}