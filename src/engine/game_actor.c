#include "game_actor.h"
#include "game_state.h"
#include <SDL.h>
#include "sdl_utils.h"

GameActor* createGameActor(GameState* state, const char* texturePath, Vector position, int width, int height) {
    SDL_Texture* texture = createTexture(state->renderer, texturePath);
    GameActor* result = malloc(sizeof(GameActor));
    *result = (GameActor){
        .texture = texture,
        .position = position,
        .width = width,
        .height = height,
        .velocity = (Vector){ .x = 0, .y = 0 }
    };

    return result;
}
