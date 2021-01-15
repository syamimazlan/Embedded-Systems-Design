//Libraries
#include "Arduino.h"
#include "Buzzer.h"
#include "LiquidCrystal_I2C.h"
#include "Wire.h" //needed for communication with liquidcrystal_i2c

//Pin Definitions
int pushButton_1 = 4;
int pushButton_2 = 5;
int pushButton_3 = 6;
int pushButton_4 = 7;
int ledR_1 = 8;
int ledY_1 = 9;
int ledR_2 = 10;
int ledY_2 = 11;
int pushButton_reset = 11;
int Potentiometer = A3;

//LCD
#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); //address, columns, rows

//Music part
const int buzzer = 2;
const int songLength = 18;
char notes[] = "cdfda ag cdfdg gf "; //the letters represents the notes, the space represents a rest/pause
int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
int tempo = 123;

//game loop part
const int MAX_LEVEL = 26; //just a random number for the number of levels available
int sequence[MAX_LEVEL];
int your_sequence[MAX_LEVEL];
int level = 1;
int velocity = 1000;

void setup() {
  Wire.begin();
  
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Game start!");
    
  // initialize the lcd
  lcd.init();
  lcd.setBacklight(LOW);
  
  pinMode(pushButton_1, INPUT);
  pinMode(pushButton_2, INPUT);
  pinMode(pushButton_3, INPUT);
  pinMode(pushButton_4, INPUT);
  pinMode(pushButton_reset, INPUT);
  
  pinMode(buzzer, OUTPUT);
  pinMode(ledR_1, OUTPUT);
  pinMode(ledR_2, OUTPUT);
  pinMode(ledY_1, OUTPUT);
  pinMode(ledY_2, OUTPUT);

  digitalWrite(ledR_1, LOW);
  digitalWrite(ledR_2, LOW);
  digitalWrite(ledY_1, LOW);
  digitalWrite(ledY_2, LOW);
  
  if(pushButton_reset == HIGH){
    Reset();
  }
}

void loop() {
  music();
  welcome();
  
  if(level == 1){
    simonSaysStart();
  }

  if(level !=1){
    simonSaysPhrase();
    simonSaysSequence();
    simonSaysInput();
  }
}

void music(){
  int i, duration;
  for (i = 0; i < songLength; i++){
    duration = beats[i] * tempo; //length of note/rest in ms
    if (notes[i] == ' '){
      delay(duration); //if it's a rest, then pause for a moment
      }
    else{
      tone(buzzer, frequency(notes[i]), duration);
      delay(duration); //wait for tone to finish
      }
    delay(tempo/10);//brief pause between notes
  }
}

int frequency(char note){
  int i;
  const int numNotes = 8;
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  for (i = 0; i < numNotes; i++){
    if (names[i] == note){
      return(frequencies[i]);
    }
  }return(0);
}

void welcome(){
  lcd.clear();
  lcd.setCursor(2,0); // Set cursor at the begining of line 1
  lcd.print("Welcome to"); // Print String to LCD on first line
  lcd.setCursor(2, 1); // Set cursor at the begining of line 2
  lcd.print("Simon Says!"); // Print String to LCD on second line
  delay(1000);
}

void Reset(){
  lcd.clear(); // Clear LCD screen.
  lcd.print("Game reset!");
}

void simonSaysPhrase(){
  int i = 0;

  if((i + level) < level){
    lcd.print("Simon Says!");
  }

  else{
    lcd.print("Simba Says!");
  }
}

void simonSaysSequence(){
  digitalWrite(ledR_1, LOW);
  digitalWrite(ledR_2, LOW);
  digitalWrite(ledY_1, LOW);
  digitalWrite(ledY_2, LOW);

  for (int i = 0; i < level; i++){
    digitalWrite(sequence[i], HIGH);
    delay(velocity);
    digitalWrite(sequence[i], LOW);
    delay(200);
    }
}

void simonSaysInput(){
  int flag = 0; //this flag indicates if the sequence is correct

  for (int i = 0; i < level; i++){
    flag = 0;
    while(flag == 0){
      if (pushButton_4 == LOW){
        digitalWrite(ledY_2, HIGH);
        your_sequence[i] = 5;
        flag = 1;
        delay(200);

        if (your_sequence[i] != sequence[i]){
          wrong_sequence();
          return;
          }
        digitalWrite(ledY_2, LOW);
        }

    if (pushButton_3 == LOW){
      digitalWrite(ledR_2, HIGH);
      your_sequence[i] = 4;
      flag = 1;
      delay(200);
      if (your_sequence[i] != sequence[i]){
        wrong_sequence();
        return;
        }
      digitalWrite(ledR_2, LOW);
      }

    if (pushButton_2 == LOW){
      digitalWrite(ledY_1, HIGH);
      your_sequence[i] = 3;
      flag = 1;
      delay(200);
      if (your_sequence[i] != sequence[i]){
        wrong_sequence();
        return;
        }
      digitalWrite(ledY_1, LOW);
      }

    if (pushButton_1 == LOW){
      digitalWrite(ledR_1, HIGH);
      your_sequence[i] = 2;
      flag = 1;
      delay(200);
      if (your_sequence[i] != sequence[i]){
        wrong_sequence();
        return;
        }
      digitalWrite(ledR_1, LOW);
      }
    }
  }
  right_sequence();
}

void simonSaysStart(){
  randomSeed(millis()); //randomiser

  for (int i = 0; i < MAX_LEVEL; i++){
    sequence[i] = random(2,6);
  }
}

void wrong_sequence(){
  for (int i = 0; i < 3; i++){
    digitalWrite(ledR_1, HIGH);
    digitalWrite(ledR_2, HIGH);
    digitalWrite(ledY_1, HIGH);
    digitalWrite(ledY_2, HIGH);
    delay(250);
    
    digitalWrite(ledR_1, LOW);
    digitalWrite(ledR_2, LOW);
    digitalWrite(ledY_1, LOW);
    digitalWrite(ledY_2, LOW);
    delay(250);
    }
    
  level = 1;
  velocity = 1000;
}

void right_sequence(){
  digitalWrite(ledR_1, LOW);
  digitalWrite(ledR_2, LOW);
  digitalWrite(ledY_1, LOW);
  digitalWrite(ledY_2, LOW);
  delay(250);

  digitalWrite(ledR_1, HIGH);
  digitalWrite(ledR_2, HIGH);
  digitalWrite(ledY_1, HIGH);
  digitalWrite(ledY_2, HIGH);
  delay(500);
  
  digitalWrite(ledR_1, LOW);
  digitalWrite(ledR_2, LOW);
  digitalWrite(ledY_1, LOW);
  digitalWrite(ledY_2, LOW);
  delay(500);

  if (level < MAX_LEVEL){
    level++;
  }
}
