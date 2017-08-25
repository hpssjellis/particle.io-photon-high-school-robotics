// a13-arduino
// By Jeremy Ellis



// 3V3 to slider switch to D6
// Power off at D6 you get a Wifi out of the box Photon
// Power on  at D6 you get a Regular Arduino

SYSTEM_MODE(SEMI_AUTOMATIC);


void setup() {
    pinMode(D6, INPUT_PULLDOWN);  // set pin D6 as an input at zero
    pinMode(D7, OUTPUT);          // our trusty D7 LED
    
    if (digitalRead(D6) == 0){
        Particle.connect();
    }
}

void loop() {
    
    digitalWrite(D7, 1);          // slow flashing
    delay(1000);
    digitalWrite(D7, 0);
    delay(1000);    
    
    if (digitalRead(D6) == 0){   // learn how to use an else statment
        Particle.connect();      // Cool I am a Photon
    }
    
    if (digitalRead(D6) == 1){
        Particle.disconnect();  // Now I am an Arduino
    }
        
}



// Learn how to load safe mode when things mess up
// 1. on bootup hold both setup and reset
// 2. release reset immediately then release setup when purple flashing
// Now you can re-flash the photon if stuck with a photon not accessing the cloud


