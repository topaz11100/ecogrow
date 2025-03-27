#include <DHT.h>

class Dht11
{
public:
  Dht11(int pin, int t, int h):
  dht(pin, DHT11), t_thre(t), h_thre(h) {}

  void init() { dht.begin(); }

  void update()
  {
    int t = dht.readTemperature();
    int h = dht.readHumidity();
  
    if (isnan(t) || isnan(h))
    {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    temp = t;
    humi = h;
  }

  bool check_weather()
  {
    return temp >= t_thre || humi >= h_thre;
  }

  String weather_str()
  {
    return String(temp) + "C " + String(humi) + "%";
  }

private:
  DHT dht;
  int temp = 25, humi = 30;
  int t_thre, h_thre;
};



