# C++ Compiler
XC=g++

# Directories
OBJ_DIR=build
BIN_DIR=bin
SRC_DIR=src
INC_DIR=include

# Compilation flags
INCLUDES= -I include -I src -I libs
FLAGS= $(strip -g -std=c++11 -Wall -Wextra $(INCLUDES))

# Get list of all .cpp files in SRC_DIR
SOURCE_FILES=$(wildcard $(SRC_DIR)/*.cpp)
# For each element in SOURCE_FILES that looks like '$(SRC_DIR)/%.cpp' transform to '$(OBJ_DIR)/%.o'
OBJECT_FILES=$(SOURCE_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


$(BIN_DIR)/program.exe: $(OBJECT_FILES)
	mkdir -p $(@D)
	$(XC) $(OBJECT_FILES) -o $(BIN_DIR)/program.exe
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(XC) $(FLAGS) -c $< -o $@
clean:
	rm -r $(OBJ_DIR)
	rm -r $(BIN_DIR)
