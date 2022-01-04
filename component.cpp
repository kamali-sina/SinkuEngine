#include "component.hpp"

using namespace std;

Button::Button(SDL_Rect draw_rect, std::string text) {
    draw_rect_ = draw_rect;
    text_ = text;
}

void Button::checkClicked(SDL_Event *evt) {
    if(evt->type == SDL_MOUSEBUTTONDOWN) {
        if(evt->button.button == SDL_BUTTON_LEFT &&
                evt->button.x >= draw_rect_.x &&
                evt->button.x <= (draw_rect_.x + draw_rect_.w) &&
                evt->button.y >= draw_rect_.y &&
                evt->button.y <= (draw_rect_.y + draw_rect_.h)) {
            clicked = true;
            cout<<"clicked"<<endl;
        }
    }
    if (evt->type == SDL_MOUSEBUTTONUP) {
        cout<<"released!"<<endl;
        clicked = false;
    }
}

void Button::render(SDL_Renderer *renderer) {
    // TODO: ...
    if (clicked) {
        SDL_SetRenderDrawColor(renderer, 100, 200, 255, 150);
    }else {
        SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);
    }
    
    SDL_RenderFillRect(renderer, &draw_rect_);
}