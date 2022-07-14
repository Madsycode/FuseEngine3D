cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 17)
project(FuseEngine3D)

# define symbol for Debug build
if(CMAKE_BUILD_TYPE MATCHES Debug)
  add_definitions(-DFUSE_DEBUG)
endif()

# output dirs windows
if(WIN32)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif(WIN32)

# output dirs linux
if(UNIX)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
endif(UNIX)

# add engine, editor, game
add_subdirectory(Engine)
add_subdirectory(Editor)
add_subdirectory(Runtime)
