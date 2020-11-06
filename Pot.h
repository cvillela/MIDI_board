#ifndef Controller_h
#define Controller_h
#include <Arduino.h>


//*************************************************************************
class Pot
{
  public:
    Pot(byte pin, byte command, byte control, byte channel);
    
    void setValue(byte command, byte control, byte channel)
    byte getValue();
    
    byte Pcommand;
    byte Pcontrol;
    byte Pchannel;

  private:
    byte _pin;
    byte _control;
    int _value;
    int _oldValue;
    bool _changed;
    byte _enablepin;
};
//*************************************************************************


#endif