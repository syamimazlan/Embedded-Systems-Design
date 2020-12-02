int  buttonPin1 = 2;
int  buttonPin2 = 3;
int  buttonPin3 = 4;

int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;

int count1 = 0;
int count2 = 0;
int count3 = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT);
  pinMode(ledPin1, OUTPUT);

  pinMode(buttonPin2, INPUT);
  pinMode(ledPin2, OUTPUT);

  
  pinMode(buttonPin3, INPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin1) == HIGH)
  {
    count1++;
    digitalWrite(ledPin1, HIGH);
    delay(200);
    digitalWrite(ledPin1, LOW);
    delay(200);
    print();
  }

  else if (digitalRead(buttonPin2) == HIGH)
  {
    count2++;
    digitalWrite(ledPin2, HIGH);
    delay(200);
    digitalWrite(ledPin2, LOW);
    delay(200);
    print();
  }

  else if (digitalRead(buttonPin3) == HIGH)
  {
    count3++;
    digitalWrite(ledPin3, HIGH);
    delay(200);
    digitalWrite(ledPin3, LOW);
    delay(200);
    print();
  }
}

void print(){
  Serial.print("A = \n");
  Serial.print(count1);

  Serial.print("B = \n");
  Serial.print(count2);

  Serial.print("C = \n");
  Serial.print(count3);

  delay(500);
}
