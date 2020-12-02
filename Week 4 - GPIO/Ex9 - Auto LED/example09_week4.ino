int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(781);
  digitalWrite(LED1, LOW);
  delay(515);

  digitalWrite(LED2, HIGH);
  delay(2014);
  digitalWrite(LED2, LOW);
  delay(1348);

  digitalWrite(LED3, HIGH);
  delay(343);
  digitalWrite(LED3, LOW);
  delay(573);

  digitalWrite(LED4, HIGH);
  delay(2014);
  digitalWrite(LED4, LOW);
  delay(1348);

  digitalWrite(LED5, HIGH);
  delay(1478);
  digitalWrite(LED5, LOW);
  delay(326);

  digitalWrite(LED6, HIGH);
  delay(1859);
  digitalWrite(LED6, LOW);
  delay(351);

  digitalWrite(LED7, HIGH);
  delay(777);
  digitalWrite(LED7, LOW);
  delay(888);
}
