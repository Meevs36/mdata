TARGET = libmdata.so
FLAGS = -Wall
BASE_FLAGS = $(foreach dir, $(INC_DIRS), -I$(dir)) -L$(LIB_DIR)
OUT_FLAGS = -o $@
OBJ_FLAGS = -c $<

CC = gcc

SRC_EXT = .c
INC_EXT = .h

SRC_DIR = src
INC_DIR = inc
LIB_DIR = lib
OBJ_DIR = obj
BIN_DIR = bin

rwildcard = $(wildcard $1$2) $(foreach dir, $(wildcard $1*), $(call rwildcard, $(dir)/,$2))

SOURCES := $(call rwildcard, $(SRC_DIR),*$(SRC_EXT))
INCLUDE := $(call rwildcard, $(INC_DIR),*$(INC_EXT))
OBJECTS := $(SOURCES:$(SRC_DIR)/%$(SRC_EXT)=$(OBJ_DIR)/%.o)

SRC_DIRS := $(sort $(dir $(call rwildcard, $(SRC_DIR),*/))) # Nested source directories
INC_DIRS := $(sort $(dir $(call rwildcard, $(INC_DIR),*/))) # Nested include directories
OBJ_DIRS := $(SRC_DIRS:$(SRC_DIR)/%=$(OBJ_DIR)/%) # Corresponding nested object directories

all: help

help:
	@echo "Meevs Box Generic C Data Structure Library Makefile Instructions"
	@echo ""
	@echo "Makefile targets:"
	@echo "  build -- Builds the library"
	@echo "  install -- Installs the mdata library onto the machine"
	@echo "  clean -- Deletes the mdata build directory"
	@echo "  uninstall -- Removes the mdata library from the current machine"
	@echo ""
	@echo "To use the mdata library with your projects, include the \"-lmdata\" flag when compiling"

install: build
	@echo "Found target: $(TARGET)"
	cp $(BIN_DIR)/$(TARGET)  /usr/lib/$(TARGET)
	if ! [ -d /usr/include/mdata ]; then mkdir /usr/include/mdata; fi
	cp -r $(INCLUDE) /usr/include/mdata/
	@echo "Meevs Box Data Library has been successfully installed!"

build: $(OBJ_DIRS) $(BIN_DIR)/$(TARGET)
	@echo "Build successful!"

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	if ! [ -d $(BIN_DIR) ]; then mkdir $(BIN_DIR); fi
	$(CC) -shared $(OUT_FLAGS) $^
	@echo "Target: $(TARGET) has been successfully built!"

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%$(SRC_EXT)
	$(CC) $(BASE_FLAGS) $(OBJ_FLAGS) $(OUT_FLAGS) $(FLAGS) -fPIC

$(OBJ_DIRS):
	$(foreach dir, $@, if ! [ -d $(dir) ]; then mkdir $(dir); fi)

uninstall:
	if [ -f /usr/lib/$(TARGET) ]; then rm /usr/lib/$(TARGET); fi
	if [ -d /usr/include/mdata ]; then rm -r /usr/include/mdata; fi
	@echo "Meevs Box Data Library has been successfully uninstalled!"

clean: tidy
	-rm -r $(BIN_DIR)

tidy:
	-rm *~
	-rm \#*#
	-rm $(SRC_DIR)/*~
	-rm $(SRC_DIR)/\#*#
	-rm -r $(OBJ_DIR)
