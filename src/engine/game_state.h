#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <SDL.h>
#include "vector.h"

typedef struct Graphic {
    SDL_Texture* texture;
    SDL_Rect positionRect;
    int system;
    Vector velocity;
} Graphic;

typedef struct GameState {
    Graphic** objects;
    const Uint8* keyboardState;
    size_t object_length;
    SDL_Renderer* renderer;
} GameState;

Graphic* createGraphic(GameState* state, const char* texturePath, SDL_Rect initialDstRect);
GameState initState(SDL_Renderer*);
void renderFrame(GameState* state);
void addObject(GameState* state, Graphic* object);
void removeObject(GameState* state, Graphic* object);
void deallocState(GameState* state);

#endif
