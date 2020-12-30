# -*- coding: utf-8 -*-
"""
   @file getCalibration.ino
   @brief 获取传感器的校准值，在运行此程序前要对传感器进行校准操作
   @n 1.先要按下传感器模块上的rst按钮去皮�?
   @n 2.放上100g质量的物�?一定要�?00g的物�?，按下cal按钮使传感器计算得出准确的校准值，
   @n 3.传感器会�?s内完成校�?红灯闪烁代表校准完成，这是便可以通过此程序获取校准�?
   @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [fengli](li.feng@dfrobot.com)
   @version  V1.0
   @date  2020-12-26
   @get from https://www.dfrobot.com
   @https://github.com/DFRobot/DFRobot_HX711_I2C
"""
import sys
import time
sys.path.append("../..")
from DFRobot_HX711_I2C import *

IIC_MODE         = 0x01           # default use IIC1
IIC_ADDRESS      = 0x60            # default iic device address
'''
   # The first  parameter is to select iic0 or iic1
   # The second parameter is the iic device address
'''
hx711 = DFRobot_HX711_I2C(IIC_MODE ,IIC_ADDRESS)

"""
     @brief 初始化函�?
"""
time.sleep(0.1)
#设置I2C地址

print("the calibration value of the sensor is: ")
calibration = hx711.getCalibration()
print(calibration[0])
time.sleep(0.1)

