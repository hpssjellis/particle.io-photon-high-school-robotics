#include "Particle.h"

// dependencies.oled-wing-adafruit=0.0.5
// https://github.com/rickkas7/oled-wing-adafruit
#include "oled-wing-adafruit.h"

#if MODULE_FUNCTION == 3
// This is a monolithic build, so we have RSSI functions available
#define HAS_RSSI
#include "ot_api.h"
extern "C" {
	int8_t otPlatRadioGetRssi(otInstance *aInstance);
};
#endif

SerialLogHandler logHandler;

SYSTEM_THREAD(ENABLED);

const unsigned long transmissionIntervalMs = 1000;
const char *meshEventName = "distanceCheck";

const unsigned long displayUpdateIntervalMs = 500;

OledWingAdafruit display;

unsigned long lastReceive = 0;
int numReceived = 0;
bool displayNow = false;
bool subscribed = false;
bool buttonClicked = false;
bool externalAntenna = false;

unsigned long lastDisplayUpdate = 0;

void meshEventHandler(const char *event, const char *data);
void displayUpdate();
void buttonHandler();
void selectAntenna(bool external);

void setup() {
	System.on(button_click, buttonHandler);

	display.setup();
	display.clearDisplay();
	display.display();
}

void buttonHandler() {
	buttonClicked = true;
}

void loop() {
	display.loop();

	if (!subscribed && Mesh.ready()) {
		subscribed = true;
		Mesh.subscribe(meshEventName, meshEventHandler);
	}

	if (((millis() - lastDisplayUpdate) >= displayUpdateIntervalMs) || displayNow) {
		lastDisplayUpdate = millis();
		displayNow = false;
		displayUpdate();
	}

	if (buttonClicked) {
		buttonClicked = false;

		externalAntenna = !externalAntenna;
		selectAntenna(externalAntenna);

		Log.info("button pressed externalAntenna=%d", externalAntenna);

		display.clearDisplay();
		display.setTextSize(2);
		display.setTextColor(WHITE);
		display.setCursor(0,0);
		display.println(externalAntenna ? "EXTERNAL" : "INTERNAL");
		display.println("ANTENNA");
		display.display();
	}
}

void meshEventHandler(const char *event, const char *data) {
	lastReceive = millis();
	numReceived++;
	displayNow = true;
}


void displayUpdate() {
	display.clearDisplay();
	display.setTextSize(2);
	display.setTextColor(WHITE);
	display.setCursor(0,0);

	char buf[64];

	if (millis() - lastReceive < 1250) {
		snprintf(buf, sizeof(buf), "%d rcvd", numReceived);
		display.println(buf);

#ifdef HAS_RSSI
		int8_t rssi = otPlatRadioGetRssi(0);
		snprintf(buf, sizeof(buf), "rssi %d", (int)rssi);
		display.println(buf);
#endif
	}
	else {
		size_t missed = (millis() - lastReceive) / 1000;
		snprintf(buf, sizeof(buf), "missed %u", missed);
		display.println(buf);
	}


	display.display();

}


void selectAntenna(bool external) {
    if (external) {
#if (PLATFORM_ID == PLATFORM_ARGON)
        digitalWrite(ANTSW1, 1);
        digitalWrite(ANTSW2, 0);
#elif (PLATFORM_ID == PLATFORM_BORON)
        digitalWrite(ANTSW1, 0);
#else
        digitalWrite(ANTSW1, 0);
        digitalWrite(ANTSW2, 1);
#endif
    } else {
#if (PLATFORM_ID == PLATFORM_ARGON)
        digitalWrite(ANTSW1, 0);
        digitalWrite(ANTSW2, 1);
#elif (PLATFORM_ID == PLATFORM_BORON)
        digitalWrite(ANTSW1, 1);
#else
        digitalWrite(ANTSW1, 1);
        digitalWrite(ANTSW2, 0);
#endif
    }
}
