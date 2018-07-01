/*
    LEDs in Space

    A short example program to control an LED in Objects in Space - flashing it
    when entering EMCON mode, using the ArduinosInSpace library.

    For more info on the protocol itself or the things you can do, check out:   
    the wiki: https://oiswiki.sysadninjas.net/wiki/Category:HardwareInterfacing
    or the official website: http://objectsgame.com/the-controllers/ois-serial-data-protocol/

    For information on the ArduinosInSpace library, visit the repo:
    https://bitbucket.org/pjhardy/arduinosinspace/src/master/
    Much of this code is based on that repo's readme

    Circuit:
    Pin 3 -> 220 resistor -> Red LED -> GND pin
*/
#include <ArduinosInSpace.h>

// LED pin for our LED
#define ledPin 3

// Set up the OIS object from the ArduinosInSpace library
ObjectsInSpace OIS(Serial, 1);

void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    // Setup for serial connection
    Serial.begin(9600);
    // Tell our object to start handshaking with the game
    OIS.begin();

    // Register callback for the bool request 'EMCON_MODE'
    // this will make sure we're recieving information on the EMCON status
    OIS.registerBool(EMCON_MODE, emconCallback);

    // Begins listening for data and sending commands, if any
    OIS.activate();
}

void loop() {
    // Asks our object to process any incoming data for us
    OIS.update();
}

// The callback function we registered in setup
void emconCallback(int channel, bool data) {
    if (data == 0) {
        // normal operation
        digitalWrite(ledPin, LOW);
    }
    else {
        // in emcon mode
        flashLED(3);
        digitalWrite(ledPin, HIGH);
    }
}

// Simple function to flash our LED 'num' times
void flashLED(int num) {
    for (int i = 0; i <= num; i++) {
        digitalWrite(ledPin, LOW);
        delay(50);
        digitalWrite(ledPin, HIGH);
        delay(100);
    }
}
