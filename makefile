# Compilation steps :
# 1. Compile c++ sources with headers into object files in the tmp directory
# 2. Compile each object file into one executable in the bin directory

# Tools
CXX := g++

# Flags
CXX_FLAGS := -Iinclude -g
LD_FLAGS :=
RUN_ARGS :=

# Directories
INC_DIR := include
SRC_DIR := src
OBJ_DIR := tmp
BIN_DIR := bin

# Files
SRC := $(wildcard $(SRC_DIR)/*.cpp)
INC := $(wildcard $(INC_DIR)/*.h)
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC)) 
EXE := $(BIN_DIR)/main

all: $(BIN_DIR) $(OBJ_DIR) $(INC) $(EXE)

run: all
	@echo ">>> Running program with args $(RUN_ARGS)"
	./$(EXE) $(RUN_ARGS)

$(EXE): $(OBJ)
	$(CXX) $(LD_FLAGS) -o $@ $^

# Objects
$(OBJ_DIR)/%.o: $(SRC)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

# Directories
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

# Removes only temporary (objects) files
flush:
	rm -rf $(OBJ_DIR)

# Removes everythings
clean: flush
	rm -rf $(BIN_DIR)
