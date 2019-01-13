#include "Particle.h"
// Easiest RSSI test program
// By Jeremy Ellis


#include "ot_api.h"
extern "C" {
//	int8_t otPlatRadioGetRssi(otInstance *aInstance);
//  uint16_t get() { return otLinkGetPanId(DeviceInstance); }
  //  uint16_t otLinkGetPanId(_In_ otInstance *aInstance)
    uint16_t otLinkGetPanId(otInstance *aInstance);
};


void setup() {
  // int8_t rssi = otPlatRadioGetRssi(0);
  
   uint16_t myPanID = otLinkGetPanId(0);
  
   Particle.publish("----------------","-------------", 60, PRIVATE);    // just to show a space between samples
   Particle.publish("Particle Thread ","Connection Information", 60, PRIVATE);    // just to show a space between samples
 
   Particle.publish("Argon Pan ID: ", String(myPanID), 60, PRIVATE);  //shows printing an integer variable
   Particle.publish("----------------","-------------", 60, PRIVATE);    // just to show a space between samples
   Particle.publish("Thats all ","this program does!", 60, PRIVATE);    // just to show a space between samples
 
}

void loop() {
 


}
