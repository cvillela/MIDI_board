#include "LOOPButton.h"

//****************************************************************************************
//LOOPButton (Pin Number, Command, Note Number, Channel, Debounce Time)
LOOPButton::LOOPButton(byte pin, byte command, byte value, byte channel, byte debounce)
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

byte LOOPButton::getValue()
{
  // Se busy não estivert setado - read MIDIButton
  if (_busy == false) {
    if (digitalRead(_pin) == _last) return 2;
  }

  // Se novo bit setado, checa tempo
  if (_new == true) {
    _busy = true;
    _new = false;
    _time = millis();
    return 255;
  }

  // Checar debounce
  if (millis() - _time < _debounce) return 255;

  // Checar estado do pino
  if (digitalRead(_pin) == _last) {
    _busy = false;
    _new = true;
    return 255;
  }

  else {
    _busy = false;
    _new = true;
    _last = ((~_last) & 0b00000001);
    return _last;
  }
}
