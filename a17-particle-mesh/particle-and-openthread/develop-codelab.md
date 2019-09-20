

this codelab sets up the nrf52840 with openthreadd

https://codelabs.developers.google.com/codelabs/openthread-apis/#0


```cd ~
git clone --recursive https://github.com/openthread/openthread.git
cd openthread
./bootstrap
```


to this file

https://github.com/openthread/openthread/blob/master/examples/platforms/openthread-system.h

add the following
```
/**
 * Init LED module.
 *
 */
void otSysLedInit(void);
void otSysLedSet(uint8_t aLed, bool aOn);
void otSysLedToggle(uint8_t aLed);

/**
* A callback will be called when GPIO interrupts occur.
*
*/
typedef void (*otSysButtonCallback)(otInstance *aInstance);
void otSysButtonInit(otSysButtonCallback aCallback);
void otSysButtonProcess(otInstance *aInstance);
```
