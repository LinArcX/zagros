# zagros
a simple operating system from scratch.

# prerequisites
- bear
- as
- gcc
- qemu(or virtualbox or bochs)

## optional
- fzf
- doxygen
- cppcheck
- objdump (from: binutils)

## libs
- libsanitizer-devel
- libsanitizer-devel-32bit

# build/run/test
./p

# todo
## tools
- [x] setup binary analysis tools. (integration with p)
  - [x] "ldd"
  - [x] "objdump"
  - [x] "strings"
  - [x] "nm"
  - [x] "readelf"
  - [x] "addr2line"
  - [x] "size"
  - [x] "file"
- [x] setup util tools. (integration with p)
  - [x] "scc"
- [x] setup doxygen. (integration with p)
- [x] setup clove-unit library. (integration with p)
- [x] setup cppcheck as static-analyzer. (integration with p)
  - [x] setup ale plugin for neovim. (integration with p)
- [x] setup frama-c as static-analyzer. (integration with p)
- [x] setup valgrind.
  - [x] setup callgrind.
  - [x] setup KCachegrind.
- [ ] create github page.
  - [ ] host doxygen on it.
  - [ ] have a page to report unit_tests resultes.
- [ ] setup jenkins on github.
  - [ ] build kernel for each commit. (when only src/* files changes)
  - [ ] build and run unit-tests for each commit. (when only unit_tests/* files changes)
  - [ ] run doxygen after each commit.

## zagros
- [ ] strings util.
- [ ] minimal c library.
- [ ] interrupts.
- [ ] keyboard.
- [ ] mouse.
- [ ] system calls.
- [ ] graphic mode.
- [ ] create GUI toolkit.
- [ ] multi-tasking.
- [ ] hard drives.
- [ ] networking.

### features will not be included in zagros
- dynamic memory management:
  it makes software unpredictable and non deterministic.
