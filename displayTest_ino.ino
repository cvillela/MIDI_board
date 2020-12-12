// MIDI Board project - LCD Tests
// Lab. de Embarcados ES070 - Angelo H Barbosa 166527 ; Caio S Vilella RA

//pin usage as follow:
//             CS  CD  RST  MOSI  MISO  CLK  LED  
//Arduino Uno  A5  A3  A4   A2    NONE  A1   A3
//Arduino Uno  10  9   8    11    NONE  13   A3

#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include <SPI.h>

LCDWIKI_SPI mylcd(SSD1283A,10,9,8,A3); //hardware spi,cs,cd,reset

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


/*Cabeçalho da tela*/
unsigned long show_text(void)
{
    unsigned long i;
    unsigned long time_start = micros();
    mylcd.Set_Draw_color(128, 128, 128); // CINZA
    mylcd.Fill_Rectangle(0, 0, mylcd.Get_Display_Width()-1, 10);
    mylcd.Set_Text_colour(GREEN);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("MIDIBoard Test", CENTER, 1);

    mylcd.Set_Draw_color(128, 128, 128); // CINZA
    mylcd.Fill_Rectangle(0, mylcd.Get_Display_Height()-1-10, mylcd.Get_Display_Width()-1, mylcd.Get_Display_Height()-1);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("Angelo e Caio - ES070", CENTER, mylcd.Get_Display_Height()-10);

    mylcd.Set_Draw_color(CYAN); // Cor da borda da tela principal
    mylcd.Draw_Rectangle(0, 11, mylcd.Get_Display_Width()-1, mylcd.Get_Display_Height()-1-11);   
    
    i = show_sinewave();
    clear_screen();
    
    return micros() - time_start;
}

unsigned long show_sinewave(void)
{
   uint16_t buf[mylcd.Get_Display_Width()-2],x = 1,i,y;
   unsigned long time_start = micros();
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
  return micros()- time_start;   
}

unsigned long show_LooperButtons(int x, int y)
{
    unsigned long time_start = micros();
    
    mylcd.Set_Draw_color(GREEN);
    mylcd.Fill_Round_Rectangle(x+10, y+15, x+33, y+38, 5);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("L1", x+12, y+20);
    
    mylcd.Set_Draw_color(GREEN);
    mylcd.Fill_Round_Rectangle(x+38, y+15, x+61, y+38, 5);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("L2", x+39, y+20);
    
    mylcd.Set_Draw_color(GREEN);
    mylcd.Fill_Round_Rectangle(x+66, y+15, x+89, y+38, 5);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("L3", x+67, y+20);
    
    mylcd.Set_Draw_color(GREEN);
    mylcd.Fill_Round_Rectangle(x+94, y+15, x+117, y+38, 5);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("L4", x+95, y+20);
     
     return micros()- time_start;   
}

//void Fill_Triangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,int16_t x2, int16_t y2)

unsigned long show_RSOButtons(int x, int y, String R, String S, String O)
{
    unsigned long time_start = micros();
    
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x,y,x+10,y-10,x+10,y+10);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String(R, x+15, y-8);
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x+30,y-10,x+30,y+10,x+40,y);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("Root", x+60, y-8);
    
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x,y+25,x+10,y+15,x+10,y+35);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String(S, x+15, y+17);
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x+30,y+15,x+30,y+35,x+40,y+25);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("Scale", x+60, y+17);
    
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x,y+50,x+10,y+40,x+10,y+60);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String(O, x+15, y+42);
    mylcd.Set_Draw_color(YELLOW);
    mylcd.Fill_Triangle(x+30,y+40,x+30,y+60,x+40,y+50);
    mylcd.Set_Text_colour(WHITE);   
    mylcd.Set_Text_Size(1);
    mylcd.Set_Text_Mode(1);
    mylcd.Print_String("Octave", x+60, y+42);
    
    return time_start;
}


unsigned long show_fill_circle(void)
{
    uint16_t i;
    unsigned long time_start = micros();
    uint16_t r_len = (mylcd.Get_Display_Height()-40)/5/2;
    uint16_t x_spec = (mylcd.Get_Display_Width()-5*r_len*2)/2;
    uint16_t y_spec = (mylcd.Get_Display_Height()-5*r_len*2)/2;
    for(i = 0;i<5;i++)
    {
          switch (i)
          {
            case 0:
              mylcd.Set_Draw_color(255,0,255);
              break;
            case 1:
              mylcd.Set_Draw_color(255,0,0);
              break;
            case 2:
              mylcd.Set_Draw_color(0,255,0);
              break;
            case 3:
              mylcd.Set_Draw_color(0,0,255);
              break;
            case 4:
              mylcd.Set_Draw_color(255,255,0);
              break;
            default:
              break;
          }   
          mylcd.Fill_Circle(x_spec+r_len+i*r_len*2-1, y_spec+r_len+i*r_len*2-1,r_len);
          mylcd.Fill_Circle(x_spec+r_len+i*r_len*2-1, y_spec+(5-i)*r_len*2-r_len-1,r_len); 
     }
     return micros()- time_start;   
 }
 
 unsigned long show_grid_lines(void)
{
    uint16_t i;
    unsigned long time_start = micros();
    int16_t wid = mylcd.Get_Display_Width();
   float k = 1.44;

    mylcd.Set_Draw_color(255,0,0);
    for (i=12; i<mylcd.Get_Display_Height()-1-12; i+=5)
    {
       mylcd.Draw_Line(1, i, (i*k)-10, mylcd.Get_Display_Height()-2-12);
     }
     mylcd.Set_Draw_color(255,0,0);
     for (i=mylcd.Get_Display_Height()-2-12; i>13; i-=5)
    {
      mylcd.Draw_Line(mylcd.Get_Display_Width()-2, i, (i*k)-10, 12);
    }
    mylcd.Set_Draw_color(0,255,255);
    for (i=mylcd.Get_Display_Height()-2-12; i>13; i-=5)
    {
        mylcd.Draw_Line(1, i, (mylcd.Get_Display_Height()-1-12)*k+10-(i*k), 12);
    }
    mylcd.Set_Draw_color(0,255,255);
    for (int i=13; i<mylcd.Get_Display_Height()-2-12; i+=5)
    {
        mylcd.Draw_Line(mylcd.Get_Display_Width()-2, i, (mylcd.Get_Display_Height()-1-12)*k+10-(i*k), mylcd.Get_Display_Height()-2-12);
    }
    return micros()- time_start;   
}

unsigned long show_random_circles(void)
{
    uint16_t i;
    unsigned long time_start = micros();
    for(i = 0;i< 150;i++)
    {
       mylcd.Set_Draw_color(random(255),random(255),random(255));
       mylcd.Draw_Circle(41+random(mylcd.Get_Display_Width()-82), 52+random(mylcd.Get_Display_Height()-104), random(40));
    }
    return micros()- time_start; 
}

void show_end(unsigned long run_time)
{
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
    mylcd.Set_Text_colour(255, 255, 0); 
    mylcd.Print_String("runtime(us): ", mylcd.Get_Display_Width()/2-1-65, mylcd.Get_Display_Height()/2-1+25);
    mylcd.Set_Text_colour(0, 255, 0);
    mylcd.Print_Number_Int(run_time, mylcd.Get_Display_Width()/2-1+12, mylcd.Get_Display_Height()/2-1+25, 0, ' ', 10);  
    delay(10000);   
}


void clear_screen(void)
{
   delay(100);  
   mylcd.Set_Draw_color(0, 0, 0);
   mylcd.Fill_Rectangle(1, 12, mylcd.Get_Display_Width()-2, mylcd.Get_Display_Height()-1-12);
}

void setup(){
  
  unsigned long opening;
  
  mylcd.Init_LCD();// Inicializa o modulo SPI do LCD
  mylcd.Fill_Screen(BLACK); // Preenche todo o background
  
  opening = show_text();
  clear_screen();
  
}

void loop(){
  
  unsigned long time;

  time += show_LooperButtons(0,0);

  time += show_RSOButtons(10,55, "R", "S", "O");
  
}
  
  
  /* Trecho p/ escrever String*/
  /*
  mylcd.Set_Text_Mode(0);
  mylcd.Fill_Screen(BLACK);
  mylcd.Set_Text_Back_colour(BLACK);
  
  mylcd.Set_Text_colour(GREEN);
  mylcd.Set_Text_Size(1);
  mylcd.Print_String("Eu te amo Flai", 0, 0); // void Print_String(const uint8_t *st, int16_t x, int16_t y)
  */
  
  /* Escrever letra a letra c/ respectiva cor */
  /*
  void Draw_Char(int16_t x, int16_t y, uint8_t c, uint16_t color,uint16_t bg, uint8_t size, boolean mode)
  mylcd.Draw_Char(0,0,'A',GREEN, WHITE, 3, 0); // Exemplo
  */
 




