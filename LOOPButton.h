#ifndef LOOPButton_h
#define LOOPButton_h
#include <Arduino.h>


//************************************************************************
//Button (Pin Number, Command, Note Number, Channel, Debounce Time)
class LOOPButton
{
  public:
    LOOPButton(byte pin, byte command, byte value, byte channel, byte debounce);
    
    byte getValue();
    void setValue(byte command, byte value, byte channel);

    byte Bcommand;
    byte Bvalue;
    byte Bchannel;

  private:
    bool _busy;
    bool _new;
    unsigned long _time;
    int _debounce;
    byte _pin;
    byte _last;
};

#endif
