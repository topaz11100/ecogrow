#include "class.h"

Actuator led(13);
AnalogSensor cds(A3, 500);

int a = 0;

void setup()
{
  Serial.begin(9600);
  led.init();
}

void loop()
{
  led.write(a%2 == 0);
  delay(100);
  a++;
}
