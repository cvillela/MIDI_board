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

 private:

    // Update functions
    void updateRoot(int dir);
    void updateMode(int dir);
    void updateOctave(int dir);
    void setScale(const int* mode);

    // Current Parameter
    int Iroot;
    int Ioctave;
    int Imode;


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
