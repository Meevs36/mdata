# Meevs Box Data Structure Library Version Log

## What's New?

Released version 0.2.x

This update fixes memory leaks that were present in the Linky, and Stacky modules. 0.2.0 also brings Binary Trees to the library, allowing users to easily create binary trees with simple data values using the built in compare funciton, or complex data structures with custom compare functions.

## 0.2.1

- Updates to documentation to keep it more up-to-date
  - Creation of the Stacky documentation
  - Creation of the Queue documentation
  - Creation of the Binary Tree documentation
- Creation of the Version Log (hey, that's this file!)
  - Changes can now be tracked here

### 0.2.0

- Added the Binary Tree module
  - Users can now easily create binary trees of simple data types using the provided default compare function
  - Users can alternatively provide their own compare function to allow creation of binary trees with complex data structures
  - Created check tests to ensure functionality of all Binary Tree functions
  - Updated cmake files to include the Binary Tree module
    - Binary Tree module is now compiled into the library
    - Binary Tree module check tests are compiled and included with the default tests
- Bug fixes for the Linky, Stacky and Queue modules
  - Linky, Stacky and Queue modules no longer have a memory leak when attempting to extract data from the respective data structure
  - Updated tests to make better use of check macro-functions
  - Remove over-intensive logging which was leading to real problems being lost in a sea of logs for tests that were infact working.
- All modules now make use of unions, this allows for an abstraction of the data stored in the data structure, while appearing equivalent to the older implementation of generic pointers

### 0.1.7

- Added [check](https://libcheck.github.io/check/) support. This allows for unit testing of each module ensuring that everything works as intended!
- Added cmake rules to compile tests with check, these tests can be ran via
  ```bash
  make test
  ```
  or
  ```bash
  ctest
  ```
  from the build directory.
  Tests can also be ran with
  ```bash
  ctest --verbose
  ```
  for more detailed output of failed tests.

### 0.1.6

- Added [cmake](https://cmake.org/) support, replacing the original custom makefile I had provided with this project. This will make the project more standardized and more intuitive to use. This will also make future modifications to the project much easier to make.

### 0.1.5

- Implemented Queue
  - Implemented enqueuing of values into a queue
  - Implemented dequeuing of values from a queue
  - Implemented the 'front' function, allowing for users to look at the front of the queue without removing the value from the queue
  - Implemented the 'rear' function, allowing for users to look at the back of the queue
- Added support for double-linked Linky lists

### 0.1.x

- Implemented Linky
  - Implemented adding nodes to a Linky list
  - Implemented the 'linkyGetData' function, allowing users to easily extract the desired data from a Linky node
  - Linky lists properly track how many values have been added to the list
- Implemented Stacky
  - Implemented pushing of values onto a Stacky stack
  - Implemented popping of values off of a Stacky stack
  - Implemented the 'peak' function, allowing users to peak at the top of a Stacky stack without removing the value

