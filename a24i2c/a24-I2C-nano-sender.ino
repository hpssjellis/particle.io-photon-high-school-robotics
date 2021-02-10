uint8_t val = 0;

void setup() {
    Wire.begin();
    pinMode(LEDB,OUTPUT); // the blue LED
}

void loop() {
    delay(1000);
    digitalWrite(LEDB,HIGH);
    Wire.beginTransmission(8);
    Wire.write(&val,1);
    Wire.endTransmission();
    val++;
    delay(20);
    digitalWrite(LEDB,LOW);
}
