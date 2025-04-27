#ifndef SDL_UTILS_H
#define SDL_UTILS_H
#include <SDL.h>

int init();
SDL_Window* createWindow(const char*, int, int, int, int, Uint32);
SDL_Renderer* createRenderer(SDL_Window* window);
SDL_Texture* createTexture(SDL_Renderer* renderer, const char* path);
void cleanup(SDL_Window* window, SDL_Renderer* renderer);
void destroyTexture(SDL_Texture* texture);

#endif
