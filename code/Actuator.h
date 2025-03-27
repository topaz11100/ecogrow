class Actuator
{
public:
  Actuator(int p):
  pin(p), status(false) {}

  void init()
  {
    pinMode(pin, OUTPUT);
  }

  void write(bool state)
  {
    digitalWrite(pin, state);
    status = state;
  }

  bool get_status()
  {
    return status;
  }
  
private:
  int pin;
  bool status;
};