TARGET = libmbdata.so
FLAGS = -Wall
BASE_FLAGS = -I$(INC_DIR) -L$(LIB_DIR)
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

SOURCES := $(wildcard $(SRC_DIR)/*$(SRC_EXT))
INCLUDE := $(wildcard $(INC_DIR)/*$(INC_EXT))
OBJECTS := $(SOURCES:$(SRC_DIR)/%$(SRC_EXT)=$(OBJ_DIR)/%.o)

all: help

help:
	@echo "Meevs Box Generic C Data Structure Library Makefile Instructions"
	@echo ""
	@echo "Makefile targets:"
	@echo "  build -- Builds the library"
	@echo "  install -- Installs the mbdata library onto the machine"
	@echo "  clean -- Deletes the mbdata build directory"
	@echo "  uninstall -- Removes the mbdata library from the current machine"
	@echo ""
	@echo "To use the mbdata library with your projects, include the \"-lmbdata\" flag when compiling"

install: build
	@echo "Found target: $(TARGET)"
	@cp $(BIN_DIR)/$(TARGET)  /usr/lib/$(TARGET)
	@cp $(INCLUDE) /usr/include/
	@echo "mbdata has been successfully installed!"

build: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	if ! [ -d $(BIN_DIR) ]; then mkdir $(BIN_DIR); fi
	$(CC) -shared $(OUT_FLAGS) $^
	@echo "Target: $(TARGET) has been successfully built!"

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%$(SRC_EXT)
	if ! [ -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi
	$(CC) $(BASE_FLAGS) $(OBJ_FLAGS) $(OUT_FLAGS) $(FLAGS) -fPIC

uninstall:
	rm /usr/lib/$(TARGET)
	@echo "mbdata has been successfully uninstalled!"

clean: tidy
	-rm -r $(BIN_DIR)

tidy:
	-rm *~
	-rm \#*#
	-rm $(SRC_DIR)/*~
	-rm $(SRC_DIR)/\#*#
	-rm -r $(OBJ_DIR)
