# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).


## [unreleased]

## [0.6] - 2020-03-29
### Added
- removed the need for the "pulse" section
- using micros (microseconds) on any arduino to track PPM pulses is a way to support a wider range of Arduino's. Feathers remain to be tested, SAMD based boards to be tested.
- PPM works of the RISING edge of a pulse, the falling pulse is not as important.
- No need for any Timers other than the default TimerA1 on most arduino hardware used to count milliseconds.
	
### Known Issues
- micros would need to be be pre-rolled before they overflow. Which should discard all readings until the next Sync Cycle.
- micros on 16Mhz MCU will have a resolution of 4us, on 8Mhz it will have a resolution of 8us

### Changed
- Project file renamed to match the clone directory name. This will prevent issues with opening in Arduino IDE.

### Removed
- The need for a 2nd timer. Micros is all that was needed.

## [0.5]
- Small bugfixes & sync pulses raised to 710us

## [0.4]

- Immediate Servo output beta

## [0.3]
- Bugfixes


## [0.2]
- now out. increased resolution to 0.5us on 16MHz & to 1us on 8MHz by using timer1 instead of micros()
