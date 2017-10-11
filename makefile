all:
	+$(MAKE) -C source
	+$(MAKE) -C build

os.iso: build/kernel.elf
	cp build/kernel.elf iso/boot/kernel.elf
	genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot \
							-boot-load-size 4 -A os -input-charset utf8 -quiet \
							-boot-info-table -o os.iso iso


clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.elf' -delete
	find . -type f -name '*.iso' -delete

run: os.iso
	bochs -f bochsrc.txt -q
