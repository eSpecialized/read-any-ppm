This Arduino code reads a PPM signal and puts the servo values into an array (called ppm), reagrdless of channel number, polarity, ppm frame length, etc...

Please report any issues

# This Fork is based on the work from;
- Uses a Timer, not compatibile with newer Arduino platforms, Requires older Atmel Atmega platforms.
- https://github.com/Hasi123/read-any-ppm/blob/master/Read_any_PPM.ino

- Why did I fork?
	- I needed something that worked on an Arduino Uno Wifi Rev2. This new Fork fufilles that need.

# This library attempts to work around those issues.
- Remove the need for an independant timer, and uses the standard micros which is available on other hardware platforms.
- Tested and Working on Arduino Wifi Uno Rev2 (Atmega4809 newest chip which has none of the same registers as the other project requires.)
- micros on 16Mhz MCU will have a resolution of 4us, on 8Mhz it will have a resolution of 8us.
	- For better resolution of 1us, a timer would need to be used on the platform.
