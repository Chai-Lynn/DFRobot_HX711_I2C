# -*- coding:utf-8 -*-
"""
   @file readWeight.ino
   @brief 获取物体的重量,按下模块上的rst按键，程序会自动去皮
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

IIC_MODE         = 0x01            # default use IIC1
IIC_ADDRESS      = 0x60        # default i2c device address
'''
   # The first  parameter is to select iic0 or iic1
   # The second parameter is the iic device address
'''
hx711 = DFRobot_HX711_I2C(IIC_MODE ,IIC_ADDRESS)
"""
     @brief 初始化函数
"""

hx711.begin()

print("start\r\n")
#手动设置校准校准值
hx711.setCalibration(2242.0)
while(1):
  data = hx711.readWeight(10)
  print('weight is %.1f g' % data)
  time.sleep(2)
  #hx711.peelFlag();
