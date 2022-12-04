cmake_minimum_required(VERSION 3.20)
project(example)

set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_STATIC_PIC ON CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/SDL)

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

  set(CMAKE_C_FLAGS_RELEASE "/O2 /GL")
  set(CMAKE_CXX_FLAGS_RELEASE "/O2 /GL")
  set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/LTCG")
endif()

add_executable(example WIN32 MACOSX_BUNDLE ${EXAMPLE_SOURCES} ${THIRDPARTY_SOURCES})
target_link_libraries(example SDL2main SDL2-static)
set_target_properties(example PROPERTIES C_STANDARD 11)