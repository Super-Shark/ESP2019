#ifndef _GLOBALS_h
#define _GLOBALS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// 조도 센서
#define	MJUC_CHANNEL_ILLUMINANT						0

// 초음파 거리 센서
#define MJUC_CHANNEL_ULTRASONIC_WAVE_TRANSMITTER	7
#define MJUC_CHANNEL_ULTRASONIC_WAVE_RECEIVER		6
#define MJUC_TIME_OUT_OF_MEASURING_IN_MICROSECOND	1000000
#define MJUC_DIVISOR_FOR_DISTANCE_CALCULATION		58.2		// 초음파 속도: 340m/s

// RGBLED
#define MJUC_CHANNEL_RGBLED_RED						3
#define MJUC_CHANNEL_RGBLED_GREEN					10
#define MJUC_CHANNEL_RGBLED_BLUE					5
#define MJUC_LED_STRENGTH_STRONG					255
#define MJUC_LED_STRENGTH_WEAK						50

// 거리구분(cm)
#define MJUC_DISTANCE_TOO_CLOSE						3	// < 3cm
#define MJUC_DISTANCE_VERY_CLOSE					5	
#define MJUC_DISTANCE_CLOSE							8	
#define MJUC_DISTANCE_FAR							10	
#define MJUC_DISTANCE_VERY_FAR						15
#define WAIT_TIME						            10

// 밝기구분(CDS 저항 0~1023)
#define MJUC_LIGHT_DISTINCTION						800

enum ELightState {
	eBright,
	eDark,
	eNumLightStates
};
enum EDistanceState {
	eTooClose,
	eVeryClose,
	eClose,
	eFar,
	eVeryFar,
	eUnknown,
	eNumDistanceStates
};

#define MJUC_POLLSIZE_OF_MEMORY_MANAGER 32

#endif

