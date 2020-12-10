/* =============================================================================
  SDCC MSX ROM JOYSTICK Functions Library (object type)
  Version: 1.2
  Author: mvac7/303bcn
  Architecture: MSX
  Format: C Object (SDCC .rel)
  Programming language: C
  WEB: 
  mail: mvac7303b@gmail.com

  Description:
    Opensource library with functions to access to joysticks or keyboard 
    cursors keys. 
    
  History of versions:
    v1.2 (11/03/2018) current version
    v1.1 (03/03/2017) 
    v1.0 (01/02/2016)

============================================================================= */

#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__



#define CURSORKEYS  0
#define JOYA        1
#define JOYB        2

#define SPACEBAR       0
#define JOYA_BUTTONA   1
#define JOYB_BUTTONA   2
#define JOYA_BUTTONB   3
#define JOYB_BUTTONB   4

#define INACTIVE    0
#define UP          1
#define UP_RIGHT    2
#define RIGHT       3
#define DOWN_RIGHT  4
#define DOWN        5
#define DOWN_LEFT   6
#define LEFT        7
#define UP_LEFT     8

#define UNPRESSED   0
#define PRESSED    -1




/* =============================================================================
STICK

 Description: Returns the joystick status
 
 Input    : [char] joy port: 
                  0=cursor keys 
                  1=joystick A 
                  2=joystick B
 Output   : [char]
                  0=inactive
                  1=up
                  2=up & right
                  3=right
                  4=down & right
                  5=down
                  6=down & left
                  7=left
                  8=up & left 
============================================================================= */
char STICK(char joy);



/* =============================================================================
 STRIG
  
 Description: Returns current trigger status
            
 Input    : [char] 
                    0 - space key
                    1 - button 1 joy A
                    2 - button 1 joy B
                    3 - button 2 joy A
                    4 - button 2 joy B
                    
 Output   : [char] status:
                    0 = inactive
                   -1 = when the space key or the joystick/mouse button is 
                        pressed down 
============================================================================= */
signed char STRIG(char joy);



#endif