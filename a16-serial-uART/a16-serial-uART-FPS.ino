// This #include statement was automatically added by the Particle IDE.
#include <Fingerprint_FPS_GT511C3.h>

/* 
	FPS_Enroll.ino - Library example for controlling the GT-511C3 Finger Print Scanner (FPS)
	Created by Josh Hawley, July 23rd 2013
	Licensed for non-commercial use, must include this license message
	basically, Feel free to hack away at it, but just give me credit for my work =)
	TLDR; Wil Wheaton's Law

	This sketch will attempt to identify a previously enrolled fingerprint.
	
	Adapted for Particle Libraries by Michael Frontz, April 2017
*/

//#include "FPS_GT511C3.h"
	

	
/* Hardware setup - FPS connected to Photon using JST SH Jumper 4 Wire Assembly (https://www.sparkfun.com/products/10359)
	If the JST SH jumper wires were numbered left to right as 1-4 (with black wire being Wire 4), the connections would be:	
	FPS Wire 1 (White) = VCC --> Photon 3.3V
	FPS Wire 2 (White) = GND --> Photon GND
	FPS Wire 3 (White) = RX --> Photon TX
	FPS Wire 4 (Black) = TX --> Photon RX
	
	Built-in green LED on FPS will light up if wiring is correct
*/

FPS_GT511C3 fps;

void setup()
{
	//Serial.begin(9600);
	//delay(100);
	fps.Open();
	fps.SetLED(true);
}

void loop()
{

	// Identify fingerprint test
	if (fps.IsPressFinger())
	{
		fps.CaptureFinger(false);
		int id = fps.Identify1_N();
		if (id <200)
		{
			//Serial.print("Verified ID:");
			//Serial.println(id);
			Particle.publish("Verified ID:", String(id), 60, PRIVATE);
		}
		else
		{
			//Serial.println("Finger not found");
			
			Particle.publish("Finger not found", "-----", 60, PRIVATE);
		}
	}
	else
	{
		//Serial.println("Please press finger");
		
		Particle.publish("Please press finger", "-----", 60, PRIVATE);
	}
	delay(2000);
}
