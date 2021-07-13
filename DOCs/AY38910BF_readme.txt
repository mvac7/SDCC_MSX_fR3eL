PSG AY-3-8910 BF MSX SDCC Library (fR3eL Project)
Version: v0.9b
Date: 7 July 2021
Author: mvac7
Architecture: MSX
Format: C Object (SDCC .rel)
Programming language: C and Z80 assembler
Project WEB: https://github.com/mvac7/SDCC_AY38910_Lib


--------------------------------------------------------------------------------    
History of versions:

- v0.9b (7 July 2021) First version (Based in AY-3-8910 RT Library)



--------------------------------------------------------------------------------
Index:

1 Description
2 Acknowledgments.
3 Requirements
4 Definitions
  4.1 AY Type
  4.2 AY Registers
  4.3 Envelope shapes
  4.4 AY Channels 

5 Functions
  5.1 AY_Init()
  5.2 SOUND(register, value)
  5.3 GetSound(register)
  5.4 SetTonePeriod(channel, period)
  5.5 SetNoisePeriod(period)
  5.6 SetEnvelopePeriod(period)
  5.7 SetVolume(channel, volume)
  5.8 SetChannel(channel, isTone, isNoise)
  5.9 SetEnvelope(shape)
  5.10 PlayAY() 
                       
6 Set Internal or External AY



--------------------------------------------------------------------------------
1. Description

This project is an opensource library functions for access to internal or 
external MSX PSG AY-3-8910. 

Designed for developing MSX applications using Small Device C Compiler (SDCC).
  
It does not use the BIOS so it can be used to program both ROMs or MSX-DOS 
executables.
  
This library is similar to the [PSG AY-3-8910 RT]
(https://github.com/mvac7/SDCC_AY38910RT_Lib), but instead of writing directly 
to the registers, it does so to a buffer that should be dumped to the AY in each
VBLANK frame.

It is designed to work together with the PT3player and/or ayFXplayer libraries, 
but you can also use it for your own or third-party player.

It incorporates the SOUND function with the same behavior as the command 
included in MSX BASIC, as well as specific functions to modify the different 
sound parameters of the AY. 

Controls the I/O bits of register 7 (Mixer), of the internal AY.

It allows to use the internal PSG of the MSX or an external one (like the one 
incorporated in the MEGAFLASHROM SCC +).

In the header file there is a definition of SWITCHER type, needed for the 
functions. This type uses the values "ON" or "OFF", which equals 1 and 0 
respectively.

Include definitions to improve the readability of your programs.

In the source code (\examples), you can find applications for testing and 
learning purposes.                          

This library is part of the MSX fR3eL Project
https://github.com/mvac7/SDCC_MSX_fR3eL

Enjoy it! 



--------------------------------------------------------------------------------
2. Acknowledgments
  
I want to give a special thanks to all those who freely share their knowledge 
with the MSX developer community.

* Avelino Herrera > [WEB] http://msx.avelinoherrera.com
* Nerlaska > [Blog] http://albertodehoyonebot.blogspot.com.es
* Marq/Lieves!Tuore > [Blog] http://www.kameli.net/marq/
* MSXKun/Paxanga soft > [WEB] http://paxangasoft.retroinvaders.com/
* Fubukimaru [Blog] http://www.gamerachan.org/fubu/
* Andrear > [Blog] http://andrear.altervista.org/home/msxsoftware.php
* Ramones > 
  - [MSXblog] https://www.msxblog.es/tutoriales-de-programacion-en-ensamblador-ramones/
  - [MSXbanzai] http://msxbanzai.tni.nl/dev/faq.html
* Sapphire/Z80ST > [WEB] http://z80st.auic.es/
* Fernando Garc�a > http://www.z80st.es/cursos/bitvision-assembler
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

 * Small Device C Compiler (SDCC) v4.1 
   http://sdcc.sourceforge.net/
     
 * Hex2bin v2.5 
   http://hex2bin.sourceforge.net/



--------------------------------------------------------------------------------
4 Definitions


4.1 AY Type 

  * AY_INTERNAL = 0
  * AY_EXTERNAL = 1



4.2 AY Registers
  
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
  
  

4.3 Envelope shapes

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

Attention! The LowerBeat shape may be produced with the values: 0,1,2,3 and 9. 
The value 1 has been assigned to LowerBeat as 0 can be useful in case you need
to control when the envelope is triggered. In this case 0 can act as a "don't
write the envelop" event. Remember that, every time the register 13 is written,
the sound with the assigned shape is started.

The Upper shape may be produced with the values: 4,5,6,7 and 15.



4.4 AY Channels

  You can use it in the functions: SetTonePeriod, SetVolume and SetChannel.
  
  * AY_Channel_A = 0
  * AY_Channel_B = 1
  * AY_Channel_C = 2



  
--------------------------------------------------------------------------------
5 Functions



================================================================================
5.1 AY_Init()

 Function : Initialize the buffer
 Input    : -
 Output   : -
 Examples : 

            AY_Init();



================================================================================
5.2 SOUND(register, value)

 Function : Write into a register of PSG
 Input    : [char] register number (0 to 13)
            [char] value
 Output   : -
 Examples : 

            Sound(8,16); //channel A envelope on


================================================================================
5.3 GetSound(register) 

 Function : Read PSG register value
 Input    : [char] register number (0 to 13)
 Output   : [char] value
 Examples :              

            char value;            
            value = GetSound(7);  //read mixer register


================================================================================
5.4 SetTonePeriod(channel, period) 

 Function : Set Tone Period for any channel
 Input    : [char] channel (0, 1 or 2)
            [unsigned int] period (0 - 4095)
 Output   : -
 Examples :              

            SetTonePeriod(0, 1100);  //set tone period for channel A
            

================================================================================
5.5 SetNoisePeriod(period) 

 Function : Set Noise Period
 Input    : [char] Noise period (0 - 31) 
 Output   : -
 Examples :
 
            SetNoisePeriod(10);
            

================================================================================
5.6 SetEnvelopePeriod(period) 

 Function : Set Envelope Period
 Input    : [unsigned int] Envelope period (0 - 65535) 
 Output   : -
 Examples :
 
            SetEnvelopePeriod(1000);
 

================================================================================
5.7 SetVolume(channel, volume) 

 Function : Set volume channel
 Input    : [char] channel (0, 1 or 2)
            [char] volume, 0 to 15 or 16 for activate envelope
 Output   : -
 Examples :
 
            SetVolume(0,14);  // set 14 volume level for channel A
            SetVolume(1,16);  // activate envelope for channel B


================================================================================
5.8 SetChannel(channel, isTone, isNoise)

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
5.9 SetEnvelope(shape) 

 Function : Set envelope type.
            Plays the sound on channels that have a volume of 16.
 Input    : [char] Envelope shape (0-15) (see envelope shapes definitions)
 Output   : -
 Examples :              

            SetEnvelope(0); //Play LowerBeat envelope shape
            
            SetEnvelope(ENV_LowerTriangle); //Play LowerTriangle envelope shape



================================================================================
5.10 PlayAY() 

 Function : Copy buffer to AY (internal or external).
 Input    : -
 Output   : -
 Examples :

            // Routine for Hook TIMI (FD9Fh)
            void my_TIMI() 
            {
              PUSH_AF;
              
              PlayAY();
            
              POP_AF;
            }
            


--------------------------------------------------------------------------------
6 Set Internal or External AY

To indicate in which PSG the sounds are to be played, you have the AY_TYPE 
variable. To select an external AY (ports 10h to 12h), like the one included in 
the MegaFlashROM SCC+, Flashjacks or other, you have to set the variable to 1 
(or AY_EXTERNAL).

  AY_TYPE = AY_EXTERNAL;
  


Attention!: When you execute the AY_Init() function, it will be updated to the 
default value corresponding to the internal AY.


================================================================================



