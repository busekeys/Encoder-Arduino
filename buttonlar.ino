#include <Encoder.h>
Encoder knobLeft(5, 6); //2 sol pin
Encoder knobRight(7, 8); //2 sağ pin
int outPin = 13; // push output pini
int inPin = 7;   // push input pini
int val = 0;     //pin sayaci

void setup() {
  Serial.begin(9600);
  Serial.println("Buton Yon Encoder Test:");
   pinMode(outPin, OUTPUT);  //output
  pinMode(inPin, INPUT);    // dinput
}

long positionLeft  = -999;  //sol
long positionRight = -999;  //sağ

void loop() {
  long newLeft, newRight;
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  if (newLeft != positionLeft || newRight != positionRight) {
    Serial.print("Left = ");
    Serial.print(newLeft);
    Serial.print(", Right = ");
    Serial.print(newRight);
    Serial.println();
    positionLeft = newLeft;
    positionRight = newRight;
  }
 
  if (Serial.available()) {
    Serial.read();
    Serial.println("Butonlari Resetle");
    knobLeft.write(0);
    knobRight.write(0);
  }
   val = digitalRead(inPin);  // push button input al
  if (val == HIGH) {         // check input is HIGH (button released)
    digitalWrite(outPin, LOW); 
  } else {
    digitalWrite(outPin, HIGH);  
  }
}

 
