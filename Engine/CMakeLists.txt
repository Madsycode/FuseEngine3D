# engine library
project(Engine)

# collect all headers and cpp files
file(GLOB_RECURSE VAR_SOURCES src/*.cpp CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE VAR_HEADERS src/*.h CMAKE_CONFIGURE_DEPENDS)
add_library(${PROJECT_NAME} ${VAR_HEADERS} ${VAR_SOURCES})

# define export api symbol
add_definitions(-DFUSE_EXPORT)

# add src directory to include paths
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# precompile headers
target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h)

# linux
if (UNIX)
  find_package(glfw3 REQUIRED)
  target_link_libraries(${PROJECT_NAME} glfw)
endif (UNIX)

# Windows
if (WIN32)
  # link libraries
  target_link_libraries(${PROJECT_NAME} glfw3dll)  

  # define path variable for libraries folder called VAR_LIBRARIES
  set(VAR_LIBRARIES ${CMAKE_SOURCE_DIR}/Dependencies/Libraries)

  # libraries includes folder
  target_include_directories(${PROJECT_NAME} PUBLIC ${VAR_LIBRARIES}/Includes)

  # .lib files directory
  target_link_directories(${PROJECT_NAME} PUBLIC ${VAR_LIBRARIES}/Shared/libs)
  target_link_directories(${PROJECT_NAME} PUBLIC ${VAR_LIBRARIES}/$<CONFIGURATION>/libs)

  # post-build command to copy all debug/release .dll files to the output directory
  add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
   ${VAR_LIBRARIES}/$<CONFIGURATION>/bin ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)

  # post-build command copy all shared .dll files to output directory
  add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
   ${VAR_LIBRARIES}/Shared/bin ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)
endif (WIN32)