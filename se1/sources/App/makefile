#root Path
rootPath = /home/user/Desktop/host-se1/se1/
#includes Path
incPath = $(rootPath)includes/
#libraries Path
libsPath = $(rootPath)libs/
#bsp Path
bspPath = $(rootPath)bsp/

#GCC Library
LIBGCC = /usr/local/arm-tools/arm-2009q1/lib/gcc/arm-none-eabi/4.3.3/libgcc.a
#C Library
LIBC = -L/usr/local/arm-tools/arm-2009q1/arm-none-eabi/lib/ -lc
#Script RAM
LDSCRIPT = $(bspPath)ldscript_ram
#init
OINIT = $(bspPath)initSam.o
SINIT = $(bspPath)initSam.S

#LIBS
lpc = lpc2106
lcd = lcd
led = led

LIBLPC = $(libsPath)lib$(lpc).a
LIBLCD = $(libsPath)lib$(lcd).a
LIBLED = $(libsPath)lib$(led).a

ILIBLPC = -L$(libsPath) -l$(lpc)
ILIBLCD = -L$(libsPath) -l$(lcd)
ILIBLED = -L$(libsPath) -l$(led)

IALLLIBS = $(ILIBLCD) $(ILIBLED) $(ILIBLPC) $(LIBC) $(LIBGCC) 

#ARN
ARM = arm-none-eabi-

#ARM insight -> debug
Ainsight = $(ARM)insight
#ARM gcc -> C compiler
Agcc = $(ARM)gcc
#ARM ld -> Linker
Ald = $(ARM)ld
#ARM ar -> library
Aar = %(ARM)ar
#ARM as -> Assembler
Aas = $(ARM)as

insight: App.axf
	$(Ainsight) App.axf

App.axf :  App.o Button.o $(OINIT) TempManagement.o
	$(Ald) $(OINIT) App.o Button.o TempManagement.o -T $(LDSCRIPT) $(IALLLIBS) -o App.axf

App.o: App.c
	$(Agcc) -c -g App.c -o App.o	

Button.o: Button.c
	$(Agcc) -c -g Button.c -o Button.o

$(OINIT): $(SINIT)
	$(Aas) $(SINIT) -o $(OINIT) -g
	
TempManagement.o: TempManagement.c
	$(Agcc) -c -g TempManagement.c -o TempManagement.o

Manutencao.o: Manutencao.c
	$(Agcc) -c -g Manutencao.c -o Manutencao.o

clean: 
	rm *.o *.axf
