#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include <vector>
#include <iostream>
#include <SDL2/SDL.h>
#include "tools.hpp"

class Window {
    public:
    Window(int width, int height, std::string window_name="main window");
    void update();

    // vector<Component*>
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Renderer* renderer;
    int width_;
    int height_;
    std::string window_name_;
};


#endif