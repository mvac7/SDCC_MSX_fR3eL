/* =============================================================================
  Mouse MSX SDCC Library (fR3eL Project)
  Version: header v1.1

  Description:
    Opensource library with functions to access to mouse controller. 
============================================================================= */

#ifndef  __MOUSE_H__
#define  __MOUSE_H__


extern char Mouse_port;
extern signed char Mouse_X;
extern signed char Mouse_Y;

char CheckMouse(void);

void MouseRead(void);

#endif