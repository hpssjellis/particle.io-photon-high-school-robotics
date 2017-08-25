// a09-servo.ino
// By Jeremy Ellis
// MIT License


// servo red to 6V battery positive
// servo ground (brown or black) to 6V battery negative
// servo ground to Photon GND
// servo controller (orange or the other color) to Photon PWM pin A4   

// Note PWM pins are either: 
// D0, D1, A4, A5, WKP, RX, TX 
// D0, D1, D2, D3, WKP, RX, TX

Servo myServo;

void setup() {
    myServo.attach(A4);
    pinMode(D7, OUTPUT);

}

void loop() {
    digitalWrite(D7, 1);       // D7 on    
    
    myServo.write(0);          // servo at 0 degrees minimum
    delay(2000);
    
    myServo.write(180);        // servo at 180 degrees Maximum
    delay(2000);

    myServo.write(90);         // servo at 90 degrees
    delay(2000);   
    
    
    for (int myLoop = 0; myLoop <= 180; myLoop++){
        myServo.write(myLoop);
        delay(20);
    }


    digitalWrite(D7, 0);     // D7 off
    
    
    
    delay(5000);            // 5 second delay

}
