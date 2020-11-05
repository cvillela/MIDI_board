#ifndef MIDIButton_h
#define MIDIButton_h
#include <Arduino.h>


//************************************************************************
//Button (Pin Number, Command, Note Number, Channel, Debounce Time)
class MIDIButton
{
  public:
    MIDIButton(byte pin, byte command, byte value, byte channel, byte debounce);
    byte getValue();
    void newValue(byte command, byte value, byte channel);
    byte Bcommand;
    byte Bvalue;
    byte Bchannel;
    byte Btoggle;

  private:
    byte _previous;
    byte _current;
    unsigned long _time;
    int _debounce;
    byte _pin;
    byte _value;
    byte _command;
    byte _status;
    byte _last;
    byte _enablepin;
};

#endif
