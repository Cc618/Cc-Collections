# Compilation steps :
# 1. Compile c++ sources with headers into object files in the tmp directory
# 2. Compile each object file into one executable in the bin directory

# Directories
INC_DIR := ./include
SRC_DIR := ./src
OBJ_DIR := ./tmp
BIN_DIR := ./bin

# Flags
BUILD_FLAGS := -I $(INC_DIR) -Wall
OBJ_FLAGS := -MMD
LINK_FLAGS :=

# Files
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
DEP := $(OBJ:.o=.d)
EXE := $(BIN_DIR)/main


$(EXE): objects $(BIN_DIR)
	g++ $(LINK_FLAGS) -o $(EXE) $(OBJ)

.PHONY: run
run: $(EXE)
	@echo ">>> Running program with args $(RUN_ARGS)"
	./$(EXE) $(RUN_ARGS)

# Objects
.PHONY: objects
objects: $(OBJ_DIR) $(OBJ)

# Each object
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(OBJ_FLAGS) $(BUILD_FLAGS) -c -o $@ $<

# Directories
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

# Removes only temporary (objects) files
.PHONY: flush
flush:
	rm -rf $(OBJ_DIR)

# Removes everythings
.PHONY: clean
clean: flush
	rm -rf $(BIN_DIR)


# Include depedencies (auto update headers)
-include $(DEP)
