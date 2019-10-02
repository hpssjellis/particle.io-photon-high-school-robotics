
// Particle Mesh Devices Connection Information Testing
// By Jeremy Ellis



// Install po-util with the following
// sudo apt install curl
// bash <(curl -sL get.po-util.com)
// Might want to pre install git, node, npm and particle-cli
// To check po-util version type
// po

// Start a po-util project
// po init argon myArgonProject
// cd myArgonProject

// po config mesh-develop 
// po setup-mesh

// MODULAR=n po argon build

// particle login
// particle list
// particle flash --usb myArgonProject-argon.bin



#include "Particle.h"

#define OT_MASTER_KEY_SIZE 16

#include <assert.h>
#include "ot_api.h"
#include "openthread/dataset.h"

//#include <openthread/thread_ftd.h>


#include <string.h>


extern "C" {

int8_t    otLinkGetChannel(otInstance *aInstance);
uint16_t  otLinkGetPanId(otInstance *aInstance);         // type otPanId
otMasterKey *otThreadGetMasterKey(otInstance *aInstance);
char     *otThreadGetNetworkName(otInstance *aInstance);


        otOperationalDataset aDataset;

};

void loop() {



        memset(&aDataset, 0, sizeof(otOperationalDataset));



        /* Set Network Name to OTCodelab */
        static char          aNetworkName[] = "OTCodelab";
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


 otInstance*  ot = ot_get_instance();


   otDatasetSetActive(ot, &aDataset);




        Particle.publish("Cool stuff happening","every 60 seconds", 60, PRIVATE); // just to show a space between samples

        delay(60000); // wait 60 seconds before re-print

}


/*



        otInstance*  ot = ot_get_instance();

        int8_t myChannel = otLinkGetChannel(ot);
        uint16_t myPanID = otLinkGetPanId(ot); // otPanId

        char myPanIDBuff[255];
        snprintf(myPanIDBuff, sizeof(myPanIDBuff), "0x%02X", myPanID); // put hex into myPanIDBuff


        constexpr char hexmap[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
        const otMasterKey *key = otThreadGetMasterKey(ot);
        wchar_t szKey[OT_MASTER_KEY_SIZE * 2 + 1] = { 0 };
        for (uint8_t i = 0; i < OT_MASTER_KEY_SIZE; i++)
        {
                szKey[2 * i]     = hexmap[(key->m8[i] & 0xF0) >> 4];
                szKey[2 * i + 1] = hexmap[key->m8[i] & 0x0F];
        }


        char myMasterKeyBuff[255];
        wcstombs(myMasterKeyBuff, szKey, sizeof(myMasterKeyBuff));

// End changes

        char *myNetworkName = otThreadGetNetworkName(ot);
        char myNetworkNameBuff[255];
        snprintf(myNetworkNameBuff, sizeof(myNetworkNameBuff), "%s", myNetworkName); // network name as a string


        Particle.publish("----------------","-------------", 60, PRIVATE); // just to show a space between samples
        delay(2000);
        Particle.publish("Particle Thread ","Connection Information", 60, PRIVATE); // just to show a space between samples
        delay(2000);
        Particle.publish("My Channel: ", String(myChannel), 60, PRIVATE); //shows printing an integer variable

        delay(2000);
        Particle.publish("Argon Pan ID: ", String(myPanIDBuff), 60, PRIVATE); //shows printing an integer variable
        delay(2000);

        Particle.publish("My Master Key: ", String(myMasterKeyBuff), 60, PRIVATE); //shows printing an integer variable
        delay(2000);
        Particle.publish("My Network Name: ", String(myNetworkNameBuff), 60, PRIVATE); //shows printing an integer variable
        delay(2000);
        Particle.publish("----------------","-------------", 60, PRIVATE); // just to show a space between samples
        delay(2000);
        Particle.publish("Generates the same info","every 60 seconds", 60, PRIVATE); // just to show a space between samples

        delay(60000); // wait 60 seconds before re-print
}


*/



