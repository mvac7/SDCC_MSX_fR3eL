@echo off
REM fR3eL Project
REM MAKEFILE for MSXDOS .COM (without parameters) for SDCC compiler
REM 1 > Configure
REM CFILENAME = source code file name without the extension
SET CFILENAME=file_name
REM OUTPUTFILENAME = final binary file name without extension (8 uppercase characters)
SET OUTPUTFILENAME=FILENAME
SET CODELOC=0x0108
SET CRT=crt0\crt0_MSXDOS.rel
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
REM get SDCC version
sdcc -v
if not exist build\%CFILENAME%.ihx goto COMPILE
del build\%CFILENAME%.ihx
REM 3 > Compile with SDCC
:COMPILE
echo Compiling...
sdcc -mz80 -o build\ --code-loc %CODELOC% --data-loc 0 --use-stdout --no-std-crt0 %CRT% %LIB0% %LIB1% %LIB2% %LIB3% %LIB4% %LIB5% %LIB6% %LIB7% %LIB8% %LIB9% %LIB10% %LIB11% %LIB12% src\%CFILENAME%.c
if not exist build\%CFILENAME%.ihx goto ERROROUTPUT
REM 4 > Converts a hexadecimal SDCC output to a binary file
hex2bin -e BIN build\%CFILENAME%.ihx
copy build\%CFILENAME%.BIN bin\%OUTPUTFILENAME%.COM
REM 5 > Exit
pause
exit
REM 5 > Exit with ERROR 
:ERROROUTPUT
echo ERROR
pause
exit