cmake_minimum_required(VERSION 3.10)  # Set the minimum required version of CMake
project(MyProject)                    # Replace "MyProject" with your project name

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}      # Include current source directory
    ${CMAKE_SOURCE_DIR}/lib  # Include lib directory
)

# Source files
set(SRCS
    main.cpp
    utils/Image.cc
    utils/ImageHandler.cc
    utils/ImageProcessor.cc
    lib/stb_image.cc
    lib/stb_image_write.cc
    utils/ChartGenerator/Chart.cc
)

# Header files (optional, for IDEs and documentation)
set(HEADERS
    utils/Image.hh
    utils/ImageHandler.hh
    utils/ImageProcessor.hh
    utils/ChartGenerator/BMPHeader.hh
    utils/ChartGenerator/Font.hh
    utils/ChartGenerator/Chart.hh
    lib/stb_image.h
    lib/stb_image_write.h
)

# Find TIFF library
find_package(TIFF REQUIRED)
if (TIFF_FOUND)
    include_directories(${TIFF_INCLUDE_DIR})  # Include TIFF headers
else()
    message(FATAL_ERROR "TIFF library not found")
endif()

# Add executable target
add_executable(main ${SRCS})

# Link the TIFF library to the target
target_link_libraries(main ${TIFF_LIBRARIES})
