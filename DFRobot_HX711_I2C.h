/*!
 * @file DFRobot_HX711_I2C.h
 * @brief Define the basic structure of class DFRobot_HX711_I2C 
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2020-12-23
 * @get from https://www.dfrobot.com
 * @https://github.com/DFRobot/DFRobot_HX711_I2C
 */

#ifndef DFROBOT_HX711_I2C_H
#define DFROBOT_HX711_I2C_H
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include <Wire.h>

//#define ENABLE_DBG

#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("["); Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#define HX711_I2C_ADDR  (0x60)  /*sensor IIC address*/

//#define ERR_OK             0      //ok
//#define ERR_DATA_BUS      -1      //error in data bus
//#define ERR_IC_VERSION    -2      //chip version mismatch

class DFRobot_HX711_I2C
{
public:
  #define REG_DATA_GET_RAM_DATA       0x66     /*Get sensor raw data*/
  #define REG_DATA_GET_CALIBRATION    0x67     /*Get the low byte of command voc*/
  #define REG_DATA_SET_CALIBRATION    0x68     /*Get the high byte of command Version*/
  #define REG_DATA_GET_PEEL_FLAG      0x69     /*Get the high byte of command Version*/
  
    /*!
     * @brief Constructor 
     * @param pWire I2c controller
     * @param addr  I2C address
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

private:
    long getValue();
    bool peelFlag();
    long average(uint8_t times = 10);
  /**
   * @brief Write command into sensor chip 
   * @param pBuf  Data included in command
   * @param size  The number of the byte of command
   */
    int readReg(uint8_t reg,uint8_t * data ,size_t size);
  /**
   * @brief Write command into sensor chip 
   * @param pBuf  Data included in command
   * @param size  The number of the byte of command
   * @return      Return 0 if the reading is done, otherwise return non-zero. 
   */
    uint8_t  writeReg(uint8_t reg,const void *data,size_t size);   
    uint8_t _address;
    uint8_t pFlag = 0;
    long _offset;
    TwoWire *_pWire;
    float _calibration = 2236.0f;
    
};
#endif