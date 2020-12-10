@echo off
REM MAKEFILE for MSXDOS .COM using SDCC compiler
REM CFILENAME = Source name without extension
SET CFILENAME=sourcename
SET OUTPUTFILENAME=DOSNAME
SET CRT=libs\crt0_MSXDOS.rel
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
if not exist build\%CFILENAME%.ihx goto COMPILA
del build\%CFILENAME%.ihx
:COMPILA
echo Compiling...
sdcc -mz80 -o build\ --code-loc 0x0170 --data-loc 0 --use-stdout --no-std-crt0 %CRT% %LIB0% %LIB1% %LIB2% %LIB3% %LIB4% %LIB5% %LIB6% %LIB7% %LIB8% %LIB9% %LIB10% %LIB11% %LIB12% src\%CFILENAME%.c
if not exist build\%CFILENAME%.ihx goto ERROROUTPUT
hex2bin -e BIN build\%CFILENAME%.ihx
copy build\%CFILENAME%.BIN bin\%OUTPUTFILENAME%.COM
pause
exit
:ERROROUTPUT
echo ERROR
pause
exit