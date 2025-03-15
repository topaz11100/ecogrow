#include "LiquidCrystal_I2C.h"
#include "DHT.h"

class Actuator
{
public:
  Actuator(int p): pin{p} {}
  void init() { pinMode(pin, OUTPUT); }
  void write(bool state) { digitalWrite(pin, state); status = state; }
  bool get_status() { return status; }
private:
  int pin;
  bool status;
};
Actuator led(27);
Actuator water(9);
Actuator fan(10);
Actuator air(11);

class AnalogSensor
{
public:
  AnalogSensor(int p, int t): pin{p}, threshold{t} {}
  int read() { return analogRead(pin); }
  bool trigger() { return read() >= threshold;}
private:
  int pin;
  int threshold;
};
AnalogSensor cds(A3, 500);
AnalogSensor water_sensor(A1, 500);

DHT dht(A0, DHT11);
int t_thre = 30, h_thre = 60;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);

  led.init();
  water.init();
  fan.init();
  air.init();

  dht.begin();

  lcd_init();
}

void loop()
{
  led.write(cds.trigger());
  air.write(1);
  water.write(water_sensor.trigger());
  fan.write(weather_check());
}

bool weather_check()
{
  int t = dht.readTemperature();
  int h = dht.readHumidity();
  
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT sensor!");
    return false;
  }

  return t > t_thre || h > h_thre;
}

void lcd_init()
{
  lcd.init();
  lcd.backlight();
}
void lcd_print(String str, int x, int y)
{
  lcd.setCursor(x, y);
  lcd.print(str);
}