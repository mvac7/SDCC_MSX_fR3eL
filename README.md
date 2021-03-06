# MSX fR3eL SDCC Libraries Project

```
Authors: 
         mvac7
         Fubukimaru (Linux Makefiles)
         Ramones and Adrear (mouse Library)
         S.V.Bulba, Dioniso, MSXKun and SapphiRe (PT3 Player)
         SapphiRe (ayFX Player)
         WYZ (WYZ Player) 
Architecture: MSX
Format: C Object (SDCC .rel)
Programming language: C and Z80 assembler
```


# WORK IN PROCESS!



## About MSX fR3eL Project 

This repository compiles all the fR3eL libraries for the development in C language of MSX applications with the SDCC cross compiler.

It also provides startups (CRTs) and Makefiles for different types of application formats (ROM or MSX-DOS), in a directory structure prepared to start a project.

Most of the libraries use the BIOS of the MSX System, with what is achieved lightness and compatibility but not speed. 

It will not be a problem, for most of the cases where the use is controlled, but if you need to perform tasks that work with large volumes of data (such as dynamic graphics), you may need to program more optimal functions and adapted to the requirements of your project.
                                                                                                                                                                                   
Unlike other libraries that are more homogeneous, here you can find in some cases several libraries addressing the same task in different ways (as in the case of SPRITES). That is so you can choose the solution that best suits your needs.

You can improve them, cut what you need or transform them to other compilers, for your personal projects or you can share them with the community. 

The main reason that has led me to create this project is learning and to use them in my MSX application development.
 
You can use it freely, but keep in mind that there are better and more complete libraries, such as [Fusion-C](https://github.com/ericb59/Fusion-C-v1.2) by [Eric Boez](https://github.com/ericb59) (see section 'C Libraries for MSX'). 

The choice is yours.

mvac7



## Requirements

* Small Device C Compiler (SDCC) v4.1 > http://sdcc.sourceforge.net/
* Hex2bin v2.5 http://hex2bin.sourceforge.net/ 



## Acknowledgments
  
I want to thank everyone who has contributed directly or indirectly to this project in any way. 
I also want to thank everyone who selflessly shares information and code, as they contribute to continued development and extend the life of retro platforms.

* Avelino Herrera > [(WEB)](http://msx.avelinoherrera.com/index_es.html)
* Nerlaska > [(Blog)](http://albertodehoyonebot.blogspot.com.es)
* Marq/Lieves!Tuore > [(Marq)](http://www.kameli.net/marq/) [Lieves!Tuore](http://www.kameli.net/lt/)
* MSXKun/Paxanga soft > [(WEB)](http://paxangasoft.retroinvaders.com/)
* [Fubukimaru](https://github.com/Fubukimaru) > [Blog](http://www.gamerachan.org/fubu/)
* Andrear > [(Blog)](http://andrear.altervista.org/home/msxsoftware.php)
* Ramones > [(MSXblog)](https://www.msxblog.es/tutoriales-de-programacion-en-ensamblador-ramones/) - [MSXbanzai](http://msxbanzai.tni.nl/dev/faq.html)
* Sapphire/Z80ST > [(WEB)](http://z80st.auic.es/)
* WYZ [(WEB)](https://sites.google.com/site/wyzplayer/home)
* S.V.Bulba > [WEB](http://bulba.at.kz)
* Dioniso
* PipaGerardo [(gitHub)](https://github.com/pipagerardo)
* Ram�n de las Heras [(@pentacour)](https://twitter.com/pentacour)
* N�stor Sancho (theNestruo) [(gitHub)](https://github.com/theNestruo) 
* Baze > [(WEB)](http://baze.sk/3sc/misc/z80bits.html)
* Fernando Garc�a > [(Video Curso)](http://www.z80st.es/cursos/bitvision-assembler)
* Eric Boez > [(gitHub)](https://github.com/ericb59)
* Guillaume "Aoineko" Blanchard > [(gitHub)](https://github.com/aoineko-fr)
* MSX Assembly Page > [(WEB)](http://map.grauw.nl/)
* Portar MSX Tech Doc > [(WEB)](http://nocash.emubase.de/portar.htm)
* MSX Resource Center > [Wiki](https://www.msx.org/wiki/)
* Karoshi MSX Community (RIP 2007-2020)
* BlueMSX emulator >> [(WEB)](http://www.bluemsx.com/)
* OpenMSX emulator >> [(WEB)](http://openmsx.sourceforge.net/)
* WebMSX emulator >> [(gitHub)](https://github.com/ppeccin/webmsx)
* Meisei emulator >> ?


 
## List of Libraries

They are divided into three groups, since in some cases they have been developed to work in specific execution environments: ROMs or MSX-DOS.

### To develop MSX ROMs:

- **MSX 8/16K 8000h ROM startup file (CRT)** [(gitHub project)](https://github.com/mvac7/SDCC_startup_MSX816kROM8000)
- **MSX 8/16K 4000h ROM startup file (CRT)** [(gitHub project)](https://github.com/mvac7/SDCC_startup_MSX816kROM4000)
- **MSX 32K 4000h ROM startup file (CRT)** [(gitHub project)](https://github.com/mvac7/SDCC_startup_MSX32kROM4000)
- **Keyboard MSX ROM Library** - _Functions for reading the keyboard of MSX computers._ [(gitHub project)](https://github.com/mvac7/SDCC_KEYBOARD_MSXROM_Lib)
- **Joystick MSX ROM Library** - _Basic functions for reading Joystick controllers or Cursor Keys._ [(gitHub project)](https://github.com/mvac7/SDCC_JOYSTICK_MSXROM_Lib)
- **Textmode MSX ROM Library** - _Functions for starting and printing in text modes._ [(gitHub project)](https://github.com/mvac7/SDCC_TEXTMODE_MSXROM_Lib)
- **VDP TMS9918A MSX ROM Library** - _Basic functions to work with the TMS9918A video processor using the MSX BIOS._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_TMS9918A_MSXROM_Lib)
- **VDP SPRITES MSX ROM Library** - _Functions to facilitate the use of Sprites of the TMS9918A._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_SPRITES_MSXROM_Lib)
- **VDP SPRITES mode 1/2 MSX ROM Library** - _Basic functions for managing Sprites with facilities to work with G3 mode (Screen 4)._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_SPRITES_12_MSXROM_Lib)
- **VDP SPRITES Small MSX ROM Library** - _ClearSprites and PUTSPRITE functions._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_SPRITES_S_MSXROM_Lib)
- **VDP SPRITES mode 2 MSX ROM SDCC Library** - _Library with functions to display mode 2 sprites in V9938 graphics mode 3_ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_SPRITES_mode2_MSXROM_Lib)


### To develop MSX-DOS applications (.COM):

- **Keyboard MSX-DOS Library** - _Functions for reading the keyboard of MSX computers._ [(gitHub project)](https://github.com/mvac7/SDCC_KEYBOARD_MSXDOS_Lib)
- **Joystick MSX-DOS Library** - _Basic functions for reading Joystick controllers or Cursor Keys._ [(gitHub project)](https://github.com/mvac7/SDCC_JOYSTICK_MSXDOS_Lib)
- **Textmode MSX-DOS Library** - _Functions for starting and printing in text modes._ [(gitHub project)](https://github.com/mvac7/SDCC_TEXTMODE_MSXDOS_Lib)


### To develop anything:

- **Z80 Memory MSX Library** - _Basic functions for Z80's memory and page slots/sublots access._ [(gitHub project)](https://github.com/mvac7/SDCC_MEMORY_MSX_Lib)
- **Z80 Interrupt M1 Hooks MSX Library** - _Control over the hooks (TIMI and KEYI) of the ISR of the MSX System for the M1 interrupt of the Z80_ [(gitHub project)](https://github.com/mvac7/SDCC_interruptM1_Hooks)
- **VDP TMS9918A Library** - _Functions to work with the TMS9918A without using the MSX BIOS._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_TMS9918A_Lib) 
- **VDP SPRITES Library** - _Functions to facilitate the use of Sprites of the TMS9918A._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_SPRITES_Lib)
- **VDP PRINT Library** - _Functions Library for display text strings in the graphic modes of the TMS9918A (G1 and G2)._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_PRINT_Lib)
- **String BASICs Library** - _Basic functions for the treatment of Character Arrays in SDCC, similar to those of MSX BASIC._ [(gitHub project)](https://github.com/mvac7/SDCC_STRING_B_Lib)
- **PSG AY-3-8910 RT Library** - _Basic functions to work with PSG AY-3-8910 or compatible._ [(gitHub project)](https://github.com/mvac7/SDCC_AY38910RT_Lib)
- **PSG AY-3-8910 playFX Library** - _Functions for playing sound effects with the AY-3-8910._ [(gitHub project)](https://github.com/mvac7/SDCC_AY38910_playFX_Lib)
- **PSG AY-3-8910 BF Library** - _Library to access the internal or external PSG AY-3-8910 through a Buffer._ [(gitHub project)](https://github.com/mvac7/SDCC_AY38910BF_Lib)
- **PSG ayFX Player Library** - _Play ayFX effects for the PSG AY-3-8910 (requires AY38910BF library)_ [(gitHub project)](https://github.com/mvac7/SDCC_ayFXplayer)
- **PT3 Player Library for MSX** - _SDCC PT3 Player (Vortex Tracker) Library for MSX (requires AY38910BF library)_ [(gitHub project)](https://github.com/mvac7/SDCC_PT3player)
- **WYZ Player Library for MSX** - _SDCC WYZ Tracker Player Library for MSX._ [(gitHub project)](https://github.com/mvac7/SDCC_WYZplayer)
- **Mouse MSX Library** - _Basic functions for reading mouse controller of MSX computers._ [(gitHub project)](https://github.com/mvac7/SDCC_MOUSE_MSX_Lib) 
- **Z80 RLEWB decompress** - _C functions and Z80 Assembler source for decompress RLEWB data encoding._ [(gitHub project)](https://github.com/mvac7/Z80_RLEWB)


## AY Sound System

The [AY38910BF](https://github.com/mvac7/SDCC_AY38910BF_Lib), [PT3player](https://github.com/mvac7/SDCC_AY38910BF_Lib) and [ayFXplayer](https://github.com/mvac7/SDCC_ayFXplayer) libraries are designed to work together, so you will have a system to provide music and effects in game development.

![AY Sound System](https://raw.githubusercontent.com/mvac7/SDCC_AY38910BF_Lib/master/doc/AYlibs.png)



<br/>

---

# Development resources

## C Libraries or Engines for MSX

* **Libraries for SDCC** _by Avelino Herrera_ [Link](http://msx.avelinoherrera.com/index_en.html)  
* **Libraries for SDCC** _by Konamiman_ [Link](https://www.konamiman.com/msx/msx-e.html#sdcc)
* **Fusion-C** (SDCC) _by Eric Boez_ [gitHub](https://github.com/ericb59/Fusion-C-v1.2)
* **RetroDeluxe Game Engine** (SDCC) _by Retro DeLuxe_ [gitHub](https://github.com/retrodeluxe/rlengine-msx)
* **MSXLib** (SDCC) _by Marq_ [Link](http://www.kameli.net/marq/?page_id=974) --> Get it with svn co svn://www.kameli.net/marq/msxlib
* **sdcc-msx** _by Manuel Martinez Torres_ [gitHub](https://github.com/MartinezTorres/sdcc_msx)
* **ubox MSX lib** (SDCC) _by Juan J. Martinez_ [gitHub](https://github.com/reidrac/ubox-msx-lib)
* **GFX lib** (Hitech-C) _by Janonne_ [Link](https://github.com/jannone/msx-gfxlib)

<br/>

## Development Tools

* [nMSXtiles](https://github.com/pipagerardo/nMSXtiles) - Tiles and Sprites Editor for MSX in SC2 and SC4 graphic mode - By Pentacour and PipaGerardo
* [png2msx](https://github.com/pipagerardo/png2msx) - Tools for graphics and data in MSX. - By PipaGerardo
* [PCXTOOLS](https://github.com/theNestruo/pcxtools) - MSX cross-development command line tools PNG2MSX, PNG2SPR[+] and TMX2BIN - 
* [MSX Pixel Tools](https://github.com/reidrac/msx-pixel-tools) - Convert PNG images into sprites and tilesets to be used by the MSX in screen 2 mode - By Juan J. Mart�nez (reidrac)
* [CMSXbin](https://github.com/aoineko-fr/CMSXbin) - Convert binary to text file - By Guillaume "Aoineko" Blanchard
* [CMSXimg](https://github.com/aoineko-fr/CMSXimg) - Command line tool to create images table to add to MSX programs (C/ASM/Bin) - By Guillaume "Aoineko" Blanchard
* [CMSXmath](https://github.com/aoineko-fr/CMSXmath) - Command line tool to create pre-calculated mathematics tables - By Guillaume "Aoineko" Blanchard
* [WYZtoSDCCobj Converter Tool](https://github.com/mvac7/mSXdevtools_WYZtoSDCCobj) - WYZ to C Object Converter Tool for WYZ Player MSX SDCC Library
* [PT3toCdata Converter Tool](https://github.com/mvac7/mSXdevtools_PT3toCdata) - Vortex PT3 to C data Converter Tool.

<br/>

## Documentation

* [MSX2 Technical Handbook](https://konamiman.github.io/MSX2-Technical-Handbook/)
* [The MSX Red Book](https://github.com/gseidler/The-MSX-Red-Book/blob/master/the_msx_red_book.md)
* [MSX Assembly Page](http://map.grauw.nl/)
* [Portar MSX Tech Doc](http://nocash.emubase.de/portar.htm)
* MSX Resource Center [Sevelopment Wiki](https://www.msx.org/wiki/#Developing_for_MSX)
* Tutorial pr�ctico de desarrollo de videojuegos para ordenadores MSX (por Frederic Garc�a Nieto) > [PDF](https://riunet.upv.es/bitstream/handle/10251/145214/Memoria.pdf?sequence=2)
