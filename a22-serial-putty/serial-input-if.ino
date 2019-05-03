// Use putty serial mode 
// gete putty here   https://www.putty.org/
// To find which COM port use the device manager
// If no access to the device manager type on a windows command line   CMD or powershell
// mode





int incomingByte = 0; // for incoming serial data

void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    Serial.print("Press any key, then try the letter A");
}

void loop() {
  // send data only when you receive data:
    if (Serial.available() > 0) {
    // read the incoming byte:
        incomingByte = Serial.read();

        Serial.print("I received: ");
        Serial.println(incomingByte, DEC);
        
        if ((char)incomingByte == 'A'){   // #65
            Serial.println("Cool, you entered an 'A' ");
 
        }        
        if ((char)incomingByte == 'a'){   // #97
            Serial.println("Sweet, you entered an 'a' ");
 
        }
        
    }
  
}
