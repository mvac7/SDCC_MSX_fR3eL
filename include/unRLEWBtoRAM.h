/* =============================================================================
                                                                           
unRLEWBtoRAM                                                                

 WB RLE  v1.0

 $80 nn dd            ; run of n consecutive identical bytes ($1>$FE), value dd
 $80 $0               ; for one $80 value
 $80 $FF              ; end of data block
 <any other value>    ; raw data                                                               

============================================================================= */
#ifndef  __UNWBRLE2RAM_H__
#define  __UNWBRLE2RAM_H__



/* =============================================================================
 Function : unpack RLE-WB to RAM
  
 Input    : [unsigned int] source RAM RLE data address
            [unsigned int] target RAM address       
 Output   : -                        
============================================================================= */
extern void unRLEWBtoRAM (unsigned int, unsigned int);



/* =============================================================================
unRLEWBRAM (for Assembler inline)

 Function : unpack RLE-WB to RAM
     
 Input    : HL - source RAM RLE data address
            DE - target RAM address
 Output   : -                       
============================================================================= */



#endif