#include "Actuator.h"
#include "AnalogSensor.h"
#include "dht11.h"
#include "lcd.h"
#include "rtc_ds1302.h"

#define LED 27
#define WAT 9
#define FAN 10
#define AIR 11
#define CDS A3
#define WAT_SEN A1
#define DHT A0
#define RTC_DAT 6
#define RTC_CLK 5
#define RTC_RST 7
#define LCD_COL 16
#define LCD_ROW 2

Actuator led(LED);
Actuator water(WAT);
Actuator fan(FAN);
Actuator air(AIR);

AnalogSensor cds(CDS, 500);
AnalogSensor water_sensor(WAT_SEN, 500);

Dht11 dht11(DHT, 30, 60);

//Rtc rtc(RTC_DAT, RTC_CLK, RTC_RST);

Lcd lcd(LCD_COL, LCD_ROW);

void sensor_init()
{
  led.init();
  water.init();
  fan.init();
  air.init();
  dht11.init();
  //rtc.init();
  lcd.init();
}

void setup()
{
  Serial.begin(9600);

  sensor_init();
}

void loop()
{
  //조도
  led.write(cds.trigger());

  //물 공기펌프
  air.write(1);

  //수위
  water.write(water_sensor.trigger());

  //온습도
  dht11.update();
  fan.write(dht11.check_weather());
  lcd.print(dht11.weather_str(), 0, 0);

  //시간
  //rtc.update();
  //lcd.print(rtc.now_time(), 0, 1);
}



