#include "mbed.h"
#include "Motor.h"
#include "Servo.h"
 
Servo my_servo(PTB3,PTE19,PTE18,PTE31);
AnalogIn Spanel(PTB2);
uint16_t reading_array[3];
int position_array[3]={30,75,120};
uint16_t largest = 0; 
int largesti = 0;
int i;
 
int main() {
 
while (1) {  
 
for (i = 0; i < 3; i++){
my_servo.set(position_array[i]);
wait(3);
reading_array[i] = Spanel.read_u16();
}
 
 
 
 
 
for (i = 0; i < 3; i++){
    if (reading_array[i] > largest){
        largest = reading_array[i];
        largesti = i;
        
        }
    }
my_servo.set(position_array[largesti]);
wait(15);
    }
}