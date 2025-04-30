#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <SDL.h>
#include "game_actor.h"

struct GameActor;
typedef struct GameState {
    struct GameActor** objects;
    const Uint8* keyboardState;
    size_t object_length;
    SDL_Renderer* renderer;
} GameState;

GameState initState(SDL_Renderer*);
void renderFrame(GameState* state);
void addObject(GameState* state, struct GameActor* object);
void removeObject(GameState* state, struct GameActor* object);
void deallocState(GameState* state);

#endif
