// big motor driver check
// By Jeremy Ellis
// MIT license

// You are suppossed to get it working using the web-app
// Draw your circuit diagram first
// This program will just tell you if  the connections are working
// See https://www.pololu.com/product/1451 for assistance

void setup() {
    pinMode(A5, OUTPUT);   // PWM 0 to 255
    pinMode(D5, OUTPUT);   // digital 0 to 1
    pinMode(D6, OUTPUT);   // digital 0 to 1
    
    pinMode(D7, OUTPUT);

}

void loop() {
    
    digitalWrite(D7, 1);    // D7 on
    
    digitalWrite(D5, 1);    // set one direction
    digitalWrite(D6, 0);    // set one direction 
    
    analogWrite(A5, 50);   // go medium
    delay(3000);
    
    analogWrite(A5, 0);     // stop
    delay(3000); 
   

    digitalWrite(D5, 0);    // set other direction
    digitalWrite(D6, 1);    // set one direction
    
    analogWrite(A5, 50);   // go medium   
    delay(1000);    
    
    analogWrite(A5, 255);   // go full speed
    delay(1000);
    
    analogWrite(A5, 0);     // stop
    digitalWrite(D7, 0);    // D7 off
    delay(9000);            // wait 9 seconds
        
}
