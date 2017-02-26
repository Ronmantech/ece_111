#include "mbed.h"
#include "Motor.h"
#include "Servo.h"
 
Servo my_servo(PTB3,PTE19,PTE18,PTE31);
 
int main() {
 
while (1) {  
 
 
my_servo.set(45);
wait(4); 
 
my_servo.set(65);
wait(4); 
my_servo.set(90);
wait(4); 
 
my_servo.set(135);
wait(4); 
 
my_servo.set(180);
wait(4); 
 
    }
}