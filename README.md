# MSX fR3eL SDCC Libraries Project

![title logo](https://github.com/mvac7/SDCC_MSX_fR3eL/blob/main/GFX/logos/fR3eL_m_328x104.png)

---

## Project info

<table>
<tr><td>Architecture</td><td>MSX</td></tr>
<tr><td>Environment</td><td>ROM, MSX-DOS or MSX BASIC</td></tr>
<tr><td>Format</td><td>SDCC Relocatable object file (.rel)</td></tr>
<tr><td>Compiler</td><td>SDCC v4.4</td></tr>
</table>

<br/>

---

# Attention, please!

| Z80 calling conventions |
| :---       |
| Some libraries aren't adapted to the improvements added in the new SDCC releases (Z80 calling conventions), so they won't work.<br/>I'm working on adapting them and adding improvements.<br/>Thank you for your patience. |

This project is **WORK IN PROCESS**.

This project is not finished and I cannot guarantee its completion.

There are no libraries for disk access (MSX-DOS).

There are no libraries for hardware like the superior VDPs (V9938 or V9958), or PSGs like the SCC, FM, ...

The project is alive, so it may undergo changes. 

I'm currently adapting the library code to the Z80 calling conventions included in SDCC version 4.1.12. [#5](https://github.com/mvac7/SDCC_MSX_fR3eL/issues/5)
I'm taking this opportunity to add improvements and reorganize the different parts of the project, which is why it's taking longer than expected.
Among these changes, I'm renaming the projects so they're more easily identifiable. [#6](https://github.com/mvac7/SDCC_MSX_fR3eL/issues/6)

You can use it freely, but keep in mind that there are better and more complete libraries, such as [`Fusion-C`](https://github.com/ericb59/Fusion-C-v1.2) by [_Eric Boez_](https://github.com/ericb59), [`MSXgl`](https://github.com/aoineko-fr/MSXgl) by [_Aoineko_](https://github.com/aoineko-fr) or [`libmsx`](https://github.com/mori0091/libmsx) by [_Daishi Mori_](https://github.com/mori0091).
(See section [`C Libraries or Engines for MSX`](#C-Libraries-or-Engines-for-MSX)). 

The choice is yours.

Thanks for waiting.

mvac7 _aka a0rante_

<br/>

---

## About MSX fR3eL Project 

This repository compiles all the fR3eL libraries for the development in C language of MSX applications with the SDCC cross compiler.

It also provides startups (CRTs) and Makefiles for different types of application formats (ROM or MSX-DOS), in a C project structure prepared to start a new project.

Most of the libraries use the BIOS of the MSX System, with what is achieved lightness and compatibility but not speed. 

It will not be a problem, for most of the cases where the use is controlled, but if you need to perform tasks that work with large volumes of data (such as dynamic graphics), you may need to program more optimal functions and adapted to the requirements of your project.
                                                                                                                                                                                   
Unlike other libraries that are more homogeneous, here you can find in some cases several libraries addressing the same task in different ways (as in the case of SPRITES). That is so you can choose the solution that best suits your needs.

You can improve them, cut what you need or transform them to other compilers, for your personal projects or you can share them with the community. 

<br/>

---

### Authors:

This project has been developed mainly by mvac7, but includes code and ideas contributed by numerous developers who share their knowledge with the MSX community.
I add here a list of people who have participated directly or indirectly, in recognition of their work.
 
- mvac7 (Coder and project manager)
- Avelino Herrera (Knowledge)
- Konamiman (CRTs and Knowledge)
- Fubukimaru (Linux Makefiles and documentation fixes)
- Ramones (Mouse Library) 
- AndreaR (Mouse Library SDCC adaptation and Knowledge)
- S.V.Bulba (PT3 Player) 
- Dioniso (PT3 Player MSX adaptation), 
- MSXKun (PT3 Player improvements and Knowledge) 
- SapphiRe (ayFX Player and PT3 Player improvements)
- WYZ (WYZ Player)
- baze - Includes a 16-bit integer to ASCII conversion routine, based on [num2Dec16](http://baze.sk/3sc/misc/z80bits.html#5.1)

<br/>

---

## License

This project is open source under the [MIT license](LICENSE).
You can add part or all of this code in your application development or include it in other libraries/engines.

<br/>

---

## Requirements

- [Small Device C Compiler (SDCC) v4.4](http://sdcc.sourceforge.net/)
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

<br/>

- MSX Assembly Page > [`WEB`](http://map.grauw.nl/resources/msxbios.php)
- MSX Resource Center > [`WEB`](https://www.msx.org)
- Portar MSX Tech Doc > [`WEB`](https://problemkaputt.de/portar.htm)
- Karoshi MSX Community > [`WEB`](http://karoshi.auic.es/)

<br/>

---

## Project Structure

Uses a standard structure for C projects:

```
/bin			<--- final file (ROM, COM or BIN)
/build			<--- compiler output files
/crt0			<--- SDCC startup files (CRT)
/include		<--- general and library includes from fR3eL
/libs			<--- fR3eL libraries
/src			<--- source code
MAKEFILE.BAT	<--- Windows script
makefile		<--- Linux script
```

<br/>

In the [c_project_structure](https://github.com/mvac7/SDCC_MSX_fR3eL/tree/main/c_project_structure) folder you will find the basis for starting a project for different MSX environments.

- MSX 32K ROM
- MSX 8 or 16K ROM (at 4000h address)
- MSX 8 or 16K ROM (at 8000h address)
- MSX-DOS (without parameters)
- MSX-DOS with parameters

<br/>

---

## Startup files (CRT)

| Library | Description |
| :---    | :---        |
| [crt0_MSX816kROM4000](https://github.com/mvac7/SDCC_startup_MSX816kROM4000)  | MSX 8/16K 4000h ROM startup file (CRT) |
| [crt0_MSX816kROM8000](https://github.com/mvac7/SDCC_startup_MSX816kROM8000)  | MSX 8/16K 8000h ROM startup file (CRT) |
| [crt0_MSX32kROM4000](https://github.com/mvac7/SDCC_startup_MSX32kROM4000)    | MSX 32K 4000h ROM startup file (CRT)   |
| [crt0_MSXDOS](https://github.com/mvac7/SDCC_startup_MSXDOS/tree/main/CRT0_simple) | Simple CRT for MSX-DOS applications without parameters |
| [crt0_MSXDOS_advanced](https://github.com/mvac7/SDCC_startup_MSXDOS/tree/main/CRT0_advanced) | Advanced CRT for MSX-DOS applications with parameter input |

<br/>

---
 
## List of Libraries

They are divided into three groups, since in some cases they have been developed to work in specific execution environments: 
- with BIOS (ROM or MSX BASIC) 
- without BIOs (MSX-DOS)
- for any of the environments

<br/>
 

| Note: |
| :---  |
| Libraries that do not specify an environment can be used in `ROM`, `MSX-DOS` or `MSX BASIC` |


### General Pourpose

- **MSX Memory** C function library for accessing Z80 memory and slots/subslots on MSX computers. [`Project`](https://github.com/mvac7/fR3eL_memory_MSX_Libraries) - [`DOC`](https://github.com/mvac7/fR3eL_memory_MSX_Libraries/blob/master/docs/HOWTO.md)
	- _memory_Z80.rel_ Provides you with functions to read or write to the memory.
	- _memory_Slots_MSX.rel_ Allows you to configure the pages of the slots and subslots.
- **Interrupt M1** Libraries to work with Z80 Mode 1 interrupts. [`Project`](https://github.com/mvac7/fR3eL_interruptM1_Libraries) - [`DOC`](https://github.com/mvac7/fR3eL_interruptM1_Libraries/blob/main/ISR/docs/HOWTO.md)
	- _interruptM1_ISR.rel_ Functions to control the Interrupt Service Routine (ISR).
	- _interruptM1_Hooks.rel_ Functions to control the MSX system interrupt hooks.
- **Keyboard** - Library with Basic functions for reading the keyboard of MSX computers. [`Project`](https://github.com/mvac7/fR3eL_keyboard_MSX_Libraries) - [`DOC`](https://github.com/mvac7/fR3eL_keyboard_MSX_Libraries/blob/master/docs/HOWTO.md)
	- _keyboard_MSXBIOS_ Uses the MSX BIOS. It takes up very little memory. `ROM` or `MSX BASIC` 
	- _keyboard_MSXDOS_ Uses the MSX BIOS functions via inter-slot call (CALSLT). `MSX-DOS`
- **Joystick** - Library with basic functions for reading Joystick controllers or Cursor Keys. [`Project`](https://github.com/mvac7/fR3eL_joystick_MSX_Lib) - [`DOC`](https://github.com/mvac7/fR3eL_joystick_MSX_Lib/blob/master/docs/HOWTO.md)
	- _joystick_MSX_ Does not use the MSX BIOS. For all environments.
	- _joystick_MSXBIOS_ Uses the MSX BIOS. It takes up very little memory. `ROM` or `MSX BASIC`
- **String Basics** - Basic functions for the managing C Strings. [`Project`](https://github.com/mvac7/fR3eL_string_Basics_Lib) - [`DOC`](https://github.com/mvac7/fR3eL_string_Basics_Lib/blob/master/docs/HOWTO.md)

<br/>

### Video

- **VDP_TMS9918A** - Library with basic functions to work with the TMS9918A video processor. [`Project`](https://github.com/mvac7/fR3eL_VDP_TMS9918A_Lib) - [`DOC`](https://github.com/mvac7/fR3eL_VDP_TMS9918A_Lib/blob/master/docs/HOWTO.md)
- **VDP_TMS9918A_MSXBIOS** - Library with basic functions to work with the TMS9918A video processor. `ROM` or `MSX BASIC`  [`Project`](https://github.com/mvac7/SDCC_VDP_TMS9918A_MSXROM_Lib) - [`DOC`](https://github.com/mvac7/fR3eL_VDP_TMS9918A_MSXBIOS_Lib/blob/master/docs/HOWTO.md)
- **VDP_SPRITES** - Library for directly accessing sprite attributes from the TMS9918A/28A/29A video processor._ [`Project`](https://github.com/mvac7/fR3eL_VDP_SPRITES_Lib) - [`DOC`](https://github.com/mvac7/fR3eL_VDP_SPRITES_Lib/blob/master/docs/HOWTO.md)
- **VDP_PRINT** Library for displaying text strings in TMS9918A graphics modes (Graphic1 and Graphic2). [`Project`](https://github.com/mvac7/fR3eL_VDP_PRINT_Lib) - [`DOC`](https://github.com/mvac7/fR3eL_VDP_PRINT_Lib/blob/master/docs/HOWTO.md)
- **Textmode** - with functions for developing text-mode applications. Includes functions for screen initialization and printing of texts and numbers. [`Project`](https://github.com/mvac7/fR3eL_textmode_MSX_Lib) - [`DOC`](https://github.com/mvac7/fR3eL_textmode_MSX_Lib/blob/master/docs/HOWTO.md)
	- _textmode_MSXBIOS_ Uses the MSX BIOS. It takes up very little memory. `ROM` or `MSX BASIC` 
	- _textmode_MSXDOS_ Uses the MSX BIOS functions via inter-slot call (CALSLT). `MSX-DOS`

<br/>

### Pending conversion to SDCC v4.4

- **Mouse** - Basic functions for reading mouse controller of MSX computers. [`Project`](https://github.com/mvac7/SDCC_MOUSE_MSX_Lib) 
- **WRLE decompress (aka RLEWB)** - C Library for decompress WRLE data encoding. [`Project`](https://github.com/mvac7/Z80_RLEWB)
- **PSG AY-3-8910 RT Library** - Basic functions to work with PSG AY-3-8910 or compatible. [`Project`](https://github.com/mvac7/SDCC_AY38910RT_Lib) - [`DOC`](https://github.com/mvac7/SDCC_AY38910RT_Lib/blob/master/docs/HOWTO.md)
- **PSG AY-3-8910 BF Library** - Library to access the internal or external PSG AY-3-8910 through a Buffer. [`Project`](https://github.com/mvac7/SDCC_AY38910BF_Lib) - [`DOC`](https://github.com/mvac7/SDCC_AY38910BF_Lib/blob/main/docs/HOWTO.md)
- **PSG ayFX Player Library** - Play ayFX effects for the PSG AY-3-8910 (requires AY38910BF library) [`Project`](https://github.com/mvac7/SDCC_ayFXplayer) - [`DOC`](https://github.com/mvac7/SDCC_ayFXplayer_Lib/blob/main/docs/HOWTO.md)
- **PT3 Player Library for MSX** - SDCC PT3 Player (Vortex Tracker) Library for MSX (requires AY38910BF library) [`Project`](https://github.com/mvac7/SDCC_PT3player) - [`DOC`](https://github.com/mvac7/SDCC_PT3player/blob/master/docs/HOWTO.md)
- **WYZ Player Library for MSX** - SDCC WYZ Tracker Player Library for MSX. [`Project`](https://github.com/mvac7/SDCC_WYZplayer)

<br/>

### Deprecated

- **PSG AY-3-8910 playFX Library** - Functions for playing sound effects with the AY-3-8910. [`Project`](https://github.com/mvac7/SDCC_AY38910_playFX_Lib)  

<br/>

---

## fR3eL AY Sound System

The [`AY38910BF`](https://github.com/mvac7/SDCC_AY38910BF_Lib), [`PT3player`](https://github.com/mvac7/SDCC_AY38910BF_Lib) and [`ayFXplayer`](https://github.com/mvac7/SDCC_ayFXplayer) libraries are designed to work together, so you will have a system to provide music and effects in game development.

![AY Sound System](https://raw.githubusercontent.com/mvac7/SDCC_AY38910BF_Lib/master/docs/AYlibs.png)

<br/>

---

## fR3eL's Development Tools

- [`WYZtoSDCCobj Converter Tool`](https://github.com/mvac7/mSXdevtools_WYZtoSDCCobj) - WYZ to C Object Converter Tool for WYZ Player MSX SDCC Library
- [`PT3toCdata Converter Tool`](https://github.com/mvac7/mSXdevtools_PT3toCdata) - Vortex PT3 to C data Converter Tool

<br/>

- [`WYZ Tracker`](https://github.com/AugustoRuiz/WYZTracker) _by Augusto Ruiz_
- [`Vortex Tracker`](https://bulba.untergrund.net/vortex_e.htm) _by Sergey Bulba_

<br/>

- [`AY Sound FX Editor`](https://shiru.untergrund.net/software.shtml) _by Shiru_
- [`AY Sound FX Editor (Improved)`](https://github.com/Threetwosevensixseven/ayfxedit-improved) by _Shiru_ and _Robin Verhagen-Guest_

<br/>

---

##  Projects that use fR3eL

- [The Alan Randoms Project](https://github.com/mvac7/TARP) (TARP) _Random music maker for MSX computers._

<br/>

---

# Development resources

## Libraries or Engines for MSX Cross-Platform Development in C

- **Libraries for SDCC** `SDCC` _by Avelino Herrera_ [`WEB`](http://msx.avelinoherrera.com/index_en.html)  
- **Libraries for SDCC** `SDCC` _by Konamiman_ [`WEB`](https://www.konamiman.com/msx/msx-e.html#sdcc)
- **Fusion-C** `SDCC` _by Eric Boez_ [`gitHub`](https://github.com/ericb59/Fusion-C-v1.2)
- **MSXgl** `SDCC` _by Aoineko_ [`gitHub`](https://github.com/aoineko-fr/MSXgl) The MSX Game Library in C language
- **RetroDeluxe Game Engine** `SDCC` _by Retro DeLuxe_ [`gitHub`](https://github.com/retrodeluxe/rlengine-msx)
- **libmsx** `SDCC` _by Daishi Mori (mori0091)_ [`gitHub`](https://github.com/mori0091/libmsx)
- **MSXLib** `SDCC` _by Marq_ [`WEB`](http://www.kameli.net/marq/?page_id=974) --> Get it with svn co svn://www.kameli.net/marq/msxlib
- **sdcc-msx** `SDCC` _by Manuel Martinez Torres_ [`gitHub`](https://github.com/MartinezTorres/sdcc_msx)
- **ubox MSX lib** `SDCC` _by Juan J. Martinez_ [`gitLab`](https://gitlab.com/reidrac/ubox-msx-lib) · [`WEB`](https://www.usebox.net/jjm/ubox-msx-lib/)
- **GFX lib** `Hitech-C` _by Janonne_ [`gitHub`](https://github.com/jannone/msx-gfxlib)

<br/>

## Development Tools

- [`nMSXtiles`](https://github.com/pipagerardo/nMSXtiles) - Tiles and Sprites Editor for MSX in SC2 and SC4 graphic mode - _by Pentacour_ and _PipaGerardo_
- [`99x8Edit`](https://github.com/YusukeLab/99x8Edit) - Graphic editor for systems based on TI TMS9918 and Yamaha V9938 - _by Yusuke Miyauchi_
- [`png2msx`](https://github.com/pipagerardo/png2msx) - Tools for graphics and data in MSX. - _by PipaGerardo_
- [`PCXTOOLS`](https://github.com/theNestruo/pcxtools) - MSX cross-development command line tools PNG2MSX, PNG2SPR[+] and TMX2BIN - _by theNestruo_
- [`IMG2SPR`](http://andrear.altervista.org/home/msxsoftware.php) Sprite generator utility - _by AndreaR_
- [`MSX Pixel Tools`](https://github.com/reidrac/msx-pixel-tools) - Convert PNG images into sprites and tilesets to be used by the MSX in screen 2 mode - _by Juan J. Martínez (reidrac)_
- [`CMSXbin`](https://github.com/aoineko-fr/CMSXbin) - Convert binary to text file - By Guillaume "Aoineko" Blanchard
- [`CMSXimg`](https://github.com/aoineko-fr/CMSXimg) - Command line tool to create images table to add to MSX programs (C/ASM/Bin) - _by Guillaume "Aoineko" Blanchard_
- [`CMSXmath`](https://github.com/aoineko-fr/CMSXmath) - Command line tool to create pre-calculated mathematics tables - _by Guillaume "Aoineko" Blanchard_
- [`MSX Tile Forge`](https://github.com/DamnedAngel/msx-tile-forge) - A Pallete, Tile, Supertile, Palette, and Map Editor for MSX, built with Python and Tkinter - _by DamnedAngel_

<br/>

## MSX Emulators

- [`OpenMSX`](http://openmsx.sourceforge.net/) Emulator
- [`BlueMSX`](http://www.bluemsx.com/) Emulator
- [`Meisei`](https://github.com/pipagerardo/meisei) emulator - _by Hap_ and _PipaGerardo_
- [`WebMSX`](https://webmsx.org/) Emulator  >> [`gitHub`](https://github.com/ppeccin/webmsx) - _by Paulo A. Peccin_
- [`MSXPen`](https://msxpen.com/) MSX Developer Playground & Code Editor in the Browser - _by_ [_Rafael Jannone_](https://twitter.com/jannone)
- [`fMSX`](https://fms.komkon.org/fMSX/) - _by Marat Fayzullin_


<br/>

## Documentation

### MSX
- [MSX2 Technical Handbook](https://konamiman.github.io/MSX2-Technical-Handbook/)
- [The MSX Red Book](https://github.com/gseidler/The-MSX-Red-Book/blob/master/the_msx_red_book.md)
- [MSX Assembly Page](https://map.grauw.nl/)
	- [Z80/R800 instruction set](https://map.grauw.nl/resources/z80instr.php)
- [Portar MSX Tech Doc](https://problemkaputt.de/portar.htm)
- MSX Resource Center · [Development Wiki](https://www.msx.org/wiki/#Developing_for_MSX)

<br/>

### Tutorials
- **MoltSXalats** - Blog about programming with FUSION-C - [English](https://moltsxalats.wixsite.com/fusionc) - [Català](https://moltsxalats.wixsite.com/fusionc/ca) - [Español](https://moltsxalats.wixsite.com/fusionc/es)
- Tutorial práctico de desarrollo de videojuegos para ordenadores MSX (por Frederic García Nieto) > [PDF](https://riunet.upv.es/bitstream/handle/10251/145214/Memoria.pdf?sequence=2)

<br/>

### MSX Hardware

#### VDP TMS9918A
- Texas Instruments TMS9918A application manual [`PDF`](http://map.grauw.nl/resources/video/texasinstruments_tms9918.pdf)
- Texas Instruments VDP Programmer's Guide [`PDF`](http://map.grauw.nl/resources/video/ti-vdp-programmers-guide.pdf)
- Texas Instruments TMS9918A VDP by Sean Young [`TXT`](http://bifi.msxnet.org/msxnet/tech/tms9918a.txt)
- The MSX Red Book · [2 Video Display Processor](https://github.com/gseidler/The-MSX-Red-Book/blob/master/the_msx_red_book.md#chapter_2)

<br/>

#### VDP V9938
- V9938 Technical Data Book [`PDF`](http://map.grauw.nl/resources/video/yamaha_v9938.pdf) [`TXT`](http://map.grauw.nl/resources/video/v9938/v9938.xhtml)
- V9938 Programmers Guide [`PDF`](http://rs.gr8bit.ru/Documentation/V9938-programmers-guide.pdf)
- Portar Doc [Video Display Processor](https://problemkaputt.de/portar.htm#videodisplayprocessor)

<br/>

#### VDP V9958
- V9958 Technical Data Book [`PDF`](http://map.grauw.nl/resources/video/yamaha_v9958_ocr.pdf)

<br/>

#### PSG AY-3-8910
- GI AY-3-8910 Datasheet [`PDF`](http://map.grauw.nl/resources/sound/generalinstrument_ay-3-8910.pdf)
- The MSX Red Book [3. Programmable Sound Generator](https://github.com/gseidler/The-MSX-Red-Book/blob/master/the_msx_red_book.md#chapter_3)

<br/>

### Programming languages
- Z80 Assembler - [z80 Heaven](http://z80-heaven.wikidot.com/)
- Wikibooks [C Programming](https://en.wikibooks.org/wiki/C_Programming)
