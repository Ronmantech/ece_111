 #include "mbed.h"
 #include "Servo.h"
 // gloabl varevlbe used only inseide the class 
int value_current;
int value_target;
float value_target_raw;
Ticker tick;
SLCD slcd;
int n;
int counter;
char buffer[50];
 
Servo::Servo(PinName analog_input,PinName Positive, PinName Negative,PinName Speed):
     _feedback(analog_input),_motor(Positive,Negative,Speed) {
      
}   
     /* input is angle intger from 0 - 180 
     *  
     */
void Servo::set(int degree) {
   if(degree > 90){
   value_target = degree;   // set the value target as the input of the function
   tick.attach(this,&Servo::move,0.001); // set the ticker to call move every 0.001 sec
}
  else{
   value_target = degree-15;   // set the value target as the input of the function
   tick.attach(this,&Servo::move,0.001);   
      } 
  
       }//End of Move
   
void Servo::move() {
 
value_current = (int)((int)(_feedback*1000)*0.30769230769);
 
if(value_target > value_current){ 
        _motor.Direction(LEFT);
      //  _motor.Speed(10);
        //wait(0.1);
        n = sprintf (buffer, "%d", value_current);
        slcd.clear();
        slcd.Home();  
        slcd.printf(buffer); 
       }
else if(value_target < value_current){
        _motor.Direction(RIGHT);
      //  _motor.Speed(counter);
        n = sprintf (buffer, "%d", value_current);
        slcd.clear();
        slcd.Home();  
        slcd.printf(buffer);
        }     
else if((value_target == value_current))
 {
        tick.detach();
        _motor.Stop();
        n = sprintf (buffer, "%d", value_current);
        slcd.clear();
        slcd.Home();  
        slcd.printf(buffer);
       }
 
      
 
      }
      
      
   
void Servo::check() {
 
  value_current = (int)((int)(_feedback*1000)*0.30769230769);
  n = sprintf (buffer, "%d", value_current);
  slcd.clear();
  slcd.Home();  
  slcd.printf(buffer);
   
      }
         