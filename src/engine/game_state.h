#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <SDL.h>
#include "vector.h"

typedef struct GameActor {
    SDL_Texture* texture;
    int system;
    int width;
    int height;
    Vector position;
    Vector velocity;
} GameActor;

typedef struct GameState {
    GameActor** objects;
    const Uint8* keyboardState;
    size_t object_length;
    SDL_Renderer* renderer;
} GameState;

GameActor* createGameActor(GameState* state, const char* texturePath, Vector, int, int);
GameState initState(SDL_Renderer*);
void renderFrame(GameState* state);
void addObject(GameState* state, GameActor* object);
void removeObject(GameState* state, GameActor* object);
void deallocState(GameState* state);

#endif
