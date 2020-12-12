/* *************************************************** */
/* **************** ES070 **************************** */
/* File name: LCDManager                               */
/* File description: This file implements the functions*/
/*              of the 160x160 LCD and is used to test */
/*           differents layouts for the screen content */
/*                                                     */
/* Project: MIDIBoard                                  */
/* Author: Angelo H Barbosa e Caio S Vilella           */
/* Date: 12/2020                                       */
/* *************************************************** */

#include <lcdManagert.h>
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include <SPI.h>

/* Colors definitions */
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

/* To manage the LCD with SPI is necessary to intantiate the LCDWIKI_SPI class */
LCDWIKI_SPI mylcd(SSD1283A,10,9,8,A3); //hardware spi,CS,CD,RESET

/* *************************************************** */
/* **************** ES070 **************************** */
/* Method name: showSinewave                           */
/* Method description: This function implements the    */
/*                     sinewave used on the opening    */
/*                     screen                          */
/* Input params: void                                  */
/*                                                     */
/* Output params: unsigned long that represents the    */
/*                time spent by this routine           */
/*                                                     */
/* Project: MIDIBoard                                  */
/* Author: Angelo H Barbosa e Caio S Vilella           */
/* Date: 12/2020                                       */
/* *************************************************** */
unsigned long showSinewave(void)
{
   uint16_t buf[mylcd.Get_Display_Width()-2],x = 1,i,y;
   unsigned long ulTimeStart = micros();
   int16_t t = 20, b = 40;
   float k = 4;

   for (i=1; i<((mylcd.Get_Display_Width()-2)*t); i++) 
   {
      x++;
      if (x==mylcd.Get_Display_Width()-1)
      {
          x=1;
      }
      if (i>mylcd.Get_Display_Width()-1)
      {
          if ((x==mylcd.Get_Display_Width()/2-1)||(buf[x-1]==mylcd.Get_Display_Height()/2-1))
          {
              mylcd.Set_Draw_color(BLACK); 
          }
          else
          {
             mylcd.Set_Draw_color(BLACK); 
          }
          mylcd.Draw_Pixel(x,buf[x-1]);
    }
    mylcd.Set_Draw_color(255, 64, 255);
    y=mylcd.Get_Display_Height()/2-1+(sin(((i*k)*3.14)/180)*(b-(i/100)));
    mylcd.Draw_Pixel(x,y);
    buf[x-1]=y;
  }
  return micros()-ulTimeStart;   
}
 
/* *************************************************** */
/* **************** ES070 **************************** */
/* Method name: showRandomCircle                       */
/* Method description: This function implements the    */
/*                     randoms circles used on the     */
/*                     opneing screen                  */
/* Input params: void                                  */
/*                                                     */
/* Output params: unsigned long that represents the    */
/*                time spent by this routine           */
/*                                                     */
/* Project: MIDIBoard                                  */
/* Author: Angelo H Barbosa e Caio S Vilella           */
/* Date: 12/2020                                       */
/* *************************************************** */
unsigned long showRandomCircles(void)
{
    uint16_t i;
    unsigned long ulTimeStart = micros();
    
    for(i = 0;i< 150;i++)
    {
       mylcd.Set_Draw_color(random(255),random(255),random(255));
       mylcd.Draw_Circle(41+random(mylcd.Get_Display_Width()-82), 52+random(mylcd.Get_Display_Height()-104), random(40));
    }
    return micros() - ulTimeStart; 
}

/* *************************************************** */
/* **************** ES070 **************************** */
/* Method name: clearScreen                            */
/* Method description: This function implements the    */
/*                     cleaning of the screen used     */
/*                     on the screen's transitions     */
/* Input params: void                                  */
/*                                                     */
/* Output params: void                                 */
/*                                                     */
/* Project: MIDIBoard                                  */
/* Author: Angelo H Barbosa e Caio S Vilella           */
/* Date: 12/2020                                       */
/* *************************************************** */
void clearScreen(void)
{
   delay(100);  
   mylcd.Set_Draw_color(0, 0, 0);
   mylcd.Fill_Rectangle(1, 12, mylcd.Get_Display_Width()-2, mylcd.Get_Display_Height()-1-12);
}

/* *************************************************** */
/* **************** ES070 **************************** */
/* Method name: showBegin                              */
/* Method description: This function implements the    */
/*                     initialization screen           */
/* Input params: void                                  */
/*                                                     */
/* Output params: unsigned long that represents the    */
/*                time spent by this opening           */
/*                                                     */
/* Project: MIDIBoard                                  */
/* Author: Angelo H Barbosa e Caio S Vilella           */
/* Date: 12/2020                                       */
/* *************************************************** */
unsigned long showBegin(void)
{
    unsigned long ulTimeStart = micros();
    unsigned long ulDisplay;
    
    /*Setting the top layout*/
    mylcd.Set_Draw_color(128, 128, 128); // CINZA
    mylcd.Fill_Rectangle(0, 0, mylcd.Get_Display_Width()-1, 10);
    /*Setting the top text*/
    mylcd.Set_Text_colour(GREEN);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("MIDIBoard Project", CENTER, 1);

    /*Setting the bottom layout*/
    mylcd.Set_Draw_color(128, 128, 128); // CINZA
    mylcd.Fill_Rectangle(0, mylcd.Get_Display_Height()-1-10, mylcd.Get_Display_Width()-1, mylcd.Get_Display_Height()-1);
    /*Setting the bottom text*/
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("Angelo e Caio", CENTER, mylcd.Get_Display_Height()-10);

    /*Setting border color of opening screen*/
    mylcd.Set_Draw_color(CYAN); // Cor da borda da tela principal
    mylcd.Draw_Rectangle(0, 11, mylcd.Get_Display_Width()-1, mylcd.Get_Display_Height()-1-11);   
    
    /*Setting opening effect*/
    ulDisplay = showRandomCircles();
    
    /*Cleaning screen before initiate the main screen*/
    clearScreen();
    
    return micros() - ulTimeStart;
}

/* *************************************************** */
/* **************** ES070 **************************** */
/* Method name: showLooperButtons                      */
/* Method description: This function implements the    */
/*                     Looper buttons on screen        */
/* Input params: int x: x coordinate reference         */
/*               int y: y coordinate reference         */
/*                                                     */
/* Output params: unsigned long that represents the    */
/*                time spent by this function          */
/*                                                     */
/* Project: MIDIBoard                                  */
/* Author: Angelo H Barbosa e Caio S Vilella           */
/* Date: 12/2020                                       */
/* *************************************************** */
unsigned long showLooperButtons(int x, int y)
{
    unsigned long ulTimeStart = micros();
    
    /*Setting L1 button layout*/
    mylcd.Set_Draw_color(GREEN);
    mylcd.Fill_Round_Rectangle(x+10, y+15, x+33, y+38, 5);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("L1", x+12, y+20);
    
    /*Setting L2 button layout*/
    mylcd.Set_Draw_color(GREEN);
    mylcd.Fill_Round_Rectangle(x+38, y+15, x+61, y+38, 5);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("L2", x+39, y+20);
    
    /*Setting L3 button layout*/
    mylcd.Set_Draw_color(GREEN);
    mylcd.Fill_Round_Rectangle(x+66, y+15, x+89, y+38, 5);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("L3", x+67, y+20);
    
    /*Setting L4 button layout*/
    mylcd.Set_Draw_color(GREEN);
    mylcd.Fill_Round_Rectangle(x+94, y+15, x+117, y+38, 5);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("L4", x+95, y+20);
     
    return micros()- ulTimeStart;   
}

/* *************************************************** */
/* **************** ES070 **************************** */
/* Method name: showFeatureButtons                     */
/* Method description: This function implements the    */
/*                     different feature buttons       */
/* Input params: int x: x coordinate reference         */
/*               int y: y coordinate reference         */
/*               String R, S, O: Values of the features*/
/*                                                     */
/* Output params: unsigned long that represents the    */
/*                time spent by this function          */
/*                                                     */
/* Project: MIDIBoard                                  */
/* Author: Angelo H Barbosa e Caio S Vilella           */
/* Date: 12/2020                                       */
/* *************************************************** */
unsigned long showFeatureButtons(int x, int y, String R, String S, String O)
{
    unsigned long ulTimeStart = micros();
    
    /*Setting left selection arrow*/
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x,y,x+10,y-10,x+10,y+10);
   /*Setting the value of the feature showed*/
    mylcd.Set_Text_colour(WHITE); 
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String(R, x+15, y-8);
    /*Setting right selection arrow*/
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x+30,y-10,x+30,y+10,x+40,y);
    mylcd.Set_Text_colour(WHITE);  
    /*Setting the description of the feature*/
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("Root", x+60, y-8);
   
   /*Setting left selection arrow*/
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x,y+25,x+10,y+15,x+10,y+35);
   /*Setting the value of the feature showed*/
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String(S, x+15, y+17);
   /*Setting right selection arrow*/
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x+30,y+15,x+30,y+35,x+40,y+25);
   /*Setting the description of the feature*/
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("Scale", x+60, y+17);
    
    /*Setting left selection arrow*/
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x,y+50,x+10,y+40,x+10,y+60);
   /*Setting the value of the feature showed*/
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String(O, x+15, y+42);
   /*Setting right selection arrow*/
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x+30,y+40,x+30,y+60,x+40,y+50);
   /*Setting the description of the feature*/
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("Octave", x+60, y+42);
    
    return micros() - ulTimeStart;
}

/* *************************************************** */
/* **************** ES070 **************************** */
/* Method name: showEnd                                */
/* Method description: This function implements the    */
/*                     ending screen                   */
/* Input params: void                                  */
/*                                                     */
/* Output params: unsigned long that represents the    */
/*                time spent by this opening           */
/*                                                     */
/* Project: MIDIBoard                                  */
/* Author: Angelo H Barbosa e Caio S Vilella           */
/* Date: 12/2020                                       */
/* *************************************************** */
unsigned long showEnd()
{
    unsigned long ulTimeStart = micros();  
  
    mylcd.Fill_Screen(0, 255, 255);
    mylcd.Set_Draw_color(255, 0, 0);
    mylcd.Fill_Round_Rectangle(mylcd.Get_Display_Width()/2-1-70+1, mylcd.Get_Display_Height()/2-1-40+1, mylcd.Get_Display_Width()/2-1+70-1, mylcd.Get_Display_Height()/2-1+40-1,5);
    mylcd.Set_Text_colour(0, 255, 255);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("Running over!", CENTER, mylcd.Get_Display_Height()/2-1-30);
    mylcd.Print_String("That's ok!", CENTER, mylcd.Get_Display_Height()/2-1-20);
    mylcd.Print_String("it will restart.", CENTER, mylcd.Get_Display_Height()/2-1-10);
    mylcd.Print_String("Please wait ...", CENTER, mylcd.Get_Display_Height()/2-1);  
    delay(5000);
    return micros() - ulTimeStart;   
}

/*void setup(){
  
  unsigned long opening;
  
  mylcd.Init_LCD();// Inicializa o modulo SPI do LCD
  mylcd.Fill_Screen(BLACK); // Preenche todo o background
  
  opening = showBegin();
  clearScreen();
  
}

void loop(){
  
  unsigned long time;

  time += showLooperButtons(0,0);

  time += showFeatureButtons(10,55, "R", "S", "O");
  
}
*/
