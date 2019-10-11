/*
* Particle Mesh Devices Connection with Openthread
* By Jeremy Ellis
* Twitter @rocksetta

* Warning, will need Argon binaries to get Particle back to normal
* v1.4.1-rc.1 found at the below link
* https://github.com/particle-iot/device-os/releases/download/v1.4.1-rc.1/particle_device-os@1.4.1-rc.1.zip
* Latest OS Device information found at the bottom of this blog
* https://community.particle.io/t/particle-device-os-updates-thread/14378/97
* files are in the \1.4.1-rc.1\argon\release\

* particle flash --usb argon-system-part1@1.4.1-rc.1.bin
* reminder if you have to rer-install the boatloader you must flash in serial mode first then dfu for the system file
* particle flash --serial argon-bootloader@1.4.1-rc.1.bin

* To run the below code you must install po-util with the following
* Might want to pre install git, node, npm and particle-cli
* sudo apt install curl
* bash <(curl -sL get.po-util.com)
* To check po-util version type
* po

* To start a po-util project
* po init argon myArgonProject
* cd myArgonProject

* po config mesh-develop 
* po setup-mesh

* MODULAR=n po argon build

* particle login
* particle list
* particle flash --usb myArgonProject-argon.bin

* Good idea between builds to clean
* po argon clean

*/

#include "Particle.h"

// uncomment the next line to improve stability
SYSTEM_THREAD(ENABLED);  // causes a small delay for Mesh.publish()

SYSTEM_MODE(SEMI_AUTOMATIC);  // so wifi not needed

//Next line allows you to use the Particle Featherwing plug and play
//STARTUP(System.enableFeature(FEATURE_ETHERNET_DETECTION)); 

#define OT_MASTER_KEY_SIZE 16

#include <assert.h>
#include "ot_api.h"
#include "openthread/dataset.h"

// Following line might be needed
//#include <openthread/thread_ftd.h>

#include <string.h>


extern "C" {

   int8_t               otLinkGetChannel(otInstance *aInstance);
   uint16_t             otLinkGetPanId(otInstance *aInstance);         
   otMasterKey         *otThreadGetMasterKey(otInstance *aInstance);
   char                *otThreadGetNetworkName(otInstance *aInstance);
   otOperationalDataset aDataset;

   void myHandler(const char *event, const char *data); 

};


/////////////////////////// important globals here ///////////////////////////////

int  myCode                     = 5;  // number of flashes
bool myXenonAntennaAttached     = false;  
bool myArgonBothAntennaAttached = false;  
bool myPublishToConsole         = true;        // set true for Argon for debugging

int myCount = 0;
bool myButtonReady = true;

/////////////////////////////// end globals ////////////////////////////


void setup() {   // runs once

   pinMode(D0, INPUT_PULLDOWN);   // set pin D0 as an input at zero
   pinMode(D6, INPUT_PULLDOWN);   // set pin D6 as an input at zero
   pinMode(D7, OUTPUT);           // our trusty D7 LED
    
   if (digitalRead(D6) == 0){   // If D6 HIGH connect wifi
        Particle.connect();
   }

   Mesh.subscribe("mySendToAll", myHandler);
	
   if (myXenonAntennaAttached){
       #if (PLATFORM_ID == PLATFORM_XENON) 
	   digitalWrite(ANTSW1, 0);
	   digitalWrite(ANTSW2, 1);
       #endif  
   }
	
   if (myArgonBothAntennaAttached){
       #if (PLATFORM_ID == PLATFORM_ARGON) 
	   digitalWrite(ANTSW1, 1);
	   digitalWrite(ANTSW2, 0);
       #endif  
   }

   // Set Mesh Dataset	  
   memset(&aDataset, 0, sizeof(otOperationalDataset));

   /* Set Network Name to OTCodelab */
   static char aNetworkName[] = "OTCodelab";
   size_t length = strlen(aNetworkName);
   assert(length <= OT_NETWORK_NAME_MAX_SIZE);
   memcpy(aDataset.mNetworkName.m8, aNetworkName, length);
   aDataset.mComponents.mIsNetworkNamePresent = true;

   /*
     * Fields that can be configured in otOperationDataset to override defaults:
     *     Network Name, Mesh Local Prefix, Extended PAN ID, PAN ID, Delay Timer,
     *     Channel, Channel Mask Page 0, Network Master Key, PSKc, Security Policy
   */
   aDataset.mActiveTimestamp                      = 1;
   aDataset.mComponents.mIsActiveTimestampPresent = true;

   /* Set Channel to 15 */
   aDataset.mChannel                      = 15;
   aDataset.mComponents.mIsChannelPresent = true;

   /* Set Pan ID to 2222 */
   aDataset.mPanId                      = (otPanId)0x2222;
   aDataset.mComponents.mIsPanIdPresent = true;

   /* Set Extended Pan ID to C0DE1AB5C0DE1AB5 */
   uint8_t extPanId[OT_EXT_PAN_ID_SIZE] = {0xC0, 0xDE, 0x1A, 0xB5, 0xC0, 0xDE, 0x1A, 0xB5};
   memcpy(aDataset.mExtendedPanId.m8, extPanId, sizeof(aDataset.mExtendedPanId));
   aDataset.mComponents.mIsExtendedPanIdPresent = true;

   /* Set master key to 1234C0DE1AB51234C0DE1AB51234C0DE */
   uint8_t key[OT_MASTER_KEY_SIZE] = {0x12, 0x34, 0xC0, 0xDE, 0x1A, 0xB5, 0x12, 0x34, 0xC0, 0xDE, 0x1A, 0xB5};
   memcpy(aDataset.mMasterKey.m8, key, sizeof(aDataset.mMasterKey));
   aDataset.mComponents.mIsMasterKeyPresent = true;

   // Must have an otInstance
   otInstance*  ot = ot_get_instance();
   otDatasetSetActive(ot, &aDataset);

   char *myNetworkName = otThreadGetNetworkName(ot);
   char myNetworkNameBuff[255];
   snprintf(myNetworkNameBuff, sizeof(myNetworkNameBuff), "%s", myNetworkName); // network name as a string
	
   Particle.publish("Successful","Startup", 60, PRIVATE);	
   delay(1000);
   Particle.publish("My Network Name: ", String(myNetworkNameBuff), 60, PRIVATE); 
   delay(1000);
	
   // Mesh.localIP().toString().c_str());
   Particle.publish("My local ip: ", String(Mesh.localIP()), 60, PRIVATE); //shows local Mesh IPv4 address
   delay(1000);

}


void loop() {   // runs continuously

   myCount +=1;
    
   if (digitalRead(D6) == 0){  // If D6 is HIGH
      Particle.connect();      // I am a Photon (has Wifi)
   } else {
      Particle.disconnect();  // I am an Arduino (no Wifi)
   }

   if (myButtonReady && digitalRead(D0) == 1){
      myCount = 0;
      digitalWrite(D7, 1);
      myButtonReady = false;
      
      Particle.publish("Sending Mesh Multicast", "...", 60, PRIVATE); 
      Mesh.publish("mySendToAll", String(myCode));  
      delay(1000);
      digitalWrite(D7, 0);
   }
    
   if (myCount >= 1000){
      if (! myButtonReady){
         Particle.publish("Device Reset", "...", 60, PRIVATE); 
      }
      myButtonReady = true; 

   }
   delay(5);  // becomes about 5 seconds with the 1000 count 

}


// Event listener for "mySendToAll" event from Mesh Devices
void myHandler(const char *event, const char *data) {

   String parse = data;  //Cast char*data to String class
   int myNumber = parse.toInt();
   if (myPublishToConsole){  // mainly for Argon gateway unless debugging
      Particle.publish("Flashing D7 this many times:", parse, 60, PRIVATE); 
   }
   for (int myLoop = 0; myLoop < myNumber; myLoop++){
      digitalWrite(D7, HIGH);
      delay(200);   // very quick flash
      digitalWrite(D7, LOW);
      delay(200);   
   }
   delay(500); // to tell if 2 devices signal at similar times
}


