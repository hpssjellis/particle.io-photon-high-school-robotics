// dual motor driver
// By Jeremy Ellis
// MIT license

// You are suppossed to get it working using the web-app
// Draw your circuit diagram first
// This program will just tell you if  the connections are working
// See https://www.pololu.com/product/2135 for assistance

void setup() {
    pinMode(A4, OUTPUT);   // PWM 0 to 255
    pinMode(D4, OUTPUT);   // digital 0 to 1
    pinMode(D7, OUTPUT);

}

void loop() {
    
    digitalWrite(D7, 1);    // D7 on
    digitalWrite(D4, 1);    // set one direction
    analogWrite(A4, 50);   // go medium
    delay(3000);
    
    analogWrite(A4, 0);     // stop
    delay(3000); 
   
    digitalWrite(D4, 0);    // set the other direction
    analogWrite(A4, 50);   // go medium   
    delay(1000);    
    
    analogWrite(A4, 255);   // go full speed
    delay(1000);
    
    analogWrite(A4, 0);     // stop
    
    digitalWrite(D7, 0);    // D7 off
    delay(9000);            // wait 9 seconds
        
}
