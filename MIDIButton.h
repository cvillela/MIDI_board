#ifndef MIDIButton_h
#define MIDIButton_h
#include <Arduino.h>


//************************************************************************
//Button (Command, Note Number, Channel)
class MIDIButton
{
  public:
    MIDIButton(byte command, byte note, byte channel);
    
    void setNote(int note);
    void setMsg(byte msg);
    byte getValue();

    byte Bcommand;
    byte Bnote;
    byte Bchannel;

  private:
    byte msg;
    byte last;

};

#endif
