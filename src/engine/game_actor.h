#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H
#include <SDL.h>
#include "vector.h"
#include "game_state.h"

struct GameState;
typedef struct GameActor {
    SDL_Texture* texture;
    int system;
    int width;
    int height;
    Vector position;
    Vector velocity;
} GameActor;

GameActor* createGameActor(struct GameState* state, const char* texturePath, Vector, int, int);

#endif
