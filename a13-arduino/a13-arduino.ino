// a13-arduino
// By Jeremy Ellis
// MIT License

// 3V3 to slider switch to D6
// Switch off at D6 you get a Wifi out of the box Photon
// Switch on  at D6 you get an Arduino!
// The main flashing LED is really interesting 

// These are fancy feactures so be carefull
SYSTEM_THREAD(ENABLED);
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
    
    if (digitalRead(D6) == 0){   
        Particle.connect();      // Cool I am a Photon
    } else {
        Particle.disconnect();  // Now I am an Arduino
    }
        
}



// Learn how to load SAFE MODE when things mess up
// 1. On bootup hold both SETUP and RESET buttons
// 2. Release RESET immediately 
// 3. When LED fashing purple relese SETUP button

