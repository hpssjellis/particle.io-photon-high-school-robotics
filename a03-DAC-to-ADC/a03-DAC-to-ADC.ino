// DAC to ADC
// By Jeremy Ellis

// Connect A6 (DAC) to A0
// Connect A6 (DAC) to D6


int myRandomNumber = 0;

void setup() {
      pinMode(DAC, OUTPUT);
      pinMode(D6, INPUT);
      // You don't have to declare A0 for Analog read!

}

void loop() {
  myRandomNumber  = rand() % 4094;
  analogWrite(DAC, myRandomNumber );
 
  Particle.publish("DAC (A6) sending", String( myRandomNumber), 60, PRIVATE);  // shows A6
  delay(1000); // wait about 1 seconds
  Particle.publish("Analog Read A0 = ", String(analogRead(A0)), 60, PRIVATE);  // shows A0
  delay(1000); // wait about 1 seconds
  Particle.publish("Digital Read D6 = ", String(digitalRead(D6)), 60, PRIVATE);  // shows D6
  delay(1000); // wait about 1 seconds
  Particle.publish("---------------","------------------", 60, PRIVATE);  // shows spaces
  delay(6000); // wait about 6 seconds

}
