#include "window.hpp"

using namespace std;

Window::Window(int width, int height, string window_name) {
    window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                width, height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        sdl_error("Window could not be created!");
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        sdl_error("create renderer failed!");
        exit(1);
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    surface = SDL_GetWindowSurface(window);
    width_ = width;
    height_ = height;
    window_name_ = window_name;
}

void Window::update() {
    SDL_UpdateWindowSurface(window);
}