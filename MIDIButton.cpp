#include "MIDIButton.h"

//****************************************************************************************
//MIDIButton (Pin Number, Command, Note Number, Channel, Debounce Time)
MIDIButton::MIDIButton(byte pin, byte command, byte value, byte channel, byte debounce)
{
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
  _debounce = debounce;
  _time = 0;
  _new = true;
  _busy = false;
  _last = 1;
  Bcommand = command;
  Bvalue = value;
  Bchannel = channel;
}

byte MIDIButton::getValue()
{
  // If BUSY bit not set - read MIDIButton
  if (_busy == false) { // If busy false
    if (digitalRead(_pin) == _last) return 2; // If same as last state - exit
  }

  // If NEW Bit set - Key just pressed, record time
  if (_new == true) { // If new is true
    _busy = true; // Set busy TRUE
    _new = false; // Set New FALSE
    _time = millis();
    return 255;
  }

  // Check if debounce time has passed - If no, exit
  if (millis() - _time < _debounce) return 255;

  // Debounce time has passed. Read pin to see if still set the same
  // If it has changed back - assume false alarm
  if (digitalRead(_pin) == _last) {
    _busy = false; // Set busy false
    _new = true; // Set new true
    return 255;
  }

  // If this point is reached, event is valid. return event type
  else {
    _busy = false; // Set busy false
    _new = true; // Set new true
    _last = ((~_last) & 0b00000001); // invert _last
    return _last;
  }
}

