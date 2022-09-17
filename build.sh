#assemble boot.s file
as --32 boot.s -o out/boot.o

#compile kernel.c file
gcc -m32 -c src/main.c -o out/main.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
gcc -m32 -c src/screen.c -o out/screen.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
# gcc -m32 -nostartfiles -ffreestanding -o out/kernel.o out/main.o out/screen.o

#linking the kernel with kernel.o and boot.o files
ld -m elf_i386 -T linker.ld -o out/MyOS.bin out/main.o out/screen.o out/boot.o -nostdlib

# #check MyOS.bin file is x86 multiboot file or not
grub-file --is-x86-multiboot out/MyOS.bin

#building the iso file
mkdir -p out/isodir/boot/grub
cp out/MyOS.bin out/isodir/boot/MyOS.bin
cp grub.cfg out/isodir/boot/grub/grub.cfg
grub-mkrescue -o out/MyOS.iso out/isodir

#run it in qemu
qemu-system-x86_64 -cdrom out/MyOS.iso