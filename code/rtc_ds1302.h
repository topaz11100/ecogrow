#include <RtcDS1302.h>

class Rtc
{
public:
  Rtc(int dat, int clk, int rst): myWire(dat, clk, rst), rtc(myWire) {}

  void init()
  {
    rtc.Begin();
    rtc.SetDateTime(RtcDateTime(__DATE__, __TIME__));
  }

  void update()
  {
    now = rtc.GetDateTime();
  }

  String now_time()
  {
    return String(now.Month()) + "/" +
           String(now.Day()) + ":" +
           String(now.Hour()) + "." +
           String(now.Minute()) + "." +
           String(now.Second());
  }

private:
  ThreeWire myWire;
  RtcDS1302<ThreeWire> rtc;
  RtcDateTime now;
};

Rtc rtc(6, 5, 7);

