# zagros
a simple operating system from scratch.

# prerequisites
- fzf
- doxygen
- cppcheck
- as
- gcc
- objdump (from: binutils)
- qemu(or virtualbox or bochs)

# build/run
./p

# todo
- [x] setup objdump.
- [x] generate docs with doxygen.
- [x] setup clove-unit library for unit-tests.
- [x] setup cppcheck as static analyzer.
  - [ ] setup frama-c as static analyzer.
- [ ] setup valgrind.
  - [] setup callgrind.
  - [] setup KCachegrind.
- [ ] setup CI on github.
  - [ ] build kernel for each commit.
  - [ ] build and run unit-tests for each commit.
  - [ ] run doxygen for each commit.
- [ ] create github page and host doxygen on it.
- [ ] implement strings utility.
- [ ] imlement minimal c library.
- [ ] interrupts
- [ ] keyboard
- [ ] mouse
- [ ] system calls
- [ ] graphic mode
- [ ] create GUI toolkit
- [ ] multi-tasking
- [ ] hard drives
- [ ] networking

# features will not be included in zagros
- dynamic memory management:
  it makes software unpredictable and non deterministic.
