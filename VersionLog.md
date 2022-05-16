# Meevs Box Data Structure Library Version Log

## What's New?

Released version 0.2.x

This update fixes memory leaks that were present in the Linky, and Stacky modules. 0.2.0 also brings Binary Trees to the library, allowing users to easily create binary trees with simple data values using the built in compare funciton, or complex data structures with custom compare functions.

#### 0.2.6.2 -- 2022-05-16

- Fixed a mistake from the v0.2.6.1 tweak where many tests from the Linky module were commented out
  - This was done for testing purposes, but should not have stayed in the v0.2.6.1 commit
- Modified the v0.2.6.1 header in the 'VersionLog.md' file so that it uses the appropriate header size

#### 0.2.6.1 -- 2022-05-13

- Modifications were made to the previously implemented valgrind tests
  - The tests will no longer treat "reachable" memory segments as an error when conducting the valgrind test. This is for two reasons
    - Valgrind does not consider a "reachable" memory segment to be an error by default
    - This creates issues when trying to use the "fork" mode of the Check unit testing library
  - Removed the setting of the CK_FORK environment variable in the 'CMakeLists.txt' file
    - The origianl intention behind setting this variable was to avoid forking causing "reachable" "memory leaks", since that is no longer required, this action is obsolete
    - This flag didn't actually achieve what the original intention was anyways (it only sets the ENV for the CMake build)
- The Linky, Stacky, and Binary Tree modules now all pass their respective valgrind tests
  - The Queue module will be looked into in a future update
- Modified the 'VersionLog.md' so that some previous tweaks are represented as such and not as patches from the future
  - I honestly have no idea what I was thinking when I created those tweaks...

### 0.2.6 -- 2022-04-25

- Added new valgrind tests for each module
  - The valgrind test is only included if the respective module is enabled
  - The valgrind test will simply re-run the already established tests under valgrind, failing if valgrind reports any errors or memory leaks
  - At time of writing all four modules are plagued by memory leaks of varying degrees (these will be addressed in a future patch
- Modified main cmake file to incldue the addition of above mentioned tests
- Added missing date for 0.2.5 patch date

### 0.2.5 -- 2022-04-23

- Modified the project's cmake files to make use of the 'target_sources' command rather than appending all sources to a global list
- Modified the project's cmake files to compile each module into their own seperate archives rather than one shared object
  - These seperate archives can then be compiled together to form the shared object with the desired modules
- Added logic to allow for compilation of specific modules of the library
  - Users can setup their build directory to only compile specific modules of the mdata libray into the final build
  - This is controlled through the 'MDATA_MODULES' variable which can be set when executing `cmake` through the -D flag
  - Tests will only be compiled/executed when the respective module has been enabled
  - Added output to indicate which modules have been enabled when executing `cmake`
- Removed the 'mdataTest' test suite from compilation as it has been deemed a non-useful test
- Updates to the 'README.md' file
  - Added documentation explaining how to make use of the modular compilation added in this patch
  - Future revision of the documentation here might be required
- Fixed small mistake in the 'Linky.md' file where it references using '-lmbdata' instead of '-lmdata' 

#### 0.2.4.3 -- 2022-01-08

- Modified data structure definitions to instead use the stdint data types. This is to be more precise with the widths of the basic data values that shall be held.
  - These changes were made specifically with 64-bit systems in mind
  - These changes were made to better support Windows builds

#### 0.2.4.2

- Removed the unit tests from the make 'all' target. Since not all users may be interested in developing this library and instead may just want to use it, it would be unfair to expect them to install a unit test framework to use the library.
  - The make 'all' target will ONLY compile the library .so file
  - Added a new make target, the make 'mtests' target
    - This will compile all unit test executables
    - This new target should be run prior to the make 'test' target, or ctest

#### 0.2.4.1

- Fixed another mistake in the installation of the library.
  - Though the Binary Tree was now included in the .so file, the header file for the Binary Tree module was still not being installed. This patch fixes that!
- Modified the make target 'uninstall' to also remove the '/usr/include/mdata/' directory

### 0.2.4

- Modified the '*GetSize' functions for the Queue and Binary Tree modules to be more resistant to failure. They will no longer cause a segmentation fault if the given queue or binary tree are empty (uninitialized)
- Modified the version log headers to better represent the version modifications
  - Smaller changes now use smaller headers than larger changes, as would kind of be expected

### 0.2.3

- Fixed a bug where using multiple data structures together (specifically including the header files of more than one data structure) led to compilation errors
- Added the 'mdataTest' Which will test the functionality of the created .so file. This is to ensure the functionality of the library file itself, rather than just the source code.
  - This was actually why the Binary Tree module was excluded from the .so file in previous versions, the code worked fine! But the code was not included in the library file and therefore was not very useful!
- Broke up the '*TestSuite.c' files into two seperate files for each data structure
  - Now there exists a '*TestSuite.c' which contains the main function for that modules test and the '*TestSuiteFuncs.c' file which generates the test suite for the respective module
  - This was to allow for easy re-use of the tests for the .so module

### 0.2.2

- Fixed mistake where the new Binary Tree module was being excluded from the created .so file. This meant that the Binary Tree module would be missing when attempting to use it from the library file

### 0.2.1

- Updates to documentation to keep it more up-to-date
  - Creation of the Stacky documentation
  - Creation of the Queue documentation
  - Creation of the Binary Tree documentation
- Creation of the Version Log (hey, that's this file!)
  - Changes can now be tracked here

## 0.2.0
---

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

## 0.1.7

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

## 0.1.6

- Added [cmake](https://cmake.org/) support, replacing the original custom makefile I had provided with this project. This will make the project more standardized and more intuitive to use. This will also make future modifications to the project much easier to make.

## 0.1.5

- Implemented Queue
  - Implemented enqueuing of values into a queue
  - Implemented dequeuing of values from a queue
  - Implemented the 'front' function, allowing for users to look at the front of the queue without removing the value from the queue
  - Implemented the 'rear' function, allowing for users to look at the back of the queue
- Added support for double-linked Linky lists

## 0.1.x

- Implemented Linky
  - Implemented adding nodes to a Linky list
  - Implemented the 'linkyGetData' function, allowing users to easily extract the desired data from a Linky node
  - Linky lists properly track how many values have been added to the list
- Implemented Stacky
  - Implemented pushing of values onto a Stacky stack
  - Implemented popping of values off of a Stacky stack
  - Implemented the 'peak' function, allowing users to peak at the top of a Stacky stack without removing the value


