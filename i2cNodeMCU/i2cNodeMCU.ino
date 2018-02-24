#include <I2C_Anything.h>

//Master Reader
#include<Wire.h>


void setup() {
  Wire.begin(D1, D2); // sda, scl
  Serial.begin(9600);  // start serial for output
}
struct SensorPacket{
    float Temp;
    float lum;
    float noise;
  };
SensorPacket myData;
void loop(){
  Serial.println("--------------------");
   Wire.requestFrom(8, sizeof(SensorPacket));    // request SensorPacket bytes from slave device #8
  
    delay(100);
    I2C_readAnything (myData);
    

  
  Serial.println("----------");
  Serial.print("TEMPERATURA:\t");
  Serial.println(myData.Temp);
  Serial.print("LUMINOSITÀ:\t");
  Serial.println(myData.lum);
  Serial.print("RUMORE:\t");
  Serial.println(myData.noise);
  Serial.println("----------");
  delay(1000);

}

