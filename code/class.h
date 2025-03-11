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

