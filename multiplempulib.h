

#ifndef _multiplempulib_h
#define multiplempulib_h
#include "Arduino.h"
#include "Wire.h"

class multiplempulib{ 
public:
#define MPU9250_ADDRESS  0x68// Device address when ADO = 1
#define PWR_MGMT_1       0x6B // Device defaults to the SLEEP mode
#define WHO_AM_I_MPU9250 0x75 // Should return 0x71
#define CONFIG           0x1A
#define GYRO_CONFIG      0x1B
#define ACCEL_CONFIG      0x1C
#define ACCEL_CONFIG2     0x1D
#define FIFO_EN          0x23
#define XG_OFFSET_H      0x13  // User-defined trim values for gyroscope
#define XG_OFFSET_L      0x14
#define YG_OFFSET_H      0x15
#define YG_OFFSET_L      0x16
#define ZG_OFFSET_H      0x17
#define ZG_OFFSET_L      0x18
#define XA_OFFSET_H      0x77
#define XA_OFFSET_L      0x78
#define YA_OFFSET_H      0x7A
#define YA_OFFSET_L      0x7B
#define ZA_OFFSET_H      0x7D
#define ZA_OFFSET_L      0x7E
#define USER_CTRL        0x6A  // Bit 7 enable DMP, bit 3 reset DMP
#define FIFO_COUNTH      0x72
#define FIFO_COUNTL      0x73
#define FIFO_R_W         0x74
#define SMPLRT_DIV       0x19
#define PWR_MGMT_2       0x6C
#define ACCEL_XOUT_H     0x3B
#define ACCEL_XOUT_L     0x3C
#define ACCEL_YOUT_H     0x3D
#define ACCEL_YOUT_L     0x3E
#define ACCEL_ZOUT_H     0x3F
#define ACCEL_ZOUT_L     0x40
#define GYRO_XOUT_H      0x43
#define GYRO_XOUT_L      0x44
#define GYRO_YOUT_H      0x45
#define GYRO_YOUT_L      0x46
#define GYRO_ZOUT_H      0x47
#define GYRO_ZOUT_L      0x48
#define TEMP_OUT_H       0x41
#define TEMP_OUT_L       0x42
#define INT_PIN_CFG      0x37
#define INT_EN           0x38
#define I2C_MST_CTRL     0x24
#define WHO_AM_I         0x75


//// MAGNETOMETER REGISTERS
#define AK8963_ADDRESS 0x0C
#define AK8963_ST1     0x02  // data ready status bit 0
#define AK8963_XOUT_L  0x03  // data
#define AK8963_XOUT_H  0x04
#define AK8963_YOUT_L  0x05
#define AK8963_YOUT_H  0x06
#define AK8963_ZOUT_L  0x07
#define AK8963_ZOUT_H  0x08
#define AK8963_ST2     0x09  // Data overflow bit 3 and data read error status bit 2
#define AK8963_CNTL1   0x0A  // Power down (0000), single-measurement (0001), self-test (1000) and Fuse ROM (1111) modes on bits 3:0
#define AK8963_CNTL2   0x0B 
#define AK8963_ASAX    0x10  // Fuse ROM x-axis sensitivity adjustment value
#define AK8963_ASAY    0x11  // Fuse ROM y-axis sensitivity adjustment value
#define AK8963_ASAZ    0x12  // Fuse ROM z-axis sensitivity adjustment value

float rawAcc[3];
float rawGyro[3];
float rawMag[3];
float Yaw;
float Pitch;
float Roll;
int allready=0;
float accelScale;
float gyroScale;
float g=0.9807;
float told=0;
int numSamp=100;
float gyroError=PI*(40.0f/180.0f);
float beta=sqrt(3.0f/4.0f)*gyroError;
bool initialized=false;
bool first_sample=true;
float magSens1[3];
float magSens2[3];
float magSens3[3];
float magSens4[3];
float acc1_bias[3]={0};
float gyr1_bias[3]={0};
float acc2_bias[3]={0};
float gyr2_bias[3]={0};
float acc3_bias[3]={0};
float gyr3_bias[3]={0};
float acc4_bias[3]={0};
float gyr4_bias[3]={0};
float magBias1[3];
float magBias2[3];
float magBias3[3];
float magBias4[3];
float magSoft1[3];
float magSoft2[3];
float magSoft3[3];
float magSoft4[3];

void initiate();
void calibrateIMU();
void calibrateMag();

void MVA(float ax, float ay, float az, float gx, float gy, float gz, 
float* readingBuffer0, float* readingBuffer1, float* readingBuffer2, 
float* readingBuffer3, float* readingBuffer4, float* readingBuffer5);

void imu_update(float acx, float acy, float acz,
                float wx, float wy, float wz,
                float &q1, float &q2, float &q3, float &q4);
void accRead();
void gyrRead();
void magRead();
void mpu_select(uint8_t bus);

void madgwickUpdate(float ax, float ay, float az,
 float gx, float gy, float gz,
 float mx, float my, float mz,
 float &q1, float &q2, float &q3, float &q4);
void getEuler(float q_or0, float q_or1, float q_or2, float q_or3);
float gyroX1();
float gyroY1();
float gyroZ1();
float accX1();
float accY1();
float accZ1();
float magX1();
float magY1();
float magZ1();
float gyroX2();
float gyroY2();
float gyroZ2();
float accX2();
float accY2();
float accZ2();
float magX2();
float magY2();
float magZ2();
float gyroX3();
float gyroY3();
float gyroZ3();
float accX3();
float accY3();
float accZ3();
float magX3();
float magY3();
float magZ3();
float gyroX4();
float gyroY4();
float gyroZ4();
float accX4();
float accY4();
float accZ4();
float magX4();
float magY4();
float magZ4();

uint8_t readByte(uint8_t address, uint8_t subAddress);
void writeByte(uint8_t address, uint8_t subAddress, uint8_t data);


};

#endif
