#include<Servo.h>
#define Servo_pin 13
Servo motor;

void setup() {
  pinMode(Servo_pin,OUTPUT);
  motor.attach(Servo_pin);
}
void loop() {
  motor.write(0);
  delay(1000);

  motor.write(90);
   delay(1000);

  motor.write(180);
   delay(1000);

}
