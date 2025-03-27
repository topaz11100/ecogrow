#include <LiquidCrystal_I2C.h>

class Lcd
{
public:
  Lcd(int col, int row):
  lcd(0x27, col, row) {}

  void init()
  {
    lcd.init();
    lcd.backlight();
    lcd.clear();
  }

  void print(String str, int x, int y)
  {
    lcd.setCursor(x, y);
    lcd.print(str);
  }

private:
  LiquidCrystal_I2C lcd;
};






