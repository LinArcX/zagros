# Multiboot magic number required by the Multiboot Specification.
# It identifies the binary as a Multiboot-compliant kernel to the bootloader.
.set MAGIC, 0x1badb002

# (1<<0) sets bit 0, requesting the bootloader to align loaded modules on 4KB page boundaries.
# (1<<1) sets bit 1, requesting the bootloader to provide a memory map (information about available memory).
# 1<<0 | 1<<1 == 0x3,
.set FLAGS, (1<<0 | 1<<1) 
.set CHECKSUM, -(MAGIC + FLAGS)

# this .section contains the Multiboot header in object file.
# it typically placed at the beginning of the binary (within the first 8KB, as required by the Multiboot Specification) so the bootloader can find it.
# .long is 4 bytes (a 32-bit word)
.section .multiboot
  .long MAGIC
  .long FLAGS
  .long CHECKSUM

# .section .text: contains the executable code of the program.
.section .text
.extern kmain
# .global making it visible to the linker and accessible to the bootloader.
.global loader

# the starting point of the bootloader’s code.
loader:
  # kernel_stack is defined later in the .bss section and represents the base (top) of the stack.
  # This initializes the stack, which is necessary for function calls and local variables in the kernel.
  # The stack grows downward in memory (toward lower addresses) on x86 architectures.
  mov $kernel_stack, %esp

  # Pushes the contents of the %eax and %ebx registers onto the stack.
  # According to the Multiboot Specification, when the bootloader transfers control to the kernel:
  #   - %eax contains the Multiboot magic number (0x2BADB002 for Multiboot 1).
  #   - %ebx contains the physical address of the Multiboot information structure, which includes details like the memory map and loaded modules.
  # These values are pushed onto the stack as arguments to kmain, following the C calling convention:
  #  kmain(uint32_t magic, multiboot_info_t* mb_info)
  #.code32
  #mov %eax, 0xCAFEBABE
  push %eax
  push %ebx
  call kmain

# kernel shouldn't stop. there's an infinite loop at the end of kmain.
# _loop here, is just to make sure we never goes outside of infinite loop.
_loop:
  cli
  hlt
  jmp _loop

# the block starting symbol (.bss) is the portion of an object file that contains statically allocated variables that are declared
# but have not been assigned a value yet. Typically only the length of the bss section, but no data, is stored in the object file.
# The program loader allocates memory for the bss section when it loads the program.
# By placing variables with no value in the .bss section, instead of the .data or .rodata section which require initial value data,
# the size of the object file is reduced.
.section .bss
#                            a    -- 2MB space -- b 
# +-----------+--------------+--------------------*-------------------+
# |  BIOS FW  |  BootLoader  |              kernel.bin                |     
# +-----------+--------------+----------------------------------------+
#
# since stack grows to the left and we don't want our kernel.bin overwrite stack, we reserve 2MB as empty space.
# so instead of pointing ESP to "a", now it points to b.
# 
.space 2*1024*1024 # 2MB

kernel_stack:
