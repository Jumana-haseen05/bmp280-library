#include <Adafruit_BMP280.h>
#include <SPI.h>
#define BMP_CS 17 // CS -> GPIO17 on Pico
Adafruit_BMP280 bmp(BMP_CS); // Using default SPI interface
void setup() {
Serial.begin(115200);
while (!Serial);
if (!bmp.begin()) {
Serial.println("Could not find a valid BMP280 sensor, check wiring!");
while (1);
}
Serial.println("BMP280 sensor initialized.");
}
void loop() {
Serial.print("Temperature = ");
Serial.print(bmp.readTemperature());
Serial.println(" *C");
Serial.print("Pressure = ");
Serial.print(bmp.readPressure());
Serial.println(" Pa");
Serial.print("Approx Altitude = ");
Serial.print(bmp.readAltitude(1013.25)); // standard sea-level pressure
Serial.println(" m");
Serial.println();
delay(2000);
}
