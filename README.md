# Meevs Box Data Structure Library
A flexible library of generic data structures implemented in C.

## Features
---

This library features various generic data structures for C.
These data structures are all generic, supporting anything you can throw at them!
The data structures provided (or intended to be provided) in this library are:

- Linky: A generic linked list implemented in C.
- Stacky: A generic stack implemented in C.
- Queue: A generic queue implemented in C.
- Binary Tree: A generic binary tree implemented in C.

## Dependencies
---

Required:
- [cmake](https://cmake.org/)

Optional:
- [check](https://libcheck.github.io/check/)

## Installation
---

1. Compilation

From the root of the project:
```bash
$ cmake -S ./ -B ./build/
$ make [all] -C ./build/
```

The modules which are compiled into the mdata library can be controlled through the use of the 'MDATA_MODULES' variable when executing cmake. The 'MDATA_MODULES' variable takes a semicolon-seperated list of which modules should be included into the final build of the library. The modules are defined as follows:
* LINKY
* STACKY
* QUEUE
* BT

If the 'MDATA_MODULES' variable is not defined, the library will include all modules by default.

Example:
```bash
$ cmake -S ./ -B ./build -D MDATA_MODULES="LINKY;STACKY"
```
Would compile the Linky and Stacky modules into the mdata library

2. Verify Tests (if check is installed)

The 'mtests' build target will compile all tests and must be run prior to attempting the 'test' target

```bash
$ make mtests -C ./build/
$ make test -C ./build/
```

Note: The 'mtests' target will only compile tests for modules which have been enabled. Similarly, the 'test' target will only execute tests from modules which have been enabled.

3. Install onto system (requires root)
```bash
# make install -C ./build/
```

## Library References
- [Linky](src/main/linky/Linky.md)
- [Stacky](src/main/stacky/Stacky.md)
- [Queue](src/main/queue/Queue.md)
- [Binary Tree](src/main/binaryTree/BinaryTree.md)

## [Version Log](VersionLog.md)

