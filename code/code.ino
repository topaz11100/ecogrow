#include "class.h"

Actuator led(13);
Actuator pump();

AnalogSensor cds(A3, 500);
AnalogSensor water(A3, 500);

void setup()
{
  Serial.begin(9600);
  led.init();
}

void loop()
{
  led.write(cds.trigger());
  delay(100);
  a++;
}
