/* =============================================================================
   PSG ayFXplayer MSX SDCC Library (fR3eL Project)
   Version: 1.0 (7 July 2021)
   Authors: Original code: SapphiRe  <http://z80st.auic.es>
            This adaptation to SDCC: mvac7 
   Architecture: MSX
   Format: C Object (SDCC .rel)
   Programming language: C and Z80 assembler
============================================================================= */

#ifndef  __AYFXPLAYER_H__
#define  __AYFXPLAYER_H__



#define  ayFX_FIXED  0
#define  ayFX_CYCLE  1



extern char ayFX_MODE;      // ayFX mode: (0 fixed; 1 cyclic)
extern char ayFX_CHANNEL;   // PSG channel to play the ayFX stream (1=C;2=B,3=A)
extern char ayFX_PRIORITY;  // Current ayFX stream priotity



/* =============================================================================
 ayFX_SETUP

 Function : ayFX replayer setup
 Input    : [unsigned int] Samples Bank address
            [char] mode    (0=Fixed channel;0=Cycle channel)
            [char] channel (0=A;1=B;2=C)
 Output   : -
============================================================================= */
void ayFX_Setup(unsigned int BANKaddr, char mode, char channel);



/* =============================================================================
 ayFX_SetChannel

 Function : Change output channel (useful only in Fixed channel mode)
 Input    : [char] channel (0=A;1=B;2=C)
 Output   : -
============================================================================= */
void ayFX_SetChannel(char channel);



/* =============================================================================
 ayFX_Play (ASM name:ayFX_INIT)
 
 Function : Play FX
 Input    : [char] sound to be played (0 to 255)
            [char] sound priority  (0 to 15)
 Output   : [char] 
          0: no errors, the new sample has been correctly initialized
          1: priority error, there's a sample with higher priority being played
          2: index error, the current bank don't have a sample with such index 
============================================================================= */
char ayFX_Play(char FXnumber, char FXpriority);



/* =============================================================================
 ayFX_Decode (ASM name: ayFX_PLAY)

 Function : Generates the values of registers of a frame of the ayFX in 
            progress. It has to be executed in every frame, not necessarily in 
            the interrupt routine.
 Input    : -
 Output   : -
============================================================================= */
void ayFX_Decode();



#endif