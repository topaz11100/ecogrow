class Buzzer
{
public:
  Buzzer(int p): pin(p) {}

  void play(int sound[][2], int sound_count)
  {
    for (int i = 0; i < sound_count; i++)
    {
      tone(pin, sound[i][0]);
      delayMicroseconds(sound[i][1]);
    }
    noTone(pin);
  }

private:
  int pin;
};

Buzzer buzz(12);