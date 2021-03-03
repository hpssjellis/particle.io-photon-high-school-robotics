// a09-servo.ino
// By Jeremy Ellis
// MIT License


// MUST HAVE A 6 VOLT EXTERNAL BATTERY
// Servos run from 0 to 180 degrees

// servo red to 6V battery positive
// servo ground (brown or black) to 6V battery negative
// servo ground to Photon GND
// servo controller (orange or the other color) to Photon PWM pin A4   

// Note PWM pins are either: 
// D0, D1, A4, A5, WKP, RX, TX 
// D0, D1, D2, D3, WKP, RX, TX

Servo myServo4;

void setup() {
   // myServo.attach(A4);
    pinMode(D7, OUTPUT);

}

void loop() {
    
    myServo4.attach(A4);
    
    
    digitalWrite(D7, 1);       // D7 on    
    
    myServo4.write(10);          // servo at 10 degrees minimum
    delay(2000);                 // Minimum is 0 sometimes weird
    
    myServo4.write(170);        // servo at 170 degrees Maximum
    delay(2000);                // maximum 180 sometimes weird

    myServo4.write(90);         // servo at 90 degrees
    delay(2000);   
    
    
    for (int myLoop = 0; myLoop <= 180; myLoop++){
        myServo4.write(myLoop);
        delay(25);  // short delay 25 ms
    }


    digitalWrite(D7, 0);     // D7 off
    delay(5000);            // 5 second delay
    
    
    myServo4.detach();   // less weird stuff if you detach the servo

}




