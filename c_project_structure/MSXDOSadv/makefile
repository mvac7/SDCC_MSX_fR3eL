# fR3eL Project
# MAKEFILE for MSXDOS .COM with parameters for SDCC compiler
# CFILENAME = source code file name without the extension
CFILENAME=SOURCENAME
# OUTPUTFILENAME = final binary file name without extension (8 uppercase characters)
OUTPUTFILENAME=FILENAME
CODELOC=0x0180
CRT=crt0\crt0_MSXDOS_advanced.rel

# add paths from our objects files into LIB variable
LIBS=

all: bin/$(ROMFILENAME).ROM
	# get SDCC version
	sdcc -v

build:
	echo "mkdir build"
	mkdir build

bin:
	echo "mkdir bin"
	mkdir bin


build/$(CFILENAME).ihx: build bin
	echo "Compiling..."
	sdcc -mz80 -o build/ --code-loc $(CODELOC) --data-loc 0 --use-stdout --no-std-crt0 $(CRT) $(LIBS) src/$(CFILENAME).c

build/$(CFILENAME).bin: build/$(CFILENAME).ihx
	hex2bin -e bin build/$(CFILENAME).ihx

bin/$(OUTPUTFILENAME).ROM: build/$(CFILENAME).bin 
	cp build/$(CFILENAME).bin bin/$(OUTPUTFILENAME).ROM

clean: build/$(CFILENAME).ihx
	rm build/$(CFILENAME).ihx
	rm bin/$(OUTPUTFILENAME).ROM
	

