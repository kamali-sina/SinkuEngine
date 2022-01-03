#include "tools.hpp"

using namespace std;

void sdl_error(string error_message) {
    cout << error_message << endl << "SDL_Error: " << SDL_GetError() << endl;
}