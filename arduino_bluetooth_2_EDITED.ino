#include <SoftwareSerial.h>

const int enA = 10;
const int in1 = 9;
const int in2 = 8;
const int enB = 5;
const int in3 = 7;
const int in4 = 6;

int Speed;
int command; 
int data;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
  Serial.begin(9600);
  Serial.print("Starting");
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();
    Serial.println(data);
    switch (data) {
      case 'F' : forward(); 
        break;
      case 'B' : back(); 
        break;
      case 'L' : left();
        break;
      case 'R' : right();
        break;
      case 'S' : Stop();
        break;
      
    }
  }
}

void forward() {
  Serial.println("Going forward");
  analogWrite(enA, 170);
  analogWrite(enB, 170);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void back() {
  Serial.println("Going back");
  analogWrite(enA, 170);
  analogWrite(enB, 170);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void left() {
  Serial.println("Going left");
  analogWrite(enA, 120);
  analogWrite(enB, 80);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //delay(1000);
}

void right() {
  Serial.println("Going right");
  analogWrite(enA, 80);
  analogWrite(enB, 120);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  //delay(1000);
}


void Stop() {
  Serial.println("Stopping");
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
