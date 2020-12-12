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

#ifndef LCDMANAGER_H
#define LCDMANAGER_H  

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
unsigned long showSinewave(void);
 
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
unsigned long showRandomCircles(void);

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
void clearScreen(void);

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
unsigned long showBegin(void);

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
unsigned long showLooperButtons(int x, int y);

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
unsigned long showFeatureButtons(int x, int y, String R, String S, String O);

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
unsigned long showEnd();

#endif
