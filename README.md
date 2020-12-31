# HX711-Arduino
HX711 is a 24-bit A / D converter chip designed for high-precision electronic scales.<br>
This example is suitable for HX711 sensor and read data through Arduino.<br>


## DFRobot_HX711_I2C Library for Arduino
---------------------------------------------------------

Provide an Arduino library to get weight by reading data from HX711.

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

Provide an Arduino library to get weight by reading data from HX711.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++

#include <DFRobot_HX711_I2C.h>

/*!
 * @brief Constructor 
 * @param pWire I2c controller
 * @param addr  I2C address(0x64/0x65/0x660x67)
 */
DFRobot_HX711_I2C(TwoWire * pWire = &Wire,uint8_t addr = HX711_I2C_ADDR);

/**
 * @brief init function
 * @return Return 1 if initialization succeeds, otherwise return non-zero and error code.
 */
int begin(void);

/**
 * @brief Get the weight of the object
 * @param times Take the average several times
 * @return Return the read weight value, unit: g
 */
float readWeight(uint8_t times = 12);

/**
 * @brief get calibration value 
 * @return return the read calibration value
 */
float getCalibration();

/**
 * @brief Set calibration value
 * @return return the read calibration value
 */
void  setCalibration(float value);


```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
FireBeetle-ESP8266        |      √       |              |             | 
FireBeetle-ESP32        |      √       |              |             | 
掌控板        |      √       |              |             | 
树莓派        |      √       |              |             | 
microbit        |      √       |              |             | 



## History

- data 2020-12-31
- version V1.0


## Credits

Written by(li.feng@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))
