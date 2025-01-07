/* ==============================================================================
               ___   ___  ___ 
  _ __  ____ _|   \ / _ \/ __|
 | '  \(_-< \ / |) | (_) \__ \
 |_|_|_/__/_\_\___/ \___/|___/

	MSX-DOS Function Calls (by MSX Assembly Page)
	http://map.grauw.nl/resources/dos2_functioncalls.php
	
	MSX-DOS 2 Program Interface Specification (by MSX Assembly Page)
	http://map.grauw.nl/resources/dos2_environment.php

	MSX2-Technical-Handbook
	CHAPTER 3 - MSX-DOS
	https://konamiman.github.io/MSX2-Technical-Handbook/md/Chapter3.html
	
	Nextor 2.1 Programmers Reference
	https://github.com/Konamiman/Nextor/blob/v2.1/docs/Nextor%202.1%20Programmers%20Reference.md
============================================================================== */

#ifndef  __MSXDOS_H__
#define  __MSXDOS_H__




/*
https://ia801501.us.archive.org/17/items/msx-dos-2-command-specification-1986-11-26-version-2.00/MSX-DOS_2_System_Specification_1986-11-26_version_2.00.pdf
MSX-DOS 2 System Specification
3 Disk Device Interface 
3.2 Disk driver initialization
At initialization time the "INIHRD", "DRIVES" and "INIENV" routines of the disk driver will 
each be called once, it that order. None of these three routines will ever be called again.

"INIHRD" should just initialize the hardware. When this routine is called the disk driver 
workspace has not yet been allocated.
*/

// KDOS_INIHRD	EQU	$????	//Initialize Hardware
// KDOS_DRIVES	EQU	$????	//Return number of drives in system
// KDOS_INIENV	EQU	$????	//Initialize work area

// Disk Driver Table
#define KDOS_DISKIO	0x4010	//Physical input/output for disk devices (See PHYDIO in main BIOS)
#define KDOS_DSKCHG	0x4013	//Check if disk has been changed
#define KDOS_GETDPB	0x4016	//Get Drive Parameter Block
#define KDOS_CHOICE	0x4019	//Get string that describes disk formatting options
#define KDOS_DSKFMT	0x401C	//Format disk
#define KDOS_DSKSTP	0x401F	//Stop the drive motor of the corresponding interface (or MTOFF)?

// Kernel table
#define KDOS_BASENT	0x4022	//BASIC cold start
#define KDOS_FORMBS	0x4025	//Format a disk in BASIC by asking the user for settings (oficial name?)
#define KDOS_FORMTM	0x4026	//Format a disk from a program with user-specified parameters
#define KDOS_MTOFF 	0x4029	//Stop all drives of all controllers
#define KDOS_GETSLT	0x402D	//Get slot ID of disk ROM
#define KDOS_GETLAD	0x4030	//Get lowest address used by the base MSX-DOS system (oficial name?)



/*
BDOS (Basic Disk Operating System)
DOS Kernel
https://www.msx.org/wiki/Disk-ROM_BIOS
Disk Driver table
*/


#define BDOS    0x0005
#define BDOSram 0xF37D //BDOS alternative entry



//MSX-DOS1 Function Calls
#define DOS_TERM0     0x00	//Program terminate
#define DOS_CONIN     0x01	//Console input
#define DOS_CONOUT    0x02	//Console output
#define DOS_AUXIN     0x03	//Auxiliary input
#define DOS_AUXOUT    0x04	//Auxiliary output
#define DOS_LSTOUT    0x05	//Printer output
#define DOS_DIRIO     0x06	//Direct console I/O
#define DOS_DIRIN     0x07	//Direct console input
#define DOS_INNOE     0x08	//Console input without echo
#define DOS_STROUT    0x09	//String output
#define DOS_BUFIN     0x0A	//Buffered line input
#define DOS_CONST     0x0B	//Console status
#define DOS_CPMVER    0x0C	//Return version number
#define DOS_DSKRST    0x0D	//Disk reset
#define DOS_SELDSK    0x0E	//Select disk
#define DOS_FOPEN     0x0F	//Open file (FCB)
#define DOS_FCLOSE    0x10	//Close file (FCB)
#define DOS_SFIRST    0x11	//Search for first entry (FCB)
#define DOS_SNEXT     0x12	//Search for next entry (FCB)
#define DOS_FDEL      0x13	//Delete file (FCB)
#define DOS_RDSEQ     0x14	//Sequential read (FCB)
#define DOS_WRSEQ     0x15	//Sequential write (FCB)
#define DOS_FMAKE     0x16	//Create file (FCB)
#define DOS_FREN      0x17	//Rename file (FCB)
#define DOS_LOGIN     0x18	//Get login vector
#define DOS_CURDRV    0x19	//Get current drive
#define DOS_SETDTA    0x1A	//Set disk transfer address
#define DOS_ALLOC     0x1B	//Get allocation information
#define DOS_RDRND     0x21	//Random read (FCB)
#define DOS_WRRND     0x22	//Random write (FCB)
#define DOS_FSIZE     0x23	//Get file size (FCB)
#define DOS_SETRND    0x24	//Set random record (FCB)
#define DOS_WRBLK     0x26	//Random block write (FCB)
#define DOS_RDBLK     0x27	//Random block read (FCB)
#define DOS_WRZER     0x28	//Random write with zero fill (FCB)
#define DOS_GDATE     0x2A	//Get date
#define DOS_SDATE     0x2B	//Set date
#define DOS_GTIME     0x2C	//Get time
#define DOS_STIME     0x2D	//Set time
#define DOS_VERIFY    0x2E	//Set/reset verify flag
#define DOS_RDABS     0x2F	//Absolute sector read
#define DOS_WRABS     0x30	//Absolute sector write


//MSX-DOS2 Function Calls
#define DOS2_DPARM    0x31	//Get disk parameters
#define DOS2_FFIRST   0x40	//Find first entry
#define DOS2_FNEXT    0x41	//Find next entry
#define DOS2_FNEW     0x42	//Find new entry
#define DOS2_OPEN     0x43	//Open file handle
#define DOS2_CREATE   0x44	//Create file handle
#define DOS2_CLOSE    0x45	//Close file handle
#define DOS2_ENSURE   0x46	//Ensure file handle
#define DOS2_DUP      0x47	//Duplicate file handle
#define DOS2_READ     0x48	//Read from file handle
#define DOS2_WRITE    0x49	//Write to file handle
#define DOS2_SEEK     0x4A	//Move file handle pointer
#define DOS2_IOCTL    0x4B	//I/O control for devices
#define DOS2_HTEST    0x4C	//Test file handle
#define DOS2_DELETE   0x4D	//Delete file or subdirectory
#define DOS2_RENAME   0x4E	//Rename file or subdirectory
#define DOS2_MOVE     0x4F	//Move file or subdirectory
#define DOS2_ATTR     0x50	//Get/set file attributes
#define DOS2_FTIME    0x51	//Get/set file date and time
#define DOS2_HDELETE  0x52	//Delete file handle
#define DOS2_HRENAME  0x53	//Rename file handle
#define DOS2_HMOVE    0x54	//Move file handle
#define DOS2_HATTR    0x55	//Get/set file handle attributes
#define DOS2_HFTIME   0x56	//Get/set file handle date and time
#define DOS2_GETDTA   0x57	//Get disk transfer address
#define DOS2_GETVFY   0x58	//Get verify flag setting
#define DOS2_GETCD    0x59	//Get current directory
#define DOS2_CHDIR    0x5A	//Change current directory
#define DOS2_PARSE    0x5B	//Parse pathname
#define DOS2_PFILE    0x5C  //Parse filename
#define DOS2_CHKCHR   0x5D	//Check character
#define DOS2_WPATH    0x5E	//Get whole path string
#define DOS2_FLUSH    0x5F	//Flush disk buffers
#define DOS2_FORK     0x60	//Fork a child process
#define DOS2_JOIN     0x61	//Rejoin parent process
#define DOS2_TERM     0x62	//Terminate with error code
#define DOS2_DEFAB    0x63	//Define abort exit routine
#define DOS2_DEFER    0x64	//Define disk error handler routine
#define DOS2_ERROR    0x65	//Get previous error code
#define DOS2_EXPLAIN  0x66	//Explain error code
#define DOS2_FORMAT   0x67	//Format a disk
#define DOS2_RAMD     0x68	//Create or destroy RAM disk
#define DOS2_BUFFER   0x69	//Allocate sector buffers
#define DOS2_ASSIGN   0x6A	//Logical drive assignment
#define DOS2_GENV     0x6B	//Get environment item
#define DOS2_SENV     0x6C	//Set environment item
#define DOS2_FENV     0x6D	//Find environment item
#define DOS2_DSKCHK   0x6E	//Get/set disk check status
#define DOS2_DOSVER   0x6F	//Get MSX-DOS version number
#define DOS2_REDIR    0x70	//Get/set redirection status




/* ==============================================================================
MSX-DOS 2 Error Messages

References:
- MSX Resource Center · Wiki · MSX-DOS 2 Error Messages
  https://www.msx.org/wiki/Category:MSX-DOS_2_Error_Messages
- MSX Assembly Page · MSX-DOS 2 Program Interface Specification · Errors
  https://map.grauw.nl/resources/dos2_environment.php#c6

Notes:
The error code labels used are those published in the MSX Assembly Page document, 
with the addition of the prefix 'DOS2ERR_'. 

At the time of writing this guide, I don't know if they belong to an official 
definition. In other publications consulted I have not found any reference to 
them.

Codes 0, 126, 127 and 183 did not contain a name, so I have provided them with 
one trying to follow the style of the documented ones.

(1) Don't display an error message, although they correspond to an internal error. 
(2) Undocumented labels.
============================================================================== */

//System Errors
#define DOS2ERR_NOERR    0 //No Error (2)
#define DOS2ERR_ANYKEY 126 //Press any key to continue... (2)
#define DOS2ERR_INSDSK 127 //Insert MSX-DOS disk in drive: (2)

//Command Errors
#define DOS2ERR_OVDEST 129 //Cannot overwrite previous destination file
#define DOS2ERR_COPY   130 //File cannot be copied onto itself
#define DOS2ERR_BADEST 131 //Cannot create destination file
#define DOS2ERR_NOCAT  132 //Cannot concatenate destination file
#define DOS2ERR_BADVER 133 //Wrong version of MSX-DOS
#define DOS2ERR_NOHELP 134 //File for HELP not found
#define DOS2ERR_BADNO  135 //Invalid number
#define DOS2ERR_IOPT   136 //Invalid option
#define DOS2ERR_NOPAR  137 //Missing parameter
#define DOS2ERR_INP    138 //Too many parameters
#define DOS2ERR_IPARM  139 //Invalid parameter
#define DOS2ERR_OKCMD  140 //------- | COMMAND Internal error (1)
#define DOS2ERR_BUFUL  141 //Command too long
#define DOS2ERR_BADCM  142 //Unrecognized command
#define DOS2ERR_BADCOM 143 //Wrong version of COMMAND

//Program Termination Errors
#define DOS2ERR_INERR  155 //------- | Error on standard input (1)
#define DOS2ERR_OUTERR 156 //------- | Error on standard output (1)
#define DOS2ERR_ABORT  157 //Disk operation aborted
#define DOS2ERR_CTRLC  158 //Ctrl-C pressed
#define DOS2ERR_STOP   159 //Ctrl-STOP pressed

//MSX-DOS Function Errors
#define DOS2ERR_IFCBK  183 //Invalid File Control Block (2)
#define DOS2ERR_ISBFN  184 //Invalid sub-function number		
#define DOS2ERR_EOL    185 //System Error 185 | MSX-DOS Function Internal error (1)	
#define DOS2ERR_HDEAD  186 //File handle has been deleted	
#define DOS2ERR_NRAMD  187 //RAM disk does not exist	
#define DOS2ERR_RAMDX  188 //RAM disk (drive H:) already exists	
#define DOS2ERR_ITIME  189 //Invalid time
#define DOS2ERR_IDATE  190 //Invalid date	
#define DOS2ERR_ELONG  191 //Invalid string too long	
#define DOS2ERR_IENV   192 //Invalid environment string	
#define DOS2ERR_IDEV   193 //Invalid device operation	
#define DOS2ERR_NOPEN  194 //File handle not open	
#define DOS2ERR_IHAND  195 //Invalid file handle	
#define DOS2ERR_NHAND  196 //No spare file handles	
#define DOS2ERR_IPROC  197 //Invalid process id	
#define DOS2ERR_ACCV   198 //File access violation	
#define DOS2ERR_EOF    199 //End of file	
#define DOS2ERR_FILE   200 //File allocation error
#define DOS2ERR_OV64K  201 //Cannot transfer above 64K
#define DOS2ERR_FOPEN  202 //File already in use
#define DOS2ERR_FILEX  203 //File exists
#define DOS2ERR_DIRX   204 //Directory exists
#define DOS2ERR_SYSX   205 //System file exists
#define DOS2ERR_DOT    206 //Invalid . or .. operation
#define DOS2ERR_IATTR  207 //Invalid attributes
#define DOS2ERR_DIRNE  208 //Directory not empty
#define DOS2ERR_FILRO  209 //Read only file
#define DOS2ERR_DIRE   210 //Invalid directory move
#define DOS2ERR_DUPF   211 //Duplicate filename
#define DOS2ERR_DKFUL  212 //Disk full
#define DOS2ERR_DRFUL  213 //Root directory full
#define DOS2ERR_NODIR  214 //Directory not found
#define DOS2ERR_NOFIL  215 //File not found
#define DOS2ERR_PLONG  216 //Pathname too long
#define DOS2ERR_IPATH  217 //Invalid pathname
#define DOS2ERR_IFNM   218 //Invalid filename
#define DOS2ERR_IDRV   219 //Invalid drive
#define DOS2ERR_IBDOS  220 //Invalid MSX-DOS call
//#define DOS2ERR_     221 //System Error 221
#define DOS2ERR_NORAM  222 //Not enough memory
#define DOS2ERR_INTER  223 //Internal error

//Disk errors
#define DOS2ERR_IFORM  240 //Cannot format this drive
#define DOS2ERR_NOUPB  241 //System Error 241 | Disk change Internal error (1) 
#define DOS2ERR_IFAT   242 //Bad file allocation table
#define DOS2ERR_SEEK   243 //Seek error
#define DOS2ERR_WFILE  244 //Wrong disk for file
#define DOS2ERR_WDISK  245 //Wrong disk
#define DOS2ERR_NDOS   246 //Not a DOS disk
#define DOS2ERR_UFORM  247 //Unformatted disk
#define DOS2ERR_WPROT  248 //Write protected disk
#define DOS2ERR_RNF    249 //Sector not found
#define DOS2ERR_DATA   250 //Data error
#define DOS2ERR_VERFY  251 //Verify error
#define DOS2ERR_NRDY   252 //Not ready
#define DOS2ERR_DISK   253 //Disk error
#define DOS2ERR_WRERR  254 //Write error
#define DOS2ERR_NCOMP  255 //Incompatible disk


#endif