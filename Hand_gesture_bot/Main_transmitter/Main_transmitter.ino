#include <Wire.h>  // Wire library - used for I2C communication
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
int ADXL345 = 0x53; // The ADXL345 sensor I2C address
RF24 radio(7,8);
const byte address[6] = "00001";
struct data{
  float xAxis;
  float yAxis;

};
data send_data;
float X_out, Y_out;  // Outputs

void setup() {
  Serial.begin(9600); // Initiate serial communication for printing the results on the Serial monitor
  Wire.begin(); // Initiate the Wire library
  // Set ADXL345 in measuring mode
  Wire.beginTransmission(ADXL345); // Start communicating with the device 
  Wire.write(0x2D); // Access/ talk to POWER_CTL Register - 0x2D
  // Enable measurement
  Wire.write(8); // (8dec -> 0000 1000 binary) Bit D3 High for measuring enable 
  Wire.endTransmission();
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setPayloadSize(sizeof(send_data));
  radio.stopListening();
}

void loop() {
  // === Read acceleromter data === //
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
  X_out = X_out/256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
  send_data.xAxis = X_out;
  Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
  Y_out = Y_out/256;
  send_data.yAxis = Y_out;
  
  Serial.print("Xa= ");
  Serial.print(X_out);
  Serial.print("   Ya= ");
  Serial.println(Y_out);
  radio.write(&send_data, sizeof(send_data));
  Serial.println(send_data.xAxis); //To check whether data of x-axis is storing or not
  
}

