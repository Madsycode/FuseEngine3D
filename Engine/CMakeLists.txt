# engine library
project(Engine)

# collect all headers and cpp files
file(GLOB_RECURSE VAR_SOURCES src/*.cpp CMAKE_CONFIGURE_DEPENDS)
file(GLOB_RECURSE VAR_HEADERS src/*.h CMAKE_CONFIGURE_DEPENDS)
add_library(${PROJECT_NAME} ${VAR_HEADERS} ${VAR_SOURCES})

# define export api symbol
add_definitions(-DFUSE_EXPORT)

# Windows
if (WIN32)
  # define path variable for libraries folder called VAR_LIBRARIES
  set(VAR_LIBRARIES ${CMAKE_SOURCE_DIR}/Dependencies/Libraries)

  # libraries includes folder
  target_include_directories(${PROJECT_NAME} PUBLIC ${VAR_LIBRARIES}/Includes)

  # shared .lib files folder
  target_link_directories(${PROJECT_NAME} PUBLIC ${VAR_LIBRARIES}/Shared/libs)

  if(${FUSE_DEBUG})  
    # debug .lib files folder
    target_link_directories(${PROJECT_NAME} PUBLIC ${VAR_LIBRARIES}/Debug/libs)
  else()
    # release .lib files folder
    target_link_directories(${PROJECT_NAME} PUBLIC ${VAR_LIBRARIES}/Release/libs)
  endif()

  # link libraries
  target_link_libraries(${PROJECT_NAME} glfw3dll)
endif (WIN32)


# linux
if (UNIX)
  find_package(glfw3 REQUIRED)
  target_link_libraries(${PROJECT_NAME} glfw)
endif (UNIX)


# precompile headers
target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h)

# add src directory to include paths
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

