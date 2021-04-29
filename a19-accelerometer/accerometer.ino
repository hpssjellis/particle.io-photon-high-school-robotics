//T4A03-Accelerometer-optional-fred 

 

//Go to the library and enter adxl then find and include adxl362 into this file. 

//that will insert a line similar to  

 
 

// This #include statement was automatically added by the Particle IDE. 

//#include <adxl362.h> 

 
 
 
 

/* 

ADXL362_SimpleRead.ino -  Simple XYZ axis reading example 

for Analog Devices ADXL362 - Micropower 3-axis accelerometer 

go to http://www.analog.com/ADXL362 for datasheet 

License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free  

to use and abuse this code however you'd like. If you find it useful 

please attribute, and SHARE-ALIKE! 

Created June 2012 

by Anne Mahaffey - hosted on http://annem.github.com/ADXL362 

Modified May 2013 

by Jonathan Ruiz de Garibay 

Connect SCLK, MISO, MOSI, and CSB of ADXL362 to 

SCLK, MISO, MOSI, and DP 10 of Arduino  

(check http://arduino.cc/en/Reference/SPI for details) 

Converted for Spark Core/Spark Internet Button by Gregory Fenton 

http://labby.co.uk 

 
 

Modified by Jeremy Ellis March 01, 2017 

*/  

 
 
 
 

// Connect the ADXL362 breakout: 

// VIN: 3V3 

// GND: GND 

// SCL: A3 (SCK) 

// SDA: A5 (MOSI) 

// SDO: A4 (MISO) 

// CS: A2 (SS) 

// INT1: no connection 

// INT1: no connection 

 
 

//#include "adxl362/adxl362.h" 

 
 

ADXL362 xl; 

 
 

int16_t temp; 

int16_t XValue, YValue, ZValue, Temperature; 

int16_t XValueT, YValueT, ZValueT ; 

float XValueF, YValueF, ZValueF, TemperatureF; 

 
 
 

void setup(){ 

  

 xl.begin(SS);                   // Setup SPI protocol, issue device soft reset 

 xl.beginMeasure();              // Switch ADXL362 to measure mode   

} 

 
 

void loop(){ 

    

 // read all three axis in burst to ensure all measurements correspond to same sample time 

 xl.readXYZTData(XValue, YValue, ZValue, Temperature);   

 
 

 // Convert to m/^s  

 
 

 XValueF = XValue/100.1; 

 YValueF = YValue/100.1; 

 ZValueF = ZValue/100.1; 

   

  

 Temperature = Temperature / 14.5;  

 Particle.publish("Temp="+String(Temperature, DEC)+" °C", String("x=" + String(XValueF, 3)+", y=" + String(YValueF, 3)+", z=" + String(ZValueF, 3)), 60, PRIVATE);   

 delay(1000);               

} 
