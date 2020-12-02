int LED1 = 2;
int LED2 = 3;
int LED3 = 4;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  digitalWrite(LED3, HIGH);
  
  digitalWrite(LED1, HIGH);
  delay(750);
  digitalWrite(LED1, LOW);
  delay(350);

  digitalWrite(LED2, HIGH);
  delay(400);
  digitalWrite(LED2, LOW);
  delay(600);
  }
