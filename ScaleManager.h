#ifndef ScaleManager_h
#define ScaleManager_h
#include <Arduino.h>


//************************************************************************
class ScaleManager
{
 public:
   ScaleManager();
   int SMnotes[8];
   void updateScale(int aram, int dir);

    // Current Parameter
    int Iroot;
    int Ioctave;
    int Imode;

    // Note and Modes names
    const char *cMode[7];
    cMode[0] = "Jônio";
    cMode[1] = "Dórico";
    cMode[2] = "Frígio";
    cMode[3] = "Lídio";
    cMode[4] = "Mixolídio";
    cMode[5] = "Eólio";
    cMode[6] = "Lócrio";

    const char *cNote[11];
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

 private:

    // Update functions
    void updateRoot(int dir);
    void updateMode(int dir);
    void updateOctave(int dir);
    void setScale(const int* mode);

    //Scale intervals
    const int modos_array[7][7] = {
      {1, 1, 0, 1, 1, 1, 0},  //Jonio
      {1, 0, 1, 1, 1, 0, 1},  //Dórico
      {0, 1, 1, 1, 0, 1, 1},  //Frígio
      {1, 1, 1, 0, 1, 1, 0},  //Lídio
      {1, 1, 0, 1, 1, 0, 1},  //Mixolídio
      {1, 0, 1, 1, 0, 1, 1},  //Eólio
      {0, 1, 1, 0, 1, 1, 1}   //Lócrio
    };

};

#endif
