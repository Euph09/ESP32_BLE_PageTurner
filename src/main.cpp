#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;
const int button_pin = 18;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(button_pin,INPUT_PULLUP);
}

void loop() {
  int buttonState =digitalRead(button_pin);
  if(bleKeyboard.isConnected()) {
    
    Serial.println("Connected to device ");
    if (buttonState==LOW){
      Serial.println("Button pressed");
      bleKeyboard.write(KEY_RIGHT_ARROW);

    }

    
  }

  Serial.println("Waiting 0.1 seconds...");
  delay(100);
}