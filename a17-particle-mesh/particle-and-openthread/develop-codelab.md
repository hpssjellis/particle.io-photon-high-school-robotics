

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




-----------------------------------------------------------------------

best to go to this page next lots of things to do

https://codelabs.developers.google.com/codelabs/openthread-apis/#4



but really it is just add this file

examples/platforms/nrf52840/gpio.c (NEW FILE)



```

/**
 * @file
 *   This file implements the system abstraction for GPIO and GPIOTE.
 *
 */

#define BUTTON_GPIO_PORT 0x50000300UL
#define BUTTON_PIN 11 // button #1

#define GPIO_LOGIC_HI 0
#define GPIO_LOGIC_LOW 1

#define LED_GPIO_PORT 0x50000300UL
#define LED_1_PIN 13 // turn on to indicate leader role
#define LED_2_PIN 14 // turn on to indicate router role
#define LED_3_PIN 15 // turn on to indicate child role
#define LED_4_PIN 16 // turn on to indicate UDP receive





```

-------------------------------------------------------------------------
