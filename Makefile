# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -I. -Ilib

# Source files
SRCS = main.cpp utils/Image.cc utils/ImageHandler.cc

# Header files (not used in the compilation command, just for reference)
HEADERS = utils/Image.hh utils/ImageHandler.hh lib/stb_image.h lib/stb_image_write.h

# Output executable
TARGET = img_processing

# Build target
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Print header files (optional)
headers:
	@echo "Header files:"
	@echo $(HEADERS)

# Clean target
clean:
	rm -f $(TARGET)

.PHONY: all clean headers
