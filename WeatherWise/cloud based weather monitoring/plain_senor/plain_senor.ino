
// bmp 108 sensor sda to d2 and scl d1

#define rainPin A0       //D0 
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() 
{
  Serial.begin(9600);
  pinMode(rainPin , INPUT);
  if (!bmp.begin()) 
  {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) 
    {
    }
  }
}

void loop() 
{
  int rainVal= analogRead(rainPin);
  //Serial.println(rainVal);
  if(rainVal<=1024 && rainVal>=600)
  {
    Serial.println("No rain");
  }
  if(rainVal<=600 && rainVal>=300)
  {
    Serial.println("Moderate rain");
  }
  if(rainVal<=300 && rainVal>=0)
  {
    Serial.println("Heavy rain");
  }
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" meters");
    
    Serial.println();
    delay(1500);
}
