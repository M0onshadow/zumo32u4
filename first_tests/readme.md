# Zumo32u4

Small project written in 3 hours (Arduino).
It concerns robots Zumo 32U4, it will detect an object in a white area, push it out of this area thanks to the tracks that serve as wheels and the engine launched at maximum speed, and at detection of a black zone, return to the white zone.

Needs an Arduino IDE, A-star Drivers (https://www.pololu.com/file/0J1240/a-star-windows-1.3.0.0.zip for Windows) and Zumo 32U4 libraries (https://files.pololu.com/arduino/package_pololu_index.json).

For more informations, please visit https://www.pololu.com/docs/0J63/


Edit (18/12/2018) :

- Add of stop button
- LEDs are now turned on when there is a specific value in "ProxSensors" and "LineSensors"

Edit (20/12/2018) :

- Some lines of the program were contradictory, so they have been deleted

Edit (15/01/2018) :

- The robot is now programmed to detect another robot and drive it over to eject it from the white area. There may be major changes in the program, so make sure there is no update before you use it.
