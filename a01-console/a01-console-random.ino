// Easiest Analog Console test program
// By Jeremy Ellis

// lots of sensors have these labels 
// GND     Ground
// VCC     Normal  Vin check the board may work with 3V3
// NC      Not Connected - might be labelled LED 
// Sig     Connect to A0 


int   x = 0;
float y = 0; 


void setup() {

}




void loop() {

  x += 1;
  y = rand() / 10000000.0;    //Note: decimal makes float division. If integer result would be an integer!
  
  Particle.publish("Integer x = ", "Count #" + String(x), 60, PRIVATE);  //shows printing an integer variable
  delay(1000); 
  Particle.publish("Random Decimal y = ", String(y, 3), 60, PRIVATE);  // show a float to 3 decimal places
  delay(1000); 
  Particle.publish("Analog Read A0 = ", String(analogRead(A0)), 60, PRIVATE);  // shows A0
  delay(1000); 
  Particle.publish("----------------","-------------", 60, PRIVATE);    // just to show a space between samples
  delay(6000); // wait about 6 seconds

}
