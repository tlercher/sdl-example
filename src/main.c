#include <stdbool.h>
#include <stdio.h>

#include "SDL.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

bool should_exit = false;

void quit(int rc) {
  SDL_Quit();
  exit(rc);
}

void mainLoop() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        should_exit = true;
        break;
    }
  }
}

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s\n", SDL_GetError());
    quit(1);
  }

  SDL_Window *window = SDL_CreateWindow(
    "SDL Window",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
  );

  if (!window) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s\n", SDL_GetError());
    quit(2);
  }

  while (!should_exit) {
    mainLoop();
  }

  SDL_DestroyWindow(window);
  window = NULL;

  quit(0);
  return 0;
}