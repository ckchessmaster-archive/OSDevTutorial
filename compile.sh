#!/bin/sh
nasm -f elf32 source/loader.s -o bin/loader.o
ld -T source/link.ld -melf_i386 bin/loader.o -o bin/kernel.elf
genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -A os -input-charset utf8 -quiet -boot-info-table -o os.iso iso
