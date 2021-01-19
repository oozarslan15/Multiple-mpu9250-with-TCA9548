#include "multiplempulib.h"

void multiplempulib::initiate()
{
uint8_t regdata[3];
uint8_t acc_cfg=0x18;
uint8_t gyr_cfg=0x18;
uint8_t acc_cfg_2=0x00;
uint8_t gyr_cfg_2=0x00;
uint8_t fs=0x09;
float* accSca;
float* gyrSca;
float* mgSns[3];

accSca=&accelScale;
gyrSca=&gyroScale;
mpu_select(1);
delay(1);
mgSns[0]=&magSens1[0];
mgSns[1]=&magSens1[1];
mgSns[2]=&magSens1[2];
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x01);
writeByte(MPU9250_ADDRESS, USER_CTRL, 0x20);
writeByte(MPU9250_ADDRESS, I2C_MST_CTRL, 0x0D);
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x80);
delay(1);
writeByte(AK8963_ADDRESS, AK8963_CNTL2, 0x01);
delay(1);
writeByte(MPU9250_ADDRESS,PWR_MGMT_2, 0x00);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, acc_cfg);
if (acc_cfg==0x00){*accSca=2.0f/32768.0f;}
if (acc_cfg==0x08){*accSca=4.0f/32768.0f;}
if (acc_cfg==0x10){*accSca=8.0f/32768.0f;}
if (acc_cfg==0x18){*accSca=16.0f/32768.0f;}
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, gyr_cfg);
if (gyr_cfg==0x00){*gyrSca=(250.0f/32768.0f);}
if (gyr_cfg==0x08){*gyrSca=(500.0f/32768.0f);}
if (gyr_cfg==0x10){*gyrSca=(1000.0f/32768.0f);}
if (gyr_cfg==0x18){*gyrSca=(2000.0f/32768.0f);}
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, acc_cfg_2);
writeByte(MPU9250_ADDRESS, CONFIG, gyr_cfg_2);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, fs);
writeByte(MPU9250_ADDRESS, I2C_MST_CTRL, 0x0D);
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x01);
writeByte(MPU9250_ADDRESS, INT_EN, 0x01);
writeByte(MPU9250_ADDRESS, INT_PIN_CFG, 0x02);
writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x00);
delay(100);
 uint8_t x=readByte(AK8963_ADDRESS,AK8963_ASAX);
 uint8_t y=readByte(AK8963_ADDRESS,AK8963_ASAY);
 uint8_t z=readByte(AK8963_ADDRESS,AK8963_ASAZ);
*mgSns[0]=(((((float)regdata[0])-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
*mgSns[1]=(((((float)regdata[1])-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
*mgSns[2]=(((((float)regdata[2])-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x00);
delay(100);
//writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x16);
//delay(100);


mpu_select(2);
delay(1);
mgSns[0]=&magSens2[0];
mgSns[1]=&magSens2[1];
mgSns[2]=&magSens2[2];
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x01);
writeByte(MPU9250_ADDRESS, USER_CTRL, 0x20);
writeByte(MPU9250_ADDRESS, I2C_MST_CTRL, 0x0D);
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x80);
delay(1);
writeByte(AK8963_ADDRESS, AK8963_CNTL2, 0x01);
delay(1);
writeByte(MPU9250_ADDRESS,PWR_MGMT_2, 0x00);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, acc_cfg);
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, gyr_cfg);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, acc_cfg_2);
writeByte(MPU9250_ADDRESS, CONFIG, gyr_cfg_2);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, fs);
writeByte(MPU9250_ADDRESS, I2C_MST_CTRL, 0x0D);
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x01);
writeByte(MPU9250_ADDRESS, INT_EN, 0x01);
writeByte(MPU9250_ADDRESS, INT_PIN_CFG, 0x02);
writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x00);
delay(100);
  x=readByte(AK8963_ADDRESS,AK8963_ASAX);
  y=readByte(AK8963_ADDRESS,AK8963_ASAY);
  z=readByte(AK8963_ADDRESS,AK8963_ASAZ);
*mgSns[0]=(((((float)x)-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
*mgSns[1]=(((((float)y)-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
*mgSns[2]=(((((float)z)-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x00);
delay(100);
//writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x16);
//delay(100);

mpu_select(3);
delay(1);
mgSns[0]=&magSens3[0];
mgSns[1]=&magSens3[1];
mgSns[2]=&magSens3[2];
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x01);
writeByte(MPU9250_ADDRESS, USER_CTRL, 0x20);
writeByte(MPU9250_ADDRESS, I2C_MST_CTRL, 0x0D);
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x80);
delay(1);
writeByte(AK8963_ADDRESS, AK8963_CNTL2, 0x01);
delay(1);
writeByte(MPU9250_ADDRESS,PWR_MGMT_2, 0x00);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, acc_cfg);
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, gyr_cfg);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, acc_cfg_2);
writeByte(MPU9250_ADDRESS, CONFIG, gyr_cfg_2);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, fs);
writeByte(MPU9250_ADDRESS, I2C_MST_CTRL, 0x0D);
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x01);
writeByte(MPU9250_ADDRESS, INT_EN, 0x01);
writeByte(MPU9250_ADDRESS, INT_PIN_CFG, 0x02);
writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x00);
delay(100);
  x=readByte(AK8963_ADDRESS,AK8963_ASAX);
  y=readByte(AK8963_ADDRESS,AK8963_ASAY);
  z=readByte(AK8963_ADDRESS,AK8963_ASAZ);
*mgSns[0]=(((((float)x)-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
*mgSns[1]=(((((float)y)-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
*mgSns[2]=(((((float)z)-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x00);
delay(100);
//writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x16);
delay(100);

mpu_select(4);
delay(1);
mgSns[0]=&magSens4[0];
mgSns[1]=&magSens4[1];
mgSns[2]=&magSens4[2];
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x01);
writeByte(MPU9250_ADDRESS, USER_CTRL, 0x20);
writeByte(MPU9250_ADDRESS, I2C_MST_CTRL, 0x0D);
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x80);
delay(1);
writeByte(AK8963_ADDRESS, AK8963_CNTL2, 0x01);
delay(1);
writeByte(MPU9250_ADDRESS,PWR_MGMT_2, 0x00);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, acc_cfg);
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, gyr_cfg);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, acc_cfg_2);
writeByte(MPU9250_ADDRESS, CONFIG, gyr_cfg_2);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, fs);
writeByte(MPU9250_ADDRESS, I2C_MST_CTRL, 0x0D);
writeByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x01);
writeByte(MPU9250_ADDRESS, INT_EN, 0x01);
writeByte(MPU9250_ADDRESS, INT_PIN_CFG, 0x02);
writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x00);
delay(100);
  x=readByte(AK8963_ADDRESS,AK8963_ASAX);
  y=readByte(AK8963_ADDRESS,AK8963_ASAY);
  z=readByte(AK8963_ADDRESS,AK8963_ASAZ);
*mgSns[0]=(((((float)x)-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
*mgSns[1]=(((((float)y)-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
*mgSns[2]=(((((float)z)-128.0f)/256.0f)+1.0f)*4912.0f/32768.0f;
writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x00);
delay(100);
//writeByte(AK8963_ADDRESS, AK8963_CNTL1, 0x16);
//delay(100);
calibrateIMU();
//calibrateMag();
}

void multiplempulib::calibrateIMU()
{

float acc_biasX_tmp;
float acc_biasY_tmp;
float acc_biasZ_tmp;
float gyro_biasX_tmp;
float gyro_biasY_tmp;
float gyro_biasZ_tmp;
float* accOffX, *accOffY, *accOffZ, *gyrOffX, *gyrOffY, *gyrOffZ;
	mpu_select(1);
acc_biasX_tmp=0;
acc_biasY_tmp=0;
acc_biasZ_tmp=0;
gyro_biasX_tmp=0;
gyro_biasY_tmp=0;
gyro_biasZ_tmp=0;
	accOffX=&acc1_bias[0];
	accOffY=&acc1_bias[1];
	accOffZ=&acc1_bias[2];
	gyrOffX=&gyr1_bias[0];
	gyrOffY=&gyr1_bias[1];
	gyrOffZ=&gyr1_bias[2];
uint8_t c=readByte(MPU9250_ADDRESS, GYRO_CONFIG);
uint8_t d=readByte(MPU9250_ADDRESS, CONFIG);
uint8_t f=readByte(MPU9250_ADDRESS, SMPLRT_DIV);
uint8_t e=readByte(MPU9250_ADDRESS, ACCEL_CONFIG);
uint8_t z=readByte(MPU9250_ADDRESS, ACCEL_CONFIG2);
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, 0x00);
writeByte(MPU9250_ADDRESS, CONFIG, 0x04);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, 0x00);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, 0x04);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, 0x19);
for (int i=0;i<numSamp;i++)
{
accRead();
gyrRead();
gyro_biasX_tmp+=rawGyro[0]*250.0f/32768.0f;
gyro_biasY_tmp+=rawGyro[1]*250.0f/32768.0f;
gyro_biasZ_tmp+=rawGyro[2]*250.0f/32768.0f;
acc_biasX_tmp+=rawAcc[0]*2.0f/32768.0f;
acc_biasY_tmp+=rawAcc[1]*2.0f/32768.0f;
acc_biasZ_tmp+=rawAcc[2]*2.0f/32768.0f;
Serial.print("gyro_bias MPU1");
Serial.print(", ");
Serial.print(gyro_biasX_tmp);
Serial.print(", ");
Serial.print(gyro_biasY_tmp);
Serial.print(", ");
Serial.println(gyro_biasZ_tmp);
delay(20);
}
acc_biasX_tmp/=numSamp;
acc_biasY_tmp/=numSamp;
acc_biasZ_tmp/=numSamp;
gyro_biasX_tmp/=numSamp;
gyro_biasY_tmp/=numSamp;
gyro_biasZ_tmp/=numSamp;
if (acc_biasZ_tmp<0){acc_biasZ_tmp+=g;}else{acc_biasZ_tmp-=g;}
*accOffX=acc_biasX_tmp;
*accOffY=acc_biasY_tmp;
*accOffZ=acc_biasZ_tmp;
*gyrOffX=gyro_biasX_tmp;
*gyrOffY=gyro_biasY_tmp;
*gyrOffZ=gyro_biasZ_tmp;
acc_biasX_tmp=0;
acc_biasY_tmp=0;
acc_biasZ_tmp=0;
gyro_biasX_tmp=0;
gyro_biasY_tmp=0;
gyro_biasZ_tmp=0;
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, c);
writeByte(MPU9250_ADDRESS, CONFIG, d);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, e);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, z);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, f);
Serial.println("MPU1::Accel - Gyro Calibrated");	

	mpu_select(2);
	delay(100);
	accOffX=&acc2_bias[0];
	accOffY=&acc2_bias[1];
	accOffZ=&acc2_bias[2];
	gyrOffX=&gyr2_bias[0];
	gyrOffY=&gyr2_bias[1];
	gyrOffZ=&gyr2_bias[2];
c=readByte(MPU9250_ADDRESS, GYRO_CONFIG);
d=readByte(MPU9250_ADDRESS, CONFIG);
f=readByte(MPU9250_ADDRESS, SMPLRT_DIV);
e=readByte(MPU9250_ADDRESS, ACCEL_CONFIG);
z=readByte(MPU9250_ADDRESS, ACCEL_CONFIG2);
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, 0x00);
writeByte(MPU9250_ADDRESS, CONFIG, 0x04);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, 0x00);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, 0x04);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, 0x19);
for (int i=0;i<numSamp;i++)
{
accRead();
gyrRead();
gyro_biasX_tmp+=rawGyro[0]*250.0f/32768.0f;
gyro_biasY_tmp+=rawGyro[1]*250.0f/32768.0f;
gyro_biasZ_tmp+=rawGyro[2]*250.0f/32768.0f;
acc_biasX_tmp+=rawAcc[0]*2.0f/32768.0f;
acc_biasY_tmp+=rawAcc[1]*2.0f/32768.0f;
acc_biasZ_tmp+=rawAcc[2]*2.0f/32768.0f;
Serial.print("acc_bias MPU2");
Serial.print(", ");
Serial.print(acc_biasX_tmp);
Serial.print(", ");
Serial.print(acc_biasY_tmp);
Serial.print(", ");
Serial.println(acc_biasZ_tmp);
delay(20);
}
acc_biasX_tmp/=numSamp;
acc_biasY_tmp/=numSamp;
acc_biasZ_tmp/=numSamp;
gyro_biasX_tmp/=numSamp;
gyro_biasY_tmp/=numSamp;
gyro_biasZ_tmp/=numSamp;
if (acc_biasZ_tmp<0){acc_biasZ_tmp+=g;}else{acc_biasZ_tmp-=g;}
*accOffX=acc_biasX_tmp;
*accOffY=acc_biasY_tmp;
*accOffZ=acc_biasZ_tmp;
*gyrOffX=gyro_biasX_tmp;
*gyrOffY=gyro_biasY_tmp;
*gyrOffZ=gyro_biasZ_tmp;
acc_biasX_tmp=0;
acc_biasY_tmp=0;
acc_biasZ_tmp=0;
gyro_biasX_tmp=0;
gyro_biasY_tmp=0;
gyro_biasZ_tmp=0;
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, c);
writeByte(MPU9250_ADDRESS, CONFIG, d);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, e);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, z);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, f);
Serial.println("MPU2::Accel - Gyro Calibrated");	

	mpu_select(3);
	delay(100);
	accOffX=&acc3_bias[0];
	accOffY=&acc3_bias[1];
	accOffZ=&acc3_bias[2];
	gyrOffX=&gyr3_bias[0];
	gyrOffY=&gyr3_bias[1];
	gyrOffZ=&gyr3_bias[2];
c=readByte(MPU9250_ADDRESS, GYRO_CONFIG);
d=readByte(MPU9250_ADDRESS, CONFIG);
f=readByte(MPU9250_ADDRESS, SMPLRT_DIV);
e=readByte(MPU9250_ADDRESS, ACCEL_CONFIG);
z=readByte(MPU9250_ADDRESS, ACCEL_CONFIG2);
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, 0x00);
writeByte(MPU9250_ADDRESS, CONFIG, 0x04);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, 0x00);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, 0x04);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, 0x19);
for (int i=0;i<numSamp;i++)
{
accRead();
gyrRead();
gyro_biasX_tmp+=rawGyro[0]*250.0f/32768.0f;
gyro_biasY_tmp+=rawGyro[1]*250.0f/32768.0f;
gyro_biasZ_tmp+=rawGyro[2]*250.0f/32768.0f;
acc_biasX_tmp+=rawAcc[0]*2.0f/32768.0f;
acc_biasY_tmp+=rawAcc[1]*2.0f/32768.0f;
acc_biasZ_tmp+=rawAcc[2]*2.0f/32768.0f;
Serial.print("acc_bias MPU3");
Serial.print(", ");
Serial.print(acc_biasX_tmp);
Serial.print(", ");
Serial.print(acc_biasY_tmp);
Serial.print(", ");
Serial.println(acc_biasZ_tmp);
delay(20);
}
acc_biasX_tmp/=numSamp;
acc_biasY_tmp/=numSamp;
acc_biasZ_tmp/=numSamp;
gyro_biasX_tmp/=numSamp;
gyro_biasY_tmp/=numSamp;
gyro_biasZ_tmp/=numSamp;
if (acc_biasZ_tmp<0){acc_biasZ_tmp+=g;}else{acc_biasZ_tmp-=g;}
*accOffX=acc_biasX_tmp;
*accOffY=acc_biasY_tmp;
*accOffZ=acc_biasZ_tmp;
*gyrOffX=gyro_biasX_tmp;
*gyrOffY=gyro_biasY_tmp;
*gyrOffZ=gyro_biasZ_tmp;
acc_biasX_tmp=0;
acc_biasY_tmp=0;
acc_biasZ_tmp=0;
gyro_biasX_tmp=0;
gyro_biasY_tmp=0;
gyro_biasZ_tmp=0;
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, c);
writeByte(MPU9250_ADDRESS, CONFIG, d);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, e);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, z);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, f);
Serial.println("MPU3::Accel - Gyro Calibrated");	

	mpu_select(4);
	delay(100);
	accOffX=&acc4_bias[0];
	accOffY=&acc4_bias[1];
	accOffZ=&acc4_bias[2];
	gyrOffX=&gyr4_bias[0];
	gyrOffY=&gyr4_bias[1];
	gyrOffZ=&gyr4_bias[2];
c=readByte(MPU9250_ADDRESS, GYRO_CONFIG);
d=readByte(MPU9250_ADDRESS, CONFIG);
f=readByte(MPU9250_ADDRESS, SMPLRT_DIV);
e=readByte(MPU9250_ADDRESS, ACCEL_CONFIG);
z=readByte(MPU9250_ADDRESS, ACCEL_CONFIG2);
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, 0x00);
writeByte(MPU9250_ADDRESS, CONFIG, 0x04);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, 0x00);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, 0x04);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, 0x19);
for (int i=0;i<numSamp;i++)
{
accRead();
gyrRead();
gyro_biasX_tmp+=rawGyro[0]*250.0f/32768.0f;
gyro_biasY_tmp+=rawGyro[1]*250.0f/32768.0f;
gyro_biasZ_tmp+=rawGyro[2]*250.0f/32768.0f;
acc_biasX_tmp+=rawAcc[0]*2.0f/32768.0f;
acc_biasY_tmp+=rawAcc[1]*2.0f/32768.0f;
acc_biasZ_tmp+=rawAcc[2]*2.0f/32768.0f;
Serial.print("acc_bias MPU4");
Serial.print(", ");
Serial.print(acc_biasX_tmp);
Serial.print(", ");
Serial.print(acc_biasY_tmp);
Serial.print(", ");
Serial.println(acc_biasZ_tmp);
delay(20);
}
acc_biasX_tmp/=numSamp;
acc_biasY_tmp/=numSamp;
acc_biasZ_tmp/=numSamp;
gyro_biasX_tmp/=numSamp;
gyro_biasY_tmp/=numSamp;
gyro_biasZ_tmp/=numSamp;
if (acc_biasZ_tmp<0){acc_biasZ_tmp+=g;}else{acc_biasZ_tmp-=g;}
*accOffX=acc_biasX_tmp;
*accOffY=acc_biasY_tmp;
*accOffZ=acc_biasZ_tmp;
*gyrOffX=gyro_biasX_tmp;
*gyrOffY=gyro_biasY_tmp;
*gyrOffZ=gyro_biasZ_tmp;
acc_biasX_tmp=0;
acc_biasY_tmp=0;
acc_biasZ_tmp=0;
gyro_biasX_tmp=0;
gyro_biasY_tmp=0;
gyro_biasZ_tmp=0;
writeByte(MPU9250_ADDRESS, GYRO_CONFIG, c);
writeByte(MPU9250_ADDRESS, CONFIG, d);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG, e);
writeByte(MPU9250_ADDRESS, ACCEL_CONFIG2, z);
writeByte(MPU9250_ADDRESS, SMPLRT_DIV, f);
Serial.println("MPU4::Accel - Gyro Calibrated");	
}

void multiplempulib::calibrateMag()
{
 
 int16_t count = 50;
 float ave_center;
 int16_t magCenter[3]={0,0,0};
 int16_t mag_max[3]={-32767,-32767,-32767};
 int16_t mag_min[3]={32767,32767,32767};   
 
 float *magbiasX;
 float *magbiasY;
 float *magbiasZ;
 float *magSoftX;
 float *magSoftY;
 float *magSoftZ;
 mpu_select(1);
 uint8_t c=readByte(MPU9250_ADDRESS, SMPLRT_DIV);
 writeByte(MPU9250_ADDRESS, SMPLRT_DIV, 0x19);
 Serial.println("8-motion for magnetometer calibration MPU1");   
 delay(2000);
 for (int i=0;i<count;i++)
  {
    magRead();
Serial.print("Raw Magnetometer Readings for MPU1 [X Y Z] =  ");
Serial.print(rawMag[0]);
Serial.print(", ");
Serial.print(rawMag[1]);
Serial.print(", ");
Serial.println(rawMag[2]);
for (int j=0;j<3;j++)
    {
      if (rawMag[j]>mag_max[j])
      {mag_max[j]=rawMag[j];}
      else
      {mag_min[j]=rawMag[j];}
    }  
    delay(12);   
  }
  writeByte(MPU9250_ADDRESS, SMPLRT_DIV, c);
  magbiasX=&magBias1[0];
  magbiasY=&magBias1[1];
  magbiasZ=&magBias1[2];
  magSoftX=&magSoft1[0];
  magSoftY=&magSoft1[1];
  magSoftZ=&magSoft1[2];
  *magbiasX=(float)(mag_max[0]+mag_min[0])*magSens1[0]/2.0f;
  *magbiasY=(float)(mag_max[1]+mag_min[1])*magSens1[1]/2.0f;
  *magbiasZ=(float)(mag_max[2]+mag_min[2])*magSens1[2]/2.0f;
  //////Soft Iron Calibration
  magCenter[0]=(mag_max[0]-mag_min[0])/2;
  magCenter[1]=(mag_max[1]-mag_min[1])/2;
  magCenter[2]=(mag_max[2]-mag_min[2])/2;
  ave_center=magCenter[0]+magCenter[1]+magCenter[2];
  ave_center/=3.0f;
  *magSoftX=(float)ave_center/magCenter[0];
  *magSoftY=(float)ave_center/magCenter[1];
  *magSoftZ=(float)ave_center/magCenter[2];

  mpu_select(2);
  delay(1);
  mag_min[0]=32767;
  mag_min[1]=32767;
  mag_min[2]=32767;
  mag_max[0]=-32767;
  mag_max[1]=-32767;
  mag_max[2]=-32767;
  magCenter[0]=0;
  magCenter[1]=0;
  magCenter[2]=0;
  ave_center=0;
 c = readByte(MPU9250_ADDRESS, SMPLRT_DIV);
 writeByte(MPU9250_ADDRESS, SMPLRT_DIV, 0x19);
 Serial.println("8-motion for magnetometer calibration for MPU2");   
 delay(2000);
 for (int i=0;i<count;i++)
  {
magRead();
Serial.print("Raw Magnetometer Readings for MPU2 [X Y Z] =  ");
Serial.print(rawMag[0]);
Serial.print(", ");
Serial.print(rawMag[1]);
Serial.print(", ");
Serial.println(rawMag[2]);
for (int j=0;j<3;j++)
    {
      if (rawMag[j]>mag_max[j])
      {mag_max[j]=rawMag[j];}
      else
      {mag_min[j]=rawMag[j];}
    }  
    delay(12);   
  }
  writeByte(MPU9250_ADDRESS, SMPLRT_DIV, c);
  magbiasX=&magBias2[0];
  magbiasY=&magBias2[1];
  magbiasZ=&magBias2[2];
  magSoftX=&magSoft2[0];
  magSoftY=&magSoft2[1];
  magSoftZ=&magSoft2[2];
  *magbiasX=(float)(mag_max[0]+mag_min[0])*magSens2[0]/2.0f;
  *magbiasY=(float)(mag_max[1]+mag_min[1])*magSens2[1]/2.0f;
  *magbiasZ=(float)(mag_max[2]+mag_min[2])*magSens2[2]/2.0f;
  //////Soft Iron Calibration
  magCenter[0]=(mag_max[0]-mag_min[0])/2;
  magCenter[1]=(mag_max[1]-mag_min[1])/2;
  magCenter[2]=(mag_max[2]-mag_min[2])/2;
  ave_center=magCenter[0]+magCenter[1]+magCenter[2];
  ave_center/=3.0f;
  *magSoftX=(float)ave_center/magCenter[0];
  *magSoftY=(float)ave_center/magCenter[1];
  *magSoftZ=(float)ave_center/magCenter[2];

 mpu_select(3);
  delay(1);
  mag_min[0]=32767;
  mag_min[1]=32767;
  mag_min[2]=32767;
  mag_max[0]=-32767;
  mag_max[1]=-32767;
  mag_max[2]=-32767;
  magCenter[0]=0;
  magCenter[1]=0;
  magCenter[2]=0;
  ave_center=0;
  ave_center=0;
 c = readByte(MPU9250_ADDRESS, SMPLRT_DIV);
 writeByte(MPU9250_ADDRESS, SMPLRT_DIV, 0x19);
 Serial.println("8-motion for magnetometer calibration for MPU3");   
 delay(2000);
 for (int i=0;i<count;i++)
  {
magRead();
Serial.print("Raw Magnetometer Readings for MPU3 [X Y Z] =  ");
Serial.print(rawMag[0]);
Serial.print(", ");
Serial.print(rawMag[1]);
Serial.print(", ");
Serial.println(rawMag[2]);
for (int j=0;j<3;j++)
    {
      if (rawMag[j]>mag_max[j])
      {mag_max[j]=rawMag[j];}
      else
      {mag_min[j]=rawMag[j];}
    }  
    delay(12);   
  }
  writeByte(MPU9250_ADDRESS, SMPLRT_DIV, c);
  magbiasX=&magBias3[0];
  magbiasY=&magBias3[1];
  magbiasZ=&magBias3[2];
  magSoftX=&magSoft3[0];
  magSoftY=&magSoft3[1];
  magSoftZ=&magSoft3[2];
  *magbiasX=(float)(mag_max[0]+mag_min[0])*magSens3[0]/2.0f;
  *magbiasY=(float)(mag_max[1]+mag_min[1])*magSens3[1]/2.0f;
  *magbiasZ=(float)(mag_max[2]+mag_min[2])*magSens3[2]/2.0f;
  //////Soft Iron Calibration
  magCenter[0]=(mag_max[0]-mag_min[0])/2;
  magCenter[1]=(mag_max[1]-mag_min[1])/2;
  magCenter[2]=(mag_max[2]-mag_min[2])/2;
  ave_center=magCenter[0]+magCenter[1]+magCenter[2];
  ave_center/=3.0f;
  *magSoftX=(float)ave_center/magCenter[0];
  *magSoftY=(float)ave_center/magCenter[1];
  *magSoftZ=(float)ave_center/magCenter[2];
  
  mpu_select(4);
  delay(1);
  mag_min[0]=32767;
  mag_min[1]=32767;
  mag_min[2]=32767;
  mag_max[0]=-32767;
  mag_max[1]=-32767;
  mag_max[2]=-32767;
  magCenter[0]=0;
  magCenter[1]=0;
  magCenter[2]=0;
  ave_center=0;
  ave_center=0;
 c = readByte(MPU9250_ADDRESS, SMPLRT_DIV);
 writeByte(MPU9250_ADDRESS, SMPLRT_DIV, 0x19);
 Serial.println("8-motion for magnetometer calibration for MPU4");   
 delay(2000);
 for (int i=0;i<count;i++)
  {
magRead();
Serial.print("Raw Magnetometer Readings for MPU4 [X Y Z] =  ");
Serial.print(rawMag[0]);
Serial.print(", ");
Serial.print(rawMag[1]);
Serial.print(", ");
Serial.println(rawMag[2]);
for (int j=0;j<3;j++)
    {
      if (rawMag[j]>mag_max[j])
      {mag_max[j]=rawMag[j];}
      else
      {mag_min[j]=rawMag[j];}
    }  
    delay(12);   
  }
  writeByte(MPU9250_ADDRESS, SMPLRT_DIV, c);
  magbiasX=&magBias4[0];
  magbiasY=&magBias4[1];
  magbiasZ=&magBias4[2];
  magSoftX=&magSoft4[0];
  magSoftY=&magSoft4[1];
  magSoftZ=&magSoft4[2];
  *magbiasX=(float)(mag_max[0]+mag_min[0])*magSens4[0]/2.0f;
  *magbiasY=(float)(mag_max[1]+mag_min[1])*magSens4[1]/2.0f;
  *magbiasZ=(float)(mag_max[2]+mag_min[2])*magSens4[2]/2.0f;
  //////Soft Iron Calibration
  magCenter[0]=(mag_max[0]-mag_min[0])/2;
  magCenter[1]=(mag_max[1]-mag_min[1])/2;
  magCenter[2]=(mag_max[2]-mag_min[2])/2;
  ave_center=magCenter[0]+magCenter[1]+magCenter[2];
  ave_center/=3.0f;
  *magSoftX=(float)ave_center/magCenter[0];
  *magSoftY=(float)ave_center/magCenter[1];
  *magSoftZ=(float)ave_center/magCenter[2]; 
}

void multiplempulib::accRead()
{
float *rawAccelX;
float *rawAccelY;
float *rawAccelZ;
rawAccelX=&rawAcc[0];
rawAccelY=&rawAcc[1];
rawAccelZ=&rawAcc[2];

uint8_t rawData[6];
int16_t dest[3];
rawData[0]=readByte(MPU9250_ADDRESS, ACCEL_XOUT_H);
rawData[1]=readByte(MPU9250_ADDRESS, ACCEL_XOUT_L);
rawData[2]=readByte(MPU9250_ADDRESS, ACCEL_YOUT_H);
rawData[3]=readByte(MPU9250_ADDRESS, ACCEL_YOUT_L);
rawData[4]=readByte(MPU9250_ADDRESS, ACCEL_ZOUT_H);
rawData[5]=readByte(MPU9250_ADDRESS, ACCEL_ZOUT_L);
//readBytes(MPU9250_ADDRESS, ACCEL_XOUT_H, 6, &rawData[0]);
dest[0]= ((int16_t) rawData[0])<<8|rawData[1];
dest[1]= ((int16_t) rawData[2]<<8)|rawData[3];
dest[2]= ((int16_t) rawData[4]<<8)|rawData[5];
*rawAccelX=(float)dest[0];
*rawAccelY=(float)dest[1];
*rawAccelZ=(float)dest[2];
}

void multiplempulib::gyrRead()
{
uint8_t rawData[6];
int16_t dest[3];
float *rawGyroX;
float *rawGyroY;
float *rawGyroZ;
rawGyroX=&rawGyro[0];
rawGyroY=&rawGyro[1];
rawGyroZ=&rawGyro[2];
rawData[0]=readByte(MPU9250_ADDRESS, GYRO_XOUT_H);
rawData[1]=readByte(MPU9250_ADDRESS, GYRO_XOUT_L);
rawData[2]=readByte(MPU9250_ADDRESS, GYRO_YOUT_H);
rawData[3]=readByte(MPU9250_ADDRESS, GYRO_YOUT_L);
rawData[4]=readByte(MPU9250_ADDRESS, GYRO_ZOUT_H);
rawData[5]=readByte(MPU9250_ADDRESS, GYRO_ZOUT_L);
dest[0]=(int16_t) rawData[0]<<8|rawData[1];
dest[1]=(int16_t) rawData[2]<<8|rawData[3];
dest[2]=(int16_t) rawData[4]<<8|rawData[5];
*rawGyroX=(float)dest[0];
*rawGyroY=(float)dest[1];
*rawGyroZ=(float)dest[2];
}

void multiplempulib::magRead()
{
 uint8_t rawData[7];
 int16_t dest[3];
 float *rawMagX;
 float *rawMagY;
 float *rawMagZ;
 rawMagX=&rawMag[0];
 rawMagY=&rawMag[1];
 rawMagZ=&rawMag[2];
 uint8_t c=readByte(AK8963_ADDRESS, AK8963_ST1);
 c=c&0x01;
  if(c=0x01)
  {
rawData[0]=readByte(AK8963_ADDRESS, AK8963_XOUT_L);
rawData[1]=readByte(AK8963_ADDRESS, AK8963_XOUT_H);
rawData[2]=readByte(AK8963_ADDRESS, AK8963_YOUT_L);
rawData[3]=readByte(AK8963_ADDRESS, AK8963_YOUT_H);
rawData[4]=readByte(AK8963_ADDRESS, AK8963_ZOUT_L);
rawData[5]=readByte(AK8963_ADDRESS, AK8963_ZOUT_H);
rawData[6]=readByte(AK8963_ADDRESS, AK8963_ST2);
//readBytes(AK8963_ADDRESS, AK8963_XOUT_L,7, &rawData[0]);  
   rawData[6]=rawData[6] & 0x18;
    if(rawData[6]=0x10)
    {
     dest[0]=((int16_t) rawData[1]<<8)|rawData[0];
     dest[1]=((int16_t) rawData[3]<<8)|rawData[2];
     dest[2]=((int16_t) rawData[5]<<8)|rawData[4];
    }
  }
*rawMagX=dest[0];
*rawMagY=dest[1];
*rawMagZ=dest[2];
}

uint8_t multiplempulib::readByte(uint8_t address, uint8_t subAddress)
{
  uint8_t tmp;                            // `data` will store the register data   
  Wire.beginTransmission(address);         // Initialize the Tx buffer
  Wire.write(subAddress);                  // Put slave register address in Tx buffer
  Wire.endTransmission(false);             // Send the Tx buffer, but send a restart to keep connection alive
  Wire.requestFrom(address, 1);            // Read one byte from slave register address 
  tmp = Wire.read();                      // Fill Rx buffer with result
  return tmp;    
}


void multiplempulib::writeByte(uint8_t address, uint8_t subAddress, uint8_t data) 
{
  Wire.beginTransmission(address);  // Initialize the Tx buffer
  Wire.write(subAddress);           // Put slave register address in Tx buffer
  Wire.write(data);                 // Put data in Tx buffer
  Wire.endTransmission();
}

void multiplempulib::mpu_select(uint8_t bus)
{
Wire.beginTransmission(0x70);
Wire.write(1<<bus-1);
Wire.endTransmission();
}

/*
Initiate and calibration procedures are done. now return method for obtaining acc - gyr - mag readings will be implemented 
by using their own calculated biases and mag sensitivity.
*/

float multiplempulib::accX1()
{
return -(rawAcc[1]*accelScale- acc1_bias[1]);
}
float multiplempulib::accY1()
{
return -(rawAcc[0]*accelScale- acc1_bias[0]);
}
float multiplempulib::accZ1()
{
return (rawAcc[2]*accelScale- acc1_bias[2]);
}

float multiplempulib::gyroX1()
{
return -(rawGyro[1]*gyroScale- gyr1_bias[1])*PI/180.0f;
}
float multiplempulib::gyroY1()
{
return -(rawGyro[0]*gyroScale- gyr1_bias[0])*PI/180.0f;
}
float multiplempulib::gyroZ1()
{
return (rawGyro[2]*gyroScale- gyr1_bias[2])*PI/180.0f;
}

float multiplempulib::magX1()
{
return (rawMag[1]*magSens1[1]-magBias1[1])*magSoft1[1];  
}
float multiplempulib::magY1()
{
return -(rawMag[0]*magSens1[0]-magBias1[0])*magSoft1[0];  
}
float multiplempulib::magZ1()
{
return (rawMag[2]*magSens1[2]-magBias1[2])*magSoft1[2];  
}


float multiplempulib::accX2()
{
return (rawAcc[0]*accelScale- acc2_bias[0]);
}
float multiplempulib::accY2()
{
return (rawAcc[1]*accelScale- acc2_bias[1]);
}
float multiplempulib::accZ2()
{
return rawAcc[2]*accelScale- acc2_bias[2];
}

float multiplempulib::gyroX2()
{
return rawGyro[0]*gyroScale- gyr2_bias[0];
}
float multiplempulib::gyroY2()
{
return (rawGyro[1]*gyroScale- gyr2_bias[1]);
}
float multiplempulib::gyroZ2()
{
return (rawGyro[2]*gyroScale- gyr2_bias[2]);
}

float multiplempulib::magX2()
{
return (rawMag[1]*magSens2[1]-magBias2[1])*magSoft2[1];  
}
float multiplempulib::magY2()
{
return -(rawMag[0]*magSens2[0]-magBias2[0])*magSoft2[0];  
}
float multiplempulib::magZ2()
{
return (rawMag[2]*magSens2[2]-magBias2[2])*magSoft2[2];  
}

float multiplempulib::accX3()
{
return (rawAcc[0]*accelScale- acc3_bias[0]);
}
float multiplempulib::accY3()
{
return rawAcc[1]*accelScale- acc3_bias[1];
}
float multiplempulib::accZ3()
{
return rawAcc[2]*accelScale- acc3_bias[2];
}

float multiplempulib::gyroX3()
{
return rawGyro[0]*gyroScale- gyr3_bias[0];
}
float multiplempulib::gyroY3()
{
return (rawGyro[1]*gyroScale- gyr3_bias[1]);
}
float multiplempulib::gyroZ3()
{
return (rawGyro[2]*gyroScale- gyr3_bias[2]);
}

float multiplempulib::magX3()
{
return (rawMag[1]*magSens3[1]-magBias3[1])*magSoft3[1];  
}
float multiplempulib::magY3()
{
return -(rawMag[0]*magSens3[0]-magBias2[0])*magSoft3[0];  
}
float multiplempulib::magZ3()
{
return (rawMag[2]*magSens3[2]-magBias3[2])*magSoft3[2];  
}

float multiplempulib::accX4()
{
return (rawAcc[0]*accelScale- acc4_bias[0]);
}
float multiplempulib::accY4()
{
return rawAcc[1]*accelScale- acc4_bias[1];
}
float multiplempulib::accZ4()
{
return rawAcc[2]*accelScale- acc4_bias[2];
}

float multiplempulib::gyroX4()
{
return rawGyro[0]*gyroScale- gyr4_bias[0];
}
float multiplempulib::gyroY4()
{
return (rawGyro[1]*gyroScale- gyr4_bias[1]);
}
float multiplempulib::gyroZ4()
{
return (rawGyro[2]*gyroScale- gyr4_bias[2]);
}

float multiplempulib::magX4()
{
return (rawMag[1]*magSens4[1]-magBias4[1])*magSoft4[1];  
}
float multiplempulib::magY4()
{
return -(rawMag[0]*magSens4[0]-magBias4[0])*magSoft4[0];  
}
float multiplempulib::magZ4()
{
return (rawMag[2]*magSens4[2]-magBias4[2])*magSoft4[2];  
}


void multiplempulib::madgwickUpdate(float ax, float ay, float az,
 float gx, float gy, float gz,
 float mx, float my, float mz,
 float &q1, float &q2, float &q3, float &q4)
{
float norm, hx, hy, s1, s2, s3, s4, _2bx, _2bz, dt, tnow;  
dt=0.005;
norm=(float)sqrt(ax*ax+ay*ay+az*az);
ax/=norm;
ay/=norm;
az/=norm; 
norm =(float) sqrt(mx*mx+my*my+mz*mz);
mx/=norm;
my/=norm;
mz/=norm;
hx=mx*q1*q1-2.0f*q1*my*q4+2.0f*q1*mz*q3+mx*q2*q2+2.0f*q2*my*q3+2.0f*q2*mz*q4-mx*q3*q3-mx*q4*q4;
hy=2.0f*q1*mx*q4+my*q1*q1-2.0f*q1*mz*q2+2.0f*q2*mx*q3-my*q2*q2+my*q3*q3+2.0f*q3*mz*q4-my*q4*q4;
_2bx=(float)sqrt(hx*hx+hy*hy);
_2bz = -2.0f*q1*mx*q3+2.0f*q1*my*q2+mz*q1*q1+2.0f*q2*mx*q4-mz*q2*q2+2.0f*q3*my*q4-mz*q3*q3+mz*q4*q4;
s1 = -2.0f*q3*(2.0f*q2*q4-2.0f*q1*q3-ax)+2.0f*q2*(2.0f*q1*q2+2.0f*q3*q4-ay)-_2bz*q3*(_2bx*(0.5f-q3*q3-q4*q4)+_2bz*(q2*q4-q1*q3)-mx)+(-_2bx*q4+_2bz*q2)*(_2bx*(q2*q3-q1*q4)+_2bz*(q1*q2+q3*q4)-my)+_2bx*q3*(_2bx*(q1*q3+q2*q4)+_2bz*(0.5f-q2*q2-q3*q3)-mz);
s2 = 2.0f*q4*(2.0f*q2*q4-2.0f*q1*q3-ax)+2.0f*q1*(2.0f*q1*q2+2.0f*q3*q4-ay)-4.0f*q2*(1.0f-2.0f*q2*q2-2.0f*q3*q3-az)+_2bz*q4*(_2bx*(0.5f-q3*q3-q4*q4)+_2bz*(q2*q4-q1*q3)-mx)+(_2bx*q3+_2bz*q1)*(_2bx*(q2*q3-q1*q4)+_2bz*(q1*q2+q3*q4)-my)+(_2bx*q4-2.0f*_2bz*q2)*(_2bx*(q1*q3+q2*q4)+_2bz*(0.5f-q2*q2-q3*q3)-mz);
s3 = -2.0f*q1*(2.0f*q2*q4-2.0f*q1*q3-ax)+2.0f*q4*(2.0f*q1*q2+2.0f*q3*q4-ay)-4.0f*q3*(1.0f-2.0f*q2*q2-2.0f*q3*q3-az)+(-2.0f*_2bx*q3-_2bz*q1)*(_2bx*(0.5f-q3*q3-q4*q4)+_2bz*(q2*q4-q1*q3)-mx)+(_2bx*q2+_2bz*q4)*(_2bx*(q2*q3-q1*q4)+_2bz*(q1*q2+q3*q4)-my)+(_2bx*q1-2.0f*_2bz*q3)*(_2bx*(q1*q3+q2*q4)+_2bz*(0.5f-q2*q2-q3*q3)-mz);
s4 = 2.0f*q2*(2.0f*q2*q4-2.0f*q1*q3-ax)+2.0f*q3*(2.0f*q1*q2+2.0f*q3*q4-ay)+(-2.0f*_2bx*q4+_2bz*q2)*(_2bx*(0.5f-q3*q3-q4*q4)+_2bz*(q2*q4-q1*q3)-mx)+(-_2bx*q1+_2bz*q3)*(_2bx*(q2*q3-q1*q4)+_2bz*(q1*q2+q3*q4)-my)+_2bx*q2*(_2bx*(q1*q3+q2*q4)+_2bz*(0.5f-q2*q2-q3*q3)-mz);
norm =(float) sqrt(s1 * s1 + s2 * s2 + s3 * s3 + s4 * s4);
s1 /= norm;
s2 /= norm;
s3 /= norm;
s4 /= norm;
q1+=(float)(0.5f*(-q2*gx-q3*gy-q4*gz)-beta*s1)*dt;
q2+=(float)(0.5f*(q1*gx+q3*gz-q4*gy)-beta*s1)*dt;
q3+=(float)(0.5f*(q1*gy-q2*gz+q4*gx)-beta*s3)*dt;
q4+=(float)(0.5f*(q1*gz+q2*gy-q3*gx)-beta*s4)*dt;
norm=(float)sqrt(q1*q1+q2*q2+q3*q3+q4*q4);
q1/=norm;
q2/=norm;
q3/=norm;
q4/=norm;
}



void multiplempulib::imu_update(float acx, float acy, float acz,
                                float wx, float wy, float wz,
                                float &q0, float &q1, float &q2, float &q3)
{
  float recipNorm;
  float s0, s1, s2, s3, dt;
  float qDot1, qDot2, qDot3, qDot4;
  float _2q0, _2q1, _2q2, _2q3, _4q0, _4q1, _4q2 ,_8q1, _8q2, q0q0, q1q1, q2q2, q3q3;
  float tnow;
  tnow=micros();
  dt=(tnow-told)/1000000.0f;
  told=tnow;
  if(initialized){

  qDot1 = 0.5f *(-q1 * wx - q2 * wy - q3 * wz);
  qDot2 = 0.5f * (q0 * wx + q2 * wz - q3 * wy);
  qDot3 = 0.5f * (q0 * wy - q1 * wz + q3 * wx);
  qDot4 = 0.5f * (q0 * wz + q1 * wy - q2 * wx);
  _2q0 = 2.0f * q0;
  _2q1 = 2.0f * q1;
  _2q2 = 2.0f * q2;
  _2q3 = 2.0f * q3;
  _4q0 = 4.0f * q0;
  _4q1 = 4.0f * q1;
  _4q2 = 4.0f * q2;
  _8q1 = 8.0f * q1;
  _8q2 = 8.0f * q2;
   q0q0 = q0 * q0;
   q1q1 = q1 * q1;
   q2q2 = q2 * q2;
   q3q3 = q3 * q3;
   recipNorm=sqrt(acx*acx+acy*acy+acz*acz);
   acx /= recipNorm;
   acy /= recipNorm;
   acz /= recipNorm;
   s0 = _4q0 * q2q2 + _2q2 * acx + _4q0 * q1q1 - _2q1 * acy;
   s1 = _4q1 * q3q3 - _2q3 * acx + 4.0f * q0q0 * q1 - _2q0 * acy - _4q1 + _8q1 * q1q1 + _8q1 * q2q2 + _4q1 * acz;
   s2 = 4.0f * q0q0 * q2 + _2q0 * acx + _4q2 * q3q3 - _2q3 * acy - _4q2 + _8q2 * q1q1 + _8q2 * q2q2 + _4q2 * acz;
   s3 = 4.0f * q1q1 * q3 - _2q1 * acx + 4.0f * q2q2 * q3 - _2q2 * acy;
   recipNorm = sqrt(s0 * s0 + s1 * s1 + s2 * s2 + s3 * s3); // normalise step magnitude
   s0 /= recipNorm;
   s1 /= recipNorm;
   s2 /= recipNorm;
   s3 /= recipNorm;
   qDot1 -= beta * s0;
   qDot2 -= beta * s1;
   qDot3 -= beta * s2;
   qDot4 -= beta * s3;
   q0 += qDot1 * dt;
   q1 += qDot2 * dt;
   q2 += qDot3 * dt;
   q3 += qDot4 * dt;
   recipNorm = sqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
   q0 /= recipNorm;
   q1 /= recipNorm;
   q2 /= recipNorm;
   q3 /= recipNorm;
  }
}

void multiplempulib::getEuler(float q_or0, float q_or1, float q_or2, float q_or3)
{ 
float *yaw, *pitch, *roll;
yaw=&Yaw;
pitch=&Pitch;
roll=&Roll;
*yaw   =atan2(2.0f*(q_or1*q_or2+q_or0*q_or3), q_or0*q_or0+q_or1*q_or1-q_or2*q_or2-q_or3*q_or3)*(180.0f/PI);
*pitch =-asin(2.0f*(q_or1*q_or3-q_or0*q_or2))*(180.0f/PI);
*roll  =atan2(2.0f*(q_or0*q_or1+q_or2*q_or3), q_or0*q_or0-q_or1*q_or1-q_or2*q_or2+q_or3*q_or3)*(180.0f/PI);
Serial.print(Roll);
Serial.print(", ");
Serial.print(Pitch);
Serial.print(", ");
Serial.println(Yaw);
}

void multiplempulib::MVA(float ax, float ay, float az, float gx, float gy, float gz, 
float* readingBuffer0, float* readingBuffer1, float* readingBuffer2, 
float* readingBuffer3, float* readingBuffer4, float* readingBuffer5)
{
float scalar1=1.0f/10.0f;
float scalar2=1.0f-scalar1;
  if (scalar2==0.0f){ 
  initialized= true;
  return;}
  if(first_sample)
   {
    allready+=2;
    if (allready>3)
    first_sample = false;
    return;
   }
     initialized= true;
    *readingBuffer0= (ax*scalar1) + (*readingBuffer0*scalar2);
    *readingBuffer1= (ay*scalar1) + (*readingBuffer1*scalar2);
    *readingBuffer2= (az*scalar1) + (*readingBuffer2*scalar2);
    *readingBuffer3= (gx*scalar1) + (*readingBuffer3*scalar2);
    *readingBuffer4= (gy*scalar1) + (*readingBuffer4*scalar2);
    *readingBuffer5= (gz*scalar1) + (*readingBuffer5*scalar2);
}
