ENTRY(loader)     /* the name of the entry label */
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)

SECTIONS
{
  . = 0x0100000;  /* the code should be loaded at 1 MB, 
                    because addresses lower than 1 MB are used by GRUB itself, BIOS and memory-mapped I/O. */
  .text :
  {
    *(.multiboot)
    *(.text*)     /* all text sections from all files */
    *(.rodata)    /* all read-only data sections from all files */
  }

  .data :
  {
    *(.data)      /* all data sections from all files */
    /*start_ctors = .;*/
    /*KEEP(*( .init_array ));
    KEEP(*( SORT_BY_INIT_PRIORITY( .init_array.* ) ))*/
    /*end_ctors = .;*/

  }

  .bss :
  {
    *(.bss)       /* all bss sections from all files */
  }

  /*/DISCARD/ :
  {
    *(.fini_array*)
    *(.comment)
  }*/

}
