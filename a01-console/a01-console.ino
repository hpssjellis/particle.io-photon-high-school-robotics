// Easiest Analog Console test program
// By Jeremy Ellis

// This program works even without anything connected to A0

// If you want to connect something to A0
// lots of sensors have these labels 

// GND     Ground
// VCC     Normal  Vin check the board may work with 3V3
// NC      Not Connected 
// Sig     Connect to A0 

void setup() {

}



void loop() {

  Particle.publish("Analog Read A0 = ", String(analogRead(A0)), 60, PRIVATE);  // shows A0
  delay(6000); // wait about 6 seconds

}


// make sure you open the console.
