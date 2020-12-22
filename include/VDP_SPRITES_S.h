/* ============================================================================= 
  VDP SPRITES Small MSX SDCC Library (fR3eL Project) 
============================================================================= */

#ifndef  __VDP_SPRITESS_H__
#define  __VDP_SPRITESS_H__


// boolean
#ifndef _BOOLEAN
#define _BOOLEAN
  typedef enum {false = 0, true = 1} boolean;
#endif



/* =============================================================================
 ClearSprites
 Description: 
             Initialises all sprite data The sprite pattern is cleared to
             null, the sprite number to the sprite plane number, the
             sprite colour to the foregtound colour. The vertical location
             of the sprite is set to 209 (mode 0 to 3) or 217 (mode 4 to 8).
 Input:       -
 Output:      -
============================================================================= */
void ClearSprites();



/* =============================================================================
 PUTSPRITE
 Description: Displays the sprite pattern.
              In G4 screen mode (V9938), fills the 16 rows of color values.
 Input:       [char] sprite plane (0-31) 
              [char] x 
              [char] y
              [char] color (0-15)
              [char] pattern
 Output:      -
============================================================================= */
void PUTSPRITE(char plane, char x, char y, char color, char pattern);




#endif