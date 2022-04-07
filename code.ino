// Created by Infinity de Guzman on April 5 2022

#include<Servo.h>
int dt=10;
Servo servo;
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int pos=0;
int trig=2;
int echo=3;

//int distance,duration;
void setup() {
Serial.begin(9600);
servo.attach(7);
}

void loop() {

if (calc_dis()<50)
{
  for (pos = 0; pos <= 180; pos += 2)
  {
    servo.write(pos);
    delay(10);
  }
  for (pos = 180; pos >= 0; pos -= 2)
  {
    servo.write(pos);
    delay(10);
  }
}
else if (calc_dis()>50) {
    delay(4000);
}

// Clears the trigPin condition
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
// Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

}

//This code is written to calculate the DISTANCE using ULTRASONIC SENSOR

int calc_dis()
{
  int duration,distance;
  digitalWrite(trig,HIGH);
  delay(dt);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}



