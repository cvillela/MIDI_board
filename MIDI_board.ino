//******************************************************
// Library imports
#include <MIDI.h>
#include "Keypad.h"

// Header imports
#include "Pot.h"
#include "MIDIButton.h"
#include "ScaleManager.h"
#include "LOOPButton.h"

//******************************************************
MIDI_CREATE_DEFAULT_INSTANCE();
//******************************************************
// Global parameter storing param to be updated
// 1 == ROOT
// 2 == MODE
// 3 == OCTAVE

int ICurrentButton = 0;
int IglobalParam = 1;
//******************************************************
// Keypad
const byte ROWS = 4;
const byte COLS = 4;

 char keys[ROWS][COLS] = {
   {'1','2','3','A'},
   {'4','5','6','B'},
   {'7','8','9','C'},
   {'*','0','#','D'}
 };

byte colPins[ROWS] = {5, 4, 3, 2}; 
byte rowPins[COLS] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//******************************************************
// Scale Manager
ScaleManager scale_manager = ScaleManager();

//************************************************************
// Array size
byte NUMBER_MIDI_BUTTONS = 8;
byte NUMBER_TRACK_BUTTONS = 4;
byte NUMBER_POTS = 1;

//************************************************
//Pot (Pin Number, Command, CC Control, Channel Number)
Pot PO1(A0, 0, 1, 1);

// Pot array
Pot *POTS[] {&PO1};

//************************************************
// LOOPButton (Pin Number, Command, Note Number, Channel, Debounce Time)
//** Command parameter 0=NOTE  1=CC  2=Toggle CC **

LOOPButton BUL(10, 0, 5, 1, 5);

//************************************************
// MIDIButton (Command, Note Number, Channel)
// Command parameter 0=NOTE  1=CC  2=Toggle CC
MIDIButton BU7(0, 60, 1);
MIDIButton BU8(0, 64, 1);
MIDIButton BU9(0, 67, 1);
MIDIButton BUC(0, 70, 1);
MIDIButton BUS(0, 71, 1);
MIDIButton BU0(0, 72, 1);
MIDIButton BUH(0, 73, 1);
MIDIButton BUD(0, 74, 1);

// Track Buttons
MIDIButton BU1(0, 1, 2);
MIDIButton BU2(0, 2, 2);
MIDIButton BU3(0, 3, 2);
MIDIButton BUA(0, 4, 2);

// MIDIButton array
MIDIButton *MIDIBUTTONS[] {&BU7, &BUS, &BU8, &BU0, &BU9, &BUH, &BUC, &BUD};

// TRACKButton array
MIDIButton *TRACKBUTTONS[] {&BU1, &BU2, &BU3, &BUA};


//************************************************
void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);
  Serial.begin(115200);
  keypad.addEventListener(keypadEvent);
  keypad.setDebounceTime(10);
  setMIDINotes();
  updateScreen();
}

void loop() {
  char key = keypad.getKey();
  updateLoop();
  if(NUMBER_POTS != 0) updatePots();
}


//*****************************************************************
void updateMIDIButtons(int msg) {

  // Button is not pressed
  if (msg == 0)
    MIDI.sendNoteOff(MIDIBUTTONS[ICurrentButton]->Bnote, 0, MIDIBUTTONS[ICurrentButton]->Bchannel);

  // Button is pressed
  else if (msg == 1) 
    MIDI.sendNoteOn(MIDIBUTTONS[ICurrentButton]->Bnote, 127, MIDIBUTTONS[ICurrentButton]->Bchannel);

}

//*****************************************************************
void updateTRACKBUTTONS(int msg) {

  // Button is not pressed
  if (msg == 0)
    MIDI.sendNoteOff(TRACKBUTTONS[ICurrentButton]->Bnote, 0, TRACKBUTTONS[ICurrentButton]->Bchannel);

  // Button is pressed
  else if (msg == 1) 
    MIDI.sendNoteOn(TRACKBUTTONS[ICurrentButton]->Bnote, 127, TRACKBUTTONS[ICurrentButton]->Bchannel);

}

//***********************************************************************
void updatePots() {
  for (int i = 0; i < NUMBER_POTS; i = i + 1) {
    byte potmessage = POTS[i]->getValue();
    if (potmessage != 255) MIDI.sendControlChange(POTS[i]->Pcontrol, potmessage, POTS[i]->Pchannel);
  }
}

//***********************************************************************
void updateLoop() {

  byte message = BUL.getValue();

  //  Button is pressed
  if (message == 0)
      MIDI.sendNoteOn(BUL.Bvalue, 127, BUL.Bchannel);

  //  Button is not pressed
  if (message == 1) 
    MIDI.sendNoteOff(BUL.Bvalue, 0, BUL.Bchannel);
    
}

//***********************************************************************
void keypadEvent(KeypadEvent key){
    int msg = 2;
    switch (keypad.getState()){
      case PRESSED:
        switch(key){
          case '7':
            ICurrentButton = 0;
            updateMIDIButtons(1);
            break;
          case '8':
            ICurrentButton = 2;
            updateMIDIButtons(1);
            break;
          case '9':
            ICurrentButton = 4;
            updateMIDIButtons(1);
            break;
          case 'C':
            ICurrentButton = 6;
            updateMIDIButtons(1);
            break;
          case '*':
            ICurrentButton = 1;
            updateMIDIButtons(1);
            break;
          case '0':
            ICurrentButton = 3;
            updateMIDIButtons(1);
            break;
          case '#':
            ICurrentButton = 5;
            updateMIDIButtons(1);
            break;
          case 'D':
            ICurrentButton = 7;
            updateMIDIButtons(1);
            break;

          //CONFIG 1
          case '4':
            scale_manager.updateScale(IglobalParam, 0);
            setMIDINotes();
            updateScreen();
            break;
          case '5':
            scale_manager.updateScale(IglobalParam, 1);
            setMIDINotes();
            updateScreen();
            break;
          
          //CONFIG 2
          case '6':
            msg = 2;
            updateGlobalParam(0);
            updateScreen();
            break;
          case 'B':
            msg = 2;
            updateGlobalParam(1);
            updateScreen();
            break;

          //LOOP
          case '1':
            ICurrentButton = 0;
            updateTRACKBUTTONS(1);
            break;
          case '2':
            ICurrentButton = 1;
            updateTRACKBUTTONS(1);
            break;
          case '3':
            ICurrentButton = 2;
            updateTRACKBUTTONS(1);
            break;
          case 'A':
            ICurrentButton = 3;
            updateTRACKBUTTONS(1);
            break;
        }
        break;

      case RELEASED:
          switch(key){
            // MIDI
            case '7':
              ICurrentButton = 0;
              updateMIDIButtons(0);
              break;
            case '8':
              ICurrentButton = 2;
              updateMIDIButtons(0);
              break;
            case '9':
              ICurrentButton = 4;
              updateMIDIButtons(0);
              break;
            case 'C':
              ICurrentButton = 6;
              updateMIDIButtons(0);
              break;
            case '*':
              ICurrentButton = 1;
              updateMIDIButtons(0);
              break;
            case '0':
              ICurrentButton = 3;
              updateMIDIButtons(0);
              break;
            case '#':
              ICurrentButton = 5;
              updateMIDIButtons(0);
              break;
            case 'D':
              ICurrentButton = 7;
              updateMIDIButtons(0);
              break;

            //LOOP
            case '1':
              ICurrentButton = 0;
              updateTRACKBUTTONS(0);
              break;
            case '2':
              ICurrentButton = 1;
              updateTRACKBUTTONS(0);
              break;
            case '3':
              ICurrentButton = 2;
              updateTRACKBUTTONS(0);
              break;
            case 'A':
              ICurrentButton = 3;
              updateTRACKBUTTONS(0);
              break;
          }
          break;

    }
}

//***********************************************************************
void updateGlobalParam(byte dir){

    // up
    if(dir == 1){
      if (IglobalParam == 3){
        IglobalParam = 1;
      }
      else
        IglobalParam++;
    }

    //down
    else if(dir == 0){
      if (IglobalParam == 1){
        IglobalParam = 3;
      }
      else
        IglobalParam--;
    }
}
//************************************************************************
void setMIDINotes(){
  
  for(byte i = 0; i < NUMBER_MIDI_BUTTONS; i++){
    MIDIBUTTONS[i]->setNote(scale_manager.SMnotes[i]);
  }

}

//*************************************************************************
// JOGAR AQUI DENTRO MÉTODO DE UPDATE NA SCREEN

// IGlobalParam -> o que está sendo updated
// 1 == ROOT
// 2 == MODE
// 3 == OCTAVE

void updateScreen(){

  // Modo ou Escala escolhidos
  //const char* -> scale_manager.cNote[scale_manager.Iroot];
  
  // Nota escolhida, root
  //const char* -> scale_manager.cMode[scale_manager.Imode];
  
  // Oitava [é um número msm]
  //int -> scale_manager.Ioctave;

  // Selected Param -> Converter de acordo com a explicacao acima da funcao
  // int -> IGlobalParam;
}
