
CC      = arm-linux-gcc
LD      = arm-linux-ld
AR      = arm-linux-ar
OBJCOPY = arm-linux-objcopy
OBJDUMP = arm-linux-objdump

INCLUDEDIR 	:= $(shell pwd)/include
CFLAGS 		:= -Wall -O2
CPPFLAGS   	:= -nostdinc -I$(INCLUDEDIR)

export 	CC LD AR OBJCOPY OBJDUMP INCLUDEDIR CFLAGS CPPFLAGS

objs := head.o init.o nand.o interrupt.o serial.o lcddrv.o GPIO.o timer.o framebuffer.o game.o lcdlib.o main.o lib/libc.a

zhenjie.bin: $(objs)
	${LD} -Tzhenjie.lds -o zhenjie_elf $^
	${OBJCOPY} -O binary -S zhenjie_elf $@
	${OBJDUMP} -D -m arm zhenjie_elf > zhenjie.dis

.PHONY : lib/libc.a
lib/libc.a:
	cd lib; make; cd ..
	
%.o:%.c
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.o:%.S
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	make  clean -C lib
	rm -f zhenjie.bin zhenjie_elf zhenjie.dis *.o
	
