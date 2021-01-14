#include <EEPROM.h>

int button = 8;
int led = 4;

int ledState;
int buttonState;
int lastButtonState = LOW;

long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

  digitalWrite(led, ledState);
  Serial.begin(9600);

  checkLedState();
}

void loop() {
  int reading = digitalRead(button);

  if(reading != lastButtonState){
    lastDebounceTime = millis();
  }

  if(millis() - lastDebounceTime) > debounceRelay){
    if(reading !=  buttonState){
      buttonState = reading;

      if(buttonState == HIGH){
        ledState = !ledState;
      }
    }
  }

  digitalWrite(led, ledState);
  EEPROM.update(0, ledState);
  lastButtonState = reading;
}

void checkLedState(){
  Serial.println("LED status: ");
  ledState = EEPROM.read(0);

  if(ledState == 1){
    Serial.println("ON");
    digitalWrite(led, HIGH);
  }

  if(ledState == 0){
    Serial.println("OFF");
    digitalWrite(led, LOW);
  }
}
