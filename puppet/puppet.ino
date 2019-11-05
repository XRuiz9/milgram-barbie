#include <ESP32Servo.h>

// Create servo objects to control eye and finger motors
Servo eyes;
Servo fingers;

// Declare pins
int eyesPin = 18;
int fingersPin = 14;
int switchPin = 25;

// Declare value that we are reading
int switchValue = 0;

void setup() {
  Serial.begin(9600);

  //Initialize eye motor
  eyes.setPeriodHertz(50);
  eyes.attach(eyesPin);

  //Initialize finger motor
  fingers.setPeriodHertz(50);
  fingers.attach(fingersPin);
  
  pinMode(switchPin, INPUT);
}

void loop() {
  // Read switch value
  switchValue = analogRead(switchPin);

  // Set default eye and finger position 
  eyes.write(120);
  fingers.write(120);
  delay(5);

  // If switch is on, shock
  if (switchValue >= 4000) {
    shock();
  }

void shock() {
  // Make eyes and fingers flutter
  eyes.write(30);
  fingers.write(30);
  delay(5);
  
  eyes.write(0);
  fingers.write(0);
  delay(5);
}
