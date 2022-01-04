#include "tools.hpp"

using namespace std;

void sdl_error(string error_message) {
    cout << error_message << endl << "SDL_Error: " << SDL_GetError() << endl;
}

void sdl_image_error(std::string error_message) {
    cout << error_message << endl << "SDL_Error: " << IMG_GetError() << endl;
}

SDL_Surface* imageSurfaceRead(std::string path, SDL_Surface *window_surface) {
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL) {
        sdl_image_error("Unable to load image");
        return NULL;
	}

    optimizedSurface = SDL_ConvertSurface( loadedSurface, window_surface->format, 0 );
    if( optimizedSurface == NULL ) {
        sdl_error("Unable to optimize image");
        return loadedSurface;
    }

    SDL_FreeSurface( loadedSurface );

	return optimizedSurface;
}

SDL_Texture* imageTextureRead(std::string path, SDL_Renderer *renderer) {
	SDL_Texture* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL) {
        sdl_image_error("Unable to load image");
        return NULL;
	}

    optimizedSurface = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if( optimizedSurface == NULL ) {
        sdl_error("Unable to create texture");
        return NULL;
    }

    SDL_FreeSurface( loadedSurface );

	return optimizedSurface;
}