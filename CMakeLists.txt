# CMakeLists.txt for Database_Engine_cpp project

cmake_minimum_required(VERSION 3.10)

project(Database_Engine_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

set(SOURCE_FILES
        src/main.cpp
        # src/value.cpp
        # src/record.cpp
        # src/bplus_tree.cpp
        # src/index.cpp
        # src/table.cpp
        # src/database.cpp
        # src/sql_parser.cpp
        # src/minidb.cpp
)

add_executable(Database_Engine_cpp ${SOURCE_FILES})

set_target_properties(Database_Engine_cpp PROPERTIES
        LINK_FLAGS "-Wl,--subsystem,console"
        WIN32_EXECUTABLE FALSE
)

target_link_libraries(Database_Engine_cpp PRIVATE -lmingw32 -lstdc++) # Link essential MinGW library