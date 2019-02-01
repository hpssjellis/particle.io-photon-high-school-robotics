//T4A04-FSLP-Optional 

 

 

//X-antonio-force-pressure-strip 

 
 

/* 

  

*  Force sensor linear Potentiometer Pololu #2730 

* https://www.pololu.com/product/2730 

 
 

* looking at the strip the three pins are: 

* D1 

* A3 

* A4 

*  resistor attached D0 connected parallel with A4 

* 

* After uploading the sketch, the Arduino will control the LED 

* strip using position and pressure readings from the FSLP.  The 

* position reading will determine the number of LEDs that light 

* up, while the pressure reading will determine the color of the 

* LEDs. 

* 

* This sketch also reports the force and pressure readings over 

* serial so you can read them on your computer using a terminal 

* program such as the Serial Monitor in the Arduino IDE. 

* 

* Without connecting an LED strip, this sketch can still be used 

* to take readings from the FSLP and see them on your computer. 

*/ 

 
 
 

void setup() 

{ 

// Serial.begin(9600); 

//  delay(250); 

} 

 
 

void loop() 

{ 

 int pressure, position; 

  

  

 position = fslpGetPosition(); 

 
 

 pressure = fslpGetPressure(); 

 
 
 

 Particle.publish("Position = ", String(position), 60, PRIVATE);   

 
 

 Particle.publish("Pressure = ", String(pressure), 60, PRIVATE);   

 
 

 delay(4000); 

} 

 
 

// This function follows the steps described in the FSLP 

// integration guide to measure the position of a force on the 

// sensor.  The return value of this function is proportional to 

// the physical distance from drive line 2, and it is between 

// 0 and 1023.  This function does not give meaningful results 

// if fslpGetPressure is returning 0. 

int fslpGetPosition() 

{ 

 // Step 1 - Clear the charge on the sensor. 

 pinMode(A4, OUTPUT); 

 digitalWrite(A4, LOW); 

 
 

 pinMode(D1, OUTPUT); 

 digitalWrite(D1, LOW); 

 
 

 pinMode(A3, OUTPUT); 

 digitalWrite(A3, LOW); 

 
 

 pinMode(D0, OUTPUT); 

 digitalWrite(D0, LOW); 

 
 

 // Step 2 - Set up appropriate drive line voltages. 

 digitalWrite(D1, HIGH); 

 pinMode(D0, INPUT); 

 pinMode(A4, INPUT); 

 
 

 // Step 3 - Wait for the voltage to stabilize. 

 delayMicroseconds(10); 

 
 

 // Step 4 - Take the measurement. 

 
 

 return analogRead(A4); 

} 

 
 

// This function follows the steps described in the FSLP 

// integration guide to measure the pressure on the sensor. 

// The value returned is usually between 0 (no pressure) 

// and 500 (very high pressure), but could be as high as 

// 32736. 

int fslpGetPressure() 

{ 

 // Step 1 - Set up the appropriate drive line voltages. 

 pinMode(D1, OUTPUT); 

 digitalWrite(D1, HIGH); 

 
 

 pinMode(D0, OUTPUT); 

 digitalWrite(D0, LOW); 

 
 

 pinMode(A4, INPUT); 

 
 

 pinMode(A3, INPUT); 

 
 

 // Step 2 - Wait for the voltage to stabilize. 

 delayMicroseconds(10); 

 
 

 // Step 3 - Take two measurements. 

 
 

 int v1 = analogRead(A3); 

 
 

 int v2 = analogRead(A4); 

 
 

 // Step 4 - Calculate the pressure. 

 // Detailed information about this formula can be found in the 

 // FSLP Integration Guide. 

 if (v1 == v2) 

 { 

   // Avoid dividing by zero, and return maximum reading. 

   return 32 * 1023; 

 } 

 return 32 * v2 / (v1 - v2); 

}
