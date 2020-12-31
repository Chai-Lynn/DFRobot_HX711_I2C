/*!
 * @file DFRobot_HX711_I2C.cpp
 * @brief Define the basic structure of class DFRobot_HX711_I2C 
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2020-12-26
 * @get from https://www.dfrobot.com
 * @https://github.com/DFRobot/DFRobot_HX711_I2C
 */
#include "DFRobot_HX711_I2C.h"

DFRobot_HX711_I2C::DFRobot_HX711_I2C(TwoWire * pWire ,uint8_t addr){
   _pWire = pWire;
  _address = addr;

}

int DFRobot_HX711_I2C::begin(void){
    Wire.begin();
    DBG("\r\n");
    Wire.beginTransmission(_address);
    _pWire->write(REG_DATA_INIT_SENSOR);
    if(Wire.endTransmission() == 0) {
      DBG("\r\n");
     _offset = average(10);
      return true;
    }
    DBG("IIC ");
  return false;
}

float DFRobot_HX711_I2C::readWeight(uint8_t times){

  long value = average(times);
  if(peelFlag()) {
     //pFlag = 1;
     _offset = average(times);
  }
  //Serial.println(value);
  return (((float)value- _offset)/_calibration) ;
}
long DFRobot_HX711_I2C::average(uint8_t times){
  long sum = 0;
  for (uint8_t i = 0; i < times; i++)
  {
      sum += getValue(); 
  }
   
  return  sum/times;
}
float DFRobot_HX711_I2C::getCalibration()
{
   uint8_t data[4];
   uint32_t value = 0;
   readReg(REG_DATA_GET_CALIBRATION,data,4);

     value = data[0];
     value = (value << 8) | data[1];
     value = (value << 8) | data[2];
     value = (value << 8) | data[3];
     DBG(value,HEX);
     //if(value == 0) value ==2234.f;
     float *cal = (float *)&value;
    
     //_calibration = *cal;
     return *cal;
}

void DFRobot_HX711_I2C::setCalibration(float value)
{
  _calibration = value;

}

bool DFRobot_HX711_I2C::peelFlag(){


   uint8_t data[1];
   readReg(REG_DATA_GET_PEEL_FLAG,data,1);
   if(data[0] == 1){
       DBG("---------------------------------");
      return true;
   }else{
      return false;
   }
}

long DFRobot_HX711_I2C::getValue(){
   uint8_t data[4];
   long value = 0;
   readReg(REG_DATA_GET_RAM_DATA,data,4);
   if(data[0] == 0x12){
     value = (long)data[1];
     value = (long)((value << 8) | data[2]);
     value = (long)((value << 8) | data[3]);
   }else{
    DBG("DATA ERROR");
   }
   //Serial.println(sizeof(int),HEX);
   //Serial.println(value^0x800000);
   return (value^0x800000);
}

int DFRobot_HX711_I2C::readReg(uint8_t reg,uint8_t * data ,size_t size){

    _pWire->beginTransmission(_address);
    _pWire->write(reg);
    _pWire->endTransmission();
    delay(22);

    _pWire->requestFrom(_address, size);

    for(uint8_t i = 0;i < size;i++){
       data[i] = _pWire->read();
	   DBG(data[i],HEX);
    }

     return 1;
}

uint8_t DFRobot_HX711_I2C::writeReg(uint8_t reg,const void *data,size_t size){
    if (data == NULL) {
     DBG("pBuf ERROR!! : null pointer");
    }
    uint8_t * _pBuf = (uint8_t *)data;
   _pWire->beginTransmission(_address);
   _pWire->write(reg);
   for(uint8_t i = 0;i < size;i++){
      _pWire->write(_pBuf[i]);
     }
   _pWire->endTransmission();

   return 1;

}  


