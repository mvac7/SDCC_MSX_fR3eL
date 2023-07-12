/* =============================================================================
  Joystick MSX SDCC Library (fR3eL Project)
  Version: header v1.4

  Description:
    Opensource library with functions to access to joysticks or keyboard 
    cursors keys. 
============================================================================= */

#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__


//Joystick type
#define CURSORKEYS           0
#define JOYSTICKA            1
#define JOYSTICKB            2

//Joystick state
#define JOYSTICK_INACTIVE    0
#define JOYSTICK_UP          1
#define JOYSTICK_UP_RIGHT    2
#define JOYSTICK_RIGHT       3
#define JOYSTICK_DOWN_RIGHT  4
#define JOYSTICK_DOWN        5
#define JOYSTICK_DOWN_LEFT   6
#define JOYSTICK_LEFT        7
#define JOYSTICK_UP_LEFT     8



//Trigger type 
#define SPACEBAR_BUTTON      0
#define KEYBOARD_BUTTON      0
#define JOYSTICKA_BUTTONA    1
#define JOYSTICKB_BUTTONA    2
#define JOYSTICKA_BUTTONB    3
#define JOYSTICKB_BUTTONB    4

//Trigger state
#define BUTTON_UNPRESSED     0
#define BUTTON_PRESSED      -1






/* =============================================================================
 STICK

 Description: 
    Returns the joystick status.
    Similar to the MSX BASIC STICK instruction.
 
 Input    : [char] joy port: 
                  0=cursor keys 
                  1=joystick 1 
                  2=joystick 2
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
  
 Description: 
    Returns selected trigger status. 
    Similar to the MSX BASIC STRIG instruction.
             
 Input    : [char]  trigger number
                    0 - space key
                    1 - joystick 1 button 1   
                    2 - joystick 2 button 1
                    3 - joystick 1 button 2
                    4 - joystick 2 button 2
                    
 Output   : [signed char] status:
                    0 = inactive
                   -1 = when the space key or the joystick/mouse button is 
                        pressed down 
============================================================================= */
signed char STRIG(char triggerN);



#endif