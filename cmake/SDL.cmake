# Option to use system provided SDL, if it shouldn't be bundled in
option(VENDOR_SDL "Use vendored SDL" ON)


if(VENDOR_SDL)
  set(SDL_DIRECTORY "thirdparty/SDL")
  set(SDL_STATIC ON CACHE BOOL "" FORCE)
  set(SDL_STATIC_PIC ON CACHE BOOL "" FORCE)
  set(SDL_SHARED OFF CACHE BOOL "" FORCE)
  add_subdirectory(${SDL_DIRECTORY} EXCLUDE_FROM_ALL)

  source_group("Thirdparty\\SDL" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/${SDL_DIRECTORY}/.+")

  set(_SDL_BUILD_TARGET SDL2::SDL2main SDL2::SDL2-static)
else()
  find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
  find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2_main)
  set(_SDL_BUILD_TARGET SDL2::SDL2main SDL2::SDL2)
endif()