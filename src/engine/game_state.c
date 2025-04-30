#include "game_state.h"
#include <SDL.h>

GameState initState(SDL_Renderer* renderer) {
    GameState g = (GameState){
        .objects = NULL,
        .keyboardState = SDL_GetKeyboardState(NULL),
        .object_length = 0,
        .renderer = renderer
    };

    return g;
}

void renderFrame(GameState* state) {
    SDL_RenderClear(state->renderer);
    if(!state->objects)
        return;
    for(int i = 0; i < state->object_length; i++) {
        GameActor* object = state->objects[i];
        SDL_Rect objectRect = (SDL_Rect){
            .x = object->position.x,
            .y = object->position.y,
            .w = object->width,
            .h = object->height
        };
        if(object != NULL) {
            SDL_RenderCopy(state->renderer, object->texture, NULL, &objectRect);
        }
    }
    SDL_RenderPresent(state->renderer);
}

void addObject(GameState* state, GameActor* object) {
    if(state->objects == NULL) {
        state->object_length = 1;
        state->objects = malloc(sizeof(GameActor*));
    }
    else
        state->objects = realloc(state->objects, sizeof(GameActor*) * (++state->object_length));
    state->objects[state->object_length - 1] = object;
}

void destroyGameActor(GameActor* object) {
    if(object != NULL) {
        SDL_DestroyTexture(object->texture);
    }
    free(object);
}

void removeObject(GameState* state, GameActor* object) {
    int indexToRemove = -1;
    for(int i = 0; i < state->object_length; i++) {
        if(state->objects[i] == object) {
            indexToRemove = i;
            break;
        }
    }

    if(indexToRemove != -1) {
        destroyGameActor(state->objects[indexToRemove]); 
        for(int i = indexToRemove; i < state->object_length - 1; i++) {
            state->objects[i] = state->objects[i + 1];
        }

        state->object_length -= 1;
        if(state->object_length > 0)
            state->objects = realloc(state->objects, sizeof(GameActor*) * (state->object_length));
        else
            free(state->objects);
    }
}

void deallocState(GameState* state) {
    for(int i = 0; i < state->object_length; i++) {
        removeObject(state, state->objects[i]);
    }
    SDL_DestroyRenderer(state->renderer);
}

