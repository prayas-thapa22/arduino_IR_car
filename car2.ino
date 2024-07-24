#include<IRremote.h>
const int RemotePin=8;
IRrecv irrecv(RemotePin);
decode_results results;
int in1=3;
int in2=5;
int in3=6;
int in4=9;
unsigned long lastPressTime = 0; // Store the time of the last button press
const unsigned long timeout = 500; // Timeout period in milliseconds (adjust as needed)

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
    
}
//use a seperate program to read in the ir bluetooth codes for forward, back right etc and adjust accordingly
void loop() {
  if (irrecv.decode(&results)) {
    lastPressTime = millis(); // Update the last press time
    if (results.value == 0x90) { // Press UP Button, adjust the hex code if needed
      Forward();
    } else if (results.value == 0x890) { // Press Down Button, adjust the hex code if needed
      Backward();
    } else if (results.value == 0xC90) { // Press Left Button, adjust the hex code if needed
      Left();
    } else if (results.value == 0x490) { // Press Right Button, adjust the hex code if needed
      Right();
    } else if (results.value == 0x290) { // Stop, adjust the hex code if needed
      Stop();
    }
    irrecv.resume();
  }

  // Check if the timeout period has elapsed without a button press
  if (millis() - lastPressTime > timeout) {
    Stop();
  }
}
 
void Backward()
  {
  Serial.println(results.value, HEX);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  
  }
 void Forward()
  {  
  Serial.println(results.value, HEX);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  
  }
 void Stop()
  {
  Serial.println(results.value, HEX);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
  int Left()
    {
    Serial.println(results.value, HEX);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
   
    }
  int Right()
    {
    Serial.println(results.value, HEX);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);

    }