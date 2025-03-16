#include "Actuator.h"
#include "AnalogSensor.h"
#include "dht11.h"
#include "lcd.h"
#include "rtc_ds1302.h"

void setup()
{
  Serial.begin(9600);

  led.init();
  water.init();
  fan.init();
  air.init();

  dht11.init();

  rtc.init();

  lcd.init();
}

void loop()
{
  led.write(cds.trigger());

  air.write(1);

  water.write(water_sensor.trigger());

  dht11.update();

  fan.write(dht11.check_weather());

  lcd.print(dht11.weather_str(), 0, 0);

  rtc.update();

  lcd.print(rtc.now_time(), 0, 1);
}



