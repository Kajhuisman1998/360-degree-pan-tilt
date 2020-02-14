

const int Xpin = A0;  // Analog input pin that the joystick  is attached to
const int ypin = A1;  // Analog input pin that the joystick  is attached to
int Xvalue;      // value read from the X pin 
int YValue;     //  value read from the Y pin

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  Xvalue = analogRead(Xpin);
  YValue = analogRead(ypin);

 


  delay(2);
}