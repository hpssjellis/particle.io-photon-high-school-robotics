// Voltage Divider
// By Jeremy Ellis

// GND to resistor (try different resistors i used a 5 k ohm, larger resistor larger range of values)
// resistor to both A0 and a 2 prong sensor (such as a photoresistor)
// other side of 2 prong sensor to 3V3

void setup() {

}

void loop() {

  Particle.publish("Analog Read A0 = ", String(analogRead(A0)), 60, PRIVATE);  // shows A0
  delay(6000); // wait about 6 seconds

}

