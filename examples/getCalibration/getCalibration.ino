/*!
   @file getCalibration.ino
   @brief 获取传感器的校准值，在运行此程序前要对传感器进行校准操作
   @n 1.先要按下传感器模块上的CAL按钮,传感器会自动去除皮重,完成后CAL指示灯会点亮
   @n 2.5s内放上100g质量的物体(一定要是100g的物体)，指示灯熄灭表示模块会开始校准
   @n 3.校准完成后指示灯再一秒内闪烁3次表示校准完成
   @n 4.若没有放上100g物品，则指示灯在五秒后熄灭，此次校准无效
   @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [fengli](li.feng@dfrobot.com)
   @version  V1.0
   @date  2020-12-26
   @get from https://www.dfrobot.com
   @https://github.com/DFRobot/DFRobot_HX711_I2C
*/
#include <DFRobot_HX711_I2C.h>

/*!
 * @brief Constructor 
 * @param pWire I2c controller
 * @param addr  I2C address(0x64/0x65/0x660x67)
 */
//DFRobot_HX711_I2C MyScale(&Wire,/*addr=*/0x64);
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