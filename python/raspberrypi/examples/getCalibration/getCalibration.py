# -*- coding: utf-8 -*-
"""
   @file getCalibration.ino
   @brief 获取传感器的校准值，在运行此程序前要对传感器进行校准操作
   @n 1.先要按下传感器模块上的CAL按钮,传感器会自动去除皮重,完成后CAL指示灯会点亮
   @n 2.5s内放上一定质量的物体(通过setCalWeight函数设置)，指示灯熄灭表示模块会开始校准
   @n 3.校准完成后指示灯再一秒内闪烁3次表示校准完成
   @n 4.若没有放上100g物品，则指示灯在五秒后熄灭，此次校准无效
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
IIC_ADDRESS      = 0x64            # default iic device address
'''
   # The first  parameter is to select iic0 or iic1
   # The second parameter is the iic device address
'''
hx711 = DFRobot_HX711_I2C(IIC_MODE ,IIC_ADDRESS)

time.sleep(0.1)
#设置重量传感器模块自动校准时的触发阈值(g)
hx711.setThreshold(50)
#设置重量传感器模块自动校准时的校准重量(g)
hx711.setCalWeight(100)

print("the calibration value of the sensor is: ")
#获取自动校准值
calibration = hx711.getCalibration()
print(calibration[0])
time.sleep(0.1)

