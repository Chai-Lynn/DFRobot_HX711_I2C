/*!
   @file readWeight.ino
   @brief 获取物体的重量
   @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [fengli](li.feng@dfrobot.com)
   @version  V1.0
   @date  2020-12-26
   @get from https://www.dfrobot.com
   @https://github.com/DFRobot/DFRobot_HX711_I2C
*/
#include <DFRobot_HX711_I2C.h>
DFRobot_HX711_I2C MyScale;

void setup() {
  Serial.begin(9600);
  while (!MyScale.begin()) {
    Serial.println("The initialization of the chip is failed, please confirm whether the chip connection is correct");
    delay(1000);
  }
  //手动设置校准校准值
  MyScale.setCalibration(2236.f);
}

void loop() {
  // 获取物体重量
  Serial.print("weight is: ");
  Serial.print(MyScale.readWeight(), 1);
  Serial.println(" g");
  delay(1500);
}