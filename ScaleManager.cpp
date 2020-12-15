#include "ScaleManager.h"

//***************************************************************
ScaleManager::ScaleManager()
{   
   Iroot = 0;
   Ioctave = 4;
   Imode = 0;

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
