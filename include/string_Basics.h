/* =============================================================================
String BASICs Functions SDCC Library (fR3eL Project)
Selection of functions for managing C Strings (array of characters). 
Includes functions similar to those of MSX BASIC.
https://github.com/mvac7/SDCC_MSX_fR3eL
============================================================================= */

#ifndef __STRINGB_H__
#define __STRINGB_H__



// boolean
#ifndef _BOOLEAN
#define _BOOLEAN
  typedef enum {false = 0, true = 1} boolean;
#endif





/* =============================================================================
 StrLength

 Function : Returns the length of a string 
 Input    : [char*] string       
 Output   : [char] length 
============================================================================= */
char StrLength(char* source);



/* =============================================================================
 StrCopy

 Function : Copy the source string on the target string. 
 Input    : [char*] target string
            [char*] source string        
 Output   : -  
============================================================================= */
void StrCopy(char* target, char* source);



/* =============================================================================
 StrConcatenate

 Function : Appends a copy of the source string to the target string. 
 Input    : [char*] target string
            [char*] source string          
 Output   : -  
============================================================================= */
void StrConcatenate(char* target, char* source);




/* =============================================================================
 StrCompare

 Function : Compare two strings 
 Input    : [char*] first string
            [char*] second string         
 Output   : [boolean] result  
============================================================================= */
boolean StrCompare(char* string1, char* string2);



/* =============================================================================
 LEFT

 Function : Returns a section of the source string with the given length
            Similar as MSX BASIC instruction LEFT$ 
 Input    : [char*] target string
            [char*] source string
            [char]  length        
 Output   : -  
============================================================================= */
void LEFT(char* target, char* source, char length);



/* =============================================================================
 RIGHT

 Function : Returns a section to the right of the source string with the given 
            length.
            Similar as MSX BASIC instruction RIGHT$  
 Input    : [char*] target string
            [char*] source string
            [char]  length         
 Output   : -  
============================================================================= */
void RIGHT(char* target, char* source, char length);



/* =============================================================================
 MID

 Function : Returns a section of the source string from the given position and 
            length
            Similar as MSX BASIC instruction MID$  
 Input    : [char*] target string
            [char*] source string
            [char]  position
            [char]  length        
 Output   : -  
============================================================================= */
void MID(char* target, char* source, char leftPos, char length);



/* =============================================================================
 INSTR

 Function : Find the first occurrence of a character in the given string
            Similar as MSX BASIC instruction INSTR  
 Input    : [char*] source string
            [char] ascii code
            [char] offset        
 Output   : [char] position  
============================================================================= */
char INSTR(char* source, char asciicode, char offset);



/* =============================================================================
 STRING

 Function : Generates a string, composed with same char
            Similar as MSX BASIC instruction STRING$  
 Input    : [char*] target string
            [char] length
            [char] asciicode        
 Output   : -  
============================================================================= */
void STRING(char* target, char length, char asciicode);



/* =============================================================================
 SPACE

 Function : Generates a string composed with spaces
            Similar as MSX BASIC instruction SPACE$ 
 Input    : [char*] target string
            [char] length        
 Output   : -  
============================================================================= */
//void SPACE(char* target, char length);



#endif