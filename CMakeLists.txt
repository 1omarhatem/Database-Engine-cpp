# CMakeLists.txt for Database_Engine_cpp project

cmake_minimum_required(VERSION 3.10)
project(Database_Engine_cpp CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the source and include directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)
set(EXECUTABLE_NAME dbe)

# Collect all .cpp and .h files from src/ and include/
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${INC_DIR}/*.h)

# Add executable target
add_executable(${EXECUTABLE_NAME} ${SOURCES} ${HEADERS})

# Include the include folder for headers
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${INC_DIR})

# Set global debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb -DDEBUG -Wall -Wextra -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -Wall")

# Use the debug and release flags correctly
target_compile_options(${EXECUTABLE_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g -ggdb -Wall -Wextra -O0>
    $<$<CONFIG:Release>:-O2 -DNDEBUG -Wall>
)

# Print some useful info for debugging
message(STATUS "CMake build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler flags (Debug): ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "Compiler flags (Release): ${CMAKE_CXX_FLAGS_RELEASE}")

# Set output directory
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
