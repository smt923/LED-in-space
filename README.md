# LED-in-space

Small example Arduino code for making an LED flash in the game Objects in Space

## Info

Uses an Arduino Uno, LED and resistor for hardware

The [ArduinosInSpace library](https://bitbucket.org/pjhardy/arduinosinspace/src/master/) makes it all very simple

This is just a very simple starting point to help get something working

## Tips/Hints for getting started

You'll have to add `hardware=true` and possibly `ignorecom12=true` on Windows to your configuration file, which for me on is located `steamapps\common\Objects in Space\ObjectsInSpace` - [more info here](https://oiswiki.sysadninjas.net/wiki/Getting_started_with_hardware)

Follow the instructions to get the library set up on the ArduinosInSpace repo above

Don't leave the serial monitor on, or anything else that accesses the Arduino over usb/serial so that the game can access it

The RX LED will flash a bunch when you enter a game (either a new game, load a save or enter a scenario - the scenarios are good for quick testing) if it's working

You can upload new code to the Arduino by backing out to the main menu, it won't work while in game if OiS in using the Arduino