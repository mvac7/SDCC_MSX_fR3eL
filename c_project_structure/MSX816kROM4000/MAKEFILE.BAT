@echo off
REM fR3eL Project
REM MAKEFILE for MSX 8/16K ROM at address 0x4000 for SDCC compiler
REM 1 > Configure
REM CFILENAME = Source name without extension
SET CFILENAME=sourcename
REM ROMFILENAME = ROM file name without extension (8 uppercase characters)
SET ROMFILENAME=ROMNAME
REM ROMSIZE = 2000 for 8KBytes ROM or 4000 for 16KBytes ROM
SET ROMSIZE=2000
SET CODELOC=0x4020
SET DATALOC=0xC000
SET CRT=crt0\crt0_MSX816kROM4000.rel
REM add paths from our REL files into LIBn variables
REM don't erase empty variables
SET LIB0=
SET LIB1=
SET LIB2=
SET LIB3=
SET LIB4=
SET LIB5=
SET LIB6=
SET LIB7=
SET LIB8=
SET LIB9=
SET LIB10=
SET LIB11=
SET LIB12=
REM 2 > Check directories
if exist build\ goto NEXTSTEP1
echo MAKEDIR build
md build
:NEXTSTEP1
if exist bin\ goto NEXTSTEP2
echo MAKEDIR bin
md bin
:NEXTSTEP2
REM Print SDCC version
sdcc -v
if not exist build\%CFILENAME%.ihx goto COMPILE
del build\%CFILENAME%.ihx
REM 3 > Compile with SDCC
:COMPILE
echo Compiling...
sdcc -mz80 -o build\ --code-loc %CODELOC% --data-loc %DATALOC% --use-stdout --no-std-crt0 %CRT% %LIB0% %LIB1% %LIB2% %LIB3% %LIB4% %LIB5% %LIB6% %LIB7% %LIB8% %LIB9% %LIB10% %LIB11% %LIB12% src\%CFILENAME%.c
if not exist build\%CFILENAME%.ihx goto ERRORCOMP
REM 4 > Converts a hexadecimal SDCC output to a binary file
hex2bin -e bin -l %ROMSIZE% build\%CFILENAME%.ihx
copy build\%CFILENAME%.bin bin\%ROMFILENAME%.ROM
REM 5 > Exit
pause
exit /b
REM 5 > Exit with ERROR 
:ERRORCOMP
echo ERROR
pause
exit /b