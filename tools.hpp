#ifndef _TOOLS_HPP
#define _TOOLS_HPP

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


void sdl_error(std::string error_message);
void sdl_image_error(std::string error_message);
SDL_Surface* imageSurfaceRead(std::string path, SDL_Surface *window_surface);
SDL_Texture* imageTextureRead(std::string path, SDL_Renderer *renderer);
// TODO: Add loadimage

#endif