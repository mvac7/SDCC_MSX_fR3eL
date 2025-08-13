/* =============================================================================
# Base Source Code MSXDOS with parameters

- Version: 0
- Author: 
- Architecture: MSX
- Format: MSX-DOS
- Programming language: C and Z80 assembler
- Compiler: SDCC 4.4
- Library: fR3eL Project

## Description:
	Use with SDCC MSXDOS Startup Advanced <crt0_MSXDOS_advanced.rel>
	
## Histoy of versions: (dd/mm/yyyy)
- v0
============================================================================= */
#include "../include/newTypes.h"
#include "../include/msxSystemVariables.h"
#include "../include/msxBIOS.h"
#include "../include/msxDOS.h"

//#include "../include/interruptM1_ISR.h"
//#include "../include/interruptM1_Hooks.h"

//#include "../include/memory_Slots_MSX.h"
//#include "../include/memory_Z80.h"

//#include "../include/keyboard_MSX.h"
//#include "../include/joystick_MSX.h"
//#include "../include/mouse_MSX.h"

//#include "../include/string_Basics.h"

//#include "../include/textmode_MSX.h"

//#include "../include/VDP_TMS9918A.h"
//#include "../include/VDP_SPRITES.h"
//#include "../include/VDP_PRINT.h"

//#include "../include/AY38910BF.h"
//#include "../include/AY38910RT.h"
//#include "../include/ayFXplayer.h"
//#include "../include/PT3player.h"
//#include "../include/WYZplayer.h"



// ---------------------------------------------------------------------------- Labels




// ---------------------------------------------------------------------------- Function Declaration




// ---------------------------------------------------------------------------- Constants




// ---------------------------------------------------------------------------- Global Variables



      
// ---------------------------------------------------------------------------- Functions
char main(char argc, char** argv) 
{
//	char i;
	char DOSerrocode=DOS2ERR_NOERR;    //0 = No Error (See msxDOS.h)


/*	if (argc!=0)
	{
		for(i=0;i<argc;i++){
			//argv[i]
		}  
	}else{
			// There are no parameters.
	}*/



	return DOSerrocode;		//return to DOS 
}
