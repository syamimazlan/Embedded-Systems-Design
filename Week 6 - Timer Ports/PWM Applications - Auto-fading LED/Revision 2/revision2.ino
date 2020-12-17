int led = 9;
int brightness = 0;

void setup() {
  
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  for (int i = 0; i < 360; i++){
    float angle = radians(i);
    brightness = (255/2) + (255/2) * sin(angle);
    analogWrite(led,brightness);
    Serial.println(brightness);
    delay(15);
    }

}
