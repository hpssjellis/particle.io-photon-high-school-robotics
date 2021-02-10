uint8_t data[8];
int idx;

void receiveEvent(int numOfBytes) {
    idx = 0;
    while (Wire.available()) { 
        data[idx++] = (uint8_t)Wire.read();       
  } 
}


void setup() {
    Serial.begin(9600);
    Wire.begin(8);
    Wire.onReceive(receiveEvent);
    pinMode(D7,OUTPUT);

}

void loop() {
    if (idx != 0) {
        digitalWrite(D7,HIGH);
        Serial.print("RX (");
        Serial.print(idx);
        Serial.print("): ");
        for(int i=0;i<idx;i++) {
            Serial.println(data[i],HEX);  
        }
        idx = 0;
        digitalWrite(D7,LOW);
    }

}
