
#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 sensor_bmp;

void setup() {
  Serial.begin(9600);
  sensor_bmp.begin();
  sensor_bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                         Adafruit_BMP280::SAMPLING_X2,
                         Adafruit_BMP280::SAMPLING_X16,
                         Adafruit_BMP280::FILTER_X16,
                         Adafruit_BMP280::STANDBY_MS_500);
}

void loop() 
{
  Serial.print("Temperatura (Celsius) = ");
  Serial.println(sensor_bmp.readTemperature());

  Serial.print("Pressao (Pa) = ");
  Serial.println(sensor_bmp.readPressure());

  Serial.println();
  delay(1000);
}
