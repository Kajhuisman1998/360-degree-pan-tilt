#include <SoftwareSerial.h>
//SoftwareSerial mySerial(4, 5); // RX, TX
const int Xpin = A0;  // Analog input pin that the joystick  is attached to
const int Ypin = A1;  // Analog input pin that the joystick  is attached to
   //  value read from the Y pin

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  //mySerial.begin(9600);
}

void loop() {
  // read the analog in value:
  Serial.write("<");  
  Serial.write(analogRead(Xpin));
  Serial.write(analogRead(Ypin));
  delay(2);
}
