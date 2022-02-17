# MSX fR3eL SDCC Libraries Project

![title logo](https://github.com/mvac7/SDCC_MSX_fR3eL/blob/main/GFX/logos/fR3eL_m_328x104.png)

---

#### Authors:

This project has been developed mainly by mvac7, but includes code and ideas contributed by numerous developers who share their knowledge with the MSX community.
I add here a list of people who have participated directly or indirectly, in recognition of their work.
 
- mvac7 (Code Writer)
- Avelino Herrera (Knowledge)
- Fubukimaru (Linux Makefiles and documentation fixes)
- Ramones (Mouse Library) 
- AndreaR (Mouse Library SDCC adaptation and Knowledge)
- S.V.Bulba (PT3 Player) 
- Dioniso (PT3 Player MSX adaptation), 
- MSXKun (PT3 Player improvements) 
- SapphiRe (ayFX Player and PT3 Player improvements)
- WYZ (WYZ Player)
 
#### Architecture: MSX

#### Format: C Object (SDCC .rel)

#### Programming language: C and Z80 assembler

<br/>

---

# WORK IN PROCESS!

This project is not finished and I cannot guarantee its completion.

There are no libraries for disk access (MSX-DOS).

There are no libraries for hardware like the superior VDPs (V9938 or V9958), or PSGs like the SCC, FM, ...

The project is alive, so it may undergo changes. 

---

## About MSX fR3eL Project 

This repository compiles all the fR3eL libraries for the development in C language of MSX applications with the SDCC cross compiler.

It also provides startups (CRTs) and Makefiles for different types of application formats (ROM or MSX-DOS), in a directory structure prepared to start a project.

Most of the libraries use the BIOS of the MSX System, with what is achieved lightness and compatibility but not speed. 

It will not be a problem, for most of the cases where the use is controlled, but if you need to perform tasks that work with large volumes of data (such as dynamic graphics), you may need to program more optimal functions and adapted to the requirements of your project.
                                                                                                                                                                                   
Unlike other libraries that are more homogeneous, here you can find in some cases several libraries addressing the same task in different ways (as in the case of SPRITES). That is so you can choose the solution that best suits your needs.

You can improve them, cut what you need or transform them to other compilers, for your personal projects or you can share them with the community. 

The main reason that has led me to create this project is learning and to use them in my MSX application development.
 
You can use it freely, but keep in mind that there are better and more complete libraries, such as [`Fusion-C`](https://github.com/ericb59/Fusion-C-v1.2) by [Eric Boez](https://github.com/ericb59) (See section ['C Libraries or Engines for MSX'](#C-Libraries-or-Engines-for-MSX)). 

The choice is yours.

mvac7

<br/>

---

## Requirements

- [Small Device C Compiler (SDCC) v4.1](http://sdcc.sourceforge.net/)
- [Hex2bin v2.5](http://hex2bin.sourceforge.net/)

<br/>

---

## Acknowledgments
 
I want to give a special thanks everyone who selflessly shares information and code, as they contribute to continued development and extend the life of retro platforms.

- Avelino Herrera > [`WEB`](http://msx.avelinoherrera.com/index_es.html)
- Nerlaska > [`Blog`](http://albertodehoyonebot.blogspot.com.es)
- Marq/Lieves!Tuore > [`Marq`](http://www.kameli.net/marq/) [`Lieves!Tuore`](http://www.kameli.net/lt/)
- MSXKun/Paxanga soft > [`WEB`](http://paxangasoft.retroinvaders.com/)
- Fubukimaru [`gitHub`](https://github.com/Fubukimaru)
- AndreaR > [`Blog`](http://andrear.altervista.org/home/msxsoftware.php)
- Sapphire/Z80ST > [`WEB`](http://z80st.auic.es/)
- Fernando García > [`Video Tutorial`](http://www.z80st.es/cursos/bitvision-assembler)
- Ramones > [`MSXblog`](https://www.msxblog.es/tutoriales-de-programacion-en-ensamblador-ramones/) - [`MSXbanzai`](http://msxbanzai.tni.nl/dev/faq.html)
- Eric Boez > [`gitHub`](https://github.com/ericb59)
- WYZ [`WEB`](https://sites.google.com/site/wyzplayer/home)
- S.V.Bulba > [`WEB`](http://bulba.at.kz)
- Dioniso >> `?`
- PipaGerardo [`gitHub`](https://github.com/pipagerardo)
- Ramón de las Heras [`@pentacour`](https://twitter.com/pentacour)
- Néstor Sancho (theNestruo) [`gitHub`](https://github.com/theNestruo) 
- Baze > [`WEB`](http://baze.sk/3sc/misc/z80bits.html)
- Guillaume "Aoineko" Blanchard > [`gitHub`](https://github.com/aoineko-fr)
- Konamiman [`gitHub`](https://github.com/Konamiman) [`WEB`](https://www.konamiman.com/msx/msx-e.html)
- MSX Assembly Page > [`WEB`](http://map.grauw.nl/resources/msxbios.php)
- Portar MSX Tech Doc > [`WEB`](https://problemkaputt.de/portar.htm)
- MSX Resource Center > [`WEB`](https://www.msx.org)
- Karoshi MSX Community > [`WEB`](http://karoshi.auic.es/)
- BlueMSX emulator >> [`WEB`](http://www.bluemsx.com/)
- OpenMSX emulator >> [`WEB`](http://openmsx.sourceforge.net/)
- [`WebMSX`](https://webmsx.org/) emulator by Paulo A. Peccin >> [`gitHub`](https://github.com/ppeccin/webmsx)
- fMSX emulator by Marat Fayzullin [`WEB`](https://fms.komkon.org/fMSX/)
- Meisei emulator by Hap >> `?`

<br/>

---
 
## List of Libraries

They are divided into three groups, since in some cases they have been developed to work in specific execution environments: ROMs or MSX-DOS.

### To develop MSX ROMs:

- **MSX 8/16K 8000h ROM startup file (CRT)** [`Project`](https://github.com/mvac7/SDCC_startup_MSX816kROM8000)
- **MSX 8/16K 4000h ROM startup file (CRT)** [`Project`](https://github.com/mvac7/SDCC_startup_MSX816kROM4000)
- **MSX 32K 4000h ROM startup file (CRT)** [`Project`](https://github.com/mvac7/SDCC_startup_MSX32kROM4000)
- **Keyboard MSX ROM Library** - _Functions for reading the keyboard of MSX computers._ [`Project`](https://github.com/mvac7/SDCC_KEYBOARD_MSXROM_Lib) - [`DOC`](https://github.com/mvac7/SDCC_KEYBOARD_MSXROM_Lib/blob/master/docs/HOWTO.md)
- **Joystick MSX ROM Library** - _Basic functions for reading Joystick controllers or Cursor Keys._ [`Project`](https://github.com/mvac7/SDCC_JOYSTICK_MSXROM_Lib)
- **Textmode MSX ROM Library** - _Functions for starting and printing in text modes._ [`Project`](https://github.com/mvac7/SDCC_TEXTMODE_MSXROM_Lib)
- **VDP TMS9918A MSX ROM Library** - _Basic functions to work with the TMS9918A video processor using the MSX BIOS._ [`Project`](https://github.com/mvac7/SDCC_VDP_TMS9918A_MSXROM_Lib)
- **VDP SPRITES MSX ROM Library** - _Functions to facilitate the use of Sprites of the TMS9918A._ [`Project`](https://github.com/mvac7/SDCC_VDP_SPRITES_MSXROM_Lib)
- **VDP SPRITES mode 1/2 MSX ROM Library** - _Basic functions for managing Sprites with facilities to work with G3 mode (Screen 4)._ [`Project`](https://github.com/mvac7/SDCC_VDP_SPRITES_12_MSXROM_Lib)
- **VDP SPRITES Small MSX ROM Library** - _ClearSprites and PUTSPRITE functions._ [`Project`](https://github.com/mvac7/SDCC_VDP_SPRITES_S_MSXROM_Lib)
- **VDP SPRITES mode 2 MSX ROM SDCC Library** - _Library with functions to display mode 2 sprites in V9938 graphics mode 3_ [`Project`](https://github.com/mvac7/SDCC_VDP_SPRITES_mode2_MSXROM_Lib)


### To develop MSX-DOS applications (.COM):

- **Keyboard MSX-DOS Library** - _Functions for reading the keyboard of MSX computers._ [`Project`](https://github.com/mvac7/SDCC_KEYBOARD_MSXDOS_Lib) - [`DOC`](https://github.com/mvac7/SDCC_KEYBOARD_MSXDOS_Lib/blob/master/docs/HOWTO.md)
- **Joystick MSX-DOS Library** - _Basic functions for reading Joystick controllers or Cursor Keys._ [`Project`](https://github.com/mvac7/SDCC_JOYSTICK_MSXDOS_Lib)
- **Textmode MSX-DOS Library** - _Functions for starting and printing in text modes._ [`Project`](https://github.com/mvac7/SDCC_TEXTMODE_MSXDOS_Lib)


### To develop anything:

- **Z80 Memory MSX Library** - _Basic functions for Z80's memory and page slots/sublots access._ [`Project`](https://github.com/mvac7/SDCC_MEMORY_MSX_Lib) - [`DOC`](https://github.com/mvac7/SDCC_MEMORY_MSX_Lib/blob/master/docs/HOWTO.md)
- **Z80 Interrupt M1 Hooks MSX Library** - _Control over the hooks (TIMI and KEYI) of the ISR of the MSX System for the M1 interrupt of the Z80_ [`Project`](https://github.com/mvac7/SDCC_interruptM1_Hooks) - [`DOC`](https://github.com/mvac7/SDCC_interruptM1_Hooks_Lib/blob/main/docs/HOWTO.md)
- **VDP TMS9918A Library** - _Functions to work with the TMS9918A without using the MSX BIOS._ [`Project`](https://github.com/mvac7/SDCC_VDP_TMS9918A_Lib)  
- **VDP SPRITES Library** - _Functions to facilitate the use of Sprites of the TMS9918A._ [`Project`](https://github.com/mvac7/SDCC_VDP_SPRITES_Lib)
- **VDP PRINT Library v1.3** _Functions Library for display text strings in the graphic modes of the TMS9918A (G1 and G2)._ [`Project`](https://github.com/mvac7/SDCC_VDP_PRINT_Lib) - [`DOC`](https://github.com/mvac7/SDCC_VDP_PRINT_Lib/blob/master/docs/HOWTO.md)
- **String BASICs Library** - _Basic functions for the treatment of Character Arrays in SDCC, similar to those of MSX BASIC._ [`Project`](https://github.com/mvac7/SDCC_STRING_B_Lib)
- **PSG AY-3-8910 RT Library** - _Basic functions to work with PSG AY-3-8910 or compatible._ [`Project`](https://github.com/mvac7/SDCC_AY38910RT_Lib) - [`DOC`](https://github.com/mvac7/SDCC_AY38910RT_Lib/blob/master/HOWTO.md)
- **PSG AY-3-8910 playFX Library** - _Functions for playing sound effects with the AY-3-8910._ [`Project`](https://github.com/mvac7/SDCC_AY38910_playFX_Lib)
- **PSG AY-3-8910 BF Library** - _Library to access the internal or external PSG AY-3-8910 through a Buffer._ [`Project`](https://github.com/mvac7/SDCC_AY38910BF_Lib) - [`DOC`](https://github.com/mvac7/SDCC_AY38910BF_Lib/blob/main/docs/HOWTO.md)
- **PSG ayFX Player Library** - _Play ayFX effects for the PSG AY-3-8910 (requires AY38910BF library)_ [`Project`](https://github.com/mvac7/SDCC_ayFXplayer) - [`DOC`](https://github.com/mvac7/SDCC_ayFXplayer_Lib/blob/main/docs/HOWTO.md)
- **PT3 Player Library for MSX** - _SDCC PT3 Player (Vortex Tracker) Library for MSX (requires AY38910BF library)_ [`Project`](https://github.com/mvac7/SDCC_PT3player) - [`DOC`](https://github.com/mvac7/SDCC_PT3player/blob/master/docs/HOWTO.md)
- **WYZ Player Library for MSX** - _SDCC WYZ Tracker Player Library for MSX._ [`Project`](https://github.com/mvac7/SDCC_WYZplayer)
- **Mouse MSX Library** - _Basic functions for reading mouse controller of MSX computers._ [`Project`](https://github.com/mvac7/SDCC_MOUSE_MSX_Lib) 
- **Z80 RLEWB decompress** - _C functions and Z80 Assembler source for decompress RLEWB data encoding._ [`Project`](https://github.com/mvac7/Z80_RLEWB)

<br/>

---

## AY Sound System

The [`AY38910BF`](https://github.com/mvac7/SDCC_AY38910BF_Lib), [`PT3player`](https://github.com/mvac7/SDCC_AY38910BF_Lib) and [`ayFXplayer`](https://github.com/mvac7/SDCC_ayFXplayer) libraries are designed to work together, so you will have a system to provide music and effects in game development.

![AY Sound System](https://raw.githubusercontent.com/mvac7/SDCC_AY38910BF_Lib/master/docs/AYlibs.png)

<br/>

---

# Development resources

## Libraries or Engines for MSX Cross-Platform Development in C

- **Libraries for SDCC** `SDCC` _by Avelino Herrera_ [`WEB`](http://msx.avelinoherrera.com/index_en.html)  
- **Libraries for SDCC** `SDCC` _by Konamiman_ [`WEB`](https://www.konamiman.com/msx/msx-e.html#sdcc)
- **Fusion-C** `SDCC` _by Eric Boez_ [`gitHub`](https://github.com/ericb59/Fusion-C-v1.2)
- **RetroDeluxe Game Engine** `SDCC` _by Retro DeLuxe_ [`gitHub`](https://github.com/retrodeluxe/rlengine-msx)
- **libmsx** `SDCC` _by Daishi Mori (mori0091)_ [`gitHub`](https://github.com/mori0091/libmsx)
- **MSXLib** `SDCC` _by Marq_ [`WEB`](http://www.kameli.net/marq/?page_id=974) --> Get it with svn co svn://www.kameli.net/marq/msxlib
- **sdcc-msx** `SDCC` _by Manuel Martinez Torres_ [`gitHub`](https://github.com/MartinezTorres/sdcc_msx)
- **ubox MSX lib** `SDCC` _by Juan J. Martinez_ [`gitHub`](https://gitlab.com/reidrac/ubox-msx-lib)
- **MSXgl** `SDCC` _by Aoineko_ [`gitHub`](https://github.com/aoineko-fr/MSXgl) The MSX Game Library in C language
- **GFX lib** `Hitech-C` _by Janonne_ [`gitHub`](https://github.com/jannone/msx-gfxlib)

<br/>

## Development Tools

- [`nMSXtiles`](https://github.com/pipagerardo/nMSXtiles) - Tiles and Sprites Editor for MSX in SC2 and SC4 graphic mode - By Pentacour and PipaGerardo
- [`png2msx`](https://github.com/pipagerardo/png2msx) - Tools for graphics and data in MSX. - By PipaGerardo
- [`PCXTOOLS`](https://github.com/theNestruo/pcxtools) - MSX cross-development command line tools PNG2MSX, PNG2SPR[+] and TMX2BIN
- [`IMG2SPR`](http://andrear.altervista.org/home/msxsoftware.php) Sprite generator utility By AndreaR. 
- [`MSX Pixel Tools`](https://github.com/reidrac/msx-pixel-tools) - Convert PNG images into sprites and tilesets to be used by the MSX in screen 2 mode - By Juan J. Martínez (reidrac)
- [`CMSXbin`](https://github.com/aoineko-fr/CMSXbin) - Convert binary to text file - By Guillaume "Aoineko" Blanchard
- [`CMSXimg`](https://github.com/aoineko-fr/CMSXimg) - Command line tool to create images table to add to MSX programs (C/ASM/Bin) - By Guillaume "Aoineko" Blanchard
- [`CMSXmath`](https://github.com/aoineko-fr/CMSXmath) - Command line tool to create pre-calculated mathematics tables - By Guillaume "Aoineko" Blanchard
- [`WYZtoSDCCobj Converter Tool`](https://github.com/mvac7/mSXdevtools_WYZtoSDCCobj) - WYZ to C Object Converter Tool for WYZ Player MSX SDCC Library
- [`PT3toCdata Converter Tool`](https://github.com/mvac7/mSXdevtools_PT3toCdata) - Vortex PT3 to C data Converter Tool.


<br/>

## MSX Emulators

- OpenMSX emulator >> [`WEB`](http://openmsx.sourceforge.net/)
- BlueMSX emulator >> [`WEB`](http://www.bluemsx.com/)
- [`WebMSX`](https://webmsx.org/) emulator by Paulo A. Peccin >> [`gitHub`](https://github.com/ppeccin/webmsx)
- fMSX by Marat Fayzullin [`WEB`](https://fms.komkon.org/fMSX/)
- Meisei emulator by Hap >> `?`


<br/>

## Documentation

- [MSX2 Technical Handbook](https://konamiman.github.io/MSX2-Technical-Handbook/)
- [The MSX Red Book](https://github.com/gseidler/The-MSX-Red-Book/blob/master/the_msx_red_book.md)
- [MSX Assembly Page](http://map.grauw.nl/)
- [Portar MSX Tech Doc](https://problemkaputt.de/portar.htm)
- MSX Resource Center [Development Wiki](https://www.msx.org/wiki/#Developing_for_MSX)
- Tutorial práctico de desarrollo de videojuegos para ordenadores MSX (por Frederic García Nieto) > [PDF](https://riunet.upv.es/bitstream/handle/10251/145214/Memoria.pdf?sequence=2)
