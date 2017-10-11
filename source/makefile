OBJECTS = loader.o kmain.o io.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
AS = nasm
ASFLAGS = -f elf

all: $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o ../build/$@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o ../build/$@
