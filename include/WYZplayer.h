/* =============================================================================
 SDCC WYZ player for MSX
 Version: 1.2 (15/02/2021)
 Author: MSX PSG proPLAYER v0.3 (09.03.2016) by WYZ/Iggy Rock
         Adapted to SDCC: mvac7/303bcn > <mvac7303b@gmail.com>
 Architecture: MSX
 Format: C Object (SDCC .rel)
 Programming language: Assembler and C (SDCC)
 WEB: https://sites.google.com/site/wyzplayer/home
      http://www.cpcwiki.eu/index.php/WYZTracker
      
 Description:
 Adaptation of the WYZ music player for programming in C with the SDCC compiler.                                          
============================================================================= */
#ifndef  __WYZ_PLAYER_H__
#define  __WYZ_PLAYER_H__



//AY38910 ports
#define AY0index 0xA0
#define AY0write 0xA1
#define AY0read  0xA2



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


/*
WYZstate = INTERR            
INTERRUPTORES 1=ON 0=OFF
- BIT 0=CARGA CANCION ON/OFF
- BIT 1=PLAYER ON/OFF
- BIT 2=EFECTOS ON/OFF
- BIT 3=SFX ON/OFF
- BIT 4=LOOP
*/
extern char WYZstate;

extern char SONG;   //number of song playing
extern char TEMPO;  //TEMPO

extern char AYREGS[16];       //PSG registers buffer

//extern unsigned int TABLA_SONG;    //songs index  
//extern unsigned int TABLA_PAUTAS;  //instruments index
//extern unsigned int TABLA_SONIDOS; //FXs index
//extern unsigned int DATOS_NOTAS;   //Data of the frequencies of the notes

//------------------------------------------------------------------------------



/* =============================================================================
 Player_Init
 Description: Initialize the Player
 Input:       (unsigned int) Songs data index memory address
              (unsigned int) Instruments data index memory address
              (unsigned int) FXs data index memory address
              (unsigned int) Notes Table memory address
 Output:      -
============================================================================= */
void Player_Init(unsigned int addrSONGs, unsigned int addrInstruments, unsigned int addrFXs, unsigned int addrFreqs);



/* =============================================================================
 Player_Pause
 Description: Pause song playback
 Input:       -
 Output:      -
============================================================================= */
void Player_Pause();  



/* =============================================================================
 Player_Resume
 Description: Resume song playback
 Input:       -
 Output:      -
============================================================================= */ 
void Player_Resume(); 



/* =============================================================================
 Player_Loop
 Description: Change loop mode
 Input:       [char] false = 0, true = 1
 Output:      -
============================================================================= */ 
void Player_Loop(char loop);



/* =============================================================================
 PlayFX
 Description: Play Sound Effect
 Input:       (char) FX number
 Output:      -
============================================================================= */
void PlayFX(char numSound); 



/* =============================================================================
 PlayAY
 Description: Send data from AYREGS buffer to AY registers.
              Execute on each interruption of VBLANK
 Input:       -
 Output:      -
============================================================================= */
void PlayAY();



/* =============================================================================
 Player_InitSong
 Description: Initialize song
 Input:       [char] song number
              [char] loop status (false = 0, true = 1)
 Output:      -
============================================================================= */
void Player_InitSong(char numSong, char loop); 



/* =============================================================================
 Player_Decode
 Description: Process the next step in the song sequence 
 Input:       -
 Output:      -
============================================================================= */
void Player_Decode(); 





// mute functions, 0=off, other=on
//void muteChannelA(char value);
//void muteChannelB(char value);
//void muteChannelC(char value);
//void muteChannelFX(char value);


#endif