/* ============================================================================= 
  SDCC MSX ROM SPRITE Functions Library (object type)
  Version: 1.0
  Author: mvac7/303bcn
  Architecture: MSX
  Format: header (.h)
  Programming language: C
  WEB: 
  mail: mvac7303b@gmail.com                
============================================================================= */

#ifndef  __VDP_SPRITE_H__
#define  __VDP_SPRITE_H__


// boolean
#ifndef _BOOLEAN
#define _BOOLEAN
  typedef enum {false = 0, true = 1} boolean;
#endif



/* =============================================================================
 SetSpritesSize
 Description: Set size type for the sprites.
 Input:       [char] size: 0=8x8; 1=16x16
 Output:      -
============================================================================= */
void SetSpritesSize(char size);



/* =============================================================================
 SetSpritesZoom
 Description: Set zoom type for the sprites.
 Input:       [boolean] zoom: false/0 = x1; true/1 = x2
 Output:      -
============================================================================= */
void SetSpritesZoom(char zoom);



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