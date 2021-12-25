# Meevs Box Data Structure Library Readme
A library of generic data structures implemented in C.

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
$ mkdir build
$ cmake -S ./ -B ./build/
$ make -C ./build/
```

2. Verify Tests (if check is installed)
```bash
$ make test -C ./build/
```

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

