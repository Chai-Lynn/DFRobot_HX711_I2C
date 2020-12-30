/*!
   @file getCalibration.ino
   @brief 获取传感器的校准值，在运行此程序前要对传感器进行校准操作
   @n 1.先要按下传感器模块上的rst按钮去皮重
   @n 2.放上100g质量的物体(一定要是100g的物体)，按下cal按钮使传感器计算得出准确的校准值，
   @n 3.传感器会在5s内完成校准,红灯闪烁代表校准完成，这是便可以通过此程序获取校准值
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
  //获取校准值
  Serial.print("the calibration value of the sensor is: ");
  Serial.println(MyScale.getCalibration());
  //MyScale.setCalibration(MyScale.getCalibration());
  delay(1000);
}

void loop() {
  /*
  Serial.print("weight is: ");
  Serial.print(MyScale.readWeight(), 1);
  Serial.println(" g");
  delay(1000);
  */
}