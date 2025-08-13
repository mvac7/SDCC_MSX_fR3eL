/* =============================================================================
VDP_PRINT MSX SDCC Library (fR3eL Project)
Functions for display text strings in the graphic modes of the TMS9918A(G1 & G2)
https://github.com/mvac7/SDCC_MSX_fR3eL
============================================================================= */
#ifndef __VPRINT_H__
#define __VPRINT_H__


extern char VPRINT_ntext[6];
extern unsigned int VPRINT_vaddr;



/* =============================================================================
VLOCATE
Description:
		Moves the cursor to the specified location and optionally 
		provides the VRAM address from the pattern name table, 
		for the indicated screen position.
Inputs:	column (char) 0 - 31
		line   (char) 0 - 23
Output:	-
============================================================================= */
void VLOCATE(char column, char line);



/* =============================================================================
GetStringLength
Description:
		Provides the length of a string.
Inputs:	[char*] string
Output:	[unsigned int] length
============================================================================= */
//unsigned int GetStringLength(char* text);



/* =============================================================================
VPRINT
Description:
		Prints a string of characters on the screen.
		Places it in the position indicated by VLOCATE or in the last printed 
		position.
Inputs:	[char*] string
Output:	-
============================================================================= */
void VPRINT(char* text);



/* =============================================================================
VPRINTN
Description:
		Prints a character string with a limited length on the screen.
Inputs:	text (char*) string
		length (unsigned int) length of the string to print
Output:	-
============================================================================= */
void VPRINTN(char* text, unsigned int length);



/* =============================================================================
VPrintNumber
Description:
		Prints a number.
Inputs:	[unsigned int] number
		[char] length
Output:	-
============================================================================= */
void VPrintNumber(unsigned int value);



/* =============================================================================
PrintFNumber
Description: 
		Prints an unsigned integer on the screen with formatting parameters.
	   
Input:	(unsigned int or char) numeric value
		(char) zero/empty Char: (0 = "", 32=' ', 48='0', etc.)
		(char) length: 1 to 5          
Output:	-
============================================================================= */
void VPrintFNumber(unsigned int value, char emptyChar, char length);



/* =============================================================================
PrintNumber
Description: 
		Prints an unsigned integer on the screen.

		16-bit Integer to ASCII (decimal) based on num2Dec16 by baze
		https://baze.sk/3sc/misc/z80bits.html#5.1
		
Input:	(unsigned int) numeric value
		(unsigned int) text parameters (emptyChar<<8)+length
Output:	-
============================================================================= */
void num2Dec16(unsigned int aNumber, unsigned int variables);



#endif