#include "multiplempulib.h"
#include "Wire.h"

bool newData = false;
int intPin=19;

float buffer1[10]={0};
float buffer2[10]={0};
float buffer3[10]={0};
float buffer4[10]={0};


multiplempulib MPU;

void setup() {
Serial.begin(115200);
while (!Serial){
  Serial.println("Waiting for Serial Connection");
  }
Wire.begin(21, 22);
Wire.setClock(400000);

MPU.initiate();
MPU.mpu_select(1);
pinMode(intPin, INPUT);
buffer1[6]=1.0f;
buffer2[6]=1.0f;
buffer3[6]=1.0f;
buffer4[6]=1.0f;
attachInterrupt(digitalPinToInterrupt(intPin), inthandler, RISING);  // define interrupt for INT pin output of MPU9250
delay(2000);
}



void loop(){
  float _ax1, _ay1, _az1, _gx1, _gy1, _gz1;
  float _ax2, _ay2, _az2, _gx2, _gy2, _gz2;
  float _ax3, _ay3, _az3, _gx3, _gy3, _gz3;
  float _ax4, _ay4, _az4, _gx4, _gy4, _gz4;
  // put your main code here, to run repeatedly:
  if (newData)
  {
newData=false;    
MPU.mpu_select(1);
   
MPU.accRead();
MPU.gyrRead();
_ax1=MPU.accX1();
_ay1=MPU.accY1();
_az1=MPU.accZ1();
_gx1=MPU.gyroX1();
_gy1=MPU.gyroY1();
_gz1=MPU.gyroZ1();

//buffer1[0]=MPU.accX1();
//buffer1[1]=MPU.accY1();
//buffer1[2]=MPU.accZ1();
//buffer1[3]=MPU.gyroX1();
//buffer1[4]=MPU.gyroY1();
//buffer1[5]=MPU.gyroZ1();

MPU.mpu_select(2);    

MPU.accRead();
MPU.gyrRead();
_ax2=MPU.accX2();
_ay2=MPU.accY2();
_az2=MPU.accZ2();
_gx2=MPU.gyroX2();
_gy2=MPU.gyroY2();
_gz2=MPU.gyroZ2();

MPU.mpu_select(3);
    
MPU.accRead();
MPU.gyrRead();
_ax3=MPU.accX3();
_ay3=MPU.accY3();
_az3=MPU.accZ3();
_gx3=MPU.gyroX3();
_gy3=MPU.gyroY3();
_gz3=MPU.gyroZ3();
MPU.mpu_select(4);
    
MPU.accRead();
MPU.gyrRead();
_ax4=MPU.accX4();
_ay4=MPU.accY4();
_az4=MPU.accZ4();
_gx4=MPU.gyroX4();
_gy4=MPU.gyroY4();
_gz4=MPU.gyroZ4();
 MPU.MVA(_ax1, _ay1, _az1, _gx1, _gy1, _gz1, &buffer1[0], &buffer1[1], &buffer1[2], &buffer1[3], &buffer1[4], &buffer1[5]);
// MPU.MVA(_ax2, _ay2, _az2, _gx2, _gy2, _gz2, &buffer2[0], &buffer2[1], &buffer2[2], &buffer2[3], &buffer2[4], &buffer2[5]);
// MPU.MVA(_ax3, _ay3, _az3, _gx3, _gy3, _gz3, &buffer3[0], &buffer3[1], &buffer3[2], &buffer3[3], &buffer3[4], &buffer3[5]);
// MPU.MVA(_ax4, _ay4, _az4, _gx4, _gy4, _gz4, &buffer4[0], &buffer4[1], &buffer4[2], &buffer4[3], &buffer4[4], &buffer4[5]);
// Serial.print("buffer1: ");
// Serial.print(buffer1[0]);
// Serial.print(", ");
// Serial.print(buffer1[1]);
// Serial.print(", ");
// Serial.print(buffer1[2]);
// Serial.print(", ");
// Serial.print(buffer1[3]);
// Serial.print(", ");
// Serial.print(buffer1[4]);
// Serial.print(", ");
// Serial.println(buffer1[5]);
// Serial.print("buffer2: ");
// Serial.print(buffer2[0]);
// Serial.print(", ");
// Serial.print(buffer2[1]);
// Serial.print(", ");
// Serial.print(buffer2[2]);
// Serial.print(", ");
// Serial.print(buffer2[3]);
// Serial.print(", ");
// Serial.print(buffer2[4]);
// Serial.print(", ");
// Serial.println(buffer2[5]);
// Serial.print("buffer3: ");
// Serial.print(buffer3[0]);
// Serial.print(", ");
// Serial.print(buffer3[1]);
// Serial.print(", ");
// Serial.print(buffer3[2]);
// Serial.print(", ");
// Serial.print(buffer3[3]);
// Serial.print(", ");
// Serial.print(buffer3[4]);
// Serial.print(", ");
// Serial.println(buffer3[5]);
// Serial.print("buffer4: ");
// Serial.print(buffer4[0]);
// Serial.print(", ");
// Serial.print(buffer4[1]);
// Serial.print(", ");
// Serial.print(buffer4[2]);
// Serial.print(", ");
// Serial.print(buffer4[3]);
// Serial.print(", ");
// Serial.print(buffer4[4]);
// Serial.print(", ");
// Serial.println(buffer4[5]);

  }
MPU.imu_update(buffer1[0], buffer1[1], buffer1[2], buffer1[3], buffer1[4], buffer1[5], buffer1[6], buffer1[7], buffer1[8], buffer1[9]);
//MPU.imu_update(buffer2[0], buffer2[1], buffer2[2], buffer2[3], buffer2[4], buffer2[5], buffer2[6], buffer2[7], buffer2[8], buffer2[9]);
//MPU.imu_update(buffer3[0], buffer3[1], buffer3[2], buffer3[3], buffer3[4], buffer3[5], buffer3[6], buffer3[7], buffer3[8], buffer3[9]);
//MPU.imu_update(buffer4[0], buffer4[1], buffer4[2], buffer4[3], buffer4[4], buffer4[5], buffer4[6], buffer4[7], buffer4[8], buffer4[9]);
MPU.getEuler(buffer1[6],buffer1[7],buffer1[8],buffer1[9]);

//MPU.getEuler(buffer2[6],buffer2[7],buffer2[8],buffer2[9]);
//MPU.getEuler(buffer3[6],buffer3[7],buffer3[8],buffer3[9]);
//MPU.getEuler(buffer4[6],buffer4[7],buffer4[8],buffer4[9]);
}

ICACHE_RAM_ATTR void inthandler()
{
  bool *newData_tmp1;
  newData_tmp1 = &newData;
  *newData_tmp1=true;
  
}
