#ifndef ScaleManager_h
#define ScaleManager_h

//************************************************************************
Scale ()
class ScaleManager
{
 public:
   ScaleManager();
   void updateRoot();
   void updateMode();
   void updateScale();
   
   int SMroot;
   int SMoctave;
   int SMmode;

   int* SMnotes;

 private:
   // Notes and Scales constant values
   const int C = 0;
   const int Cs = 1;
   const int D = 2;
   const int Ds = 3;
   const int E = 4;
   const int F = 5;
   const int Fs = 6;
   const int G = 7;
   const int Gs = 8;
   const int A = 9;
   const int As = 10;
   const int B = 11;

   const int JONIO[]   =   [1, 1, 0, 1, 1, 1, 0];
   const int DORICO[]  =   [1, 0, 1, 1, 1, 0, 1];
   const int FRIGIO[]  =   [0, 1, 1, 1, 0, 1, 1];
   const int LIDIO[]   =   [1, 1, 1, 0, 1, 1, 0];
   const int MIXOLIDIO[] = [1, 1, 0, 1, 1, 0, 1];
   const int EOLIO[]   =   [1, 0, 1, 1, 0, 1, 1];
   const int LOCRIO[]  =   [0, 1, 1, 0, 1, 1, 1];

};

#endif
