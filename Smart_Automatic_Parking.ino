#include<Servo.h>
#define trigPin 7
#define echoPin 6
int led1 = 4;
int led2 = 5;
Servo servo1;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  servo1.attach(9);
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, 0);
  delayMicroseconds(2);
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);
  duration = pulseIn(echoPin, 1);
  distance = (duration / 2) / 29.1;

  if (distance < 20) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    servo1.write(90);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    servo1.write(0);
  }

  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
