
int myCount = 0;
bool myButtonReady = true;


void setup() {
    pinMode(D7, OUTPUT);
    pinMode(D0, INPUT_PULLDOWN);

}

void loop() {
    myCount +=1;
    
    if (myButtonReady && digitalRead(A0) == 1){
        myCount = 0;
        digitalWrite(D7, 1);
        myButtonReady = false;
        
    }
    
    if (myCount >= 10000){
        myButtonReady = true; 
        digitalWrite(D7, 0);
    }
    delay(1);

}
