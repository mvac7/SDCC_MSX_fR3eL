/* =============================================================================
   AY38910_playFX.h                                                             
   v1.0 (11 March 2018)
                                                                        
   Description                                                              

============================================================================= */

#ifndef  __AY38910_H__
#define  __AY38910_H__



// boolean
#ifndef _BOOLEAN
#define _BOOLEAN
  typedef enum {false = 0, true = 1} boolean;
#endif



typedef struct {
  boolean isTone;
  boolean isNoise;  
  unsigned int Tone;
  char Noise;
  unsigned int Period;
  char Shape;
} FX;



//envelope shapes
#define ENV_LowerBeat      0 
#define ENV_Upper          4 
#define ENV_LeftSaw        8
#define ENV_LowerTriangle 10 
#define ENV_LowerHold     11 
#define ENV_RightSaw      12
#define ENV_UpperHold     13
#define ENV_UpperTriangle 14 
 




/* =============================================================================
 SOUND(register, value)

 Function : Write into a register of PSG
 Input    : [char] register number (0 to 13)
            [char] value
 Output   : -
============================================================================= */
void SOUND(char reg, char value);



/* =============================================================================
 PlayFX

 Function : Play FX
 Input    : [char] channel (0, 1 or 2)
            [*FX] sound data in FX structure
 Output   : -
============================================================================= */
void PlayFX(char channel, FX *soundat);



/* =============================================================================
 SetChannel

 Function : Enable/disable Tone and Noise channels.
 Input    : [char] channel (0, 1 or 2)
            [boolean] tone state
            [boolean] noise state
 Output   : -
============================================================================= */
void SetChannel(char channel, boolean isTone, boolean isNoise);



/* =============================================================================
 SilencePSG

 Function : Silence the three PSG channels.
 Input    : -
 Output   : -
============================================================================= */
void SilencePSG();



#endif