/* =============================================================================
   AY38910.h
   SDCC AY-3-8910 Functions Library (object type)                                                             
   Author: mvac7/303bcn
   Architecture: MSX
   Format: C Object (SDCC .rel)
   Programming language: C
   WEB: 
   mail: mvac7303b@gmail.com
   
   Description:                                                              
     Opensource library for acces to PSG AY-3-8910
     It does not use the BIOS so it can be used to program ROMs or 
     MSX-DOS executables. 
============================================================================= */

#ifndef  __AY38910_H__
#define  __AY38910_H__



// boolean
#ifndef _BOOLEAN
#define _BOOLEAN
  typedef enum {false = 0, true = 1} boolean;
#endif




//envelope shapes
#define ENV_LowerBeat      0 
#define ENV_Upper          4 
#define ENV_LeftSaw        8
#define ENV_LowerTriangle 10 
#define ENV_LowerHold     11 
#define ENV_RightSaw      12
#define ENV_UpperHold     13
#define ENV_UpperTriangle 14 
 


//AY registers
#define AY_ToneA 0  //Channel A Tone Period (12 bits)
#define AY_ToneB 2  //Channel B Tone Period (12 bits)
#define AY_ToneC 4  //Channel C Tone Period (12 bits)
#define AY_Noise 6  //Noise Period (5 bits)
#define AY_Mixer 7  //Mixer
#define AY_AmplA 8  //Channel Volume A (4 bits + B5 active Envelope)
#define AY_AmplB 9  //Channel Volume B (4 bits + B5 active Envelope)
#define AY_AmplC 10 //Channel Volume C (4 bits + B5 active Envelope)
#define AY_Env   11 //Envelope Period (12 bits)
#define AY_EnvTp 13 //Envelope Type




/* =============================================================================
 SOUND(register, value)

 Function : Write into a register of PSG
 Input    : [char] register number (0 to 13)
            [char] value
 Output   : -
============================================================================= */
void SOUND(char reg, char value);



/* =============================================================================
 GetSound(register) 

 Function : Read PSG register value
 Input    : [char] register number (0 to 13)
 Output   : [char] value 
============================================================================= */
char GetSound(char reg);



/* =============================================================================
 SetTonePeriod(channel, period) 

 Function : Set Tone Period for any channel
 Input    : [char] channel (0, 1 or 2)
            [unsigned int] period (0 - 4095)
 Output   : -
============================================================================= */
void SetTonePeriod(char channel, unsigned int period);



/* =============================================================================
 SetNoisePeriod(period) 

 Function : Set Noise Period
 Input    : [char] Noise period (0 - 31) 
 Output   : - 
============================================================================= */
void SetNoisePeriod(char period);



/* =============================================================================
 SetEnvelopePeriod(period) 

 Function : Set Envelope Period
 Input    : [unsigned int] Envelope period (0 - 65535) 
 Output   : - 
============================================================================= */
void SetEnvelopePeriod(unsigned int period);



/* =============================================================================
 SetVolume(channel, volume) 

 Function : Set volume channel
 Input    : [char] channel (0, 1 or 2)
            [char] volume, 0 to 15 or 16 for activate envelope
 Output   : -
============================================================================= */
void SetVolume(char channel, char volume);



/* =============================================================================
 SetChannel(channel, isTone, isNoise)

 Function : Mixer. Enable/disable Tone and Noise channels.
 Input    : [char] channel (0, 1 or 2)
            [boolean] tone state
            [boolean] noise state
 Output   : -
============================================================================= */
void SetChannel(char channel, boolean isTone, boolean isNoise);



/* =============================================================================
 PlayEnvelope(shape) 

 Function : Set envelope type.
            Plays the sound on channels that have a volume of 16.
 Input    : [char] Envelope shape (0-15) (see envelope shapes definitions)
 Output   : -
============================================================================= */
void PlayEnvelope(char shape);



#endif