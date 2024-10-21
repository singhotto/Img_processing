# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -I./lib -I./utils -std=c++11

# Source files
SRC = main.cpp utils/Image.cc utils/ImageHandler.cc

# Object files
OBJ = $(SRC:.cpp=.o)

# Output executable
OUTPUT = main

# Default target
all: $(OUTPUT)

# Link the executable
$(OUTPUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OUTPUT) $(OBJ)

.PHONY: all clean
