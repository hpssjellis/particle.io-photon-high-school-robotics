// Easiest Analog Console test program
// By Jeremy Ellis

// Works even without anything connected to A0



void setup() {

}



void loop() {

  Particle.publish("Analog Read A0 = ", String(analogRead(A0)), 60, PRIVATE);  // shows A0
  delay(6000); // wait about 6 seconds

}
