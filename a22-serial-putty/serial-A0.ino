// Use putty serial mode 
// gete putty here   https://www.putty.org/
// To find which COM port use the device manager
// If no access to the device manager type on a windows command line   CMD or powershell
// mode




void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.println("A0:"+String(analogRead(A0)));
	delay(100);
}
