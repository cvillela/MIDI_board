#include "MIDIButton.h"

//****************************************************************************************
//MIDIButton (Command, Note Number, Channel)
MIDIButton::MIDIButton( byte command, byte note, byte channel){
  Bcommand = command;
  Bnote = note;
  Bchannel = channel;
  msg = 2;
  last = 2;

}

void MIDIButton::setMsg(byte val){
  msg = val;
}


byte MIDIButton::getValue(){
 if (msg == last){
    return 2;
 }
 else {
    last = msg;
    return msg;
 }
}

void MIDIButton::setNote(int Inote){
  Bnote = (byte)Inote;
}
