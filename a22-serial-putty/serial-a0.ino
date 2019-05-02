// Use putty serial mode 
// To find which come port type on a windows command line
// mode




void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.println("A0:"+String(analogRead(A0)));
	delay(100);
}
