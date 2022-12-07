set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
  message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the source code directory and run \"cmake -S ${CMAKE_SOURCE_DIR} -B .\" from there")
endif()


cmake_minimum_required(VERSION 3.20)
set(PROJECT_TARGET_NAME "example")

project(${PROJECT_TARGET_NAME})


include(SDL)

set(EXAMPLE_SOURCES
    src/main.c
)

set(EXAMPLE_WIN32_SOURCES
    # Files which should be included only on Windows
)
set(EXAMPLE_UNIX_SOURCES
    # Files which should be excluded for Windows
)

set(THIRDPARTY_WIN32_SOURCES
    # Files which should be included only on Windows
)
set(THIRDPARTY_UNIX_SOURCES
    # Files which should be excluded for Windows
)

include_directories(include)

if(WIN32)
  set(EXAMPLE_SOURCES ${EXAMPLE_SOURCES} ${EXAMPLE_WIN32_SOURCES})
  set(THIRDPARTY_SOURCES ${THIRDPARTY_SOURCES} ${THIRDPARTY_WIN32_SOURCES})
  add_definitions(-DUNICODE -D_UNICODE)
else()
  set(EXAMPLE_SOURCES ${EXAMPLE_SOURCES} ${EXAMPLE_UNIX_SOURCES})
  set(THIRDPARTY_SOURCES ${THIRDPARTY_SOURCES} ${THIRDPARTY_UNIX_SOURCES})
  add_definitions(-DUNIX -D_UNIX)
  add_link_options(-pthread)
endif()

if(MSVC)
  # Use all cores for compilation
  set(CMAKE_C_FLAGS "/MP ${CMAKE_C_FLAGS}")
  set(CMAKE_CXX_FLAGS "/MP ${CMAKE_CXX_FLAGS}")

  set(CMAKE_C_FLAGS_RELEASE "/O2")
  set(CMAKE_CXX_FLAGS_RELEASE "/O2")
 endif()

add_executable(${PROJECT_TARGET_NAME} WIN32 MACOSX_BUNDLE ${EXAMPLE_SOURCES} ${THIRDPARTY_SOURCES})

target_link_libraries(${PROJECT_TARGET_NAME} PRIVATE ${_SDL_BUILD_TARGET})

set_target_properties(${PROJECT_TARGET_NAME} PROPERTIES C_STANDARD 11)