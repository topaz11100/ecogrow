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