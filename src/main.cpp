#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;
const int RButton_pin = 18;
const int LButton_pin = 23;
bool previouslyConnected =false;

bool leftUp = true;
bool rightUp=false;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(LButton_pin,INPUT_PULLUP);
  pinMode(RButton_pin,INPUT_PULLUP);
}

void loop() {
  int LButtonState =digitalRead(LButton_pin);
  int RButtonState =digitalRead(RButton_pin);
  if(bleKeyboard.isConnected()) {
    if (not previouslyConnected){
      Serial.println("Connected to device ");
      previouslyConnected=true;
    }
    
    if (LButtonState==LOW and leftUp){
      Serial.println("Left button pressed");
      bleKeyboard.write(KEY_LEFT_ARROW);
      leftUp=false;
    }
    if (RButtonState==LOW and rightUp){
      Serial.println("Right button pressed");
      bleKeyboard.write(KEY_RIGHT_ARROW);
      rightUp=false;
    }
    if(LButtonState==HIGH){
      leftUp=true;
    }
    if(RButtonState==HIGH){
      rightUp=true;
    }

    
  }

  Serial.println("Waiting 0.05 seconds...");
  delay(50);
}