#!/usr/bin/bash
#
# to run this file: ./p
#
# tools:
#   diff: gitk, meld
#   memory debugger: valgrind
#   system call tracer: strace
#   display info about .obj files: objdump
#   static code analyzer: cppcheck, frama-c, splint 
#   docs of c standard librariy: install man-pages-devel and man <method>
#
# nvim tips:
#   switch between source/header: F2
#   search files: ctrl-f, alt-f
#   search strings: ctrl-g, alt-g, /
#   folding/unfolding: z Shift+m, z Shift+r
#   lsp: ,l
#   find/replace:
#     project: ambr <src> <dst> <path>
#     current buffer: :%s/akoman/zagros/g

assembly () {
    as --32 -o $2 $1
}

compile () {
    cc -Wall -Wextra -pedantic -std=c99 \
      -m32 -nostdlib -fno-builtin -fno-exceptions -fno-leading-underscore \
      -c $1 -o $2
}

commands=("build(release)" "build(debug)"
  "build(tests)" "run(tests)" "debug(tests)" "clean(tests)"
  "run(qemu)"  "run(qemu - logs)" "run(bochs)" "run(virtualbox)"
  "clean" "debug"
  "doxygen" "splint" "valgrind"
  "strings in binary" "symbols in .obj")
selected=$(printf '%s\n' "${commands[@]}" | fzf --header="project:")

case $selected in
  "build(release)")
    echo ">>> creating build/ directory"
    mkdir -p build/obj

    echo ">>> compiling .s files"
    assembly "src/loader.s" "build/obj/loader.o"

    # -lGL -ldl -O3
    echo ">>> compiling .c files"
    compile "src/kernel.c" "build/obj/kernel.o"
    compile "src/util/strings.c" "build/obj/strings.o"
    compile "src/util/video_mmio.c" "build/obj/video_mmio.o"
    compile "src/util/globals.c" "build/obj/globals.o"

    echo ">>> linking .o files into .bin"
    ld -T src/linker.ld -melf_i386 build/obj/*.o -o build/zagros.bin

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

    echo ">>> generating .img file"
    qemu-img create -f raw build/zagros.img 2G
    #rm -rf build/iso
    ;;
  "build(debug)")
    echo ">>> creating build/ directory"
    mkdir -p build
    echo ">>> building zagros_debug"
    cc -Wall -Wextra -pedantic -std=c99 -lGL -ldl -g -O0 src/*.c -o build/zagros_debug
    ;;
   "build(tests)")
    echo ">>> creating unit_tests/build/ directory"
    mkdir -p unit_tests/build

    echo ">>> building zagros_test"
    cc -Wall -Wextra -pedantic -std=c99 -g -O0 -o unit_tests/build/zagros_test unit_tests/*.c src/util/*
    ;;
  "run(tests)")
    echo ">>> running zagros_test"
    ./unit_tests/build/zagros_test
    ;;
  "debug(tests)")
    gdb ./unit_tests/build/zagros_test
    ;;
  "clean(tests)")
    echo ">>> cleaning unit_tests/build/ directory"
    rm -r unit_tests/build/*
    ;;
  "run(qemu)")
    echo ">>> running zagros.iso"
    qemu-system-i386 -cdrom build/zagros.iso -hda build/zagros.img -m 512M -daemonize
    ;;
  "run(qemu - logs)")
    echo ">>> running zagros.iso"
    #out_asm         show generated host assembly code for each compiled TB
    #in_asm          show target assembly code for each compiled TB
    #op              show micro ops for each compiled TB
    #op_opt          show micro ops after optimization
    #op_ind          show micro ops before indirect lowering
    #op_plugin       show micro ops before plugin injection
    #int             show interrupts/exceptions in short format
    #exec            show trace before each executed TB (lots of logs)
    #cpu             show CPU registers before entering a TB (lots of logs)
    #fpu             include FPU registers in the 'cpu' logging
    #mmu             log MMU-related activities
    #pcall           x86 only: show protected mode far calls/returns/exceptions
    #cpu_reset       show CPU state before CPU resets
    #unimp           log unimplemented functionality
    #guest_errors    log when the guest OS does something invalid (eg accessing a
    #non-existent register)
    #page            dump pages at beginning of user mode emulation
    #nochain         do not chain compiled TBs so that "exec" and "cpu" show
    #complete traces
    #plugin          output from TCG plugins
    #strace          log every user-mode syscall, its input, and its result
    #tid             open a separate log file per thread; filename must contain '%d'
    #vpu             include VPU registers in the 'cpu' logging
    #invalid_mem     log invalid memory accesses
    #trace:PATTERN   enable trace events
    #qemu-system-x86_64 -cdrom build/zagros.iso -d cpu,int,guest_errors,out_asm,page -monitor stdio -serial file:serial.log
    qemu-system-i386 -cdrom build/zagros.iso -hda build/zagros.img -d guest_errors,in_asm,strace,page,unimp -D build/qemu.log -serial file:build/qemu-serial.log -m 512M -daemonize
    ;;
  "run(bochs)")
    echo ">>> running zagros.iso"
    bochs -qf bochsrc.txt
    ;;
  "run(virtualbox)")
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
  "doxygen")
    doxygen
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
