/*============================================================================== 
 unRLEWBtoVRAM v1.3 (7 february 2022)

 Function : Unpack WB RLE to VRAM

 Historic of versions:
   v1.2 (20 April 2019)
   v1.1 (26 jun 2014)
                                                              
 CD = Control Digit = $80

 CD + $0         --> for one $80 value
 CD + $FF        --> end of data block
 CD + nn + dd    --> repeat nn ($1-$FE)+1 dd value
 dd (!= CD)      --> raw data                            
==============================================================================*/
#ifndef  __UNWBRLE2VRAM_H__
#define  __UNWBRLE2VRAM_H__



/* =============================================================================
 unRLEWBtoVRAM
 Function : unpack RLE-WB to VRAM
  
 Input    : [unsigned int] dataAddr <- source RLEWB data address
            [unsigned int] VRAMaddr <- target VRAM address       
 Output   : -                  
============================================================================= */
void unRLEWBtoVRAM (unsigned int dataAddr, unsigned int VRAMaddr);



/* =============================================================================
unRLEWBVRAM (for Assembler in-line)

 Function : unpack RLE-WB to VRAM
     
 Input    : HL - source RLEWB data address
            DE - target VRAM address
 Output   : -                 
============================================================================= */



#endif