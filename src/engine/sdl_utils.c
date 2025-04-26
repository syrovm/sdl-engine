#include "sdl_utils.h"
#include <SDL.h>
#include <SDL_image.h>

int init() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("IMG_Init Error: %s\n", IMG_GetError());
        return 1;
    }

    return 0;
}

SDL_Window* createWindow(const char* title, int x, int y, int w, int h, Uint32 flags) {
    SDL_Window* window = SDL_CreateWindow(title, x, y, w, h, flags);
    if(window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return NULL;
    }

    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return NULL;
    }

    return renderer;
}

SDL_Texture* createTexture(SDL_Renderer* renderer, const char* path) {
    SDL_Surface* surface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void cleanup(SDL_Window* window, SDL_Renderer* renderer) {
    if(renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if(window) {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
    IMG_Quit();
}

void destroyTexture(SDL_Texture* texture) {
    SDL_DestroyTexture(texture);
}
