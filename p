#!/usr/bin/bash
#
# to run this file: ./p
#
# memory debugger: valgrind
# system call tracer: strace
# display info about .obj files: objdump
# static code analyzer: splint, cppcheck, frama-c
#
# opening/editing files: noevim
#   folding/unfolding: z Shift+m, z Shift+r
#   switch between source/header: F1
#
# lookup refrences: neovim(lsp)
# find/replace in single file: neovim
# find/replace in whole project: ambr <source_text> <dest_text>
# find files: ctrl-t | ff <file-name> | fzf | fd
# find string/text in single file: neovim (/)
# find string/text in whole project: ft <text> | rg <text>
# find docs of c standard librariy: install man-pages-devel and man <method>
#
# debugging: gdb build/zagros_debug
#   set breakpoint: b 1
#   start debugging: start
#   from this phase, for faster moving between files and methods, you can switch to single-key-mode: C-x s. and here are the commands in this mode:
#     q - quit, exit SingleKey mode.
#     c - continue
#     d - down
#     f - finish
#     n - next
#     r - run
#     s - step
#     u - up
#     v - info locals
#     w - where

commands=("build(release)" "build(debug)" "build(test)"
  "run" "clean" "debug"
  "splint" "valgrind"
  "strings in binary" "symbols in .obj")
selected=$(printf '%s\n' "${commands[@]}" | fzf --header="project:")

case $selected in
  "build(release)")
    echo ">>> creating build/ directory"
    mkdir -p build

    echo ">>> compiling .s files"
    as --32 -o build/loader.o src/loader.s

    # -lGL -ldl -O3
    echo ">>> compiling .c files"
    cc -Wall -Wextra -pedantic -std=c99 -m32 -nostdlib -fno-builtin -fno-exceptions -fno-leading-underscore -o build/kernel.o -c src/kernel.c

    echo ">>> linking .o files into .bin"
    ld -melf_i386 -T src/linker.ld build/kernel.o build/loader.o -o build/zagros.bin

    echo ">>> copying .bin to /boot"
    sudo cp build/zagros.bin /boot/zagros.bin

    echo ">>> generating .iso file"
	  mkdir -p build/iso/boot/grub
	  cp build/zagros.bin build/iso/boot/

	  echo 'set timeout=0' > build/iso/boot/grub/grub.cfg
	  echo 'set default=0' >> build/iso/boot/grub/grub.cfg
	  echo '' >> build/iso/boot/grub/grub.cfg
	  echo 'menuentry "zagros" {' >> build/iso/boot/grub/grub.cfg
	  echo '	multiboot /boot/zagros.bin' >> build/iso/boot/grub/grub.cfg
	  echo '	boot' >> build/iso/boot/grub/grub.cfg
	  echo '}' >> build/iso/boot/grub/grub.cfg

	  grub-mkrescue --output=build/zagros.iso build/iso
	  #rm -rf build/iso
    ;;
  "build(debug)")
    echo ">>> creating build/ directory"
    mkdir -p build

    echo ">>> building zagros_debug"
    cc -Wall -Wextra -pedantic -std=c99 -lGL -ldl -g -O0 src/*.c -o build/zagros_debug
    ;;
   "build(test)")
    echo ">>> creating build/ directory"
    mkdir -p build

    echo ">>> building zagros_test "
    cc -Wall -Wextra -pedantic -std=c99 -lGL -ldl -g -O0 test/*.c -o build/zagros_test
    ;;
  "run")
    echo ">>> running zagros.iso"
    /usr/lib/virtualbox/VirtualBoxVM --startvm zagros &
    ;;
  "clean")
    echo ">>> cleaning build/ directory"
    rm -r build/*
    ;;
  "debug")
    echo ">>> debugging zagros_debug"
    gdb --tui build/zagros.bin
    ;;
  "splint")
    cppcheck --enable=all --platform=unix64 src/*.c;;
  "valgrind")
    valgrind --leak-check=yes --show-leak-kinds=all -s -v build/zagros.bin;;
    #valgrind --leak-check=full src/*.cpp ;;
  "strings in binary")
    strings ./build/zagros.bin;;
  "symbols in .obj")
    nm ./build/zagros.bin;;
  *) ;;
esac
