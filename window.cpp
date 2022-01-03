#include "window.hpp"

using namespace std;

Window::Window(int width, int height, string window_name) {
    window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                width, height, SDL_WINDOW_SHOWN);
    if( window == NULL ) {
        sdl_error("Window could not be created!");
        exit(1);
    }

    window_surface = SDL_GetWindowSurface(window);
    width_ = width;
    height_ = height;
    window_name_ = window_name;
}