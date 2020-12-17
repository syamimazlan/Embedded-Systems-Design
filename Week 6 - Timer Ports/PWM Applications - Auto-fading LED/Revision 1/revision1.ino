int led = 9;
int brightness = 0;

void setup() {
    
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {

  for (int t = 0; t < 5; t++){
    float angle = radians(t);
    brightness = (255/2) + (255/2) * sin(angle);
    analogWrite(led,brightness);
    Serial.println(brightness);
    delay(30);
  }

}
