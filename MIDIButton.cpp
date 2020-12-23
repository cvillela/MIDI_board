#include "MIDIButton.h"

//****************************************************************************************
//MIDIButton (Command, Note Number, Channel)
MIDIButton::MIDIButton( byte command, byte note, byte channel){
  Bcommand = command;
  Bnote = note;
  Bchannel = channel;
}

void MIDIButton::setNote(int Inote){
  Bnote = (byte)Inote;
}
