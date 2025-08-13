/* ============================================================================= 
  VDP SPRITES MSX SDCC Library (fR3eL Project)          
============================================================================= */

#ifndef  __VDP_SPRITES_H__
#define  __VDP_SPRITES_H__



/* =============================================================================
SetSpritePattern
Description: 
		Assign a pattern to a sprite plane.
Input:	[char] sprite plane (0-31) 
		[char] pattern number (0-255 for 8x8 sprites or 0-63 for 16x16 sprites)
Output:	-
============================================================================= */
void SetSpritePattern(char plane, char pattern);



/* =============================================================================
SetSpriteColor
Description: 
		Assign a color to a sprite plane.
Input:	[char] sprite plane (0-31) 
		[char] color (0-15)
Output:	-
============================================================================= */
void SetSpriteColor(char plane, char color);



/* =============================================================================
SetSpritePosition
Description: 
		Assigns the position coordinates of a sprite plane.
Input:	[char] sprite plane (0-31) 
		[char] x coordinate
		[char] y coordinate
Output:	-
============================================================================= */
void SetSpritePosition(char plane, char x, char y);



/* =============================================================================
SetSpriteVisible
Description: 
		Hides or shows a sprite plane.
Input:	[char] sprite plane (0-31) 
		[char] or [boolean]/[switcher] visible state: 
														0/false/OFF = hidden
														1/true/ON = visible
Output:	-
============================================================================= */
void SetSpriteVisible(char plane, char state);



/* =============================================================================
SetEarlyClock
Description: 
		Enable or Disable Early Clock of a sprite plane. 
		EC: Move 32 points to the left the X position of the sprite.
Input:	[char] sprite plane (0-31)
		[char] or [boolean]/[switcher] EC state: 
									0/false/OFF = disable
									1/true/ON = enable
Output:	-
============================================================================= */
void SetEarlyClock(char plane, char state);



#endif