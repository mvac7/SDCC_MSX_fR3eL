/* =============================================================================
 unRLEWBtoRAM                                                                      
 Function : Decompress RLEWB data to RAM

  
 CD = Control Digit = $80

 CD + $0         --> for one $80 value
 CD + $FF        --> end of data block
 CD + nn + dd    --> repeat nn ($1-$FE)+1 dd value
 dd (!= CD)      --> raw data                                                               
============================================================================= */
#ifndef  __UNWBRLE2RAM_H__
#define  __UNWBRLE2RAM_H__



/* =============================================================================
 Function : unpack RLE-WB to RAM
  
 Input    : [unsigned int] source RAM RLE data address
            [unsigned int] target RAM address       
 Output   : -                        
============================================================================= */
void unRLEWBtoRAM (unsigned int, unsigned int);



/* =============================================================================
unRLEWBRAM (for Assembler inline)

 Function : unpack RLE-WB to RAM
     
 Input    : HL - source RAM RLE data address
            DE - target RAM address
 Output   : -                       
============================================================================= */



#endif