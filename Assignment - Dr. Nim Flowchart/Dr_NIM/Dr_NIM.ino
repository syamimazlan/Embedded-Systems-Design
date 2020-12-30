#include<Servo.h>
int indicator1 = 2; //Thoose are indicator LEDs, 3 of them go to pin2,4,3
int indicator2 = 4;
int indicator3 = 3;
Servo servoM;
int player1 = 7;
int player2 = 6;
int play2s = 9;
int next2s = 8;
int play1s = 10;
int next1s = 11;
int pvps = 12;
int win = 13;

int pvp = 0;
int play1 = 0; //Play and Next button for player1
int next1 = 0;
int play2 = 0; //Play and Next button for player2
int next2 = 0;
int ballcaunter = 12; //This is counting how many balls left
int indicator = 3;
int gamestart = 0; //This is just for starting sequence
int turn = 0; //Tells you who plays
void setup() {
  pinMode(win,OUTPUT);
  pinMode(indicator1,OUTPUT);
  pinMode(indicator2,OUTPUT);
  pinMode(indicator3,OUTPUT);
  servoM.attach(5); //Servo pin 5
  
  pinMode(player1,OUTPUT);
  pinMode(player2,OUTPUT);
  pinMode(pvp,INPUT);
  
  pinMode(play1,INPUT);
  pinMode(play2,INPUT);
  pinMode(next1,INPUT);
  pinMode(next2,INPUT);
  servoM.write(140); //You will need to modify code or calibrate your servo motor
  digitalWrite(win,LOW);

}

void loop() {
  pvp = digitalRead(pvps);
  play1 = digitalRead(play1s);
  play2 = digitalRead(play2s);
  next1 = digitalRead(next1s);
  next2 = digitalRead(next2s); //This is just so evry button would work properly
  if(gamestart == 0){
    gamestart = 1;
    digitalWrite(indicator1,HIGH);
    delay(1000);
    digitalWrite(indicator1,LOW);
    digitalWrite(indicator2,HIGH);
    delay(1000);
    digitalWrite(indicator2,LOW);
    digitalWrite(indicator3,HIGH);
    delay(1000);
  }
  if(gamestart == 1){//Starting sequence
    if(indicator == 1){
      digitalWrite(indicator1,HIGH);
      digitalWrite(indicator2,LOW);
      digitalWrite(indicator3,LOW);
    }
    if(indicator == 2){
      digitalWrite(indicator1,HIGH);
      digitalWrite(indicator2,HIGH);
      digitalWrite(indicator3,LOW);      
    }
    if(indicator == 3){
      digitalWrite(indicator1,HIGH);
      digitalWrite(indicator2,HIGH);
      digitalWrite(indicator3,HIGH);      
    }
    if(indicator == 0){
      digitalWrite(indicator1,LOW);
      digitalWrite(indicator2,LOW);
      digitalWrite(indicator3,LOW);
      delay(500);
      if(ballcaunter != 0){
      indicator = 3;    
      if(turn == 0){
        turn = 1;
      }
      else{
        turn = 0;
      }
      }
     }
 if(pvp==HIGH){//If you turned off Player vs Player mode
if(turn == 0){
      digitalWrite(player1,HIGH);
      digitalWrite(player2,LOW);
      if(play1 == LOW){
        indicator = indicator-1;
        servoM.write(0);
        ballcaunter = ballcaunter-1; //each time you take the ball caunter will decrise by 1
        delay(800);
        servoM.write(140);//Calibrate your servo or modify code so that servo pushes ball
        delay(800);
      }
      if(next1 == LOW){//If you finished your turn indicator restarts and it is other players turn
        if(turn ==0){
        if(indicator == 1 || indicator == 2){
          indicator=0;
        }
      }
      }
     }
if(turn == 1){
      digitalWrite(player2,HIGH);
      digitalWrite(player1,LOW);
  if(ballcaunter == 11 || ballcaunter ==7 || ballcaunter==3){//This is how arduino nows what to play, so it will beat you evry time, it is realy simple
    servoM.write(0);
    delay(800);    
    indicator = indicator-1;
    ballcaunter=ballcaunter-1;
    servoM.write(140);
    delay(800);
    servoM.write(0);
    delay(800);
    indicator = indicator-1;
    ballcaunter=ballcaunter-1;
    servoM.write(140);
    delay(800);
    servoM.write(0);
    delay(800);
    indicator = indicator-1;
    ballcaunter=ballcaunter-1;
    servoM.write(140);
    delay(800);
  }
  if(ballcaunter == 10 || ballcaunter ==6 || ballcaunter==2){
    servoM.write(0);
    delay(800);
    ballcaunter=ballcaunter-1;
    indicator = indicator-1;
    servoM.write(140);
    delay(800);
    servoM.write(0);
    delay(800);
    indicator = indicator-1;
    ballcaunter=ballcaunter-1;
    servoM.write(140);
    delay(800);
    indicator = 0;
}
  if(ballcaunter == 9 || ballcaunter ==5 || ballcaunter==1){    
    servoM.write(0);
    delay(800);
    ballcaunter=ballcaunter-1;
    indicator = indicator-1;
    servoM.write(140);
    delay(800);
    indicator = 0;
  }
 }
}
  if(ballcaunter==0){//If the counter gets to 0 winner will be announced
    digitalWrite(win,HIGH);//Turns on winner indicator
    digitalWrite(player1,LOW);
    digitalWrite(player2,LOW);
    if(turn==0){
      indicator=0;
      digitalWrite(player1,LOW);
      delay(200);
      digitalWrite(player1,HIGH);
      delay(200);
    }
    if(turn==1){
      indicator=0;
      digitalWrite(player2,LOW);
      delay(200);
      digitalWrite(player2,HIGH);
      delay(200);
    }
   }
if(pvp == LOW){//If you turned on Player vs Player mode
if(turn == 0){
  if(ballcaunter != 0){
      digitalWrite(player1,HIGH);
      digitalWrite(player2,LOW);
      if(play1 == LOW){
        ballcaunter = ballcaunter-1;
        indicator = indicator-1;
        servoM.write(0);
        delay(800);
        servoM.write(140);
        delay(800);
      }
      if(next1 == LOW){
        if(turn ==0){
        if(indicator == 1 || indicator == 2){
          indicator=0;
        }
      }
      }
     }
    }
if(turn == 1){//same thing as player 1
  if(ballcaunter != 0){
      digitalWrite(player2,HIGH);
      digitalWrite(player1,LOW);
      if(play2 == LOW){
        ballcaunter = ballcaunter-1;
        indicator = indicator-1;
        servoM.write(0);
        delay(800);
        servoM.write(140);
        delay(800);
      }
      if(next2 == LOW){
        if(turn ==1){
        if(indicator == 1 || indicator == 2){
          indicator=0;
        }
       }
      }
     }
    }
   }
}
}
