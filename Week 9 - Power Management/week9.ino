#include <avr/sleep.h> //library that contains methods that can control sleep modes

const int interruptButton = 2; //PD2, also from Week 7
const int led = 13; //PB5
int blinkTime = 5;
int countdown = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(interruptButton, INPUT_PULLUP);
}

void loop() {
  sleep();
}

void sleep(){
  if(countdown < blinkTime){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }countdown++;

  else if(countdown == blinkTime){
    sleep_enable(); //from sleep.h, enables sleep mode
    attachInterrupt(0, wakeUp, LOW);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    digitalWrite(led, LOW);
    delay(1000);
    sleep_cpu(); //activates sleep mode
  }
}

void wakeUp(){
  Serial.println("Interrupted!");
  sleep_disable(); //disables sleep mode
  detachInterrupt(0);
}
