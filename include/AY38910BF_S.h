/* =============================================================================
   AY38910BF_S
   PSG AY-3-8910 Buffer Short MSX SDCC Library (fR3eL Project)
   Version: 0.9b (16 July 2021)
   Author: mvac7
   Architecture: MSX
   Format: C Object (SDCC .rel)
   Programming language: C and Z80 assembler
   
   Description:                                                              
     Library for accessing the AY38910 through a buffer of registers.
     
     It does not use the BIOS so it can be used to program ROMs or 
     MSX-DOS executables. 
============================================================================= */

#ifndef  __AY38910BF_H__
#define  __AY38910BF_H__



#ifndef _SWITCHER
#define _SWITCHER
  typedef enum {OFF = 0, ON = 1} SWITCHER;
#endif




//envelope shapes
#define AY_ENV_LowerBeat      1  //(0,1,2,3 and 9)<-- 0 can be useful in case you need to control when the envelope is triggered
#define AY_ENV_Upper          4  //(4,5,6,7 and 15)
#define AY_ENV_LeftSaw        8
#define AY_ENV_LowerTriangle 10 
#define AY_ENV_LowerHold     11 
#define AY_ENV_RightSaw      12
#define AY_ENV_UpperHold     13
#define AY_ENV_UpperTriangle 14 
 


#ifndef AY_REGISTERS
#define AY_REGISTERS
#define AY_ToneA      0 //Channel A Tone Period (12 bits)
#define AY_ToneB      2 //Channel B Tone Period (12 bits)
#define AY_ToneC      4 //Channel C Tone Period (12 bits)
#define AY_Noise      6 //Noise Period (5 bits)
#define AY_Mixer      7 //Mixer
#define AY_AmpA       8 //Channel Volume A (4 bits + B5 active Envelope)
#define AY_AmpB       9 //Channel Volume B (4 bits + B5 active Envelope)
#define AY_AmpC      10 //Channel Volume C (4 bits + B5 active Envelope)
#define AY_EnvPeriod 11 //Envelope Period (16 bits)
#define AY_EnvShape  13 //Envelope Shape
#endif



// AY channels
#define AY_Channel_A 0
#define AY_Channel_B 1
#define AY_Channel_C 2


// AY type 
#define AY_INTERNAL 0
#define AY_EXTERNAL 1



extern char AY_TYPE;      // 1 = External AY  Else Internal AY

extern char AYREGS[14];   // buffer of AY registers





/* =============================================================================
 AY_Init

 Function : Initialize the buffer
 Input    : -
 Output   : -
============================================================================= */
void AY_Init();



/* =============================================================================
 PlayAY() 

 Function : Copy buffer to AY (internal or external).
 Input    : -
 Output   : -
============================================================================= */
void PlayAY();



#endif