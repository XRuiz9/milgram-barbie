#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32

int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servoPin = 18;
int switchPin = 25;

int switchValue = 0;

void setup() {
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin); // attaches the servo on pin 18 to the servo object
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings
  // for an accurate 0 to 180 sweep
}

void loop() {
  switchValue = analogRead(switchPin);
  Serial.println(switchValue);
  myservo.write(0);
  delay(5);

  if (switchValue >= 4000) {
    shock();
  }

//  int val1 = random(180);
//  int val2 = random(180);
//  int max, min;
//  Serial.print(val1 + " " + val2);
//  if (val1 > val2) {
//    max = val1;
//    min = val2;
//  } else {
//    max = val2;
//    min = val1;
//  }
//  
//  for (pos = 0; pos <= max; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);    // tell servo to go to position in variable 'pos'
//    delay(5);             // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= min; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);    // tell servo to go to position in variable 'pos'
//    delay(5);             // waits 15ms for the servo to reach the position
//  }
}

void shock() {
  myservo.write(60);
  delay(5);
  myservo.write(90);
  delay(5);
}
