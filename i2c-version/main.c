#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
Adafruit_BMP280 bmp; // I2C
void setup() {
Serial.begin(9600);
delay(1000);
if (!bmp.begin(0x76)) {
Serial.println("BMP280 sensor not found. Check wiring!");
while (1);
}
bmp.setSampling(Adafruit_BMP280::MODE_NORMAL, Adafruit_BMP280::SAMPLING_X2, Adafruit_BMP280::SAMPLING_X16, Adafruit_BMP280::FILTER_X16, Adafruit_BMP280::STANDBY_MS_500);
}
void loop() {
Serial.print("Temperature = ");
Serial.print(bmp.readTemperature());
Serial.println(" *C");
Serial.print("Pressure = ");
Serial.print(bmp.readPressure() / 100.0F);
Serial.println(" hPa");
Serial.print("Approx. Altitude = ");
Serial.print(bmp.readAltitude(1013.25));
Serial.println(" m");
Serial.println();
delay(2000);
}
