#include "window.hpp"
#include "component.hpp"
#include<SDL2/SDL.h>

using namespace std;


int main(int argc , char *argv[]) {
    // main program for testing the engine
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		sdl_error("SDL could not initialize!");
        exit(1);
	}

    Window* window = new Window(800, 600, "fuck you");
    
    Button *button = new Button(SDL_Rect({0,0, 50, 50}), "fuck you");
    bool quit = false;


    while(!quit) {
        SDL_Event evt;

        while(SDL_PollEvent(&evt)) {
            // quit on close, window close, or 'escape' key hit
            if(evt.type == SDL_QUIT ||
                    (evt.type == SDL_WINDOWEVENT && evt.window.event == SDL_WINDOWEVENT_CLOSE) ||
                    (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_ESCAPE)) {
                quit = true;
            }
            button->checkClicked(&evt);
            // TODO: Handle Buttons
            // TODO: Handle key presses
        }
        
        SDL_SetRenderDrawColor(window->renderer, 200, 100, 110, 255);
        SDL_RenderClear(window->renderer);
        button->render(window->renderer);
        SDL_RenderPresent(window->renderer);
    }
    SDL_DestroyWindow(window->window);
    SDL_DestroyRenderer(window->renderer);
    return 0;
}