# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/singhotto/Documents/ImgProcessing/img_processing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/singhotto/Documents/ImgProcessing/img_processing/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: /Users/singhotto/Documents/ImgProcessing/img_processing/main.cpp
CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /Users/singhotto/Documents/ImgProcessing/img_processing/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/singhotto/Documents/ImgProcessing/img_processing/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/singhotto/Documents/ImgProcessing/img_processing/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/utils/Image.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/utils/Image.cc.o: /Users/singhotto/Documents/ImgProcessing/img_processing/utils/Image.cc
CMakeFiles/main.dir/utils/Image.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/utils/Image.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/utils/Image.cc.o -MF CMakeFiles/main.dir/utils/Image.cc.o.d -o CMakeFiles/main.dir/utils/Image.cc.o -c /Users/singhotto/Documents/ImgProcessing/img_processing/utils/Image.cc

CMakeFiles/main.dir/utils/Image.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/utils/Image.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/singhotto/Documents/ImgProcessing/img_processing/utils/Image.cc > CMakeFiles/main.dir/utils/Image.cc.i

CMakeFiles/main.dir/utils/Image.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/utils/Image.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/singhotto/Documents/ImgProcessing/img_processing/utils/Image.cc -o CMakeFiles/main.dir/utils/Image.cc.s

CMakeFiles/main.dir/utils/Pixel.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/utils/Pixel.cc.o: /Users/singhotto/Documents/ImgProcessing/img_processing/utils/Pixel.cc
CMakeFiles/main.dir/utils/Pixel.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/utils/Pixel.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/utils/Pixel.cc.o -MF CMakeFiles/main.dir/utils/Pixel.cc.o.d -o CMakeFiles/main.dir/utils/Pixel.cc.o -c /Users/singhotto/Documents/ImgProcessing/img_processing/utils/Pixel.cc

CMakeFiles/main.dir/utils/Pixel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/utils/Pixel.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/singhotto/Documents/ImgProcessing/img_processing/utils/Pixel.cc > CMakeFiles/main.dir/utils/Pixel.cc.i

CMakeFiles/main.dir/utils/Pixel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/utils/Pixel.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/singhotto/Documents/ImgProcessing/img_processing/utils/Pixel.cc -o CMakeFiles/main.dir/utils/Pixel.cc.s

CMakeFiles/main.dir/utils/ImageHandler.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/utils/ImageHandler.cc.o: /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ImageHandler.cc
CMakeFiles/main.dir/utils/ImageHandler.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/utils/ImageHandler.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/utils/ImageHandler.cc.o -MF CMakeFiles/main.dir/utils/ImageHandler.cc.o.d -o CMakeFiles/main.dir/utils/ImageHandler.cc.o -c /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ImageHandler.cc

CMakeFiles/main.dir/utils/ImageHandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/utils/ImageHandler.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ImageHandler.cc > CMakeFiles/main.dir/utils/ImageHandler.cc.i

CMakeFiles/main.dir/utils/ImageHandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/utils/ImageHandler.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ImageHandler.cc -o CMakeFiles/main.dir/utils/ImageHandler.cc.s

CMakeFiles/main.dir/utils/ImageProcessor.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/utils/ImageProcessor.cc.o: /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ImageProcessor.cc
CMakeFiles/main.dir/utils/ImageProcessor.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/utils/ImageProcessor.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/utils/ImageProcessor.cc.o -MF CMakeFiles/main.dir/utils/ImageProcessor.cc.o.d -o CMakeFiles/main.dir/utils/ImageProcessor.cc.o -c /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ImageProcessor.cc

CMakeFiles/main.dir/utils/ImageProcessor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/utils/ImageProcessor.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ImageProcessor.cc > CMakeFiles/main.dir/utils/ImageProcessor.cc.i

CMakeFiles/main.dir/utils/ImageProcessor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/utils/ImageProcessor.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ImageProcessor.cc -o CMakeFiles/main.dir/utils/ImageProcessor.cc.s

CMakeFiles/main.dir/lib/stb_image.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lib/stb_image.cc.o: /Users/singhotto/Documents/ImgProcessing/img_processing/lib/stb_image.cc
CMakeFiles/main.dir/lib/stb_image.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/lib/stb_image.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/lib/stb_image.cc.o -MF CMakeFiles/main.dir/lib/stb_image.cc.o.d -o CMakeFiles/main.dir/lib/stb_image.cc.o -c /Users/singhotto/Documents/ImgProcessing/img_processing/lib/stb_image.cc

CMakeFiles/main.dir/lib/stb_image.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/lib/stb_image.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/singhotto/Documents/ImgProcessing/img_processing/lib/stb_image.cc > CMakeFiles/main.dir/lib/stb_image.cc.i

CMakeFiles/main.dir/lib/stb_image.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/lib/stb_image.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/singhotto/Documents/ImgProcessing/img_processing/lib/stb_image.cc -o CMakeFiles/main.dir/lib/stb_image.cc.s

CMakeFiles/main.dir/lib/stb_image_write.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lib/stb_image_write.cc.o: /Users/singhotto/Documents/ImgProcessing/img_processing/lib/stb_image_write.cc
CMakeFiles/main.dir/lib/stb_image_write.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/lib/stb_image_write.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/lib/stb_image_write.cc.o -MF CMakeFiles/main.dir/lib/stb_image_write.cc.o.d -o CMakeFiles/main.dir/lib/stb_image_write.cc.o -c /Users/singhotto/Documents/ImgProcessing/img_processing/lib/stb_image_write.cc

CMakeFiles/main.dir/lib/stb_image_write.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/lib/stb_image_write.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/singhotto/Documents/ImgProcessing/img_processing/lib/stb_image_write.cc > CMakeFiles/main.dir/lib/stb_image_write.cc.i

CMakeFiles/main.dir/lib/stb_image_write.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/lib/stb_image_write.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/singhotto/Documents/ImgProcessing/img_processing/lib/stb_image_write.cc -o CMakeFiles/main.dir/lib/stb_image_write.cc.s

CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.o: /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ChartGenerator/Chart.cc
CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.o -MF CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.o.d -o CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.o -c /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ChartGenerator/Chart.cc

CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ChartGenerator/Chart.cc > CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.i

CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/singhotto/Documents/ImgProcessing/img_processing/utils/ChartGenerator/Chart.cc -o CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/utils/Image.cc.o" \
"CMakeFiles/main.dir/utils/Pixel.cc.o" \
"CMakeFiles/main.dir/utils/ImageHandler.cc.o" \
"CMakeFiles/main.dir/utils/ImageProcessor.cc.o" \
"CMakeFiles/main.dir/lib/stb_image.cc.o" \
"CMakeFiles/main.dir/lib/stb_image_write.cc.o" \
"CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/utils/Image.cc.o
main: CMakeFiles/main.dir/utils/Pixel.cc.o
main: CMakeFiles/main.dir/utils/ImageHandler.cc.o
main: CMakeFiles/main.dir/utils/ImageProcessor.cc.o
main: CMakeFiles/main.dir/lib/stb_image.cc.o
main: CMakeFiles/main.dir/lib/stb_image_write.cc.o
main: CMakeFiles/main.dir/utils/ChartGenerator/Chart.cc.o
main: CMakeFiles/main.dir/build.make
main: /opt/homebrew/lib/libtiff.dylib
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /Users/singhotto/Documents/ImgProcessing/img_processing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/singhotto/Documents/ImgProcessing/img_processing /Users/singhotto/Documents/ImgProcessing/img_processing /Users/singhotto/Documents/ImgProcessing/img_processing/build /Users/singhotto/Documents/ImgProcessing/img_processing/build /Users/singhotto/Documents/ImgProcessing/img_processing/build/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend

