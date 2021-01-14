const int led = 13; //PB5
const int interruptButton = 2; //PD2, also as external interrupt 0

volatile int ledState = LOW;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(interruptButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptButton), blink, CHANGE);
}

void loop(){
  digitalWrite(led, ledState); //will blink
}

void blink(){
  ledState = !ledState;
}
