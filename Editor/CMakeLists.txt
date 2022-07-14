# editor (.exe)
project(Editor)

# collect all headers and c++ files
file(GLOB_RECURSE VAR_SOURCES src/*.cpp CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE VAR_HEADERS src/*.h CMAKE_CONFIGURE_DEPENDS)
add_executable(${PROJECT_NAME} ${VAR_HEADERS} ${VAR_SOURCES})

# link engine library
target_link_libraries(${PROJECT_NAME} PUBLIC Engine)

# add src directory path
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
