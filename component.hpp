#ifndef _COMPONENT_HPP
#define _ENGINE_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>


class Button {
    public:
    Button(SDL_Rect draw_rect, std::string text);
    void checkClicked(SDL_Event *evt);
    void render(SDL_Renderer *renderer);

    private:
    SDL_Rect draw_rect_;
    std::string text_;
    bool clicked;
};


#endif