char *admux = (char*) 0x7C;
volatile unsigned char *adcsra = (unsigned char*) 0x7A;
volatile unsigned char *adch = (unsigned char*) 0x79;
volatile unsigned char *adcl = (unsigned char*) 0x78;


void setup() {
  *admux = 0b01000011;
  *adcsra = 0b11000111;
  Serial.begin(9600);

  while(1)
  {
    *adcsra |= 0b01000000;
    while(((*adcsra) & 0b01000000))
    {
      //do nothing
    }
  }
  
  int lowbyte = (*adcl);
  int highbyte = (*adch);
  int value = (highbyte<<8) | lowbyte;
  Serial.println(value);
}

void loop() {
  // put your main code here, to run repeatedly:

}
