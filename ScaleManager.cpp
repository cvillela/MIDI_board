#include "ScaleManager.h"

//***************************************************************
ScaleManager::ScaleManager()
{   
    Iroot = 0;
    Ioctave = 4;
    Imode = 0;

    cMode[0] = "Jônio";
    cMode[1] = "Dórico";
    cMode[2] = "Frígio";
    cMode[3] = "Lídio";
    cMode[4] = "Mixolídio";
    cMode[5] = "Eólio";
    cMode[6] = "Lócrio";
  
    cNote[0] = "C";
    cNote[1] = "C#";
    cNote[2] = "D";
    cNote[3] = "D#";
    cNote[4] = "E";
    cNote[5] = "F";
    cNote[6] = "F#";
    cNote[7] = "G";
    cNote[8] = "G#";
    cNote[9] = "A";
    cNote[10] = "Bb";
    cNote[11] = "B";
  

   int initial_notes[8] = {60, 62, 64, 65, 67, 69, 71, 72};
   for(int i = 0; i < 8; i++){
      SMnotes[i] = initial_notes[i];  
   }
}

void ScaleManager::updateScale(int param, int dir)
{
   switch(param){
      
      //root
      case 1:
         updateRoot(dir);
         break;

      //mode
      case 2:
         updateMode(dir);
         break;
      
      //octave
      case 3:
         updateOctave(dir);
         break;

   }
}

void ScaleManager::updateRoot(int dir){
   
   switch(dir){
      // up
      case 1:
         for(int i = 0; i < 8; i++){
            SMnotes[i]++;  
         }
         if(Iroot == 11){
            Iroot = 1;
         }
         else{
            Iroot++;
         }
         break;

      // down
      case 0:
         for(int i = 0; i < 8; i++){
            SMnotes[i]--;  
         }
         if(Iroot == 0){
            Iroot = 11;
         }
         else{
            Iroot--;
         }
         break;
   }
}

void ScaleManager::updateMode(int dir){

   switch(dir){
      
      // up
      case 1:
         if(Imode == 6){
            Imode = 0;
         }
         else
         {
            Imode++;
         }
         break;

      //down
      case 0:
         if(Imode == 0){
            Imode = 6;
         }
         else
         {
            Imode--;
         }
         break;
   
   }
   setScale(modos_array[Imode]);
   
   for(int i = 0; i < 7; i++){
//    Serial.println(modos_array[Imode][i]);
   }
   
}

void ScaleManager::updateOctave(int dir){
   
   switch(dir){
      // up
      case 1:
         for(int i = 0; i < 8; i++){
            SMnotes[i] = SMnotes[i] + 12;  
         }
         Ioctave++;
         break;

      // down
      case 0:
         for(int i = 0; i < 8; i++){
            SMnotes[i] = SMnotes[i] - 12;  
         }
         Ioctave--;
         break;
   }
}


void ScaleManager::setScale(const int* mode){
   for(int i = 1; i < 8; i++){
      SMnotes[i] = SMnotes[i - 1] + mode[i - 1] + 1;
   }
}
