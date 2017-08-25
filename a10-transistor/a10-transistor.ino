// a10-transitor
// By Jeremy Ellis
// MIT License


// Transistors can protect the Photon from hgiher voltages and currents 
//while still allowing the Photon to control the Higher Power circuit.

// In a PNP Transistor he large Voltage and Current circuit connects it's Ground to the to Emitter (P)
// In a PNP transistor the proton Ground (GND) goes to the BASE (N)
// And both circuits connect their Positives (Pins on the Photon) to the Collector (P)


void setup() {
   pinMode(A4, OUTPUT);
   pinMode(D7, OUTPUT);
   delay(1000);
}

void loop() {
    analogWrite(A4,100);
    digitalWrite(D7,1);
    delay(2000);
    analogWrite(A4,0);
    digitalWrite(D7,0);
    delay(1000);
    
    
    analogWrite(A4,200);  // PWM Max  = 255
    digitalWrite(D7,1);
    delay(2000);
    analogWrite(A4,0);
    digitalWrite(D7,0);
    delay(1000);

}
