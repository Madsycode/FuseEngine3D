# engine library
project(Engine)

# collect all headers and cpp files for the library
file(GLOB_RECURSE VAR_SOURCES src/*.cpp CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE VAR_HEADERS src/*.h CMAKE_CONFIGURE_DEPENDS)
add_library(${PROJECT_NAME} ${VAR_HEADERS} ${VAR_SOURCES})

# define export api symbol
add_definitions(-DFUSE_EXPORT)

# add src directory to include paths
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# precompile headers
target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h)

