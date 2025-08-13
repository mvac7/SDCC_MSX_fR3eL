/* =============================================================================
  VDP TMS9918A MSX BIOS Library (fR3eL Project)
============================================================================= */
#ifndef  __VDP_TMS9918A_H__
#define  __VDP_TMS9918A_H__




/* ----------------------------------------------------------------------------
VDP Ports
---------------------------------------------------------------------------- */
#define VDPVRAM   0x98  //VRAM Data (Read/Write)
#define VDPSTATUS 0x99  //VDP Status Registers



/* ----------------------------------------------------------------------------
VDP Registers
---------------------------------------------------------------------------- */
#define VDP_Mode0		0
#define VDP_Mode1		1
#define VDP_BGmap		2
#define VDP_BGcolors	3
#define VDP_BGtiles		4
#define VDP_OBJattr		5
#define VDP_OBJtiles	6
#define VDP_Color		7



// ---------------------------------------------------------
// screen modes
// https://konamiman.github.io/MSX2-Technical-Handbook/md/Chapter4a.html#3--screen-modes-of-the-msx2
#define TEXT1		0	// text mode       (screen 0)
#define GRAPHIC1	1	// graphics 1 mode (screen 1)
#define GRAPHIC2	2	// graphics 2 mode (screen 2)
#define MULTICOLOR	3	// multicolor mode (screen 3)



// ---------------------------------------------------------
// TMS9918 palette color codes
#ifndef _COLORS
#define _COLORS
#define TRANSPARENT   0
#define BLACK         1
#define GREEN         2
#define LIGHT_GREEN   3
#define DARK_BLUE     4
#define LIGHT_BLUE    5
#define DARK_RED      6
#define CYAN          7
#define RED           8
#define LIGHT_RED     9
#define DARK_YELLOW  10
#define LIGHT_YELLOW 11
#define DARK_GREEN   12
#define MAGENTA      13
#define GREY         14
#define GRAY         14
#define WHITE        15
#endif



/* ----------------------------------------------------------------------------
Definition of the different zones of the video memory.
---------------------------------------------------------------------------- */
//Text1
#define T1_MAP	0x0000 // Name Table
#define T1_PAT	0x0800 // Pattern Table

//GRAPHIC1
#define G1_MAP	0x1800 // Name Table
#define G1_PAT	0x0000 // Pattern Table
#define G1_COL	0x2000 // Color Table

//GRAPHIC2
#define G2_MAP	0x1800 // Name Table
#define G2_PAT	0x0000 // Pattern Table
#define G2_PAT_A	0x0000 // Pattern Table Bank A
#define G2_PAT_B	0x0800 // Pattern Table Bank B
#define G2_PAT_C	0x1000 // Pattern Table Bank C
#define G2_COL	0x2000 // Color Table
#define G2_COL_A	0x2000 // Color Table Bank A
#define G2_COL_B	0x2800 // Color Table Bank B
#define G2_COL_C	0x3000 // Color Table Bank C

//MULTICOLOR
#define MC_MAP	0x0800 // Name Table
#define MC_PAT	0x0000 // Pattern Table (A tile contains the color data of 2x2 blocks)

//Sprites
#define SPR_OAM 0x1B00 // Sprite Attribute Table (Object Attribute Memory)
#define SPR_PAT 0x3800 // Sprite Pattern Table



/* ----------------------------------------------------------------------------
Definition of the different zones of the video memory, based on the 
BASE instruction of MSX BASIC.
OAM = Object Attribute Memory
---------------------------------------------------------------------------- */
// VRAM address tables Text1 (Screen 0)
#define BASE0 0x0000 // Name Table
#define BASE2 0x0800 // Pattern Table

// VRAM address tables GRAPHIC1 (Screen 1) TXT32
#define BASE5 0x1800 // Name Table
#define BASE6 0x2000 // Color Table
#define BASE7 0x0000 // Pattern Table
#define BASE8 0x1B00 // Sprite Attribute Table (OAM)
#define BASE9 0x3800 // Sprite Pattern Table

// VRAM address tables GRAPHIC2 (Screen 2)
#define BASE10 0x1800 // Name Table
#define BASE11 0x2000 // Color Table
#define BASE12 0x0000 // Pattern Table
#define BASE13 0x1B00 // Sprite Attribute Table (OAM)
#define BASE14 0x3800 // Sprite Pattern Table

// VRAM address tables MULTICOLOR (Screen 3)
#define BASE15 0x0800 // Name Table
#define BASE17 0x0000 // Pattern Table
#define BASE18 0x1B00 // Sprite Attribute Table (OAM)
#define BASE19 0x3800 // Sprite Pattern Table



/* ----------------------------------------------------------------------------
G2 BANKs addends
Labels to facilitate the positioning of the tileset banks in G2 mode.
---------------------------------------------------------------------------- */
#define BANK0  0x0000
#define BANK1  0x0800
#define BANK2  0x1000



/* ----------------------------------------------------------------------------
Sprite Sizes
---------------------------------------------------------------------------- */
#define SPRITES8x8		0
#define SPRITES16x16	1



/* ----------------------------------------------------------------------------
Sprite Zoom
---------------------------------------------------------------------------- */
#define SPRITESzoomX1		0
#define SPRITESzoomX2		1



/* ----------------------------------------------------------------------------
Sprite hiding coordinates
---------------------------------------------------------------------------- */
#define	SPRITES_YHIDDEN	0xD1	//concealment of the sprite outside the limits of the screen in TMS9918A modes





/* =============================================================================
SCREEN
Description:	
		Initializes the display to one of the four standardized modes on the MSX.
		Same as the SCREEN instruction in MSX BASIC.

Input:	[char] number of screen mode
			0 = TextMode1
			1 = Graphic1
			2 = Graphic2
			3 = MultiColor
Output:	-
============================================================================= */
void SCREEN(char mode);



/* =============================================================================
COLOR
Description: 
		Set the foreground, background, and border screen colors.
Input:	[char] ink color
		[char] background color
		[char] border color
Output:	-     
============================================================================= */
void COLOR(char ink, char background, char border);



/* =============================================================================
CLS 
Description: 
		 Clear Screen
		 Fills the Name Table with the value 0
		 Note: Does not hide Sprite planes.
Input:	-
Output:	-
============================================================================= */
void CLS(void);



/* =============================================================================
VPOKE
Description: 
		Writes a value to VRAM 
Input:	[unsigned int] VRAM address
		[char] value
Output:	- 
============================================================================= */
void VPOKE(unsigned int vaddr, char value);



/* =============================================================================
VPEEK
Description: 
		Reads a value from VRAM
Input:	[unsigned int] VRAM address
Output:	[char] value
============================================================================= */ 
char VPEEK(unsigned int vaddr);



/* =============================================================================
FillVRAM                               
Description:
		Fill a large area of the VRAM of the same byte
Input:	[unsigned int] address of VRAM
		[unsigned int] blocklength
		[char] Value to fill.
Output:	- 
============================================================================= */
void FillVRAM(unsigned int vaddr, unsigned int length, char value);



/* =============================================================================
CopyToVRAM
Description:
		Block transfer from memory to VRAM 
Input:	[unsigned int] address of RAM
		[unsigned int] address of VRAM
		[unsigned int] blocklength
Output:	- 
============================================================================= */
void CopyToVRAM(unsigned int addr, unsigned int vaddr, unsigned int length);



/* =============================================================================
CopyFromVRAM
Description:
		Block transfer from VRAM to memory
Input:	[unsigned int] address of VRAM                     
		[unsigned int] address of RAM
		[unsigned int] blocklength
Output:	-
============================================================================= */
void CopyFromVRAM(unsigned int vaddr, unsigned int addr, unsigned int length);



/* =============================================================================
GetVDP
Description:
		Gets the value in a VDP register.
		Provides the mirror value stored in system variables.
Input:	[char] VDP register number             
Output:	[char] Value            
============================================================================= */
char GetVDP(char reg);



/* =============================================================================
SetVDP
Description:
		Writes a value to a VDP register
Input:	[char] VDP register                     
		[char] value
Output:	-
============================================================================= */
void SetVDP(char reg, char value);





//############################################################################## SPRITEs functions



/* =============================================================================
ClearSprites
Description: 
		Initialises the Sprite Attribute Table (OAM) and Sprite Pattern Table.
Input:	-
Output:	-
============================================================================= */
void ClearSprites(void) ;



/* =============================================================================
SetSpritesSize
Description: 
		Set size type for the sprites.
Input:	[char] size: 0=8x8; 1=16x16
Output:	-
============================================================================= */ 
void SetSpritesSize(char size);



/* =============================================================================
SetSpritesZoom
Description: 
		Set zoom type for the sprites.
Input:	[char] or [boolean]/[switcher] zoom: 0/false/OFF = x1; 1/true/ON = x2
Output:	-
============================================================================= */
void SetSpritesZoom(char zoom);



/* =============================================================================
PUTSPRITE
Description: 
		Displays a Sprite on the screen.
Input:	[char] sprite plane (0-31) 
		[char] X coordinate 
		[char] Y coordinate
		[char] color (0-15)
		[char] pattern number
Output:	-
============================================================================= */
void PUTSPRITE(char plane, char x, char y, char color, char pattern);



/* =============================================================================
GetSPRattrVRAM
Description: 
		Gets the address in video memory of the Sprite attributes of specified 
		plane.
Input:	[char] sprite plane (0-31) 
Output:	[unsigned int] VRAM address
============================================================================= */
unsigned int GetSPRattrVRAM(char plane);



#endif