/* ============================================================================= 
  VDP SPRITES MSX SDCC Library (fR3eL Project)          
============================================================================= */

#ifndef  __VDP_SPRITES_H__
#define  __VDP_SPRITES_H__


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



/* =============================================================================
 SetSpritePattern
 Description: Assign a pattern to a sprite plane.
 Input:       [char] sprite plane (0-31) 
              [char] pattern
 Output:      -
============================================================================= */
void SetSpritePattern(char plane, char pattern);



/* =============================================================================
 SetSpriteColor
 Description: Assign a color to a sprite plane.
              In G4 screen mode (V9938), fills the 16 rows of color values.
 Input:       [char] sprite plane (0-31) 
              [char] color (0-15)
 Output:      -
============================================================================= */
void SetSpriteColor(char plane, char color);



/* =============================================================================
 SetSpritePosition
 Description: Assigns the position coordinates of a sprite plane.
 Input:       [char] sprite plane (0-31) 
              [char] x 
              [char] y
 Output:      -
============================================================================= */
void SetSpritePosition(char plane, char x, char y);



/* =============================================================================
 SetSpriteVisible
 Description: Hides or shows a sprite plane.
 Input:       [char] sprite plane (0-31) 
              [boolean] visible state
 Output:      -
============================================================================= */
void SetSpriteVisible(char plane, boolean state);



/* =============================================================================
 SetEarlyClock
 Description: Apply the Early Clock of a sprite. Move 32 points to the left           
              the X position of the sprite.
 Input:       [char] sprite plane (0-31) 
 Output:      -
============================================================================= */
void SetEarlyClock(char plane);



/* =============================================================================
 UnsetEarlyClock
 Description: Disables the Early Clock. Restore the position of a sprite.
 Input:       [char] sprite plane (0-31)
 Output:      -
============================================================================= */
void UnsetEarlyClock(char plane);



#endif