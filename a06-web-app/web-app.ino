// web-app.ino


// For web control of the Particle.io Photon or
// The raspberry PI
// MIT license


// By Jeremy Ellis
// Github site at     https://github.com/hpssjellis/particle-photon-raspberry-pi-iot
//Github Pages webpage at     https://hpssjellis.github.io/particle-photon-raspberry-pi-iot/
// Twitter: @rocksetta
// Website: http://www.rocksetta.com




//PUT YOUR VARIABLES HERE

bool ShowConsoleMessages = true;  // When your app is fine set this false.

bool myAutoControl = false;   // You may want this to be true so that the 
                              // Special Loop controls something at startup
bool myCommandGood = false;   // for sending an error message if no command was read.                          
                            
                            
                            
bool isPI = false;            // don't change auto detected at compile.
String myDevice = "Photon";   // don't change, default is the Photon


void setup(){
    
    if (PLATFORM_ID == 31){
        isPI = true; 
         myDevice = "Raspberry Pi";
         if ( ShowConsoleMessages  ){ 
             Particle.publish("Using", "Raspberry PI", 60, PRIVATE);   
         } // end if show console
        } else  {
            if ( ShowConsoleMessages  ){ 
               Particle.publish("Using", "Photon, Core or electron", 60, PRIVATE);   
            } // end if show console
        }
    
    Particle.function("my-main", myMain);  
    
    //PUT YOUR SETUP CODE HERE. Note: Only three more functions allowed!
    // test everything using the return int from a function!

    RGB.brightness(5);    // 1=very low light, 255 = max
    
    


}

void loop(){
    
    //PUT YOUR GENERIC LOOP CODE HERE
    
    if ( myAutoControl ){
    
     //PUT YOUR SPECIAL LOOP CODE HERE 
    if ( ShowConsoleMessages  ){ 
        Particle.publish("Special Loop", "Active", 60, PRIVATE);  
        delay(5000);
    } // end if show console   


    
    }

}

int myMain(String myCode) {
    myCommandGood = false;
    
    String myDevicePlus = myDevice + " " + myCode;   // add to the device name whatever was sent to particle for the console  
    
    myCode.toUpperCase();           // set argument to uppercase
    

    
    //digitalWrite(D7,HIGH);
    
    //myActivity -- pinNumber -- myOptional
    
    // Following is a bunch of code to sperate the above statment
    

   int myComma = myCode.indexOf(",");   // find the comma
   if (myComma == -1) {myComma = myCode.indexOf(")");} //if no comma use end brackets
   
   int myOpenBracket = myCode.indexOf("(");  // find first baracket
    
    String  myActivity = myCode.substring(0, myOpenBracket);     // grab characters until bracket
  //  String  myActivity = myCode.substring(0, myOpenBracket);     // grab characters until bracket
    
    String pinNumberString = myCode.substring(myOpenBracket+1, myComma);   // Grab the PIN Characters D7 etc
    
    String myOptional = myCode.substring(myComma + 1);   //grabs the numbers after the equal sign   
 
    myOptional = myOptional.replace(");", "");  // get rid of the ); at the end
    
   // for testing
   // Particle.publish(myActivity, String(pinNumberString + ", "+myOptional), 60, PRIVATE);  
    
    int pinNumber = pinNumberString.toInt();
    
    pinNumberString = pinNumberString.replace(" ", "");  // ditch spaces

        
    int mySetWrite = 0;       
     
      
    if(myOptional == "HIGH") {mySetWrite = 1;}
        else if(myOptional == "LOW") {mySetWrite = 0; }
            else if(myOptional == "ON") {mySetWrite = 1;}
                else if(myOptional == "OFF") {mySetWrite = 0; }
                   else {mySetWrite = myOptional.toInt();  }  // sets  write value
      
     
#if (PLATFORM_ID == 31) 
  // only compile following Raspberry PI stuff
  

    if (pinNumberString == "D0"){pinNumber = 4;}    
    if (pinNumberString == "D1"){pinNumber = 17;}    
    if (pinNumberString == "D2"){pinNumber = 27;}    
    if (pinNumberString == "D3"){pinNumber = 22;}    
    if (pinNumberString == "D4"){pinNumber = 5;}     
    if (pinNumberString == "D5"){pinNumber = 4;}     
    if (pinNumberString == "D6"){pinNumber = 13;}    // PWM   
    if (pinNumberString == "D7"){pinNumber = 19;}    // PWM   
    if (pinNumberString == "A0"){pinNumber = 18;}    // PWM   
    if (pinNumberString == "A1"){pinNumber = 23;}    
    if (pinNumberString == "A2"){pinNumber = 24;}    
    if (pinNumberString == "A3"){pinNumber = 25;}    
    if (pinNumberString == "A4"){pinNumber = 12;}    // PWM (Working)
    if (pinNumberString == "A5"){pinNumber = 16;}    // PWM (not working)   
    if (pinNumberString == "A6"){pinNumber = 20;}    
    if (pinNumberString == "A7"){pinNumber = 21;}    
    

#else 
  // only compile following Photon Stuff

    if (pinNumberString == "D0"){pinNumber = 0;}     // PWM
    if (pinNumberString == "D1"){pinNumber = 1;}     // PWM
    if (pinNumberString == "D2"){pinNumber = 2;}     // PWM if not A4
    if (pinNumberString == "D3"){pinNumber = 3;}     // PWM if not A5
    if (pinNumberString == "D4"){pinNumber = 4;}    
    if (pinNumberString == "D5"){pinNumber = 5;}     
    if (pinNumberString == "D6"){pinNumber = 6;}    
    if (pinNumberString == "D7"){pinNumber = 7;}    
    if (pinNumberString == "A0"){pinNumber = 10;}    
    if (pinNumberString == "A1"){pinNumber = 11;}   
    if (pinNumberString == "A2"){pinNumber = 12;}    
    if (pinNumberString == "A3"){pinNumber = 13;}    
    if (pinNumberString == "A4"){pinNumber = 14;}      // PWM if not D2
    if (pinNumberString == "A5"){pinNumber = 15;}      // PWM if Not D3
    if (pinNumberString == "A6"){pinNumber = 16;}   
    if (pinNumberString == "A7"){pinNumber = 17;}      // PWM
    if (pinNumberString == "RX"){pinNumber = 18;}      // PWM // PWM
    if (pinNumberString == "TX"){pinNumber = 19;}      // PWM
   // if (pinNumberString == "BT"){pinNumber = 20;}    // BTN pin is 20 ??    
   

#endif
     
    
    // PUT YOUR OWN IF STATEMENT HERE
    // USE CODE     mine(xx,5);
    if (myActivity == "MINE"){ 
        myCommandGood = true;  // this command processed          
          
          // Your special code here
          
     return mySetWrite;     
    }
    
    
   
     
    if (myActivity == "WHOAMI"){   // which microprocessor
        myCommandGood = true;  // this command processed
        if ( isPI ){ 
            mySetWrite = 31;   //raspberry PI
         if ( ShowConsoleMessages  ){ 
             Particle.publish("Using", "Raspberry PI", 60, PRIVATE);   
         } // end if show console            
        } else {
            mySetWrite = 6;  // Photon 
            if ( ShowConsoleMessages  ){ 
               Particle.publish("Using", "Photon, Core or electron", 60, PRIVATE);   
            } // end if show console            
          }

     return mySetWrite;     
    }     
    
  
    
    if (myActivity == "LOOP"){   //xx:loop:1  sets loop to be on
        myCommandGood = true;  // this command processed
        if (mySetWrite == 0) {
            myAutoControl = false; 
            if ( ShowConsoleMessages  ){ 
               Particle.publish("Looping", "Auto loop turned off" , 60, PRIVATE); 
            } // end if show console    
        }  
        if (mySetWrite == 1) {
            myAutoControl = true;
            if ( ShowConsoleMessages  ){ 
               Particle.publish("Looping", "Auto loop turned on" , 60, PRIVATE); 
            } // end if show console    
        }  
          
        
        Particle.publish(myDevicePlus , String(myActivity + ", " + pinNumberString + " Pin = " + 
            String(pinNumber, DEC) + " returning = " + String(mySetWrite, DEC) ), 60, PRIVATE);  
          
     return mySetWrite;     
    }   
    
    
    
    
    
    
  
#if (PLATFORM_ID == 31) 
  // only compile following Raspberry PI stuff
   
        if (myActivity == "DIGITALREAD"){    //digital read
            myCommandGood = true;  // this command processed
            pinMode(pinNumber, INPUT_PULLDOWN);
            mySetWrite = digitalRead(pinNumber);
            if ( ShowConsoleMessages  ){ 
               Particle.publish(myDevicePlus , String(myActivity + ", " + pinNumberString + " Pin = " + 
                  String(pinNumber, DEC) + " returning = " + String(mySetWrite, DEC) ), 60, PRIVATE); 
             } // end if show console             
            
            return mySetWrite;  
        }
        
        
         if (myActivity == "DIGITALWRITE"){    //digital write   
            myCommandGood = true;  // this command processed
            pinMode(pinNumber, OUTPUT);
            digitalWrite(pinNumber, mySetWrite);
            if ( ShowConsoleMessages  ){ 
               Particle.publish(myDevicePlus , String(myActivity + ", " + pinNumberString + " Pin = " + 
                   String(pinNumber, DEC) + " returning = " + String(mySetWrite, DEC) ), 60, PRIVATE); 
            } // end if show console                  
            
            return mySetWrite;
        }   
        
        
        // PWM 0-255 on the PI only on certain pins 13, 16, 18, 19 
        
        if (myActivity == "ANALOGWRITE"){    //Analog Write
          myCommandGood = true;  // this command processed
          if (pinNumber == 13 || pinNumber == 16 || pinNumber == 18 || pinNumber == 19 ){
            pinMode(pinNumber, OUTPUT);
            analogWrite(pinNumber,  mySetWrite);
            if ( ShowConsoleMessages  ){ 
               Particle.publish(myDevicePlus , String(myActivity + ", " + pinNumberString + " Pin = " + 
                  String(pinNumber, DEC) + " returning = " + String(mySetWrite, DEC) ), 60, PRIVATE);  
            
            } // end if show console              

            return mySetWrite;
        }  else {
            
            
         if ( ShowConsoleMessages  ){ 
               Particle.publish("Error", "Wrong PI Pin number for AnalogWrite" , 60, PRIVATE); 
         } // end if show console     
           }         
      } // end if analogWrite
      
      
        if (myActivity == "ANALOGREAD"){    //NOT on PI
            myCommandGood = true;  // this command processed
            int myCounter = 0;
            
            // for capacitor method on Raspberry PI  
            //   3V3 --> Variable Resistor (parallel line to PinNumber) --> ~0.1 uf Capacitor --> 100 ohm resistor --> GND 
            pinMode(pinNumber, OUTPUT);
            digitalWrite(pinNumber, 0);  // set LOW to drain capacitor
            delayMicroseconds(10000);

            pinMode(pinNumber, INPUT);  // Pin set to read

   
            while (digitalRead(pinNumber) == 0){
               delayMicroseconds(1);
               myCounter += 1;
               if (myCounter > 10000){     // Loop always has an exit
                    Particle.publish("Analog Read Error on PI:", "Timed out more than 10,000 loops", 60, PRIVATE);
                    break;  // exit while loop if too long
                }
            } // end while loop
    
    
           // mess around with the resistor and capacitor to get your widest counter range
           // then counter range / 4095 to get your multiplier
           int myCounter2 = 4095-(myCounter * 6.31);   // *6.31 depending on your range of counter values my max was  4095 / 649 = 6.31
           if (myCounter2 <= 0){ myCounter2 = 0; }   // so no negative numbers

            mySetWrite = myCounter2;  
           
            Particle.publish(myDevicePlus , String(myActivity + ", " + pinNumberString + " Pin = " + 
                String(pinNumber, DEC) + " Capacitive return = " + String(mySetWrite, DEC) ), 60, PRIVATE); 
            

            return mySetWrite;  
        }
      
      
      

#else 
  // only compile following Photon Stuff
       if (pinNumber < 10){
           if (myActivity == "DIGITALREAD"){    //digital read
              myCommandGood = true;  // this command processed
              pinMode(pinNumber, INPUT_PULLDOWN);
              mySetWrite = digitalRead(pinNumber);
            if ( ShowConsoleMessages  ){ 
               Particle.publish(myDevicePlus , String(myActivity + ", " + pinNumberString + " Pin = " + 
                 String(pinNumber, DEC) + " returning = " + String(mySetWrite, DEC) ), 60, PRIVATE); 
              
            } // end if show console                

              return mySetWrite;  
        }
        
   
        
         if (myActivity == "DIGITALWRITE"){    //digital write   D3:writeHIGH  to fit the 5th letter miss the final colon
            myCommandGood = true;  // this command processed
            pinMode(pinNumber, OUTPUT);
            digitalWrite(pinNumber, mySetWrite);
           if ( ShowConsoleMessages  ){ 
              Particle.publish(myDevicePlus , String(myActivity + ", " + pinNumberString + " Pin = " + 
                 String(pinNumber, DEC) + " returning = " + String(mySetWrite, DEC) ), 60, PRIVATE); 
           } // end if show console               

            return mySetWrite;
        }         
       
       } else {  // only photon has analog read pin numbers over 10
       
        if (myActivity == "ANALOGREAD"){    //Analog read     values 0-4095   
            myCommandGood = true;  // this command processed
            mySetWrite = analogRead(pinNumber);  
           
            if ( ShowConsoleMessages  ){ 
               Particle.publish(myDevicePlus , String(myActivity + ", " + pinNumberString + " Pin = " + 
                   String(pinNumber, DEC) + " returning = " + String(mySetWrite, DEC) ), 60, PRIVATE); 

            } // end if show console                  

            return mySetWrite;  
        }
         
         
       // PWM 0-255 on Photon only on these pins:  D0, D1, (A4 or D2), (A5 or D3), WKP=A7, RX, TX
       if (myActivity == "ANALOGWRITE"){    //Analog Write 
          myCommandGood = true;  // this command processed
          if (pinNumber == 0 || pinNumber == 1 || pinNumber == 2 || pinNumber == 3    || pinNumber == 14  || pinNumber == 15  || pinNumber == 17   || pinNumber == 18  || pinNumber == 19   ){
       
            pinMode(pinNumber, OUTPUT);
            analogWrite(pinNumber,  mySetWrite);  
            if ( ShowConsoleMessages  ){ 
               Particle.publish(myDevicePlus , String(myActivity + ", " + pinNumberString + " Pin = " + 
                    String(pinNumber, DEC) + " returning = " + String(mySetWrite, DEC) ), 60, PRIVATE); 
            } // end if show console        
            
            return mySetWrite;
         }
         if ( ShowConsoleMessages  ){ 
               Particle.publish("Error", "Wrong Photon Pin number for AnalogWrite" , 60, PRIVATE); 
         } // end if show console      
         
         
       }    
         
           
       }
       
#endif  
    
   
   
   
   
   if ( myCommandGood ){   
          // a command was done so all is good.
       } else {
           // No command was done so must be an error
          Particle.publish( myDevicePlus    , "Error: This command not understood!", 60, PRIVATE);  
          pinMode(D7, OUTPUT);
          digitalWrite(D7, HIGH);
          delay(5);                 
          digitalWrite(D7, LOW);
       }
   
   
    
 
    
}
