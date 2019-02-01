 

 

//T4A01-RangeFinder-Name.ino 

  

// EXAMPLE 

//using Ultrasonic Range Finder from Robotshop 

//http://www.robotshop.com/ca/en/hc-sr04-ultrasonic-range-finder.html 

  

unsigned long duration; 

  

void setup() 

{ 

  

    pinMode(D7, OUTPUT);   // LED on D7 

    pinMode(D1, OUTPUT);   // Other LED connected from D1 through resistor to ground 

     

                           // ultrasonic range finder Robotshop RB-lte-54 

                            

                           // GND pin goes to ground 

    pinMode(D6, INPUT);    // echo 

    pinMode(D2, OUTPUT);   // Trig 

                           // VCC pin goes to VIN on the photon 

                                       

} 

  

void loop(){ 

     

        delay(10);                      // even cicuits need a break 

        digitalWrite(D2, HIGH);         // activate trigger 

        delayMicroseconds(10); 

        digitalWrite(D2, LOW);          // de-activate trigger 

  

        duration = pulseIn(D6, HIGH);   // how long until a reply? 

                                        // a blocking call so may wait a few seconds 

                                         

        if (duration > 2000    ){        // raw data from 200 to 16000                                          

                                        // where  2000 raw = ~35cm,  4000 raw = ~80cm                                    

            digitalWrite(D7, HIGH);     // D7 Blue LED on if far 

            digitalWrite(D1, LOW);      // Other LED off 

        } else { 

            digitalWrite(D7, LOW);      // D7 Blue LED off 

            digitalWrite(D1, HIGH);     // Other LED on if Close 

  

        }  

}
