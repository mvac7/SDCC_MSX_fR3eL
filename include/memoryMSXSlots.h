/* =============================================================================
   Memory MSX Slots Library (fR3eL Project)

   Description:
     Library for accessing page slots and subslots on MSX systems.
============================================================================= */

#ifndef __MEMORYSLOTMSX_H__
#define __MEMORYSLOTMSX_H__



// boolean
#ifndef _BOOLEAN
#define _BOOLEAN
  typedef enum {false = 0, true = 1} boolean;
#endif




/* =============================================================================
   GetSlotFromPage
 
   Function : Returns the slot number of the indicated page.
   Input    : [char] page (0-3)              
   Output   : [char] slot (0-3)   
============================================================================= */
char GetSlotFromPage(char page);



/* =============================================================================
   SetPageSlot
 
   Function : Set a slot on the indicated page.
   Input    : [char] page (0-3)
              [char] slot (0-3)
   Output   : -

  
   More Info: (by MSX Assembly Page)  
   http://map.grauw.nl/resources/msx_io_ports.php
           Primary slot select register
               page 0 > 0x0000 - 0x3FFF
               page 1 > 0x4000 - 0x7FFF
               page 2 > 0x8000 - 0xBFFF
               page 3 > 0xC000 - 0xFFFF
============================================================================= */
void SetPageSlot(char page, char slot);




// ############################################################################# <<<
//   Functions for computers with expanded slots.


/* =============================================================================
   IsSlotExpanded
 
   Function : Returns if the slot is of the expanded type.
   Input    : [char] slot (0-3)
   Output   : [boolean] true = Yes; false = No
   
        EXPTBL 0xFCC1 Slot 0 expanded?
               0xFCC2 Slot 1 expanded?
               0xFCC3 Slot 2 expanded?
               0xFCC4 Slot 3 expanded?
               Yes = 0x80 ; No = 0
============================================================================= */
boolean IsSlotExpanded(char slot);




/* =============================================================================
   GetSubslotFromPage
 
   Function : Returns the Subslot number of the indicated page.
   Input    : [char] page (0-3)              
   Output   : [char] subslot (0-3)   
============================================================================= */
char GetSubslotFromPage(char page);



/* =============================================================================
   SetPageSubslot
 
   Function : Set a subslot on the indicated page (For expanded slots)
   Input    : [char] page (0-3)
              [char] subslot (0-3)
   Output   : -

  
   More Info: (by MSX Assembly Page)  
   http://map.grauw.nl/resources/msx_io_ports.php
               
           Secondary slot select register:
               The subslot select register can be found at memory address #FFFF:
               0-1 Subslot for page 0 (#0000-#3FFF)
               2-3 Subslot for page 1 (#4000-#7FFF)
               4-5 Subslot for page 2 (#8000-#BFFF)
               6-7 Subslot for page 3 (#C000-#FFFF)
============================================================================= */
void SetPageSubslot(char page, char subslot);


// ############################################################################# <<<



/*
char WhereIsRAMslot() or SearchRAMslot() or GetRAMslot()
uint getRAM() slot + subslot
*/



#endif