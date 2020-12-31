# HX711-raspberrypi
HX711 is a 24-bit A / D converter chip designed for high-precision electronic scales.<br>
This example is suitable for HX711 sensor and read data through raspberrypi.<br>


## DFRobot_HX711_I2C Library for raspberrypi
---------------------------------------------------------

Provide an raspberrypi library to get weight by reading data from HX711.

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

Provide an raspberrypi library to get weight by reading data from HX711.

## Installation



## Methods

```py

  def begin():
    '''
      @brief 模块初始化
    '''
    
  def readWeight(self ,times):
    '''
      @brief 获取物体重量
      @param times: 从这么多测量次数中求取平均
      @return  物体重量, (g)
    '''
    
  def getCalibration(self):
    '''
      @brief 获取重量传感器模块自动校准值
      @return 自动校准值
    '''
    
  def setCalibration(self):
    '''
      @brief 手动设置自动校准值
    '''
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
树莓派 3       |      √       |              |             | 
树莓派 4       |      √       |              |             | 


## History

- data 2020-12-31
- version V1.0


## Credits

Written by(li.feng@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))
