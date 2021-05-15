PSG AY-3-8910 MSX SDCC Library (fR3eL Project)
Version: v1.5
Date: 09/05/2021
Author: mvac7
Architecture: MSX
Format: C Object (SDCC .rel)
Programming language: C and Z80 assembler
Project WEB: https://github.com/mvac7/SDCC_AY38910_Lib


--------------------------------------------------------------------------------    
History of versions:

- v1.5 (09/05/2021) 
    + External AY    

- v1.4 (17/06/2018)
    + corrected a BUG in the SOUND function
    + change name function Sound to SOUND

- v1.3 (11/02/2018)
    + Revised and first publication.

- v1.2 (?)

- v1.1 (14/02/2014)
    + Initial version.

- v1.0 (?)



--------------------------------------------------------------------------------
Index:

1 Introduction
2 Acknowledgments.
3 Requirements
4 Definitions
  4.1 AY Registers
  4.2 Envelope shapes
  4.3 AY Channels 

5 Functions
  5.1 SOUND(register, value)
  5.2 GetSound(register)
  5.3 SetTonePeriod(channel, period)
  5.4 SetNoisePeriod(period)
  5.5 SetEnvelopePeriod(period)
  5.6 SetVolume(channel, volume)
  5.7 SetChannel(channel, isTone, isNoise)
  5.8 PlayEnvelope(shape) 
                       
6 Set Internal or External AY



--------------------------------------------------------------------------------
1. Introduction:

This project is an opensource library (object type), with basic functions for 
work with PSG AY-3-8910 or compatible. 

Designed for developing MSX applications using Small Device C Compiler (SDCC).
  
It does not use the BIOS so it can be used to program both ROMs or MSX-DOS
executables.
  
Reading or writing to the PSG is done through calls to the assigned ports. 

It incorporates the SOUND function with the same behavior as the command 
included in MSX BASIC, as well as specific functions to modify the different 
sound parameters of the AY.

It allows to use the internal PSG of the MSX or an external one 
(like the one incorporated in the MEGAFLASHROM SCC +).

In the header file there is a definition of boolean type, need for the functions.
This type uses the values "true" or "false" in lowercase, which equals 1 and 0 
respectively.

Include definitions to improve the readability of your programs.

In the WEB of the project in gitHub you will find the sources and examples to 
test and learn how to use the library.    
https://github.com/mvac7/SDCC_AY38910_Lib                           


This library is part of the MSX fR3eL Project
https://github.com/mvac7/SDCC_MSX_fR3eL

Enjoy it! 



--------------------------------------------------------------------------------
2. Acknowledgments
  
I want to give a special thanks to all those who freely share their knowledge 
with the MSX developer community.

* Avelino Herrera > [WEB] http://msx.atlantes.org/index_es.html
* Nerlaska > [Blog] http://albertodehoyonebot.blogspot.com.es
* Marq/Lieves!Tuore > [Blog] http://www.kameli.net/marq/
* Fubukimaru [Blog] http://www.gamerachan.org/fubu/
* Andrear > [Blog] http://andrear.altervista.org/home/msxsoftware.php
* Ramones > 
  - [MSXblog] https://www.msxblog.es/tutoriales-de-programacion-en-ensamblador-ramones/
  - [MSXbanzai] http://msxbanzai.tni.nl/dev/faq.html
* Sapphire/Z80ST > [WEB] http://z80st.auic.es/
* Fernando García > [youTube] https://www.youtube.com/user/bitvision
* Eric Boez > [gitHub] https://github.com/ericb59
* MSX Assembly Page > [WEB] http://map.grauw.nl/resources/msxbios.php
* Portar MSX Tech Doc > [WEB] http://nocash.emubase.de/portar.htm
* MSX Resource Center > [WEB] http://www.msx.org/
* Karoshi MSX Community (RIP 2007-2020)
* BlueMSX emulator >> [WEB] http://www.bluemsx.com/
* OpenMSX emulator >> [WEB] http://openmsx.sourceforge.net/
* Meisei emulator >> ?



--------------------------------------------------------------------------------
3. Requirements:

 * Small Device C Compiler (SDCC) v3.9 
   http://sdcc.sourceforge.net/
     
 * Hex2bin v2.5 
   http://hex2bin.sourceforge.net/



--------------------------------------------------------------------------------
4 Definitions

4.1 AY Registers
  
  * AY_ToneA = 0  ---> Channel A Tone Period (12 bits)
  * AY_ToneB = 2  ---> Channel B Tone Period (12 bits)
  * AY_ToneC = 4  ---> Channel C Tone Period (12 bits)
  * AY_Noise = 6  ---> Noise Period (5 bits)
  * AY_Mixer = 7  ---> Mixer
  * AY_AmplA = 8  ---> Channel Volume A (4 bits + B5 active Envelope)
  * AY_AmplB = 9  ---> Channel Volume B (4 bits + B5 active Envelope)
  * AY_AmplC = 10 ---> Channel Volume C (4 bits + B5 active Envelope)
  * AY_Env   = 11 ---> Envelope Period (12 bits)
  * AY_EnvTp = 13 ---> Envelope Type
  
  
4.2 Envelope shapes

  The header file defines envelope shapes in case you prefer to use it instead 
  of the numerical form:
 
  * AY_ENV_LowerBeat     = 1 
  * AY_ENV_Upper         = 4 
  * AY_ENV_LeftSaw       = 8
  * AY_ENV_LowerTriangle = 10 
  * AY_ENV_LowerHold     = 11 
  * AY_ENV_RightSaw      = 12
  * AY_ENV_UpperHold     = 13
  * AY_ENV_UpperTriangle = 14

Attention! The LowerBeat form is produced with the values: 0, 1, 2 and 3. 
The value 1 has been assigned, since 0 can be useful in cases where it is 
required to have control of when the envelope is fired (every time is written 
to register 13, the sound with the assigned shape is started).



4.3 AY Channels

  You can use it in the functions: SetTonePeriod, SetVolume and SetChannel.
  
  * AY_Channel_A = 0
  * AY_Channel_B = 1
  * AY_Channel_C = 2



  
--------------------------------------------------------------------------------
5 Functions


================================================================================
5.1 SOUND(register, value)

 Function : Write into a register of PSG
 Input    : [char] register number (0 to 13)
            [char] value
 Output   : -
 Examples : 

            Sound(8,16); //channel A envelope on


================================================================================
5.2 GetSound(register) 

 Function : Read PSG register value
 Input    : [char] register number (0 to 13)
 Output   : [char] value
 Examples :              

            char value;            
            value = GetSound(7);  //read mixer register


================================================================================
5.3 SetTonePeriod(channel, period) 

 Function : Set Tone Period for any channel
 Input    : [char] channel (0, 1 or 2)
            [unsigned int] period (0 - 4095)
 Output   : -
 Examples :              

            SetTonePeriod(0, 1100);  //set tone period for channel A
            

================================================================================
5.4 SetNoisePeriod(period) 

 Function : Set Noise Period
 Input    : [char] Noise period (0 - 31) 
 Output   : -
 Examples :
 
            SetNoisePeriod(10);
            

================================================================================
5.5 SetEnvelopePeriod(period) 

 Function : Set Envelope Period
 Input    : [unsigned int] Envelope period (0 - 65535) 
 Output   : -
 Examples :
 
            SetEnvelopePeriod(1000);
 

================================================================================
5.6 SetVolume(channel, volume) 

 Function : Set volume channel
 Input    : [char] channel (0, 1 or 2)
            [char] volume, 0 to 15 or 16 for activate envelope
 Output   : -
 Examples :
 
            SetVolume(0,14);  // set 14 volume level for channel A
            SetVolume(1,16);  // activate envelope for channel B


================================================================================
5.7 SetChannel(channel, isTone, isNoise)

 Function : Mixer. Enable/disable Tone and Noise channels.
 Input    : [char] channel (0, 1 or 2)
            [boolean] tone state
            [boolean] noise state
 Output   : -
 Examples : 
 
            SetChannel(0,true,false);
            SetChannel(1,true,true);
            SetChannel(2,false,false); 
 
             
================================================================================
5.8 PlayEnvelope(shape) 

 Function : Set envelope type.
            Plays the sound on channels that have a volume of 16.
 Input    : [char] Envelope shape (0-15) (see envelope shapes definitions)
 Output   : -
 Examples :              

            PlayEnvelope(0); //Play LowerBeat envelope shape
            
            PlayEnvelope(ENV_LowerTriangle); //Play LowerTriangle envelope shape

            

--------------------------------------------------------------------------------
6 Set Internal or External AY

To indicate in which PSG the sounds are to be played, you have the isAYextern 
variable. To select an external AY, like the one included in the MegaFlashROM 
SCC+ (ports 10h to 12h), you have to set the variable to true (or 1).

  isAYextern = true;

The library does not contain an initialization function so it is recommended to 
provide a value to this variable at the beginning of your program.




================================================================================



