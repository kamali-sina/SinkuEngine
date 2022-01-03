#include "window.hpp"
#include<SDL2/SDL.h>

using namespace std;


int main(int argc , char *argv[]) {
    // main program for testing the engine
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		sdl_error("SDL could not initialize!");
        exit(1);
	}

    Window* window = new Window(1920, 1080, "fuck you");

    SDL_FillRect( window->window_surface, NULL, SDL_MapRGB( window->window_surface->format, 0xCC, 0xFF, 0xFF ) );
    SDL_UpdateWindowSurface(window->window);
    SDL_Delay(2000);
}