

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

/* Header for the functions defined here */
#include "openthread-system.h"

#include <string.h>

/* Header to access an OpenThread instance */
#include <openthread/instance.h>

/* Headers for lower-level nRF52840 functions */
#include "platform-nrf5.h"
#include "hal/nrf_gpio.h"
#include "hal/nrf_gpiote.h"
#include "nrfx/drivers/include/nrfx_gpiote.h"

/* Declaring callback function for button 1. */
static otSysButtonCallback sButtonHandler;
static bool                sButtonPressed;

/**
 * @brief Function to receive interrupt and call back function
 * set by the application for button 1.
 *
 */
static void in_pin1_handler(uint32_t pin, nrf_gpiote_polarity_t action)
{
    OT_UNUSED_VARIABLE(pin);
    OT_UNUSED_VARIABLE(action);
    sButtonPressed = true;
}


/**
 * @brief Function for configuring: PIN_IN pin for input, PIN_OUT pin for output,
 * and configures GPIOTE to give an interrupt on pin change.
 */

void otSysLedInit(void)
{
    /* Configure GPIO mode: output */
    nrf_gpio_cfg_output(LED_1_PIN);
    nrf_gpio_cfg_output(LED_2_PIN);
    nrf_gpio_cfg_output(LED_3_PIN);
    nrf_gpio_cfg_output(LED_4_PIN);
    
    /* Clear all output first */
    nrf_gpio_pin_write(LED_1_PIN, GPIO_LOGIC_LOW);
    nrf_gpio_pin_write(LED_2_PIN, GPIO_LOGIC_LOW);
    nrf_gpio_pin_write(LED_3_PIN, GPIO_LOGIC_LOW);
    nrf_gpio_pin_write(LED_4_PIN, GPIO_LOGIC_LOW);
    
    /* Initialize gpiote for button(s) input.
     Button event handlers are set in the application (main.c) */
    ret_code_t err_code;
    err_code = nrfx_gpiote_init();
    APP_ERROR_CHECK(err_code);
}


/**
 * @brief Function to set the mode of an LED.
 */

void otSysLedSet(uint8_t aLed, bool aOn)
{
    switch (aLed)
    {
    case 1:
        nrf_gpio_pin_write(LED_1_PIN, (aOn == GPIO_LOGIC_HI));
        break;
    case 2:
        nrf_gpio_pin_write(LED_2_PIN, (aOn == GPIO_LOGIC_HI));
        break;
    case 3:
        nrf_gpio_pin_write(LED_3_PIN, (aOn == GPIO_LOGIC_HI));
        break;
    case 4:
        nrf_gpio_pin_write(LED_4_PIN, (aOn == GPIO_LOGIC_HI));
        break;
    }
}



/**
 * @brief Function to toggle the mode of an LED.
 */
void otSysLedToggle(uint8_t aLed)
{
    switch (aLed)
    {
    case 1:
        nrf_gpio_pin_toggle(LED_1_PIN);
        break;
    case 2:
        nrf_gpio_pin_toggle(LED_2_PIN);
        break;
    case 3:
        nrf_gpio_pin_toggle(LED_3_PIN);
        break;
    case 4:
        nrf_gpio_pin_toggle(LED_4_PIN);
        break;
    }
}


/**
 * @brief Function to toggle the mode of an LED.
 */
void otSysButtonInit(otSysButtonCallback aCallback)
{
    nrfx_gpiote_in_config_t in_config = NRFX_GPIOTE_CONFIG_IN_SENSE_LOTOHI(true);
    in_config.pull                    = NRF_GPIO_PIN_PULLUP;

    ret_code_t err_code;
    err_code = nrfx_gpiote_in_init(BUTTON_PIN, &in_config, in_pin1_handler);
    APP_ERROR_CHECK(err_code);

    sButtonHandler = aCallback;
    sButtonPressed = false;

    nrfx_gpiote_in_event_enable(BUTTON_PIN, true);
}

void otSysButtonProcess(otInstance *aInstance)
{
    if (sButtonPressed)
    {
        sButtonPressed = false;
        sButtonHandler(aInstance);
    }
}










```

-------------------------------------------------------------------------
