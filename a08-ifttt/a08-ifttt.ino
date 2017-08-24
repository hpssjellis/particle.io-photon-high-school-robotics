// a08-ifttt.ino
// By Jeremy Ellis
// MIT license

// 3v3 to a push button and then to D2  To send to IFTTT
// 3v3 to a push button and then to D4  This is the reset



bool myDoPublish2  = false;
bool myDoSubscribe = false;

void setup(){
    
    pinMode(D7, OUTPUT);
    pinMode(D2, INPUT_PULLDOWN);  // push button send to IFTTT
    pinMode(D4, INPUT_PULLDOWN);  // Push button to reset
    //  INPUT_PULLDOWN resets D0 to LOW if no power applied to it
    
    Particle.subscribe("my-lamp-on5555", myD7Function);   // public
    // Particle.subscribe("my-lamp-on5555", myD7Function, MY_DEVICES);    // for Private
    // change the number for uniqueness. Change 5555
}

void loop(){
     
    delay(10);

    if (myDoPublish2 == true){
        if (digitalRead(D2) == 1 ){   //if D2 on then send to IFTTT
           Particle.publish("my-lamp-on5555", "SECRET-STUFF", 60, PUBLIC); // public publish
           // Particle.publish("my-lamp-on5555", "SECRET-STUFF", 60, PRIVATE);  // private publish
           myDoPublish2 = false;      // stop from doing it again
        }   
    }
    
    if (digitalRead(D4) == 1 ){  // reset everything
        myDoPublish2   = true;
        myDoSubscribe  = true;
        digitalWrite(D7, 1);    // D7 quick flash to show everything has been reset
        delay(50);        
        digitalWrite(D7, 0);    // D7 off
        delay(50);        
        digitalWrite(D7, 1);
        delay(50);
        digitalWrite(D7, 0);
        delay(1000);
    }
  
}


void myD7Function(const char *event, const char *data){    //Incoming from IFTTT
    if (myDoSubscribe == true){   
        if (String(data) == "SECRET-STUFF"){   // an attempt at security
          digitalWrite(D7, 1);    // D7 LED on to prove it works 
          delay(2000);            // 2 second wait
          digitalWrite(D7, 0);
          myDoSubscribe = false;  // stop it from doing it again
          
        }
     }
}


