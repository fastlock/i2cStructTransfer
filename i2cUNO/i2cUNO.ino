//slave sender
#include <Wire.h>
#include <I2C_Anything.h>
void setup() {
  Serial.begin(9600);
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}
struct SensorPacket{
    float Temp;
    float lum;
    float noise;
  };
SensorPacket myData;
void loop() {
  myData.Temp=18.24;
  myData.lum=2.3;
  myData.noise=200.01;
  //delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  int i=0;
  Serial.println("sending data");
    I2C_writeAnything (myData);
  
  // as expected by master
}
